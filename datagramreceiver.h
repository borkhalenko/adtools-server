#ifndef DATAGRAMRECEIVER_H
#define DATAGRAMRECEIVER_H
#include <QUdpSocket>
#include <QString>

class DatagramReceiver: public QObject{
    Q_OBJECT
public:
    DatagramReceiver(int port, QObject *parent=0);
    ~DatagramReceiver();
public slots:
    void readPendingDatagrams() const;
signals:
    void datagramReseived(QString addr, QString data) const;
private:
    QUdpSocket* mUdpSocket;
    qint16 mLocalPort;
};

#endif // DATAGRAMRECEIVER_H
