#ifndef CLIENTDATA_H
#define CLIENTDATA_H

#include <QString>
#include <QDateTime>

class ClientData{
public:
    ClientData();
    QString     pcName() const;
    void        setPcName(const QString &pcName);

    QString     ipv4() const;
    void        setIpv4(const QString &ipv4);

    QString     groupName() const;
    void        setGroupName(const QString &groupName);

    QDateTime   lastOnlineTime() const;
    void        setLastOnlineTime(const QDateTime &lastOnlineTime);

    bool        OnlineStatus_()  const;
    void        setOnlineStatus(bool);

private:
    QString     pcName_;
    QString     ipv4_;
    QString     groupName_;
    QDateTime   lastOnlineTime_;
    bool        onlineStatus_;
};

#endif // CLIENTDATA_H
