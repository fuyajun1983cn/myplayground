#include "myglwidget.h"
#include <QTimer>
#include <QKeyEvent>
#include <QMessageBox>
#include <QApplication>
#include <QVector>
#include <QVector2D>
#include <QVector3D>
#include <QDebug>
#include <GL/glu.h>

namespace {
bool    masking=TRUE;                               // Masking On/Off
bool    mp;                                 // M Pressed?
bool    sp;                                 // Space Pressed?
bool    scene;                                  // Which Scene To Draw

GLuint  texture[5];                             // Storage For Our Five Textures

GLfloat roll;                                   // Rolling Texture
}

void MyGLWidget::loadTextures()
{
    texture[0] = bindTexture(QString(":/logo.bmp"),
                             GL_TEXTURE_2D,
                             GL_RGBA,
                             QGLContext::LinearFilteringBindOption);
    // Create Nearest Filtered Texture
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    texture[1] = bindTexture(QString(":/mask1.bmp"),
                             GL_TEXTURE_2D,
                             GL_RGBA,
                             QGLContext::LinearFilteringBindOption);
    // Create Nearest Filtered Texture
    glBindTexture(GL_TEXTURE_2D, texture[1]);

    texture[2] = bindTexture(QString(":/image1.bmp"),
                             GL_TEXTURE_2D,
                             GL_RGBA,
                             QGLContext::LinearFilteringBindOption);
    // Create Nearest Filtered Texture
    glBindTexture(GL_TEXTURE_2D, texture[2]);

    texture[3] = bindTexture(QString(":/mask2.bmp"),
                             GL_TEXTURE_2D,
                             GL_RGBA,
                             QGLContext::LinearFilteringBindOption);
    // Create Nearest Filtered Texture
    glBindTexture(GL_TEXTURE_2D, texture[3]);

    texture[4] = bindTexture(QString(":/image2.bmp"),
                             GL_TEXTURE_2D,
                             GL_RGBA,
                             QGLContext::LinearFilteringBindOption);
    // Create Nearest Filtered Texture
    glBindTexture(GL_TEXTURE_2D, texture[4]);
}

MyGLWidget::MyGLWidget(QWidget *parent) :
    QGLWidget(parent), fullscreen(false)
{
    setWindowTitle(tr("nehe----lesson20"));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer->start(10);
}

void MyGLWidget::initializeGL()
{
    loadTextures();
    glShadeModel(GL_SMOOTH);   // Enables Smooth Shading
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);  // Black Background
    glClearDepth(1.0f);             // Depth Buffer Setup
    glEnable(GL_DEPTH_TEST);        // Enables Depth Testing
    glEnable(GL_TEXTURE_2D);
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
    glTranslatef(0.0f,0.0f,-2.0f);

    glBindTexture(GL_TEXTURE_2D, texture[0]);
    QVector<QVector3D> vertices;
    vertices<<QVector3D(-1.1f, -1.1f, 0.0f)
           <<QVector3D(1.1f, -1.1f, 0.0f)
          <<QVector3D(1.1f, 1.1f, 0.0f)
         <<QVector3D(-1.1f, 1.1f, 0.0f);
    QVector<QVector2D> texCoords;
    texCoords<<QVector2D(0.0f, -roll + 0.0f)
            <<QVector2D(3.0f, -roll + 0.0f)
           <<QVector2D(3.0f, -roll + 3.0f)
          <<QVector2D(0.0f, -roll + 3.0f);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices.constData());
    glTexCoordPointer(2, GL_FLOAT, 0, texCoords.constData());
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);

    glEnable(GL_BLEND);
    glDisable(GL_DEPTH_TEST);
    if (masking) {
        glBlendFunc(GL_DST_COLOR, GL_ZERO);//与屏幕颜色进行混色
    }
    if (scene) {
        glTranslatef(0, 0, -1.0f);
        glRotatef(roll * 360, 0, 0, 1);

        if (masking) {
            glBindTexture(GL_TEXTURE_2D, texture[3]);
            QVector<QVector3D> vertices;
            vertices<<QVector3D(-1.1f, -1.1f, 0.0f)
                   <<QVector3D(1.1f, -1.1f, 0.0f)
                  <<QVector3D(1.1f, 1.1f, 0.0f)
                 <<QVector3D(-1.1f, 1.1f, 0.0f);
            QVector<QVector2D> texCoords;
            texCoords<<QVector2D(0.0f, 0.0f)
                    <<QVector2D(1.0f, 0.0f)
                   <<QVector2D(1.0f, 1.0f)
                  <<QVector2D(0.0f, 1.0f);
            glEnableClientState(GL_VERTEX_ARRAY);
            glEnableClientState(GL_TEXTURE_COORD_ARRAY);
            glVertexPointer(3, GL_FLOAT, 0, vertices.constData());
            glTexCoordPointer(2, GL_FLOAT, 0, texCoords.constData());
            glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
            glDisableClientState(GL_VERTEX_ARRAY);
            glDisableClientState(GL_TEXTURE_COORD_ARRAY);
        }
        glBlendFunc(GL_ONE, GL_ONE);
        glBindTexture(GL_TEXTURE_2D, texture[4]);
        QVector<QVector3D> vertices;
        vertices<<QVector3D(-1.1f, -1.1f, 0.0f)
               <<QVector3D(1.1f, -1.1f, 0.0f)
              <<QVector3D(1.1f, 1.1f, 0.0f)
             <<QVector3D(-1.1f, 1.1f, 0.0f);
        QVector<QVector2D> texCoords;
        texCoords<<QVector2D(0.0f, 0.0f)
                <<QVector2D(1.0f, 0.0f)
               <<QVector2D(1.0f, 3.0f)
              <<QVector2D(0.0f, 3.0f);
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, vertices.constData());
        glTexCoordPointer(2, GL_FLOAT, 0, texCoords.constData());
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    } else {
        if (masking) {
            glBindTexture(GL_TEXTURE_2D, texture[1]);
            QVector<QVector3D> vertices;
            vertices<<QVector3D(-1.1f, -1.1f, 0.0f)
                   <<QVector3D(1.1f, -1.1f, 0.0f)
                  <<QVector3D(1.1f, 1.1f, 0.0f)
                 <<QVector3D(-1.1f, 1.1f, 0.0f);
            QVector<QVector2D> texCoords;
            texCoords<<QVector2D(roll + 0.0f, 0.0f)
                    <<QVector2D(roll + 4.0f, 0.0f)
                   <<QVector2D(roll + 4.0f, 4.0f)
                  <<QVector2D(roll + 0.0f, 4.0f);
            glEnableClientState(GL_VERTEX_ARRAY);
            glEnableClientState(GL_TEXTURE_COORD_ARRAY);
            glVertexPointer(3, GL_FLOAT, 0, vertices.constData());
            glTexCoordPointer(2, GL_FLOAT, 0, texCoords.constData());
            glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
            glDisableClientState(GL_VERTEX_ARRAY);
            glDisableClientState(GL_TEXTURE_COORD_ARRAY);
        }
        glBlendFunc(GL_ONE, GL_ONE);
        glBindTexture(GL_TEXTURE_2D, texture[2]);
        QVector<QVector3D> vertices;
        vertices<<QVector3D(-1.1f, -1.1f, 0.0f)
               <<QVector3D(1.1f, -1.1f, 0.0f)
              <<QVector3D(1.1f, 1.1f, 0.0f)
             <<QVector3D(-1.1f, 1.1f, 0.0f);
        QVector<QVector2D> texCoords;
        texCoords<<QVector2D(roll + 0.0f, 0.0f)
                <<QVector2D(roll + 4.0f, 0.0f)
               <<QVector2D(roll + 4.0f, 4.0f)
              <<QVector2D(roll + 0.0f, 4.0f);
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, vertices.constData());
        glTexCoordPointer(2, GL_FLOAT, 0, texCoords.constData());
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    }
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_BLEND);

    roll += 0.002f;
    if (roll > 1.0f)
        roll -= 1.0f;
}

void MyGLWidget::keyReleaseEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_Space:
        sp = false;
        break;
    case Qt::Key_M:
        mp = false;
        break;
    }
    QWidget::keyReleaseEvent(e);
}

void MyGLWidget::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_M:
        if (!mp) {
            mp = true;
            masking = !masking;
        }
        break;
    case Qt::Key_Space:
        if (!sp) {
            sp = true;
            scene = !scene;
        }
        break;
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
