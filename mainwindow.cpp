#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::addNewClient(const ClientData& clientData){
    QTreeWidgetItem* newItem=new QTreeWidgetItem(ui->treeWidget);
    newItem->setText(0, clientData.pcName());
    newItem->setText(1, clientData.ipv4());
    newItem->setText(2, clientData.lastOnlineTime().toString("dd.MM.yyyy hh:mm:ss"));
    if (clientData.onlineStatus()==true){
        newItem->setIcon(0, QIcon(":/icons/rec/online.png"));
    }
    else{
        newItem->setIcon(0, QIcon(":/icons/rec/invis.png"));
    }
    itemMap[clientData.pcName()]=newItem;
}

void MainWindow::changeClient(const ClientData & clientData){
    QTreeWidgetItem* currentItem=itemMap[clientData.pcName()];
    currentItem->setText(1, clientData.ipv4());                // If Ip is changed.
    currentItem->setText(2, clientData.lastOnlineTime().toString("dd.MM.yyyy hh:mm:ss"));
    if (clientData.onlineStatus()==true){
        currentItem->setIcon(0, QIcon(":/icons/rec/online.png"));
    }
    else{
        currentItem->setIcon(0, QIcon(":/icons/rec/invis.png"));
    }
}
