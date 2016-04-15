TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

SOURCES += \
    main.cpp \
    line.cpp \
    fresque.cpp \
    matrix.cpp \
    point.cpp \
    polygone.cpp \
    circle.cpp \
    ellipse.cpp \
    dataJSON.cpp \
    objectinterface.cpp \
    #clientgui.cpp
    client.cpp

HEADERS += \
    line.h \
    objectinterface.h \
    fresque.h \
    matrix.h \
    point.h \
    polygone.h \
    circle.h \
    ellipse.h \
    dataJSON.h \
    #clientgui.h
    client.h

DISTFILES += \
    PatchWork.pro.user

SUBDIRS += \
    PatchWorkClient.pro \
    PatchWorkServer.pro \
    PatchWorkClient2.pro \
    PatchWorkClient3.pro \
    PatchWorkClient4.pro

FORMS += \
   # clientgui.ui

win32 {
    LIBS += -lws2_32
}

