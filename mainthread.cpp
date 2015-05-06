#include "mainthread.h"
#include "QDebug"

MainThread::MainThread(QObject *parent) :
    QObject(parent),
    dataSaver_(new FileStorage()),
    mainWindow_(new MainWindow()),
    clientMonitor_(new ClientNotifyMonitor()),
    secondsToGetOfflineStatus_(60){
    connectAllSignalsAndSlots();
    mainWindow_->show();
    loadDataFromTheStorage();
}

MainThread::~MainThread(){
    saveDataToTheStorage();
}

void MainThread::processReceivedData(ClientData receivedData){
    QString clientName=receivedData.pcName();
    const ClientData& objectToChange=clientDataStorage_.value(clientName);
    if (objectToChange.pcName()==""){               // received new data from new client
        emit addNewClient(receivedData);
    }
    else{                                           // received new data from existing client
        emit changeClient(receivedData);
    }
    clientDataStorage_[clientName]=receivedData;
}

void MainThread::loadDataFromTheStorage(){
    QList<ClientData> tmpDataStorage=dataSaver_->loadData();
    foreach(const ClientData& element, tmpDataStorage){
        clientDataStorage_[element.pcName()]=element;
        emit addNewClient(element);
    }
}

void MainThread::saveDataToTheStorage(){
    dataSaver_->saveData(clientDataStorage_.values());
}

void MainThread::connectAllSignalsAndSlots(){
    connect(clientMonitor_.get(), SIGNAL(receivedNewData(ClientData)),
            this, SLOT(processReceivedData(ClientData)));
    connect(this, SIGNAL(addNewClient(ClientData)),
            mainWindow_.get(), SLOT(addNewClient(ClientData)));
    connect(this, SIGNAL(changeClient(ClientData)),
            mainWindow_.get(), SLOT(changeClient(ClientData)));
}
