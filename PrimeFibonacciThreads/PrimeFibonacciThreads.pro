TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    fibonaccisequence.cpp \
    primesequence.cpp \
    sequence.cpp \
    sequencecollection.cpp
LIBS += -pthread

HEADERS += \
    sequence.h \
    fibonaccisequence.h \
    primesequence.h \
    sequencecollection.h \
    operators.h \
    fibonaccielement.h \
    element.h \
    primeelement.h
