#ifndef CLIENTSTORAGE_H
#define CLIENTSTORAGE_H

#include <QObject>
#include <QList>

class ClientStorage : public QObject{
    Q_OBJECT
public:
    explicit ClientStorage(QObject *parent = 0);

signals:

public slots:
private:
    QList<
};

#endif // CLIENTSTORAGE_H
