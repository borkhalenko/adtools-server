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

bool ClientData::onlineStatus() const{
    return onlineStatus_;
}

void ClientData::setOnlineStatus(bool status){
    onlineStatus_=status;
}

QString ClientData::toString() const{
    QString tmpString;
    tmpString+="Client name: "+pcName()+
            "\nIP: "+ipv4()+
            "\nGroup name: "+groupName()+
            "\nLastOnlineTime: "+lastOnlineTime().toString()+
            "\nOnlineStatus: "+QString::number(onlineStatus());
    return tmpString;
}

bool operator==(const ClientData& left, const ClientData& right){
    if ( left.pcName() == right.pcName() &&
         left.ipv4() == right.ipv4() &&
         left.groupName() == right.groupName() &&
         left.lastOnlineTime() == right.lastOnlineTime() &&
         left.onlineStatus() == right.onlineStatus())
        return true;
    else
        return false;
}


bool operator!=(const ClientData& left, const ClientData& right){
    return !(left==right);
}
