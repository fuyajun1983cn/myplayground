#include "myglwidget.h"
#include <QTimer>
#include <QKeyEvent>
#include <QMessageBox>
#include <QApplication>
#include <QPainter>
#include <QDebug>
#include <GL/glu.h>
#include <QVector>
#include <QVector3D>
#include <QVector2D>
#include "MilkshapeModel.h"

namespace {
Model *pModel = NULL;		// Holds The Model Data


    GLfloat     yrot = 0;             // Y Rotation ( NEW )
}


void MyGLWidget::showFPS()
{
    static GLint Frames = 0;

    /* Gather our frames per second */
   Frames++;
   {
       GLint t = fpsUpdater.elapsed();
       if (t >= 5000) {
           GLfloat seconds = t / 1000.0;
           GLfloat fps = Frames / seconds;
           QString title = windowTitle().mid(0, 16) + QString(" FPS: %1").arg(fps);
           setWindowTitle(title);
           t = 0;
           Frames = 0;
           fpsUpdater.restart();
       }
   }
}

int LoadGLTexture(const char *filename)
{
    GLuint texPntr[1];
    QImage image;
    if (image.load(QString::fromAscii(filename))) {
        glGenTextures(1, &texPntr[0]);   /* create the texture */
        glBindTexture(GL_TEXTURE_2D, texPntr[0]);
        /* actually generate the texture */
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.width(), image.height(), 0,
            GL_RGBA, GL_UNSIGNED_BYTE, image.bits());
        /* enable linear filtering */
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }
    return texPntr[0];
}

MyGLWidget::MyGLWidget(QWidget *parent) :
    QGLWidget(parent), fullscreen(false)
{
    setWindowTitle(tr("nehe----lesson31"));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer->start(10);
    fpsUpdater = QTime::currentTime();
    fpsUpdater.start();
    pModel = new MilkshapeModel();		// Memory To Hold The Model
}

void MyGLWidget::initializeGL()
{
    if (pModel->loadModelData( "/home/fuyajun/myplayground/qt/nehe/lesson31/model.ms3d" ) == false)
        return;

    pModel->reloadTextures();
    glEnable(GL_TEXTURE_2D);    // Enable Texture Mapping ( NEW )

    glShadeModel(GL_SMOOTH);   // Enables Smooth Shading
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);  // Black Background
    glClearDepth(1.0f);             // Depth Buffer Setup
    glEnable(GL_DEPTH_TEST);        // Enables Depth Testing
    glDepthFunc(GL_LEQUAL);        // The Type Of Depth Test To Do
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Really Nice Perspective Calculations
}

void MyGLWidget::resizeGL(int width, int height)
{
    if (height==0) {    // Prevent A Divide By Zero By
        height=1;    // Making Height Equal One
    }
    glViewport(0, 0, width, height);    // Reset The Current Viewport
    glMatrixMode(GL_PROJECTION);       // Select The Projection Matrix
    glLoadIdentity();                  // Reset The Projection Matrix

    // Calculate The Aspect Ratio Of The Window
    gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,200.0f);
    //glOrtho(0.0f,width,0,height,-1.0f,1.0f);

    glMatrixMode(GL_MODELVIEW);      // Select The Modelview Matrix
    glLoadIdentity();                // Reset The Modelview Matrix

}

void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Clear The Screen And The Depth Buffer
    glLoadIdentity();       // Reset The Current Modelview Matrix
    gluLookAt( 75, 75, 75, 0, 0, 0, 0, 1, 0 );

    glRotatef(yrot,0.0f,1.0f,0.0f);

    pModel->draw();		// Draw The Model

    yrot+=0.3f;		// Increase yrot By One

    showFPS();
}

void MyGLWidget::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_F:
        fullscreen = !fullscreen;
        if (fullscreen) {
            showFullScreen();
        } else {
            resize(640, 480);
            showNormal();
        }
        break;
    case Qt::Key_Escape:
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(NULL, "NeHe",
                           "Do you want to exit?",
                           QMessageBox::Yes | QMessageBox::No,
                           QMessageBox::Yes);
        if (reply == QMessageBox::Yes) {
                qApp->quit();
        }
        break;
    default:
        QGLWidget::keyPressEvent(e);
        break;
    }
}

void MyGLWidget::closeEvent(QCloseEvent *e)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "NeHe",
                       "Do you want to exit?",
                       QMessageBox::Yes | QMessageBox::No,
                       QMessageBox::No);
    if (reply == QMessageBox::Yes) {
            e->accept();
    } else {
        e->ignore();
    }
}
