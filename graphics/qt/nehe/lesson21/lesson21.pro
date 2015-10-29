HEADERS += \
    myglwidget.h

SOURCES += \
    myglwidget.cpp \
    main.cpp
QT += opengl
LIBS += -lGLU -lphonon -L/usr/lib -L/lib

RESOURCES += \
    image.qrc
