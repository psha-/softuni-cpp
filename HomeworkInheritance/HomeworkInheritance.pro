TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    course.cpp \
    member.cpp \
    student.cpp \
    teacher.cpp \
    permanentteacher.cpp \
    guestteacher.cpp

HEADERS += \
    course.h \
    member.h \
    student.h \
    teacher.h \
    permanentteacher.h \
    guestteacher.h

