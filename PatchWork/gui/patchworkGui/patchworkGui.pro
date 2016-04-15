#-------------------------------------------------
#
# Project created by QtCreator 2016-04-13T23:01:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = patchworkGui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myqgraphicsview.cpp \
    ellipse.cpp \
    polygone.cpp \
    circle.cpp \
    line.cpp \
    object2d.cpp \
    matrix.cpp \
    fresque.cpp \
    point.cpp \
    client.cpp

HEADERS  += mainwindow.h \
    myqgraphicsview.h \
    objectinterface.h \
    object2d.h \
    matrix.h \
    fresque.h \
    ellipse.h \
    circle.h \
    polygone.h \
    point.h \
    line.h \
    client.h

FORMS    += mainwindow.ui

CONFIG += console

win32 {
    LIBS += -lws2_32
}


