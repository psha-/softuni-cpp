TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    gameobject.cpp \
    gamecharacter.cpp \
    gameenvironment.cpp \
    gamescene.cpp \
    personalized.cpp \
    charactercontroller.cpp \
    rigidbodycontroller.cpp \
    rigidbody.cpp

HEADERS += \
    gameobject.h \
    gamecharacter.h \
    gameenvironment.h \
    gamescene.h \
    personalized.h \
    charactercontroller.h \
    rigidbodycontroller.h \
    rigidbody.h \
    vec2.h

