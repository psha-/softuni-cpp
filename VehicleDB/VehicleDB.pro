TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    vehicle.cpp \
    motorcycle.cpp \
    truck.cpp \
    car.cpp \
    vehicledatabase.cpp

LIBS += -pthread

HEADERS += \
    vehicle.h \
    motorcycle.h \
    truck.h \
    car.h \
    date.h \
    person.h \
    vehicledatabase.h

