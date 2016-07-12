TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    voter.cpp \
    vote.cpp \
    person.cpp \
    votecollection.cpp

HEADERS += \
    voter.h \
    vote.h \
    person.h \
    ethnos.h \
    gender.h \
    option.h \
    votecollection.h \
    operators.h \
    votesbyoption.h

