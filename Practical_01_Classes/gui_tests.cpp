#include "mainwindow.h"
#include <QtTest>
#include <QLabel>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QLocale>
class GuiTests : public QObject {
    Q_OBJECT
private slots:
    void initTestCase() { QLocale::setDefault(QLocale(QLocale::Russian, QLocale::Russia)); }
    void initial_state() {
        MainWindow w;
        QCOMPARE(w.findChild<QLabel*>("altitudeValue")->text(), QStringLiteral("0,00 м"));
        QCOMPARE(w.findChild<QLabel*>("batteryValue")->text(), QStringLiteral("100,00%"));
        QCOMPARE(w.findChild<QLabel*>("flightValue")->text(), QStringLiteral("Не летит"));
    }
    void flight_move_and_landing() {
        MainWindow w;
        w.findChild<QPushButton*>("moveButton")->click();
        QCOMPARE(w.findChild<QLabel*>("batteryValue")->text(), QStringLiteral("100,00%"));
        w.findChild<QPushButton*>("takeoffButton")->click();
        QCOMPARE(w.findChild<QLabel*>("flightValue")->text(), QStringLiteral("В полёте"));
        QCOMPARE(w.findChild<QLabel*>("altitudeValue")->text(), QStringLiteral("1,00 м"));
        w.findChild<QPushButton*>("moveButton")->click();
        QCOMPARE(w.findChild<QLabel*>("altitudeValue")->text(), QStringLiteral("50,00 м"));
        QCOMPARE(w.findChild<QLabel*>("batteryValue")->text(), QStringLiteral("98,00%"));
        w.findChild<QPushButton*>("landButton")->click();
        QCOMPARE(w.findChild<QLabel*>("altitudeValue")->text(), QStringLiteral("0,00 м"));
        QVERIFY(w.findChild<QLabel*>("positionValue")->text().contains(QStringLiteral("10,00")));
    }
    void emergency_at_zero_and_negative_altitude() {
        MainWindow w;
        w.findChild<QPushButton*>("takeoffButton")->click();
        w.findChild<QDoubleSpinBox*>("targetZSpin")->setValue(-1);
        w.findChild<QPushButton*>("moveButton")->click();
        QCOMPARE(w.findChild<QLabel*>("altitudeValue")->text(), QStringLiteral("1,00 м"));
        w.findChild<QDoubleSpinBox*>("targetZSpin")->setValue(50);
        w.findChild<QPushButton*>("moveButton")->click();
        w.findChild<QDoubleSpinBox*>("chargeSpin")->setValue(0);
        w.findChild<QPushButton*>("chargeButton")->click();
        w.findChild<QPushButton*>("emergencyButton")->click();
        QCOMPARE(w.findChild<QLabel*>("altitudeValue")->text(), QStringLiteral("0,00 м"));
        QCOMPARE(w.findChild<QLabel*>("flightValue")->text(), QStringLiteral("Не летит"));
        QCOMPARE(w.findChild<QLabel*>("batteryValue")->text(), QStringLiteral("0,00%"));
        QVERIFY(w.findChild<QPlainTextEdit*>("eventLog")->toPlainText().contains(QStringLiteral("Аварийная посадка")));
    }
    void charge_clamp_create_and_reset() {
        MainWindow w;
        w.findChild<QDoubleSpinBox*>("chargeSpin")->setValue(150);
        w.findChild<QPushButton*>("chargeButton")->click();
        QCOMPARE(w.findChild<QLabel*>("batteryValue")->text(), QStringLiteral("100,00%"));
        w.findChild<QSpinBox*>("idSpin")->setValue(7);
        w.findChild<QPushButton*>("createButton")->click();
        QCOMPARE(w.findChild<QLabel*>("idValue")->text(), QStringLiteral("№ 7"));
        w.findChild<QDoubleSpinBox*>("chargeSpin")->setValue(5);
        w.findChild<QPushButton*>("chargeButton")->click();
        w.findChild<QPushButton*>("takeoffButton")->click();
        QCOMPARE(w.findChild<QLabel*>("flightValue")->text(), QStringLiteral("Не летит"));
        w.findChild<QPushButton*>("resetButton")->click();
        QCOMPARE(w.findChild<QLabel*>("idValue")->text(), QStringLiteral("№ 0"));
        QCOMPARE(w.findChild<QLabel*>("batteryValue")->text(), QStringLiteral("100,00%"));
    }
};
QTEST_MAIN(GuiTests)
#include "gui_tests.moc"
