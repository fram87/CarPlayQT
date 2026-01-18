#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <QObject>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothDeviceInfo>

class Bluetooth : public QObject
{
    Q_OBJECT

public:
    Bluetooth(QObject *parent = nullptr);
    void startScan();  // fonction pour lancer le scan

private slots:
    void deviceFound(const QBluetoothDeviceInfo &info);  // appelé quand un appareil est trouvé
    void scanFinished();  // appelé quand le scan est terminé

private:
    QBluetoothDeviceDiscoveryAgent *discoveryAgent;  // le scanner
};
#endif // BLUETOOTH_H
