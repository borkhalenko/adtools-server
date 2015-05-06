#ifndef FILESTORAGE_H
#define FILESTORAGE_H

#include <QList>
#include "idatasaver.h"

class FileStorage : public IDataSaver{
public:
    FileStorage();
    QList<ClientData> loadData() const;
    void saveData(const QList<ClientData>&) const;
private:
    const QString dataFileName_;
};

QDataStream& operator<<(QDataStream &, const ClientData&);
QDataStream& operator>>(QDataStream&, ClientData&);

#endif // FILESTORAGE_H
