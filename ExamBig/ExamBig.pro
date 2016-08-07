TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

LIBS += -pthread

SOURCES += main.cpp \
    mission.cpp

HEADERS += \
    LocationType.h \
    mission.h \
    datetime.h

