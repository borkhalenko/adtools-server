#ifndef IDATASAVER_H
#define IDATASAVER_H

#include <QVector>
#include "clientdata.h"

class IDataSaver{
public:
    IDataSaver(){}
    virtual QVector<ClientData> loadData()=0;
    virtual void saveData(const QVector<ClientData>&)=0;
    virtual ~IDataSaver(){}
};


#endif // IDATASAVER_H
