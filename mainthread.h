#ifndef MAINTHREAD_H
#define MAINTHREAD_H

#include <QObject>
#include <QMap>
#include <QTimer>
#include <memory>
#include "idatasaver.h"
#include "clientnotifymonitor.h"
#include "mainwindow.h"
#include "filestorage.h"

class MainThread : public QObject{
    Q_OBJECT
public:
    explicit MainThread(QObject *parent = 0);
    MainThread(const MainThread& )=delete;
    MainThread& operator=(const MainThread&)=delete;
    ~MainThread();
signals:
    void addNewClient(const ClientData&);
    void changeClient(const ClientData&);
private slots:
    void processReceivedData(ClientData receivedData);
    void checkOnlineForAll();
private:
    std::unique_ptr<IDataSaver> dataSaver_;
    std::unique_ptr<MainWindow> mainWindow_;
    std::unique_ptr<ClientNotifyMonitor> clientMonitor_;
    QMap<QString, ClientData> clientDataStorage_;
    QTimer* timer_;
    int secondsToGetOfflineStatus_;
    void loadDataFromTheStorage();
    void saveDataToTheStorage();
    void connectAllSignalsAndSlots();
};

#endif // MAINTHREAD_H
