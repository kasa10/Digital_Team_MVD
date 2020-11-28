#include "mainwindow.h"

#include <QApplication>
#include <QSplashScreen>
#include <QThread>
#include <QTimer>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    QApplication a(argc, argv);

    QPixmap pixmap(":/splash.jpg");
    QSplashScreen splash(pixmap.scaledToWidth(800));
    splash.show();
    QTimer::singleShot(5000, &splash, &QWidget::close); // keep displayed for 5 seconds
    a.processEvents();
    MainWindow w;
    w.show();
    splash.finish(&w);
    return a.exec();
}
