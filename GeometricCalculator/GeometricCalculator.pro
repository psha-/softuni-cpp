TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    calculator.cpp \
    result.cpp \
    shape.cpp \
    volumable.cpp \
    surfaceable.cpp \
    lenghtable.cpp \
    circle.cpp \
    rectangle.cpp

HEADERS += \
    calculator.h \
    result.h \
    shape.h \
    volumable.h \
    surfaceable.h \
    lenghtable.h \
    circle.h \
    rectangle.h

