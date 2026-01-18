#include "bluetooth.h"
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothDeviceInfo>

Bluetooth::Bluetooth(QObject *parent) : QObject(parent)
{
    discoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);

    // Connecter le signal qui signale qu’un appareil a été trouvé
    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
            this, &Bluetooth::deviceFound);

    // Connecter le signal qui signale la fin du scan
    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::finished,
            this, &Bluetooth::scanFinished);
}

void Bluetooth::startScan()
{
    discoveryAgent->start();  // commence le scan
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


