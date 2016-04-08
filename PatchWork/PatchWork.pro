TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    #commented because only 1 main is allowed, uncomment to get the files back in the Sources explorer, enjoy the english bitches
    #client.cpp \
    #server.cpp \
    circle.cpp \
    ellipsis.cpp \
    polygon.cpp \
    shape.cpp \
    point.cpp \
    drawing.cpp \
    line.cpp

HEADERS += \
    circle.h \
    ellipsis.h \
    polygon.h \
    shape.h \
    point.h \
    drawing.h \
    line.h
