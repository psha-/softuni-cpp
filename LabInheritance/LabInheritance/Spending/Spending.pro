TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    bankaccount.cpp \
    person.cpp \
    man.cpp \
    woman.cpp

HEADERS += \
    bankaccount.h \
    person.h \
    man.h \
    woman.h

