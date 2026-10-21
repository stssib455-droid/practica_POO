#include "mainwindow.h"
#include <QApplication>
#include <QLocale>
#include <QStyle>
#include <QTimer>
#include <QPushButton>
int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QApplication::setStyle("Fusion"); app.setPalette(app.style()->standardPalette());
    QLocale::setDefault(QLocale(QLocale::Russian, QLocale::Russia));
    MainWindow window; window.show();
    const auto args = app.arguments();
    if (args.contains("--demo-flight")) {
        window.findChild<QPushButton*>("takeoffButton")->click();
        window.findChild<QPushButton*>("moveButton")->click();
    }
    const int index = args.indexOf("--screenshot");
    if (index >= 0 && index + 1 < args.size()) QTimer::singleShot(300, &window, [&] {
        app.exit(window.grab().save(args[index + 1]) ? 0 : 1);
    });
    return app.exec();
}
