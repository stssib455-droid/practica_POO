#include "mainwindow.h"
#include <QApplication>
#include <QTimer>
#include <QTabWidget>
#include <QLocale>
#include <QPalette>
#include <QPixmap>
int main(int argc,char* argv[]){
    QApplication app(argc,argv);
    QApplication::setStyle("Fusion");
    QPalette palette;palette.setColor(QPalette::Window,Qt::white);
    palette.setColor(QPalette::WindowText,QColor("#233652"));
    palette.setColor(QPalette::Base,Qt::white);palette.setColor(QPalette::Text,QColor("#233652"));
    palette.setColor(QPalette::Button,Qt::white);palette.setColor(QPalette::ButtonText,QColor("#233652"));
    app.setPalette(palette);
    QLocale::setDefault(QLocale(QLocale::Russian,QLocale::Russia));
    MainWindow window;
    auto args=app.arguments();
    if(args.contains("--variant-2"))window.findChild<QTabWidget*>("variantTabs")->setCurrentIndex(1);
    window.show();
    const int i=args.indexOf("--screenshot");
    if(i>=0 && i+1<args.size())QTimer::singleShot(350,&window,[&]{
        const bool saved=window.grab().save(args[i+1]);app.exit(saved?0:2);
    });
    return app.exec();
}
