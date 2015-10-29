TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.cpp \
    camera.cpp

INCLUDEPATH += .
LIBS += -lGL -lGLU -lglut

HEADERS += \
    camera.h \
    math3d.h
