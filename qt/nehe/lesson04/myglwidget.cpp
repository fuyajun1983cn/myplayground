#include "myglwidget.h"
#include <QTimer>
#include <QKeyEvent>
#include <QMessageBox>
#include <QApplication>
#include <QDebug>
#include <GL/glu.h>

MyGLWidget::MyGLWidget(QWidget *parent) :
    QGLWidget(parent), fullscreen(false),rtri(0), rquad(0)
{
    setWindowTitle(tr("nehe----lesson04"));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer->start(10);
}

void MyGLWidget::initializeGL()
{
    glShadeModel(GL_SMOOTH);   // Enables Smooth Shading
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);  // Black Background
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
    gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

    glMatrixMode(GL_MODELVIEW);      // Select The Modelview Matrix
    glLoadIdentity();                // Reset The Modelview Matrix
}

void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Clear The Screen And The Depth Buffer
    glLoadIdentity();       // Reset The Current Modelview Matrix

    glTranslatef(-1.5f,0.0f,-6.0f);     // Move Left 1.5 Units And Into The Screen 6.0
    glPushMatrix();
    glRotatef(rtri, 0, 1.0f, 0);
    glBegin(GL_TRIANGLES);                      // Drawing Using Triangles
        glColor3f(1.0f,0.0f,0.0f);	       // Set The Color To Red
        glVertex3f( 0.0f, 1.0f, 0.0f);              // Top
        glColor3f(0.0f,1.0f,0.0f);          // Set The Color To Green
        glVertex3f(-1.0f,-1.0f, 0.0f);              // Bottom Left
        glColor3f(0.0f,0.0f,1.0f);          // Set The Color To Blue
        glVertex3f( 1.0f,-1.0f, 0.0f);              // Bottom Right
    glEnd();                            // Finished Drawing The Triangle
    glPopMatrix();
    glTranslatef(3.0f,0.0f,0.0f);                   // Move Right 3 Units
    glColor3f(0.5f,0.5f,1.0f);              // Set The Color To Blue One Time Only
    glRotatef(rquad, 1.0f, 0, 0);
    glBegin(GL_QUADS);                      // Draw A Quad
           glVertex3f(-1.0f, 1.0f, 0.0f);              // Top Left
           glVertex3f( 1.0f, 1.0f, 0.0f);              // Top Right
           glVertex3f( 1.0f,-1.0f, 0.0f);              // Bottom Right
           glVertex3f(-1.0f,-1.0f, 0.0f);              // Bottom Left
    glEnd();                         // Done Drawing The Quad

    rtri += 0.2f;                    // Increase The Rotation Variable For The Triangle ( NEW )
    rquad -= 0.15f;                  // Decrease The Rotation Variable For The Quad     ( NEW )
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
