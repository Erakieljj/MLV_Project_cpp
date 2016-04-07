TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    client.cpp \
    server.cpp \
    circle.cpp \
    line.cpp \
    ellipsis.cpp \
    polygon.cpp \
    shape.cpp \
    point.cpp \
    drawing.cpp

HEADERS += \
    circle.h \
    line.h \
    ellipsis.h \
    polygon.h \
    shape.h \
    point.h \
    drawing.h
