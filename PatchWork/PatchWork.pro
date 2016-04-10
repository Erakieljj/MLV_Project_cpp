TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lws2_32

SOURCES += main.cpp \
    #commented due to multiple main, uncomment to get the client and server files back
    #client.cpp \
    #server.cpp \
    line.cpp \
    object2d.cpp \
    #objectinterface.cpp \
    fresque.cpp \
    matrix.cpp \
    point.cpp

HEADERS += \
    line.h \
    object2d.h \
    objectinterface.h \
    fresque.h \
    matrix.h \
    point.h

DISTFILES += \
    PatchWork.pro.user


