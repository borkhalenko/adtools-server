#include "clientdata.h"

ClientData::ClientData(){
}

QString ClientData::pcName() const{
    return pcName_;
}

void ClientData::setPcName(const QString &pcName){
    pcName_ = pcName;
}

QString ClientData::ipv4() const{
    return ipv4_;
}

void ClientData::setIpv4(const QString &ipv4){
    ipv4_ = ipv4;
}

QString ClientData::groupName() const{
    return groupName_;
}

void ClientData::setGroupName(const QString &groupName){
    groupName_ = groupName;
}

QDateTime ClientData::lastOnlineTime() const{
    return lastOnlineTime_;
}

void ClientData::setLastOnlineTime(const QDateTime &lastOnlineTime){
    lastOnlineTime_ = lastOnlineTime;
}

bool ClientData::OnlineStatus_() const{
    return onlineStatus_;
}

void ClientData::setOnlineStatus(bool status){
    onlineStatus_=status;
}






