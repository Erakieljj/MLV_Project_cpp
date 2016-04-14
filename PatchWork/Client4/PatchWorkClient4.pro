QT += core

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

SOURCES += \
    client4.cpp

win32 {
    LIBS += -lws2_32
}
