TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    #commented due to multiple main, uncomment to get the client and server files back
    #client.cpp \
    #server.cpp \
    line.cpp \
    object2d.cpp \
    point.cpp \
    #objectinterface.cpp \
    fresque.cpp

HEADERS += \
    line.h \
    object2d.h \
    point.h \
    objectinterface.h \
    fresque.h

DISTFILES += \
    PatchWork.pro.user


