#ifndef CLIENTNOTIFYMONITOR_H
#define CLIENTNOTIFYMONITOR_H
#include <QThread>
#include <QString>
#include "clientdata.h"
#include "datagramreceiver.h"

class ClientNotifyMonitor: public QObject{
    Q_OBJECT
public:
    ClientNotifyMonitor(QObject* parent=0);
    ~ClientNotifyMonitor();
signals:
    void receivedNewData(ClientData) const;
public slots:
    void parseDatagram(QString addr, QString data) const;
private:
    DatagramReceiver* mReceiver;
};

#endif // CLIENTNOTIFYMONITOR_H
