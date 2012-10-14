TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.cpp \
    timer.cpp

LIBS += -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer

HEADERS += \
    timer.h
