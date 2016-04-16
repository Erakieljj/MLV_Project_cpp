TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

SOURCES += \
    server.cpp \
    ../circle.cpp \
    ../client.cpp \
    ../dataJSON.cpp \
    ../ellipse.cpp \
    ../fresque.cpp \
    ../line.cpp \
    ../main.cpp \
    ../matrix.cpp \
    ../objectinterface.cpp \
    ../point.cpp \
    ../polygone.cpp

win32 {
    LIBS += -lws2_32
}

HEADERS += \
    ../circle.h \
    ../client.h \
    ../dataJSON.h \
    ../ellipse.h \
    ../fresque.h \
    ../line.h \
    ../matrix.h \
    ../objectinterface.h \
    ../point.h \
    ../polygone.h
