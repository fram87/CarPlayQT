#include "mainwindow.h"
#include "bluetooth.h"
#include <QApplication>
#include <QLoggingCategory>
#include <QBluetoothLocalDevice>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QBluetoothLocalDevice localDevice;
    qDebug() << "Bluetooth isValid =" << localDevice.isValid();
    qDebug() << "Bluetooth hostMode =" << localDevice.hostMode();
    MainWindow w;
    w.show();
    Bluetooth bt;
    bt.startScan();
    return a.exec();
    //test
}
