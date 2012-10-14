TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.cpp \
    square.cpp \
    timer.cpp

LIBS += -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer

HEADERS += \
    square.h \
    timer.h \
    common.h
