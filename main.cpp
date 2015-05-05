#include <QApplication>
#include "mainthread.h"

int main(int argc, char** argv){
    QApplication app(argc, argv);
    MainThread mainThread;
    app.exec();
}
