#include <QApplication>
#include "myglwidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MyGLWidget win;
    win.show();
    return app.exec();
}

