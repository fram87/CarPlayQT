#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <QObject>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothDeviceInfo>

class Bluetooth : public QObject
{
    Q_OBJECT

public:
    explicit Bluetooth(QObject *parent = nullptr);

public slots:
    void startScan();

private slots:
    void deviceFound(const QBluetoothDeviceInfo &info);
    void scanFinished();

private:
    QBluetoothDeviceDiscoveryAgent *discoveryAgent;
};

#endif

