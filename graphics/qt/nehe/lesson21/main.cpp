#include <QApplication>
#include "myglwidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("NeHe_Lesson21");
    MyGLWidget win;
    win.show();
    /*
    Phonon::MediaObject *music = new Phonon::MediaObject(0);
    Phonon::AudioOutput *audioOutput = new Phonon::AudioOutput(Phonon::GameCategory, 0);
    Phonon::createPath(music, audioOutput);
    music->setCurrentSource(Phonon::MediaSource(":/lktheme.mod"));
    music->play();*/

    return app.exec();
}
