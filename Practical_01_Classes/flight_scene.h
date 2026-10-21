#ifndef FLIGHT_SCENE_H
#define FLIGHT_SCENE_H
#include <QWidget>
#include <QVector>
#include <QPointF>
class FlightScene : public QWidget {
public:
    explicit FlightScene(QWidget* parent = nullptr);
    void set_state(int id, double x, double y, double z, bool flying,
                   const QVector<QPointF>& route, const QPointF& target, double target_altitude);
protected:
    void paintEvent(QPaintEvent*) override;
private:
    int drone_id = 0;
    QPointF position;
    double altitude = 0;
    bool airborne = false;
    QVector<QPointF> path;
    QPointF destination;
    double destination_altitude = 0;
};
#endif
