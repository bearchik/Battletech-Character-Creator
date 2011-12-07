#include <QApplication>
#include <QtGui>
#include "mainwindow.h"



int main(int argc, char* argv[])
{
    QApplication app (argc, argv);

    MainWindow mw;

    mw.MainInit();

    mw.show();

    return app.exec();
}
