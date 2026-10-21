#include "flight_scene.h"
#include <QPainter>
#include <QPainterPath>
#include <QLocale>
#include <algorithm>
#include <cmath>
FlightScene::FlightScene(QWidget* parent) : QWidget(parent) {
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}
void FlightScene::set_state(int id, double x, double y, double z, bool flying,
                            const QVector<QPointF>& route, const QPointF& target, double target_altitude) {
    drone_id = id; position = QPointF(x, y); altitude = z; airborne = flying;
    path = route; destination = target; destination_altitude = target_altitude;
    update();
}
void FlightScene::paintEvent(QPaintEvent*) {
    QPainter p(this); p.setRenderHint(QPainter::Antialiasing); p.fillRect(rect(), Qt::white);
    p.setFont(QFont("Segoe UI", 9));
    const QRectF plot(48, 28, width() - 175, height() - 80);
    if (plot.width() < 30 || plot.height() < 30) return;
    double xmin = std::min(position.x(), destination.x()), xmax = std::max(position.x(), destination.x());
    double ymin = std::min(position.y(), destination.y()), ymax = std::max(position.y(), destination.y());
    for (const auto& point : path) {
        xmin = std::min(xmin, point.x()); xmax = std::max(xmax, point.x());
        ymin = std::min(ymin, point.y()); ymax = std::max(ymax, point.y());
    }
    const double padding = std::max({20.0, (xmax - xmin) * 0.3, (ymax - ymin) * 0.3});
    xmin -= padding; xmax += padding; ymin -= padding; ymax += padding;
    auto map = [&](const QPointF& point) {
        return QPointF(plot.left() + (point.x() - xmin) / (xmax - xmin) * plot.width(),
                       plot.bottom() - (point.y() - ymin) / (ymax - ymin) * plot.height());
    };
    p.fillRect(plot, QColor("#f8faff"));
    for (int i = 0; i <= 4; ++i) {
        const double x = plot.left() + plot.width() * i / 4;
        const double y = plot.bottom() - plot.height() * i / 4;
        p.setPen(QColor("#e1e8f3"));
        p.drawLine(QPointF(x, plot.top()), QPointF(x, plot.bottom()));
        p.drawLine(QPointF(plot.left(), y), QPointF(plot.right(), y));
        p.setPen(QColor("#7a8aa1"));
        p.drawText(QRectF(x - 28, plot.bottom() + 5, 56, 19), Qt::AlignCenter,
            QLocale().toString(xmin + (xmax - xmin) * i / 4, 'f', 0));
        p.drawText(QRectF(0, y - 9, 41, 18), Qt::AlignRight | Qt::AlignVCenter,
            QLocale().toString(ymin + (ymax - ymin) * i / 4, 'f', 0));
    }
    p.drawText(QRectF(plot.left(), plot.bottom() + 27, plot.width(), 18), Qt::AlignCenter, QStringLiteral("X, м"));
    p.drawText(QRectF(0, 2, 46, 18), Qt::AlignCenter, QStringLiteral("Y, м"));
    if (!path.isEmpty()) {
        QPainterPath trail; trail.moveTo(map(path.first()));
        for (const auto& point : path) trail.lineTo(map(point));
        p.setPen(QPen(QColor("#6c9de8"), 2.5)); p.drawPath(trail);
        p.setBrush(QColor("#3976ec"));
        for (const auto& point : path) p.drawEllipse(map(point), 3, 3);
    }
    const QPointF drone = map(position), target = map(destination);
    p.setPen(QPen(QColor("#e0a354"), 1.5, Qt::DashLine)); p.drawLine(drone, target);
    p.setPen(QPen(QColor("#d58b2f"), 2)); p.setBrush(Qt::NoBrush); p.drawEllipse(target, 9, 9);
    p.drawLine(target + QPointF(-13, 0), target + QPointF(13, 0));
    p.drawLine(target + QPointF(0, -13), target + QPointF(0, 13));
    p.drawText(QRectF(target.x() - 45, target.y() - 37, 90, 20), Qt::AlignCenter, QStringLiteral("Целевая точка"));
    p.save(); p.translate(drone); p.rotate(-35);
    p.setPen(QPen(airborne ? QColor("#2568ce") : QColor("#7189a8"), 3));
    p.drawLine(QPointF(-10, -10), QPointF(10, 10)); p.drawLine(QPointF(-10, 10), QPointF(10, -10));
    p.setBrush(Qt::white);
    for (int x : {-11, 11}) for (int y : {-11, 11}) p.drawEllipse(QPointF(x, y), 6, 6);
    p.setBrush(airborne ? QColor("#3976ec") : QColor("#9badc5")); p.drawRoundedRect(QRectF(-5, -8, 10, 16), 3, 3);
    p.restore();
    p.setPen(QColor("#29466c"));
    p.drawText(QRectF(drone.x() - 50, drone.y() + 21, 100, 19), Qt::AlignCenter, QStringLiteral("БПЛА №%1").arg(drone_id));
    const QRectF gauge(plot.right() + 48, plot.top() + 20, 20, plot.height() - 40);
    const double top = std::ceil(std::max({100.0, altitude, destination_altitude}) / 20) * 20;
    p.setPen(Qt::NoPen); p.setBrush(QColor("#eaf0f8")); p.drawRoundedRect(gauge, 6, 6);
    const double fill = gauge.height() * altitude / top;
    p.setBrush(QColor("#3976ec"));
    if (fill > 0) p.drawRoundedRect(QRectF(gauge.left(), gauge.bottom() - fill, gauge.width(), fill), 5, 5);
    p.setPen(QColor("#71839c"));
    p.drawText(QRectF(gauge.left() - 28, plot.top() - 3, 75, 19), Qt::AlignCenter, QStringLiteral("Z, м"));
    p.drawText(QRectF(gauge.left() - 15, gauge.top() + 3, 65, 20), Qt::AlignRight, QLocale().toString(top, 'f', 0));
    p.drawText(QRectF(gauge.left() - 15, gauge.bottom() + 5, 65, 20), Qt::AlignCenter, QStringLiteral("0"));
}
