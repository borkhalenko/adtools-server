#-------------------------------------------------
#
# Project created by QtCreator 2015-04-17T16:52:04
#
#-------------------------------------------------

QT += core network widgets

CONFIG += qt c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = adtools-server
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    datagramreceiver.cpp \
    clientstorage.cpp \
    clientdata.cpp

HEADERS  += mainwindow.h \
    datagramreceiver.h \
    clientstorage.h \
    clientdata.h

FORMS    += mainwindow.ui
