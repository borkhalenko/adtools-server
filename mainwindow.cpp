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
    itemMap[clientData.pcName()]=newItem;
}

void MainWindow::changeClient(const ClientData & clientData){
    itemMap[clientData.pcName()]->setText(1, clientData.ipv4());                // If Ip is changed.
    itemMap[clientData.pcName()]->setText(2, clientData.lastOnlineTime().toString("dd.MM.yyyy hh:mm:ss"));
}
