TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += \
    CTexture.cpp \
    CLogger.cpp \
    CEvent.cpp \
    CCamera.cpp \
    CApp_OnRender.cpp \
    CApp_OnLoop.cpp \
    CApp_OnInit.cpp \
    CApp_OnEvent.cpp \
    CApp_OnCleanup.cpp \
    CApp.cpp

INCLUDEPATH += .
LIBS += -lGL -lGLU -lglut -lGLEW -lSDL -lSDL_image

HEADERS += \
    CTexture.h \
    CMaths.h \
    CLogger.h \
    CEvent.h \
    CCamera.h \
    CApp.h
