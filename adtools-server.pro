#-------------------------------------------------
#
# Project created by QtCreator 2015-04-17T16:52:04
#
#-------------------------------------------------

QT += core network widgets

CONFIG += qt c++11

TARGET = adtools-server

SOURCES += \
    main.cpp \
    clientnotifymonitor.cpp \
    datagramreceiver.cpp \
    mainwindow.cpp \
    clientdata.cpp \
    mainthread.cpp \
    filestorage.cpp

HEADERS += \
    clientnotifymonitor.h \
    datagramreceiver.h \
    mainwindow.h \
    clientdata.h \
    mainthread.h \
    idatasaver.h \
    filestorage.h

FORMS += \
    mainwindow.ui

RESOURCES += \
    resources.qrc
