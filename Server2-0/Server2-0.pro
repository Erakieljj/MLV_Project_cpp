TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

SOURCES += \
    server.cpp \
    dataJSON.cpp \
    fresque.cpp \
    objectinterface.cpp \
    point.cpp \
    circle.cpp \
    ellipse.cpp \
    line.cpp \
    matrix.cpp \
    polygone.cpp

win32 {
    LIBS += -lws2_32
}

HEADERS += \
    dataJSON.h \
    fresque.h \
    objectinterface.h \
    point.h \
    circle.h \
    ellipse.h \
    line.h \
    matrix.h \
    polygone.h

