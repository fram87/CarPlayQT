#include "mainwindow.h"
#include "bluetooth.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Bluetooth bt;
    bt.startScan();
    return a.exec();
    //test
}
