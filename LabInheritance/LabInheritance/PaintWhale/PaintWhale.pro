TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    paintobject.cpp \
    whale.cpp \
    paintwhale.cpp

HEADERS += \
    paintobject.h \
    whale.h \
    paintwhale.h \
    color.h \
    size.h

