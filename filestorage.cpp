#include "filestorage.h"
#include <QFile>
#include <QIODevice>
#include <QMessageBox>
#include <QDataStream>


FileStorage::FileStorage(): dataFileName_("DataFile.dat"){

}

QList<ClientData> FileStorage::loadData() const{
    //Bad code. Need return smart pointer or use input reference.
    QList<ClientData> dataCollection;
    QFile dataFile(dataFileName_);
    if (!dataFile.open(QIODevice::ReadOnly)){
        QMessageBox::warning(0, "REad file error!", "Error reading client data from the file. Do you have correct permissions?"
                             "Please, remember this message and contact to the support");
        return QList<ClientData>();
    }
    QDataStream in(&dataFile);
    in>>dataCollection;
    dataFile.close();
    return dataCollection;
}

void FileStorage::saveData(const QList<ClientData>& dataCollection) const{
    QFile dataFile(dataFileName_);
    if (!dataFile.open(QIODevice::WriteOnly)){
        QMessageBox::warning(0, "Write file error!", "Error writing client data to the file. Do you have correct permissions?"
                             "Please, remember this message and contact to the support");
        return;
    }
    QDataStream out(&dataFile);
    out<<dataCollection;
    dataFile.close();
}


QDataStream &operator<<(QDataStream& stream,const ClientData& data){
    stream<<data.pcName();
    stream<<data.ipv4();
    stream<<data.groupName();
    stream<<data.lastOnlineTime().toString();
    stream<<data.onlineStatus();
    return stream;
}


QDataStream &operator>>(QDataStream& stream, ClientData& data){
    QString buffer;
    stream>>buffer;
    data.setPcName(buffer);
    stream>>buffer;
    data.setIpv4(buffer);
    stream>>buffer;
    data.setGroupName(buffer);
    stream>>buffer;
    data.setLastOnlineTime(QDateTime::fromString(buffer));
    bool otherBuffer;
    stream>>otherBuffer;
    data.setOnlineStatus(otherBuffer);
    return stream;
}
