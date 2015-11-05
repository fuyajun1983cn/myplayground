TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.cpp \
        dot.cpp \
        timer.cpp

LIBS += -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer

HEADERS += \
    dot.h \
    timer.h \
    common.h
