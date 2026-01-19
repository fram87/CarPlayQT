#include "bluetooth.h"
#include <QDebug>

Bluetooth::Bluetooth(QObject *parent) : QObject(parent)
{
    discoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);

    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
            this, &Bluetooth::deviceFound);

    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::finished,
            this, &Bluetooth::scanFinished);

    qDebug() << "Bluetooth initialized";
}

void Bluetooth::startScan()
{
    qDebug() << "Starting Bluetooth scan...";
    discoveryAgent->start();
}

void Bluetooth::deviceFound(const QBluetoothDeviceInfo &info)
{
    qDebug() << "Appareil trouvé :" << info.name()
             << "Adresse :" << info.address().toString();
}

void Bluetooth::scanFinished()
{
    qDebug() << "Scan terminé !";
}


