#ifndef IDATASAVER_H
#define IDATASAVER_H

#include <QVector>
#include "clientdata.h"

class IDataSaver{
public:
    IDataSaver(){}
    virtual QList<ClientData> loadData() const =0;
    virtual void saveData(const QList<ClientData>&) const =0;
    virtual ~IDataSaver(){}
};


#endif // IDATASAVER_H
