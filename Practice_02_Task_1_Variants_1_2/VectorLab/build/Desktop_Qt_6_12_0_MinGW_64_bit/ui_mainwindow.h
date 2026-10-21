/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "vector_scene.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *rootLayout;
    QHBoxLayout *headerLayout;
    QVBoxLayout *titlesLayout;
    QLabel *eyebrow;
    QLabel *title;
    QLabel *subtitle;
    QSpacerItem *headerSpacer;
    QPushButton *copyButton;
    QHBoxLayout *metricsLayout;
    QFrame *mainCard;
    QVBoxLayout *mainLayout;
    QLabel *mainCaption;
    QLabel *mainValue;
    QLabel *mainHint;
    QFrame *extraCard;
    QVBoxLayout *extraLayout;
    QLabel *extraCaption;
    QLabel *extraValue;
    QLabel *extraHint;
    QFrame *statusCard;
    QVBoxLayout *statusLayout;
    QLabel *statusCaption;
    QLabel *statusValue;
    QLabel *statusHint;
    QHBoxLayout *bodyLayout;
    QScrollArea *controlScroll;
    QFrame *controlPanel;
    QVBoxLayout *controlLayout;
    QTabWidget *variantTabs;
    QWidget *velocityTab;
    QVBoxLayout *velocityTabLayout;
    QLabel *airTitle;
    QHBoxLayout *airRow;
    QVBoxLayout *airXCol;
    QDoubleSpinBox *airX;
    QVBoxLayout *airYCol;
    QDoubleSpinBox *airY;
    QVBoxLayout *airZCol;
    QDoubleSpinBox *airZ;
    QLabel *windTitle;
    QHBoxLayout *windRow;
    QVBoxLayout *windXCol;
    QDoubleSpinBox *windX;
    QVBoxLayout *windYCol;
    QDoubleSpinBox *windY;
    QVBoxLayout *windZCol;
    QDoubleSpinBox *windZ;
    QHBoxLayout *factorRow;
    QLabel *factorCaption;
    QDoubleSpinBox *factor;
    QWidget *routeTab;
    QVBoxLayout *routeTabLayout;
    QLabel *startTitle;
    QHBoxLayout *startRow;
    QVBoxLayout *startXCol;
    QDoubleSpinBox *startX;
    QVBoxLayout *startYCol;
    QDoubleSpinBox *startY;
    QVBoxLayout *startZCol;
    QDoubleSpinBox *startZ;
    QLabel *finishTitle;
    QHBoxLayout *finishRow;
    QVBoxLayout *finishXCol;
    QDoubleSpinBox *finishX;
    QVBoxLayout *finishYCol;
    QDoubleSpinBox *finishY;
    QVBoxLayout *finishZCol;
    QDoubleSpinBox *finishZ;
    QPushButton *presetButton;
    QPushButton *zeroButton;
    QLabel *inputNote;
    QFrame *sceneCard;
    QVBoxLayout *sceneLayout;
    QHBoxLayout *viewToolbar;
    QLabel *sceneTitle;
    QSpacerItem *viewSpacer;
    QComboBox *projectionCombo;
    VectorScene *vectorScene;
    QHBoxLayout *angleLayout;
    QLabel *yawCaption;
    QSlider *yawSlider;
    QLabel *yawValue;
    QLabel *pitchCaption;
    QSlider *pitchSlider;
    QLabel *pitchValue;
    QLabel *legendLabel;
    QHBoxLayout *bottomLayout;
    QFrame *tableCard;
    QVBoxLayout *tableLayout;
    QLabel *tableTitle;
    QTableWidget *resultTable;
    QFrame *formulaCard;
    QVBoxLayout *formulaLayout;
    QLabel *formulaTitle;
    QLabel *formulaLabel;
    QLabel *feedbackLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1240, 800);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        rootLayout = new QVBoxLayout(centralwidget);
        rootLayout->setSpacing(10);
        rootLayout->setObjectName("rootLayout");
        rootLayout->setContentsMargins(16, 16, 16, 16);
        headerLayout = new QHBoxLayout();
        headerLayout->setObjectName("headerLayout");
        titlesLayout = new QVBoxLayout();
        titlesLayout->setSpacing(2);
        titlesLayout->setObjectName("titlesLayout");
        eyebrow = new QLabel(centralwidget);
        eyebrow->setObjectName("eyebrow");

        titlesLayout->addWidget(eyebrow);

        title = new QLabel(centralwidget);
        title->setObjectName("title");

        titlesLayout->addWidget(title);

        subtitle = new QLabel(centralwidget);
        subtitle->setObjectName("subtitle");

        titlesLayout->addWidget(subtitle);


        headerLayout->addLayout(titlesLayout);

        headerSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        headerLayout->addItem(headerSpacer);

        copyButton = new QPushButton(centralwidget);
        copyButton->setObjectName("copyButton");

        headerLayout->addWidget(copyButton);


        rootLayout->addLayout(headerLayout);

        metricsLayout = new QHBoxLayout();
        metricsLayout->setObjectName("metricsLayout");
        mainCard = new QFrame(centralwidget);
        mainCard->setObjectName("mainCard");
        mainLayout = new QVBoxLayout(mainCard);
        mainLayout->setSpacing(2);
        mainLayout->setObjectName("mainLayout");
        mainCaption = new QLabel(mainCard);
        mainCaption->setObjectName("mainCaption");

        mainLayout->addWidget(mainCaption);

        mainValue = new QLabel(mainCard);
        mainValue->setObjectName("mainValue");

        mainLayout->addWidget(mainValue);

        mainHint = new QLabel(mainCard);
        mainHint->setObjectName("mainHint");

        mainLayout->addWidget(mainHint);


        metricsLayout->addWidget(mainCard);

        extraCard = new QFrame(centralwidget);
        extraCard->setObjectName("extraCard");
        extraLayout = new QVBoxLayout(extraCard);
        extraLayout->setSpacing(2);
        extraLayout->setObjectName("extraLayout");
        extraCaption = new QLabel(extraCard);
        extraCaption->setObjectName("extraCaption");

        extraLayout->addWidget(extraCaption);

        extraValue = new QLabel(extraCard);
        extraValue->setObjectName("extraValue");

        extraLayout->addWidget(extraValue);

        extraHint = new QLabel(extraCard);
        extraHint->setObjectName("extraHint");

        extraLayout->addWidget(extraHint);


        metricsLayout->addWidget(extraCard);

        statusCard = new QFrame(centralwidget);
        statusCard->setObjectName("statusCard");
        statusLayout = new QVBoxLayout(statusCard);
        statusLayout->setSpacing(2);
        statusLayout->setObjectName("statusLayout");
        statusCaption = new QLabel(statusCard);
        statusCaption->setObjectName("statusCaption");

        statusLayout->addWidget(statusCaption);

        statusValue = new QLabel(statusCard);
        statusValue->setObjectName("statusValue");

        statusLayout->addWidget(statusValue);

        statusHint = new QLabel(statusCard);
        statusHint->setObjectName("statusHint");

        statusLayout->addWidget(statusHint);


        metricsLayout->addWidget(statusCard);


        rootLayout->addLayout(metricsLayout);

        bodyLayout = new QHBoxLayout();
        bodyLayout->setObjectName("bodyLayout");
        controlScroll = new QScrollArea(centralwidget);
        controlScroll->setObjectName("controlScroll");
        controlScroll->setWidgetResizable(true);
        controlScroll->setFrameShape(QFrame::NoFrame);
        controlScroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        controlScroll->setMinimumSize(QSize(325, 0));
        controlScroll->setMaximumSize(QSize(325, 16777215));
        controlPanel = new QFrame();
        controlPanel->setObjectName("controlPanel");
        controlPanel->setMinimumSize(QSize(300, 330));
        controlPanel->setMaximumSize(QSize(16777215, 16777215));
        controlLayout = new QVBoxLayout(controlPanel);
        controlLayout->setSpacing(8);
        controlLayout->setObjectName("controlLayout");
        variantTabs = new QTabWidget(controlPanel);
        variantTabs->setObjectName("variantTabs");
        velocityTab = new QWidget();
        velocityTab->setObjectName("velocityTab");
        velocityTabLayout = new QVBoxLayout(velocityTab);
        velocityTabLayout->setSpacing(8);
        velocityTabLayout->setObjectName("velocityTabLayout");
        velocityTabLayout->setContentsMargins(-1, -1, -1, 8);
        airTitle = new QLabel(velocityTab);
        airTitle->setObjectName("airTitle");

        velocityTabLayout->addWidget(airTitle);

        airRow = new QHBoxLayout();
        airRow->setObjectName("airRow");
        airXCol = new QVBoxLayout();
        airXCol->setSpacing(2);
        airXCol->setObjectName("airXCol");
        airX = new QDoubleSpinBox(velocityTab);
        airX->setObjectName("airX");
        airX->setMinimum(-1000000.000000000000000);
        airX->setMaximum(1000000.000000000000000);
        airX->setValue(10.000000000000000);
        airX->setDecimals(3);
        airX->setKeyboardTracking(false);
        airX->setMinimumSize(QSize(70, 29));

        airXCol->addWidget(airX);


        airRow->addLayout(airXCol);

        airYCol = new QVBoxLayout();
        airYCol->setSpacing(2);
        airYCol->setObjectName("airYCol");
        airY = new QDoubleSpinBox(velocityTab);
        airY->setObjectName("airY");
        airY->setMinimum(-1000000.000000000000000);
        airY->setMaximum(1000000.000000000000000);
        airY->setValue(4.000000000000000);
        airY->setDecimals(3);
        airY->setKeyboardTracking(false);
        airY->setMinimumSize(QSize(70, 29));

        airYCol->addWidget(airY);


        airRow->addLayout(airYCol);

        airZCol = new QVBoxLayout();
        airZCol->setSpacing(2);
        airZCol->setObjectName("airZCol");
        airZ = new QDoubleSpinBox(velocityTab);
        airZ->setObjectName("airZ");
        airZ->setMinimum(-1000000.000000000000000);
        airZ->setMaximum(1000000.000000000000000);
        airZ->setValue(-1.000000000000000);
        airZ->setDecimals(3);
        airZ->setKeyboardTracking(false);
        airZ->setMinimumSize(QSize(70, 29));

        airZCol->addWidget(airZ);


        airRow->addLayout(airZCol);


        velocityTabLayout->addLayout(airRow);

        windTitle = new QLabel(velocityTab);
        windTitle->setObjectName("windTitle");

        velocityTabLayout->addWidget(windTitle);

        windRow = new QHBoxLayout();
        windRow->setObjectName("windRow");
        windXCol = new QVBoxLayout();
        windXCol->setSpacing(2);
        windXCol->setObjectName("windXCol");
        windX = new QDoubleSpinBox(velocityTab);
        windX->setObjectName("windX");
        windX->setMinimum(-1000000.000000000000000);
        windX->setMaximum(1000000.000000000000000);
        windX->setValue(2.000000000000000);
        windX->setDecimals(3);
        windX->setKeyboardTracking(false);
        windX->setMinimumSize(QSize(70, 29));

        windXCol->addWidget(windX);


        windRow->addLayout(windXCol);

        windYCol = new QVBoxLayout();
        windYCol->setSpacing(2);
        windYCol->setObjectName("windYCol");
        windY = new QDoubleSpinBox(velocityTab);
        windY->setObjectName("windY");
        windY->setMinimum(-1000000.000000000000000);
        windY->setMaximum(1000000.000000000000000);
        windY->setValue(-1.000000000000000);
        windY->setDecimals(3);
        windY->setKeyboardTracking(false);
        windY->setMinimumSize(QSize(70, 29));

        windYCol->addWidget(windY);


        windRow->addLayout(windYCol);

        windZCol = new QVBoxLayout();
        windZCol->setSpacing(2);
        windZCol->setObjectName("windZCol");
        windZ = new QDoubleSpinBox(velocityTab);
        windZ->setObjectName("windZ");
        windZ->setMinimum(-1000000.000000000000000);
        windZ->setMaximum(1000000.000000000000000);
        windZ->setValue(0.000000000000000);
        windZ->setDecimals(3);
        windZ->setKeyboardTracking(false);
        windZ->setMinimumSize(QSize(70, 29));

        windZCol->addWidget(windZ);


        windRow->addLayout(windZCol);


        velocityTabLayout->addLayout(windRow);

        factorRow = new QHBoxLayout();
        factorRow->setObjectName("factorRow");
        factorCaption = new QLabel(velocityTab);
        factorCaption->setObjectName("factorCaption");

        factorRow->addWidget(factorCaption);

        factor = new QDoubleSpinBox(velocityTab);
        factor->setObjectName("factor");
        factor->setMinimum(-10.000000000000000);
        factor->setMaximum(10.000000000000000);
        factor->setValue(0.800000000000000);
        factor->setDecimals(3);
        factor->setKeyboardTracking(false);
        factor->setMinimumSize(QSize(70, 29));

        factorRow->addWidget(factor);


        velocityTabLayout->addLayout(factorRow);

        variantTabs->addTab(velocityTab, QString());
        routeTab = new QWidget();
        routeTab->setObjectName("routeTab");
        routeTabLayout = new QVBoxLayout(routeTab);
        routeTabLayout->setSpacing(8);
        routeTabLayout->setObjectName("routeTabLayout");
        routeTabLayout->setContentsMargins(-1, -1, -1, 8);
        startTitle = new QLabel(routeTab);
        startTitle->setObjectName("startTitle");

        routeTabLayout->addWidget(startTitle);

        startRow = new QHBoxLayout();
        startRow->setObjectName("startRow");
        startXCol = new QVBoxLayout();
        startXCol->setSpacing(2);
        startXCol->setObjectName("startXCol");
        startX = new QDoubleSpinBox(routeTab);
        startX->setObjectName("startX");
        startX->setMinimum(-1000000.000000000000000);
        startX->setMaximum(1000000.000000000000000);
        startX->setValue(0.000000000000000);
        startX->setDecimals(3);
        startX->setKeyboardTracking(false);
        startX->setMinimumSize(QSize(70, 29));

        startXCol->addWidget(startX);


        startRow->addLayout(startXCol);

        startYCol = new QVBoxLayout();
        startYCol->setSpacing(2);
        startYCol->setObjectName("startYCol");
        startY = new QDoubleSpinBox(routeTab);
        startY->setObjectName("startY");
        startY->setMinimum(-1000000.000000000000000);
        startY->setMaximum(1000000.000000000000000);
        startY->setValue(0.000000000000000);
        startY->setDecimals(3);
        startY->setKeyboardTracking(false);
        startY->setMinimumSize(QSize(70, 29));

        startYCol->addWidget(startY);


        startRow->addLayout(startYCol);

        startZCol = new QVBoxLayout();
        startZCol->setSpacing(2);
        startZCol->setObjectName("startZCol");
        startZ = new QDoubleSpinBox(routeTab);
        startZ->setObjectName("startZ");
        startZ->setMinimum(-1000000.000000000000000);
        startZ->setMaximum(1000000.000000000000000);
        startZ->setValue(100.000000000000000);
        startZ->setDecimals(3);
        startZ->setKeyboardTracking(false);
        startZ->setMinimumSize(QSize(70, 29));

        startZCol->addWidget(startZ);


        startRow->addLayout(startZCol);


        routeTabLayout->addLayout(startRow);

        finishTitle = new QLabel(routeTab);
        finishTitle->setObjectName("finishTitle");

        routeTabLayout->addWidget(finishTitle);

        finishRow = new QHBoxLayout();
        finishRow->setObjectName("finishRow");
        finishXCol = new QVBoxLayout();
        finishXCol->setSpacing(2);
        finishXCol->setObjectName("finishXCol");
        finishX = new QDoubleSpinBox(routeTab);
        finishX->setObjectName("finishX");
        finishX->setMinimum(-1000000.000000000000000);
        finishX->setMaximum(1000000.000000000000000);
        finishX->setValue(300.000000000000000);
        finishX->setDecimals(3);
        finishX->setKeyboardTracking(false);
        finishX->setMinimumSize(QSize(70, 29));

        finishXCol->addWidget(finishX);


        finishRow->addLayout(finishXCol);

        finishYCol = new QVBoxLayout();
        finishYCol->setSpacing(2);
        finishYCol->setObjectName("finishYCol");
        finishY = new QDoubleSpinBox(routeTab);
        finishY->setObjectName("finishY");
        finishY->setMinimum(-1000000.000000000000000);
        finishY->setMaximum(1000000.000000000000000);
        finishY->setValue(200.000000000000000);
        finishY->setDecimals(3);
        finishY->setKeyboardTracking(false);
        finishY->setMinimumSize(QSize(70, 29));

        finishYCol->addWidget(finishY);


        finishRow->addLayout(finishYCol);

        finishZCol = new QVBoxLayout();
        finishZCol->setSpacing(2);
        finishZCol->setObjectName("finishZCol");
        finishZ = new QDoubleSpinBox(routeTab);
        finishZ->setObjectName("finishZ");
        finishZ->setMinimum(-1000000.000000000000000);
        finishZ->setMaximum(1000000.000000000000000);
        finishZ->setValue(150.000000000000000);
        finishZ->setDecimals(3);
        finishZ->setKeyboardTracking(false);
        finishZ->setMinimumSize(QSize(70, 29));

        finishZCol->addWidget(finishZ);


        finishRow->addLayout(finishZCol);


        routeTabLayout->addLayout(finishRow);

        variantTabs->addTab(routeTab, QString());

        controlLayout->addWidget(variantTabs);

        presetButton = new QPushButton(controlPanel);
        presetButton->setObjectName("presetButton");

        controlLayout->addWidget(presetButton);

        zeroButton = new QPushButton(controlPanel);
        zeroButton->setObjectName("zeroButton");

        controlLayout->addWidget(zeroButton);

        inputNote = new QLabel(controlPanel);
        inputNote->setObjectName("inputNote");
        inputNote->setWordWrap(true);

        controlLayout->addWidget(inputNote);

        controlScroll->setWidget(controlPanel);

        bodyLayout->addWidget(controlScroll);

        sceneCard = new QFrame(centralwidget);
        sceneCard->setObjectName("sceneCard");
        sceneLayout = new QVBoxLayout(sceneCard);
        sceneLayout->setSpacing(5);
        sceneLayout->setObjectName("sceneLayout");
        viewToolbar = new QHBoxLayout();
        viewToolbar->setObjectName("viewToolbar");
        sceneTitle = new QLabel(sceneCard);
        sceneTitle->setObjectName("sceneTitle");

        viewToolbar->addWidget(sceneTitle);

        viewSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        viewToolbar->addItem(viewSpacer);

        projectionCombo = new QComboBox(sceneCard);
        projectionCombo->addItem(QString());
        projectionCombo->addItem(QString());
        projectionCombo->addItem(QString());
        projectionCombo->addItem(QString());
        projectionCombo->setObjectName("projectionCombo");

        viewToolbar->addWidget(projectionCombo);


        sceneLayout->addLayout(viewToolbar);

        vectorScene = new VectorScene(sceneCard);
        vectorScene->setObjectName("vectorScene");
        vectorScene->setMinimumSize(QSize(420, 200));

        sceneLayout->addWidget(vectorScene);

        angleLayout = new QHBoxLayout();
        angleLayout->setObjectName("angleLayout");
        yawCaption = new QLabel(sceneCard);
        yawCaption->setObjectName("yawCaption");

        angleLayout->addWidget(yawCaption);

        yawSlider = new QSlider(sceneCard);
        yawSlider->setObjectName("yawSlider");
        yawSlider->setOrientation(Qt::Horizontal);
        yawSlider->setMinimum(0);
        yawSlider->setMaximum(360);
        yawSlider->setValue(325);

        angleLayout->addWidget(yawSlider);

        yawValue = new QLabel(sceneCard);
        yawValue->setObjectName("yawValue");
        yawValue->setMinimumSize(QSize(38, 0));

        angleLayout->addWidget(yawValue);

        pitchCaption = new QLabel(sceneCard);
        pitchCaption->setObjectName("pitchCaption");

        angleLayout->addWidget(pitchCaption);

        pitchSlider = new QSlider(sceneCard);
        pitchSlider->setObjectName("pitchSlider");
        pitchSlider->setOrientation(Qt::Horizontal);
        pitchSlider->setMinimum(10);
        pitchSlider->setMaximum(80);
        pitchSlider->setValue(25);

        angleLayout->addWidget(pitchSlider);

        pitchValue = new QLabel(sceneCard);
        pitchValue->setObjectName("pitchValue");
        pitchValue->setMinimumSize(QSize(38, 0));

        angleLayout->addWidget(pitchValue);


        sceneLayout->addLayout(angleLayout);

        legendLabel = new QLabel(sceneCard);
        legendLabel->setObjectName("legendLabel");
        legendLabel->setWordWrap(true);

        sceneLayout->addWidget(legendLabel);


        bodyLayout->addWidget(sceneCard);

        bodyLayout->setStretch(1, 1);

        rootLayout->addLayout(bodyLayout);

        bottomLayout = new QHBoxLayout();
        bottomLayout->setObjectName("bottomLayout");
        tableCard = new QFrame(centralwidget);
        tableCard->setObjectName("tableCard");
        tableLayout = new QVBoxLayout(tableCard);
        tableLayout->setSpacing(4);
        tableLayout->setObjectName("tableLayout");
        tableTitle = new QLabel(tableCard);
        tableTitle->setObjectName("tableTitle");

        tableLayout->addWidget(tableTitle);

        resultTable = new QTableWidget(tableCard);
        resultTable->setObjectName("resultTable");
        resultTable->setMinimumSize(QSize(440, 120));
        resultTable->setMaximumSize(QSize(16777215, 140));
        resultTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        resultTable->setSelectionBehavior(QAbstractItemView::SelectRows);

        tableLayout->addWidget(resultTable);


        bottomLayout->addWidget(tableCard);

        formulaCard = new QFrame(centralwidget);
        formulaCard->setObjectName("formulaCard");
        formulaLayout = new QVBoxLayout(formulaCard);
        formulaLayout->setSpacing(5);
        formulaLayout->setObjectName("formulaLayout");
        formulaTitle = new QLabel(formulaCard);
        formulaTitle->setObjectName("formulaTitle");

        formulaLayout->addWidget(formulaTitle);

        formulaLabel = new QLabel(formulaCard);
        formulaLabel->setObjectName("formulaLabel");
        formulaLabel->setWordWrap(true);

        formulaLayout->addWidget(formulaLabel);


        bottomLayout->addWidget(formulaCard);

        bottomLayout->setStretch(0, 3);
        bottomLayout->setStretch(1, 2);

        rootLayout->addLayout(bottomLayout);

        feedbackLabel = new QLabel(centralwidget);
        feedbackLabel->setObjectName("feedbackLabel");

        rootLayout->addWidget(feedbackLabel);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "VectorLab \342\200\224 \320\237\321\200\320\260\320\272\321\202\320\270\320\272\320\260 2 \302\267 \320\227\320\260\320\264\320\260\320\275\320\270\320\265 1 \302\267 \320\222\320\260\321\200\320\270\320\260\320\275\321\202\321\213 1 \320\270 2", nullptr));
        MainWindow->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"QMainWindow, QWidget#centralwidget {background:#edf2f8;}\n"
"QWidget {font-family:\"Segoe UI\";font-size:9pt;color:#233652;}\n"
"QLabel#eyebrow {color:#5276aa;font-size:8pt;letter-spacing:1px;}\n"
"QLabel#title {font-size:25pt;font-weight:700;color:#142b4d;}\n"
"QLabel#subtitle, QLabel#inputNote, QLabel#feedbackLabel {color:#74849c;font-size:8pt;}\n"
"QFrame#mainCard, QFrame#extraCard, QFrame#statusCard, QFrame#controlPanel,\n"
"QFrame#sceneCard, QFrame#tableCard, QFrame#formulaCard {background:white;border:1px solid #dce5f1;border-radius:10px;}\n"
"QLabel#mainCaption, QLabel#extraCaption, QLabel#statusCaption {color:#74849c;font-size:8pt;}\n"
"QLabel#mainValue, QLabel#extraValue, QLabel#statusValue {font-size:21pt;font-weight:600;color:#1664b8;}\n"
"QLabel#mainHint, QLabel#extraHint, QLabel#statusHint {font-size:8pt;color:#74849c;}\n"
"QLabel#sceneTitle, QLabel#tableTitle, QLabel#formulaTitle {font-size:11pt;font-weight:600;}\n"
"QLabel#airTitle, QLabel#windTitle, QLabel#startTitle, QLabel#finishTitle {f"
                        "ont-weight:600;}\n"
"QLabel#legendLabel, QLabel#velocityNote, QLabel#routeNote {font-size:8pt;color:#5c6f89;}\n"
"QPushButton {background:#f7faff;border:1px solid #cbd9eb;border-radius:6px;padding:7px 12px;}\n"
"QPushButton:hover {background:#e9f1fc;border-color:#8badd6;}\n"
"QPushButton#presetButton {background:#246ac4;color:white;border-color:#246ac4;}\n"
"QDoubleSpinBox, QComboBox {background:white;border:1px solid #cad8eb;border-radius:4px;padding:4px 3px;}\n"
"QDoubleSpinBox:focus, QComboBox:focus {border-color:#246ac4;}\n"
"QTabWidget::pane {border:0;background:white;}\n"
"QTabBar::tab {background:#edf2f8;color:#687d98;border-radius:5px;padding:8px 10px;margin:2px;}\n"
"QTabBar::tab:selected {background:#dceafa;color:#155eac;font-weight:600;}\n"
"QTableWidget {border:0;background:white;gridline-color:#edf2f8;alternate-background-color:#f6f9fd;selection-background-color:#e3eefb;selection-color:#142b4d;}\n"
"QHeaderView::section {background:#f1f5fb;color:#69809f;border:0;padding:5px;}\n"
"QSlider::groove:h"
                        "orizontal {height:4px;background:#e3eaf4;border-radius:2px;}\n"
"QSlider::handle:horizontal {background:#3577c8;width:12px;margin:-4px 0;border-radius:6px;}\n"
"", nullptr));
        eyebrow->setText(QCoreApplication::translate("MainWindow", "\320\237\320\240\320\220\320\232\320\242\320\230\320\232\320\220 02   /   \320\227\320\220\320\224\320\220\320\235\320\230\320\225 1   /   \320\222\320\220\320\240\320\230\320\220\320\235\320\242\320\253 1 + 2", nullptr));
        title->setText(QCoreApplication::translate("MainWindow", "\320\233\320\260\320\261\320\276\321\200\320\260\321\202\320\276\321\200\320\270\321\217 \320\262\320\265\320\272\321\202\320\276\321\200\320\276\320\262", nullptr));
        subtitle->setText(QCoreApplication::translate("MainWindow", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \320\221\320\237\320\233\320\220 \320\270 \320\277\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\320\265 \320\277\320\276 \320\274\320\260\321\200\321\210\321\200\321\203\321\202\321\203 \302\267 \320\265\320\264\320\270\320\275\320\260\321\217 \320\274\320\276\320\264\320\265\320\273\321\214 Vector3D", nullptr));
        copyButton->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\277\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\200\320\260\321\201\321\207\321\221\321\202", nullptr));
        mainCaption->setText(QCoreApplication::translate("MainWindow", "\320\234\320\236\320\224\320\243\320\233\320\254 \320\241\320\232\320\236\320\240\320\236\320\241\320\242\320\230", nullptr));
        mainValue->setText(QCoreApplication::translate("MainWindow", "\342\200\224", nullptr));
        mainHint->setText(QString());
        extraCaption->setText(QCoreApplication::translate("MainWindow", "\320\243\320\237\320\240\320\220\320\222\320\233\320\257\320\256\320\251\320\230\320\231 \320\222\320\225\320\232\320\242\320\236\320\240", nullptr));
        extraValue->setText(QCoreApplication::translate("MainWindow", "\342\200\224", nullptr));
        extraHint->setText(QString());
        statusCaption->setText(QCoreApplication::translate("MainWindow", "\320\237\320\240\320\236\320\222\320\225\320\240\320\232\320\220 \320\222\320\253\320\247\320\230\320\241\320\233\320\225\320\235\320\230\320\231", nullptr));
        statusValue->setText(QCoreApplication::translate("MainWindow", "\342\200\224", nullptr));
        statusHint->setText(QString());
        airTitle->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\320\267\320\264\321\203\321\210\320\275\320\260\321\217 \321\201\320\272\320\276\321\200\320\276\321\201\321\202\321\214, \320\274/\321\201", nullptr));
        airX->setPrefix(QCoreApplication::translate("MainWindow", "X: ", nullptr));
        airY->setPrefix(QCoreApplication::translate("MainWindow", "Y: ", nullptr));
        airZ->setPrefix(QCoreApplication::translate("MainWindow", "Z: ", nullptr));
        windTitle->setText(QCoreApplication::translate("MainWindow", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \320\262\320\265\321\202\321\200\320\260, \320\274/\321\201", nullptr));
        windX->setPrefix(QCoreApplication::translate("MainWindow", "X: ", nullptr));
        windY->setPrefix(QCoreApplication::translate("MainWindow", "Y: ", nullptr));
        windZ->setPrefix(QCoreApplication::translate("MainWindow", "Z: ", nullptr));
        factorCaption->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 k", nullptr));
        variantTabs->setTabText(variantTabs->indexOf(velocityTab), QCoreApplication::translate("MainWindow", "01 \302\267 \320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214", nullptr));
        startTitle->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\320\260\321\217 \321\202\320\276\321\207\320\272\320\260 S, \320\274", nullptr));
        startX->setPrefix(QCoreApplication::translate("MainWindow", "X: ", nullptr));
        startY->setPrefix(QCoreApplication::translate("MainWindow", "Y: ", nullptr));
        startZ->setPrefix(QCoreApplication::translate("MainWindow", "Z: ", nullptr));
        finishTitle->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\275\320\265\321\207\320\275\320\260\321\217 \321\202\320\276\321\207\320\272\320\260 F, \320\274", nullptr));
        finishX->setPrefix(QCoreApplication::translate("MainWindow", "X: ", nullptr));
        finishY->setPrefix(QCoreApplication::translate("MainWindow", "Y: ", nullptr));
        finishZ->setPrefix(QCoreApplication::translate("MainWindow", "Z: ", nullptr));
        variantTabs->setTabText(variantTabs->indexOf(routeTab), QCoreApplication::translate("MainWindow", "02 \302\267 \320\234\320\260\321\200\321\210\321\200\321\203\321\202", nullptr));
        presetButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\320\275\320\275\321\213\320\265 \320\270\320\267 \320\267\320\260\320\264\320\260\320\275\320\270\321\217", nullptr));
        zeroButton->setText(QCoreApplication::translate("MainWindow", "\320\235\321\203\320\273\320\265\320\262\320\276\320\271 \320\277\321\200\320\270\320\274\320\265\321\200", nullptr));
        inputNote->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\207\321\221\321\202 \320\276\320\261\320\275\320\276\320\262\320\273\321\217\320\265\321\202\321\201\321\217 \320\277\321\200\320\270 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\270 \320\264\320\260\320\275\320\275\321\213\321\205. \320\236\321\202\321\200\320\270\321\206\320\260\321\202\320\265\320\273\321\214\320\275\321\213\320\265 \320\272\320\276\320\274\320\277\320\276\320\275\320\265\320\275\321\202\321\213 \320\264\320\276\320\277\321\203\321\201\321\202\320\270\320\274\321\213.", nullptr));
        sceneTitle->setText(QCoreApplication::translate("MainWindow", "\320\223\320\265\320\276\320\274\320\265\321\202\321\200\320\270\321\217 \320\262\320\265\320\272\321\202\320\276\321\200\320\276\320\262", nullptr));
        projectionCombo->setItemText(0, QCoreApplication::translate("MainWindow", "3D \302\267 \320\260\320\272\321\201\320\276\320\275\320\276\320\274\320\265\321\202\321\200\320\270\321\217", nullptr));
        projectionCombo->setItemText(1, QCoreApplication::translate("MainWindow", "\320\237\320\273\320\276\321\201\320\272\320\276\321\201\321\202\321\214 XY", nullptr));
        projectionCombo->setItemText(2, QCoreApplication::translate("MainWindow", "\320\237\320\273\320\276\321\201\320\272\320\276\321\201\321\202\321\214 XZ", nullptr));
        projectionCombo->setItemText(3, QCoreApplication::translate("MainWindow", "\320\237\320\273\320\276\321\201\320\272\320\276\321\201\321\202\321\214 YZ", nullptr));

        yawCaption->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", nullptr));
        yawValue->setText(QCoreApplication::translate("MainWindow", "325\302\260", nullptr));
        pitchCaption->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\272\320\273\320\276\320\275", nullptr));
        pitchValue->setText(QCoreApplication::translate("MainWindow", "25\302\260", nullptr));
        legendLabel->setText(QCoreApplication::translate("MainWindow", "\320\241\320\270\320\275\320\270\320\271 \342\200\224 \320\221\320\237\320\233\320\220   \302\267   \320\276\321\200\320\260\320\275\320\266\320\265\320\262\321\213\320\271 \342\200\224 \320\262\320\265\321\202\320\265\321\200   \302\267   \320\261\320\270\321\200\321\216\320\267\320\276\320\262\321\213\320\271 \342\200\224 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202   \302\267   \321\204\320\270\320\276\320\273\320\265\321\202\320\276\320\262\321\213\320\271 \342\200\224 \321\203\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        tableTitle->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 \320\270 \320\274\320\276\320\264\321\203\320\273\320\270", nullptr));
        formulaTitle->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\272 \320\277\320\276\320\273\321\203\321\207\320\260\320\265\321\202\321\201\321\217 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        formulaLabel->setText(QString());
        feedbackLabel->setText(QCoreApplication::translate("MainWindow", "\320\243\321\207\320\265\320\261\320\275\320\260\321\217 \320\274\320\260\321\202\320\265\320\274\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\260\321\217 \320\274\320\276\320\264\320\265\320\273\321\214 \302\267 \320\264\320\260\320\275\320\275\321\213\320\265 \320\267\320\260\320\264\320\260\321\216\321\202\321\201\321\217 \320\262\321\200\321\203\321\207\320\275\321\203\321\216 \302\267 \320\274\320\260\321\201\321\210\321\202\320\260\320\261 \321\201\321\205\320\265\320\274\321\213 \320\277\320\276\320\264\320\261\320\270\321\200\320\260\320\265\321\202\321\201\321\217 \320\260\320\262\321\202\320\276\320\274\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
