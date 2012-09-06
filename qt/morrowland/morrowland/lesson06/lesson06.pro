TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += \
    CEvent.cpp \
    CApp_OnRender.cpp \
    CApp_OnLoop.cpp \
    CApp_OnInit.cpp \
    CApp_OnEvent.cpp \
    CApp_OnCleanup.cpp \
    CApp.cpp \
    CTexture.cpp \
    CLogger.cpp

INCLUDEPATH += .
LIBS += -lGL -lGLU -lglut -lGLEW -lSDL -lSDL_image

HEADERS += \
    CEvent.h \
    CApp.h \
    CTexture.h \
    CLogger.h
