#include "mainthread.h"
#include "QDebug"

MainThread::MainThread(QObject *parent) :
    QObject(parent),
    dataSaver_(new FileStorage()),
    mainWindow_(new MainWindow()),
    clientMonitor_(new ClientNotifyMonitor()),
    timer_(new QTimer),
    secondsToGetOfflineStatus_(10){
    connectAllSignalsAndSlots();
    mainWindow_->show();
    loadDataFromTheStorage();
    checkOnlineForAll();
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

void MainThread::checkOnlineForAll(){
    QDateTime lastAllowableTime=QDateTime::currentDateTime().addSecs(-secondsToGetOfflineStatus_);
    foreach (auto element, clientDataStorage_.values()){
        if (element.lastOnlineTime()<lastAllowableTime){
            element.setOnlineStatus(false);
            emit changeClient(element);
        }
    }
    timer_->start(secondsToGetOfflineStatus_);
}

void MainThread::loadDataFromTheStorage(){
    QList<ClientData> tmpDataStorage=dataSaver_->loadData();
    foreach(const ClientData& element, tmpDataStorage){
        // bad code. need to change multiple calling element.pcName()
        // and QMap.operator[] when refactor
        clientDataStorage_[element.pcName()]=element;
        clientDataStorage_[element.pcName()].setOnlineStatus(false);
        emit addNewClient(clientDataStorage_[element.pcName()]);
    }
}

void MainThread::saveDataToTheStorage(){
    dataSaver_->saveData(clientDataStorage_.values());
}

void MainThread::connectAllSignalsAndSlots(){
    connect(clientMonitor_.get(), SIGNAL(receivedNewData(ClientData)),
            this, SLOT(processReceivedData(ClientData)));
    connect(timer_, SIGNAL(timeout()),
            this, SLOT(checkOnlineForAll()));
    connect(this, SIGNAL(addNewClient(ClientData)),
            mainWindow_.get(), SLOT(addNewClient(ClientData)));
    connect(this, SIGNAL(changeClient(ClientData)),
            mainWindow_.get(), SLOT(changeClient(ClientData)));
}
