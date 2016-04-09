TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    #commented due to multiple main, uncomment to get the client and server files back
    #client.cpp \
    #server.cpp \
    circle.cpp \
    line.cpp \
    ellipsis.cpp \
    polygon.cpp \
    drawing.cpp \
    object2d.cpp \
    point.cpp

HEADERS += \
    circle.h \
    line.h \
    ellipsis.h \
    polygon.h \
    drawing.h \
    object2d.h \
    point.h

DISTFILES += \
    PatchWork.pro.user
