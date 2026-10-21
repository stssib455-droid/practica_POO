#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <memory>
namespace Ui { class MainWindow; }
class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent=nullptr);
    ~MainWindow() override;
    QString calculationReport() const { return report; }
private:
    std::unique_ptr<Ui::MainWindow> ui;
    void refresh();
    void preset(bool zero);
    QString report;
};
#endif
