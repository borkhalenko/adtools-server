#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>
#include <QMap>
#include <memory>
#include "clientdata.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void addNewClient(const ClientData& );
    void changeClient(const ClientData& );
private:
    Ui::MainWindow *ui;
    QMap<QString, std::unique_ptr<QTreeWidgetItem>> itemMap;
};

#endif // MAINWINDOW_H
