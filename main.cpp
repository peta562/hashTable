#include "mainwindow.h"
#include "associativearr.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    setlocale(LC_ALL," ");


    return a.exec();
}
