#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setTitle("Abhay");
    w.resize(600,500);
    w.show();
    return a.exec();
}
