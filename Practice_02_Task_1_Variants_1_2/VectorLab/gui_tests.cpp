#include "mainwindow.h"
#include <QtTest>
#include <QLabel>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QTabWidget>
#include <QTableWidget>
#include <QComboBox>
#include <QSlider>
#include <QApplication>
#include <QClipboard>
class GuiTests:public QObject {
 Q_OBJECT
private slots:
 void initTestCase(){QApplication::setStyle("Fusion");QLocale::setDefault(QLocale(QLocale::Russian,QLocale::Russia));}
 void velocity_defaults(){
  MainWindow w;
  auto* table=w.findChild<QTableWidget*>("resultTable");
  QCOMPARE(table->rowCount(),4);
  QCOMPARE(table->item(2,1)->text(),QStringLiteral("12,000"));
  QCOMPARE(table->item(3,1)->text(),QStringLiteral("9,600"));
  QVERIFY(w.findChild<QLabel*>("mainValue")->text().contains("12,410"));
 }
 void route_and_live_edit(){
  MainWindow w;w.findChild<QTabWidget*>("variantTabs")->setCurrentIndex(1);
  auto* table=w.findChild<QTableWidget*>("resultTable");
  QCOMPARE(table->rowCount(),4);
  QVERIFY(table->item(2,3));QCOMPARE(table->item(2,3)->text(),QStringLiteral("50,000"));
  QVERIFY(w.findChild<QLabel*>("mainValue")->text().contains("364,005"));
  w.findChild<QDoubleSpinBox*>("finishZ")->setValue(50);
  QCOMPARE(table->item(2,3)->text(),QStringLiteral("-50,000"));
  QVERIFY(w.findChild<QLabel*>("statusValue")->text().contains(QStringLiteral("Совпадает")));
 }
 void zero_reset_and_state_preservation(){
  MainWindow w;w.findChild<QPushButton*>("zeroButton")->click();
  auto* table=w.findChild<QTableWidget*>("resultTable");
  QVERIFY(table->item(2,4));
  QCOMPARE(table->item(2,4)->text(),QStringLiteral("0,000"));
  w.findChild<QDoubleSpinBox*>("airX")->setValue(-5);
  w.findChild<QTabWidget*>("variantTabs")->setCurrentIndex(1);
  w.findChild<QPushButton*>("presetButton")->click();
  w.findChild<QTabWidget*>("variantTabs")->setCurrentIndex(0);
  QCOMPARE(w.findChild<QDoubleSpinBox*>("airX")->value(),-5.0);
  w.findChild<QPushButton*>("presetButton")->click();
  QCOMPARE(table->item(2,1)->text(),QStringLiteral("12,000"));
 }
 void negative_factor_projection_and_copy(){
  MainWindow w;w.findChild<QDoubleSpinBox*>("factor")->setValue(-1);
  auto* table=w.findChild<QTableWidget*>("resultTable");
  QVERIFY(table->item(3,1));
  QCOMPARE(table->item(3,1)->text(),QStringLiteral("-12,000"));
  auto* combo=w.findChild<QComboBox*>("projectionCombo");
  combo->setCurrentIndex(2);
  QVERIFY(!w.findChild<QSlider*>("yawSlider")->isEnabled());
  combo->setCurrentIndex(0);QVERIFY(w.findChild<QSlider*>("yawSlider")->isEnabled());
  // Verify serialized calculation independently of the Windows clipboard/session.
  QVERIFY(w.calculationReport().contains(QStringLiteral("-12,000")));
  w.show();QTest::qWait(50);QVERIFY(!w.grab().isNull());
 }
 void render_edge_cases_and_compact_window(){
  MainWindow w;w.resize(1040,720);w.show();QTest::qWait(50);
  auto* air=w.findChild<QDoubleSpinBox*>("airX");
  auto* windTitle=w.findChild<QLabel*>("windTitle");
  QVERIFY(air->mapTo(&w,QPoint(0,air->height())).y()<=windTitle->mapTo(&w,QPoint(0,0)).y());
  QVERIFY(w.grab().save("compact-preview.png"));
  for(int mode=0;mode<2;++mode){
   w.findChild<QTabWidget*>("variantTabs")->setCurrentIndex(mode);
   w.findChild<QPushButton*>("zeroButton")->click();
   for(int plane=0;plane<4;++plane){
    w.findChild<QComboBox*>("projectionCombo")->setCurrentIndex(plane);
    QVERIFY(!w.grab().isNull());
   }
  }
  w.findChild<QDoubleSpinBox*>("finishX")->setValue(-1000000);
  w.findChild<QDoubleSpinBox*>("finishY")->setValue(1000000);
  w.findChild<QDoubleSpinBox*>("finishZ")->setValue(-1000000);
  w.findChild<QComboBox*>("projectionCombo")->setCurrentIndex(0);
  QVERIFY(!w.grab().isNull());
  QVERIFY(w.findChild<QLabel*>("statusValue")->text().contains(QStringLiteral("Совпадает")));
 }
};
QTEST_MAIN(GuiTests)
#include "gui_tests.moc"
