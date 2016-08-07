TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

LIBS += -pthread

SOURCES += main.cpp \
    mission.cpp \
    landingsite.cpp \
    landingsitecontainer.cpp

HEADERS += \
    mission.h \
    datetime.h \
    geocoordinates.h \
    landingsite.h \
    locationtype.h \
    landingsitecontainer.h

