#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vector3d.h"
#include <QClipboard>
#include <QApplication>
#include <QHeaderView>
#include <QSignalBlocker>
#include <QLocale>
#include <array>
#include <cmath>
namespace {
QString number(double value){
    QLocale locale(QLocale::Russian,QLocale::Russia);
    locale.setNumberOptions(QLocale::OmitGroupSeparator);
    if(std::abs(value)<.0000001)value=0;
    return locale.toString(value,'f',3);
}
QString vectorText(const Vector3D& v){
    return QString("(%1; %2; %3)").arg(number(v.get_x()),number(v.get_y()),number(v.get_z()));
}
}
MainWindow::MainWindow(QWidget* parent):QMainWindow(parent),ui(new Ui::MainWindow){
    ui->setupUi(this);
    setMinimumSize(1040,720);
    ui->rootLayout->setStretch(2,1);
    ui->formulaLayout->setAlignment(Qt::AlignTop);
    ui->formulaLabel->setAlignment(Qt::AlignTop|Qt::AlignLeft);
    ui->controlLayout->setContentsMargins(8,8,8,8);
    ui->controlLayout->setSpacing(6);
    for(auto* layout:{ui->velocityTabLayout,ui->routeTabLayout}){
        layout->setContentsMargins(6,4,6,4);layout->setSpacing(6);
    }
    ui->resultTable->setColumnCount(5);
    ui->resultTable->verticalHeader()->hide();
    ui->resultTable->verticalHeader()->setDefaultSectionSize(25);
    ui->resultTable->setAlternatingRowColors(true);
    ui->resultTable->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
    for(int column=1;column<5;++column){
        ui->resultTable->horizontalHeader()->setSectionResizeMode(column,QHeaderView::ResizeToContents);
    }
    for(auto* spin:findChildren<QDoubleSpinBox*>())
        connect(spin,qOverload<double>(&QDoubleSpinBox::valueChanged),this,[this]{refresh();});
    connect(ui->variantTabs,&QTabWidget::currentChanged,this,[this]{refresh();});
    connect(ui->presetButton,&QPushButton::clicked,this,[this]{preset(false);});
    connect(ui->zeroButton,&QPushButton::clicked,this,[this]{preset(true);});
    connect(ui->projectionCombo,qOverload<int>(&QComboBox::currentIndexChanged),this,[this]{refresh();});
    connect(ui->yawSlider,&QSlider::valueChanged,this,[this]{refresh();});
    connect(ui->pitchSlider,&QSlider::valueChanged,this,[this]{refresh();});
    connect(ui->copyButton,&QPushButton::clicked,this,[this]{
        QApplication::clipboard()->setText(report);
        ui->feedbackLabel->setText(QApplication::clipboard()->text()==report?
            "Расчёт скопирован. Его можно вставить в отчёт или текстовый файл.":
            "Буфер обмена Windows недоступен. Повторите копирование после запуска в обычном сеансе Windows.");
    });
    refresh();
}
MainWindow::~MainWindow()=default;
void MainWindow::preset(bool zero){
    std::array<QDoubleSpinBox*,7> velocity{ui->airX,ui->airY,ui->airZ,ui->windX,ui->windY,ui->windZ,ui->factor};
    const std::array<double,7> velocityValues{10,4,-1,2,-1,0,.8};
    std::array<QDoubleSpinBox*,6> route{ui->startX,ui->startY,ui->startZ,ui->finishX,ui->finishY,ui->finishZ};
    const std::array<double,6> routeValues{0,0,100,300,200,150};
    if(ui->variantTabs->currentIndex()==0){
        for(size_t i=0;i<velocity.size();++i){
            const QSignalBlocker blocker(velocity[i]);
            velocity[i]->setValue(zero?(i==6?.8:0):velocityValues[i]);
        }
    } else {
        for(size_t i=0;i<route.size();++i){
            const QSignalBlocker blocker(route[i]);route[i]->setValue(zero?0:routeValues[i]);
        }
    }
    refresh();
}
void MainWindow::refresh(){
    const bool route=ui->variantTabs->currentIndex()==1;
    const Vector3D first=route?Vector3D(ui->startX->value(),ui->startY->value(),ui->startZ->value()):
        Vector3D(ui->airX->value(),ui->airY->value(),ui->airZ->value());
    const Vector3D second=route?Vector3D(ui->finishX->value(),ui->finishY->value(),ui->finishZ->value()):
        Vector3D(ui->windX->value(),ui->windY->value(),ui->windZ->value());
    const Vector3D result=route?second-first:first+second;
    const Vector3D fourth=route?first+result:result*ui->factor->value();
    const bool verified=route?(fourth==second):((result-second)==first);
    const QString unit=route?"м":"м/с";
    const QStringList names=route?QStringList{"Начало S","Конец F","Перемещение D","Проверка S + D"}:
        QStringList{"БПЛА Vбпла","Ветер Vветра","Земная Vзем","Управление C"};
    const std::array<Vector3D,4> values{first,second,result,fourth};
    const std::array<QColor,4> colors{QColor("#246ac4"),QColor("#d68421"),QColor("#008d89"),QColor("#8561c5")};
    ui->resultTable->setHorizontalHeaderLabels({"Вектор / точка", "X, "+unit,"Y, "+unit,"Z, "+unit,"Модуль, "+unit});
    ui->resultTable->setRowCount(4);
    report=QString("Практика 2. Задание 1. Вариант %1\n%2\n\n").arg(route?2:1).arg(route?"Перемещение по маршруту":"Скорость БПЛА");
    for(int row=0;row<4;++row){
        const auto& v=values[row];
        const QStringList texts{names[row],number(v.get_x()),number(v.get_y()),number(v.get_z()),number(v.length())};
        for(int col=0;col<5;++col){
            auto* item=new QTableWidgetItem(texts[col]);
            if(col==0)item->setForeground(colors[row]);
            else item->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
            item->setToolTip(texts[col]);ui->resultTable->setItem(row,col,item);
        }
        report+=names[row]+": "+vectorText(v)+" "+unit+"; модуль = "+number(v.length())+" "+unit+'\n';
    }
    ui->mainCaption->setText(route?"ДЛИНА ПЕРЕМЕЩЕНИЯ":"МОДУЛЬ ЗЕМНОЙ СКОРОСТИ");
    ui->mainValue->setText(number(result.length())+" "+unit);
    ui->mainHint->setText(route?"Прямая между S и F в пространстве":"Длина вектора Vбпла + Vветра");
    ui->extraCaption->setText(route?"ИЗМЕНЕНИЕ ВЫСОТЫ":"МОДУЛЬ УПРАВЛЯЮЩЕГО ВЕКТОРА");
    ui->extraValue->setText(number(route?result.get_z():fourth.length())+" "+unit);
    ui->extraHint->setText(route?"ΔZ = Zкон − Zнач":"C = Vзем × "+number(ui->factor->value()));
    ui->statusValue->setText(verified?"Совпадает":"Не совпадает");
    ui->statusValue->setStyleSheet(verified?"color:#008d89;":"color:#bd4747;");
    ui->statusHint->setText(route?"S + D == F · точность 10⁻⁶":"Vзем − Vветра == Vбпла · точность 10⁻⁶");
    ui->legendLabel->setText(route?
        "Синий — начало S · оранжевый — конец F · бирюзовый — перемещение D. Пунктир — проекции на XY.":
        "Синий — БПЛА · оранжевый — ветер · бирюзовый — сумма · фиолетовый — управление. Пунктир — перенос ветра.");
    QString formula;
    if(route){
        formula=QString("<b>D = F − S = %1 м</b><br>ΔX = %2 м; ΔY = %3 м; ΔZ = %4 м.<br>"
            "|D| = √(ΔX² + ΔY² + ΔZ²) = <b>%5 м</b>.<br>"
            "<b>S + D = %6 м</b><br>Сравнение с F: %7. Это прямое перемещение, а не длина сложного маршрута.")
            .arg(vectorText(result),number(result.get_x()),number(result.get_y()),number(result.get_z()),
                number(result.length()),vectorText(fourth),verified?"true":"false");
    }else{
        formula=QString("<b>Vзем = Vбпла + Vветра = %1 м/с</b><br>"
            "|Vзем| = √(X² + Y² + Z²) = <b>%2 м/с</b>.<br>"
            "<b>C = Vзем × %3 = %4 м/с</b><br>"
            "По условию C интерпретируется как воздействие автопилота. k — безразмерный коэффициент.")
            .arg(vectorText(result),number(result.length()),number(ui->factor->value()),vectorText(fourth));
        report+="Коэффициент k = "+number(ui->factor->value())+'\n';
    }
    ui->formulaLabel->setText(formula);
    report+=route?"D = F - S; S + D == F: ":"Vзем = Vбпла + Vветра; Vзем - Vветра == Vбпла: ";
    report+=verified?"true\n":"false\n";
    report+="Сравнение покомпонентное: |a - b| < 0.000001.\n";
    ui->vectorScene->setVectors(route?1:0,first,second,ui->factor->value());
    ui->vectorScene->setView(ui->projectionCombo->currentIndex(),ui->yawSlider->value(),ui->pitchSlider->value());
    const bool space=ui->projectionCombo->currentIndex()==0;
    ui->yawSlider->setEnabled(space);ui->pitchSlider->setEnabled(space);
    ui->yawValue->setText(QString::number(ui->yawSlider->value())+"°");
    ui->pitchValue->setText(QString::number(ui->pitchSlider->value())+"°");
    ui->feedbackLabel->setText("Учебная математическая модель · ввод до 3 знаков после запятой · масштаб схемы подбирается автоматически");
}
