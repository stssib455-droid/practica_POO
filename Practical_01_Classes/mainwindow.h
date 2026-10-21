#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <memory>
#include <functional>
#include <QVector>
#include <QPointF>
#include "drone.h"
namespace Ui { class MainWindow; }
class MainWindow : public QMainWindow {
public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;
private:
    std::unique_ptr<Ui::MainWindow> ui;
    Drone drone;
    QVector<QPointF> route;
    void execute(const QString& action_name, const std::function<void()>& action);
    void refresh();
    void create_drone();
    void reset();
};
#endif
