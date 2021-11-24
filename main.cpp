#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setTitle("The Game");
    w.resize(SCREEN_WIDTH, SCREEN_HEIGHT);
    w.show();
    return a.exec();
}
