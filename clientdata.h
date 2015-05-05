#ifndef CLIENTDATA_H
#define CLIENTDATA_H

#include <QString>

class ClientData{
public:
    ClientData();
    QString pcName() const;
    void setPcName(const QString &pcName);

    QString ipv4() const;
    void setIpv4(const QString &ipv4);

    QString groupName() const;
    void setGroupName(const QString &groupName);

    QDateTime lastOnlineTime() const;
    void setLastOnlineTime(const QDateTime &lastOnlineTime);

private:
    QString pcName_;
    QString ipv4_;
    QString groupName_;
    QDateTime lastOnlineTime_;

};

#endif // CLIENTDATA_H
