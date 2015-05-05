#ifndef FILESTORAGE_H
#define FILESTORAGE_H

#include "idatasaver.h"

class FileStorage : public IDataSaver{
public:
    FileStorage();
    QVector<ClientData> loadData();
    void saveData(const QVector<ClientData>&);
};

#endif // FILESTORAGE_H
