#include "clientnotifymonitor.h"
#include <QDateTime>
#include <string>
#include <QDebug>

ClientNotifyMonitor::ClientNotifyMonitor(QObject* parent)
    : QObject(parent){
    mReceiver=new DatagramReceiver(9054, this);
    connect(mReceiver, SIGNAL(datagramReseived(QString, QString)),
            this, SLOT(parseDatagram(QString, QString)));
}

void ClientNotifyMonitor::parseDatagram(QString address, QString data) const{
    qDebug()<<L"From "<<address<<" : "<<data;
    ClientData newClientData;
    newClientData.setIpv4(address);
    newClientData.setPcName(data);
    newClientData.setLastOnlineTime(QDateTime::currentDateTime());
    newClientData.setOnlineStatus(true);
    emit receivedNewData(newClientData);
}

ClientNotifyMonitor::~ClientNotifyMonitor(){

}
