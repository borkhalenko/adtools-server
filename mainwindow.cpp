#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::addNewClient(const ClientData &){
    std::unique_ptr<QTreeWidgetItem> newItem(new QTreeWidgetItem(ui->treeWidget));

}

void MainWindow::changeClient(const ClientData &){

}
