#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QLocale>
#include <iostream>
#include <sstream>
#include <utility>
namespace {
class OutputCapture {
    std::ostringstream stream;
    std::streambuf* previous;
public:
    OutputCapture() : previous(std::cout.rdbuf(stream.rdbuf())) {}
    ~OutputCapture() { std::cout.rdbuf(previous); }
    QString text() const { return QString::fromStdString(stream.str()).trimmed(); }
};
QString readable(QString text) {
    const std::pair<const char*, const char*> translations[] = {
        {"WARNING: Emergency landing activated", "Аварийная посадка: команда активирована"},
        {"Drone landed immediately", "Высота немедленно сброшена до 0 м"},
        {"Takeoff denied: low battery", "Взлёт отклонён: заряд ниже 10%"},
        {"Drone is already flying", "Аппарат уже находится в полёте"},
        {"Drone took off", "Взлёт выполнен. Высота 1 м, расход заряда 1%"},
        {"Drone is already on the ground", "Посадка не требуется: полёт уже отключён"},
        {"Drone landed", "Посадка выполнена. Высота 0 м"},
        {"Move denied: drone is not flying", "Перемещение отклонено: сначала выполните взлёт"},
        {"Move denied: invalid position or altitude", "Перемещение отклонено: неверные координаты или отрицательная высота"},
        {"Move denied: critically low battery", "Перемещение отклонено: заряд ниже 5%"},
        {"Drone moved to new position", "Перемещение выполнено. Расход заряда 1%"},
        {"Error: invalid position or altitude", "Координаты не изменены: неверная позиция или отрицательная высота"}
    };
    for (const auto& item : translations) text.replace(QString::fromUtf8(item.first), QString::fromUtf8(item.second));
    return text;
}
}
MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(std::make_unique<Ui::MainWindow>()) {
    ui->setupUi(this);
    setMinimumSize(980, 720);
    ui->eventLog->setMaximumBlockCount(1000);
    connect(ui->takeoffButton, &QPushButton::clicked, this, [this] { execute(QStringLiteral("Взлёт"), [this] { drone.takeoff(); }); });
    connect(ui->landButton, &QPushButton::clicked, this, [this] { execute(QStringLiteral("Посадка"), [this] { drone.land(); }); });
    connect(ui->emergencyButton, &QPushButton::clicked, this, [this] { execute(QStringLiteral("Аварийная посадка"), [this] { drone.emergency_land(); }); });
    connect(ui->moveButton, &QPushButton::clicked, this, [this] {
        execute(QStringLiteral("Перемещение"), [this] { drone.move_to(ui->targetXSpin->value(), ui->targetYSpin->value(), ui->targetZSpin->value()); });
    });
    connect(ui->positionButton, &QPushButton::clicked, this, [this] {
        execute(QStringLiteral("Установка координат"), [this] { drone.set_position(ui->targetXSpin->value(), ui->targetYSpin->value(), ui->targetZSpin->value()); });
    });
    connect(ui->chargeButton, &QPushButton::clicked, this, [this] {
        execute(QStringLiteral("Изменение заряда"), [this] { drone.set_battery(ui->chargeSpin->value()); });
    });
    connect(ui->createButton, &QPushButton::clicked, this, &MainWindow::create_drone);
    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::reset);
    for (auto spin : {ui->targetXSpin, ui->targetYSpin, ui->targetZSpin})
        connect(spin, &QDoubleSpinBox::valueChanged, this, [this] { refresh(); });
    route.append(QPointF(0, 0));
    ui->eventLog->appendPlainText(QStringLiteral("Готово. Аппарат №0 создан конструктором по умолчанию."));
    refresh();
}
MainWindow::~MainWindow() = default;
void MainWindow::execute(const QString& name, const std::function<void()>& action) {
    QString raw;
    { OutputCapture capture; action(); raw = capture.text(); }
    const QPointF point(drone.get_x(), drone.get_y());
    if (route.isEmpty() || route.last() != point) route.append(point);
    const QString message = raw.isEmpty() ? name + QStringLiteral(": выполнено.") : readable(raw);
    const bool warning = raw.contains("denied") || raw.contains("Error") || raw.contains("WARNING");
    ui->feedbackLabel->setStyleSheet(warning ? "color: #be424b;" : "color: #315e99;");
    ui->feedbackLabel->setText(message.section('\n', 0, 0));
    ui->eventLog->appendPlainText(QDateTime::currentDateTime().toString("hh:mm:ss") + "  " + name + "\n" + message);
    refresh();
}
void MainWindow::create_drone() {
    drone = Drone(ui->idSpin->value(), ui->chargeSpin->value());
    route.clear(); route.append(QPointF(0, 0));
    ui->feedbackLabel->setStyleSheet("color: #315e99;");
    ui->feedbackLabel->setText(QStringLiteral("Создан аппарат №%1. Заряд ограничен диапазоном 0–100%.").arg(drone.get_id()));
    ui->eventLog->appendPlainText(ui->feedbackLabel->text()); refresh();
}
void MainWindow::reset() {
    drone = Drone(); route.clear(); route.append(QPointF(0, 0));
    ui->idSpin->setValue(0); ui->chargeSpin->setValue(100);
    ui->targetXSpin->setValue(10); ui->targetYSpin->setValue(20); ui->targetZSpin->setValue(50);
    ui->feedbackLabel->setStyleSheet("color: #315e99;");
    ui->feedbackLabel->setText(QStringLiteral("Восстановлено исходное состояние: аппарат №0, заряд 100%, высота 0 м."));
    ui->eventLog->appendPlainText(ui->feedbackLabel->text()); refresh();
}
void MainWindow::refresh() {
    const QLocale locale;
    ui->idValue->setText(QStringLiteral("№ %1").arg(drone.get_id()));
    ui->flightValue->setText(drone.is_flying() ? QStringLiteral("В полёте") : QStringLiteral("Не летит"));
    ui->altitudeValue->setText(locale.toString(drone.get_altitude(), 'f', 2) + QStringLiteral(" м"));
    ui->batteryValue->setText(locale.toString(drone.get_battery(), 'f', 2) + "%");
    ui->batteryValue->setStyleSheet(drone.get_battery() < 10 ? "color: #be424b;" : "color: #2568ce;");
    ui->positionValue->setText(QStringLiteral("X: %1 м   Y: %2 м   Z: %3 м")
        .arg(locale.toString(drone.get_x(), 'f', 2)).arg(locale.toString(drone.get_y(), 'f', 2)).arg(locale.toString(drone.get_altitude(), 'f', 2)));
    ui->flightScene->set_state(drone.get_id(), drone.get_x(), drone.get_y(), drone.get_altitude(), drone.is_flying(),
        route, QPointF(ui->targetXSpin->value(), ui->targetYSpin->value()), ui->targetZSpin->value());
}
