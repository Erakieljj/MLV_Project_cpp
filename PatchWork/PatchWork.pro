TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

SOURCES += \
    main.cpp \
    line.cpp \
    object2d.cpp \
    fresque.cpp \
    matrix.cpp \
    point.cpp \
    polygone.cpp \
    circle.cpp \
    ellipse.cpp \
    drawingforjson.cpp

HEADERS += \
    line.h \
    object2d.h \
    objectinterface.h \
    fresque.h \
    matrix.h \
    point.h \
    polygone.h \
    circle.h \
    ellipse.h \
    drawingforjson.h

DISTFILES += \
    PatchWork.pro.user

SUBDIRS += \
    PatchWorkClient.pro \
    PatchWorkServer.pro


