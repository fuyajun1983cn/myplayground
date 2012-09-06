#include "myglwidget.h"
#include <QTimer>
#include <QKeyEvent>
#include <QMessageBox>
#include <QApplication>
#include <QPainter>
#include <QDebug>
#include <GL/glu.h>
#include <QVector>
#include <QVector2D>
#include <QVector3D>

namespace {
bool    gp;
GLuint  fogMode[] = { GL_EXP, GL_EXP2, GL_LINEAR };
GLuint  fogfilter = 0;
GLfloat fogColor[4]= {0.5f, 0.5f, 0.5f, 1.0f};      // Fog Color
bool	light;                       // Lighting ON / OFF
bool	lp;                         // L Pressed?
bool	fp;                         // F Pressed?
GLfloat	xrot;                       // X Rotation
GLfloat	yrot;                       // Y Rotation
GLfloat xspeed;                     // X Rotation Speed
GLfloat yspeed;                     // Y Rotation Speed
GLfloat	z=-5.0f;                    // Depth Into The Screen

GLfloat LightAmbient[]= { 0.5f, 0.5f, 0.5f, 1.0f };             // Ambient Light Values ( NEW )
GLfloat LightDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };              // Diffuse Light Values ( NEW )
GLfloat LightPosition[]= { 0.0f, 0.0f, 2.0f, 1.0f };            // Light Position ( NEW )
GLuint  filter;                                 // Which Filter To Use
GLuint  texture[3];                             // Storage for 3 textures

QVector<QVector3D> vertices;
QVector<QVector2D> texCoords;
QVector<QVector3D> normals;

void makeObject()
{

    vertices<<QVector3D(-1.0f, -1.0f,  1.0f)<<QVector3D(1.0f, -1.0f,  1.0f)<<QVector3D(1.0f,  1.0f,  1.0f)<<QVector3D(-1.0f,  1.0f,  1.0f)
            <<QVector3D(-1.0f, -1.0f, -1.0f)<<QVector3D(-1.0f,  1.0f, -1.0f)<<QVector3D(1.0f,  1.0f, -1.0f)<<QVector3D(1.0f, -1.0f, -1.0f)
            <<QVector3D(-1.0f,  1.0f, -1.0f)<<QVector3D(-1.0f,  1.0f,  1.0f)<<QVector3D(1.0f,  1.0f,  1.0f)<<QVector3D(1.0f,  1.0f, -1.0f)
            <<QVector3D(-1.0f, -1.0f, -1.0f)<<QVector3D(1.0f, -1.0f, -1.0f)<<QVector3D(1.0f, -1.0f,  1.0f)<<QVector3D(-1.0f, -1.0f,  1.0f)
            <<QVector3D(1.0f, -1.0f, -1.0f)<<QVector3D(1.0f,  1.0f, -1.0f)<<QVector3D(1.0f,  1.0f,  1.0f)<<QVector3D(1.0f, -1.0f,  1.0f)
            <<QVector3D(-1.0f, -1.0f, -1.0f)<<QVector3D(-1.0f, -1.0f,  1.0f)<<QVector3D(-1.0f,  1.0f,  1.0f)<<QVector3D(-1.0f,  1.0f, -1.0f);

     texCoords<<QVector2D(0.0f, 0.0f)<<QVector2D(1.0f, 0.0f)<<QVector2D(1.0f, 1.0f)<<QVector2D(0.0f, 1.0f)
              <<QVector2D(1.0f, 0.0f)<<QVector2D(1.0f, 1.0f)<<QVector2D(0.0f, 1.0f)<<QVector2D(0.0f, 0.0f)
              <<QVector2D(0.0f, 1.0f)<<QVector2D(0.0f, 0.0f)<<QVector2D(1.0f, 0.0f)<<QVector2D(1.0f, 1.0f)
              <<QVector2D(1.0f, 1.0f)<<QVector2D(0.0f, 1.0f)<<QVector2D(0.0f, 0.0f)<<QVector2D(1.0f, 0.0f)
              <<QVector2D(1.0f, 0.0f)<<QVector2D(1.0f, 1.0f)<<QVector2D(0.0f, 1.0f)<<QVector2D(0.0f, 0.0f)
              <<QVector2D(0.0f, 0.0f)<<QVector2D(1.0f, 0.0f)<<QVector2D(1.0f, 1.0f)<<QVector2D(0.0f, 1.0f);

     normals<<QVector3D(0.0f, 0.0f, 1.0f)<<QVector3D(0.0f, 0.0f, 1.0f)<<QVector3D(0.0f, 0.0f, 1.0f)<<QVector3D(0.0f, 0.0f, 1.0f)
            <<QVector3D(0.0f, 0.0f,-1.0f)<<QVector3D(0.0f, 0.0f,-1.0f)<<QVector3D(0.0f, 0.0f,-1.0f)<<QVector3D(0.0f, 0.0f,-1.0f)
            <<QVector3D(0.0f, 1.0f, 0.0f)<<QVector3D(0.0f, 1.0f, 0.0f)<<QVector3D(0.0f, 1.0f, 0.0f)<<QVector3D(0.0f, 1.0f, 0.0f)
            <<QVector3D(0.0f, -1.0f, 0.0f)<<QVector3D(0.0f, -1.0f, 0.0f)<<QVector3D(0.0f, -1.0f, 0.0f)<<QVector3D(0.0f, -1.0f, 0.0f)
            <<QVector3D(1.0f, 0.0f, 0.0f)<<QVector3D(1.0f, 0.0f, 0.0f)<<QVector3D(1.0f, 0.0f, 0.0f)<<QVector3D(1.0f, 0.0f, 0.0f)
            <<QVector3D(-1.0f, 0.0f, 0.0f)<<QVector3D(-1.0f, 0.0f, 0.0f)<<QVector3D(-1.0f, 0.0f, 0.0f)<<QVector3D(-1.0f, 0.0f, 0.0f);

      glVertexPointer(3, GL_FLOAT, 0, vertices.constData());
      glTexCoordPointer(2, GL_FLOAT, 0, texCoords.constData());
      glNormalPointer(GL_FLOAT, 0, normals.constData());

}

void drawObject()
{
      glEnableClientState(GL_VERTEX_ARRAY);
      glEnableClientState(GL_TEXTURE_COORD_ARRAY);
      glEnableClientState(GL_NORMAL_ARRAY);

      glBindTexture(GL_TEXTURE_2D, texture[filter]);
      glDrawArrays(GL_QUADS, 0, vertices.size());

      glDisableClientState(GL_VERTEX_ARRAY);
      glDisableClientState(GL_TEXTURE_COORD_ARRAY);
      glDisableClientState(GL_NORMAL_ARRAY);
}
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

void MyGLWidget::loadTextures()
{
  QImage image;
  if (image.load(":/Crate.bmp")) {
      image =  convertToGLFormat(image);
      glGenTextures(3, texture);
      // Create Nearest Filtered Texture
      glBindTexture(GL_TEXTURE_2D, texture[0]);
      glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
      glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.width(), image.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.bits());

      // Create Linear Filtered Texture
      glBindTexture(GL_TEXTURE_2D, texture[1]);
      glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
      glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.width(), image.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.bits());

      // Create MipMapped Texture
      glBindTexture(GL_TEXTURE_2D, texture[2]);
      glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
      glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
      gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, image.width(), image.height(), GL_RGBA, GL_UNSIGNED_BYTE, image.bits());
  }
}


MyGLWidget::MyGLWidget(QWidget *parent) :
    QGLWidget(parent), fullscreen(false)
{
    setWindowTitle(tr("nehe----lesson16"));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer->start(10);
    fpsUpdater = QTime::currentTime();
    fpsUpdater.start();
}

void MyGLWidget::initializeGL()
{
    makeObject();
    loadTextures();
    glEnable(GL_TEXTURE_2D);    // Enable Texture Mapping
    glShadeModel(GL_SMOOTH);   // Enables Smooth Shading
    glClearColor(0.5f,0.5f,0.5f,1.0f);  // Black Background
    glClearDepth(1.0f);             // Depth Buffer Setup
    glEnable(GL_DEPTH_TEST);        // Enables Depth Testing
    glDepthFunc(GL_LEQUAL);        // The Type Of Depth Test To Do
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Really Nice Perspective Calculations

    glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);             // Setup The Ambient Light
    glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);
    glLightfv(GL_LIGHT1, GL_POSITION,LightPosition);            // Position The Light
    glEnable(GL_LIGHT1);                            // Enable Light One

    glFogi(GL_FOG_MODE, fogMode[fogfilter]);        // Fog Mode
    glFogfv(GL_FOG_COLOR, fogColor);            // Set Fog Color
    glFogf(GL_FOG_DENSITY, 0.35f);              // How Dense Will The Fog Be
    glHint(GL_FOG_HINT, GL_DONT_CARE);          // Fog Hint Value
    glFogf(GL_FOG_START, 1.0f);             // Fog Start Depth
    glFogf(GL_FOG_END, 5.0f);               // Fog End Depth
    glEnable(GL_FOG);                   // Enables GL_FOG
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
    //glOrtho(0.0f,width,0,height,-1.0f,1.0f);

    glMatrixMode(GL_MODELVIEW);      // Select The Modelview Matrix
    glLoadIdentity();                // Reset The Modelview Matrix

}
void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Clear The Screen And The Depth Buffer
    glLoadIdentity();       // Reset The Current Modelview Matrix

    glTranslatef(0.0f,0.0f,z);                      // Translate Into/Out Of The Screen By z

    glRotatef(xrot,1.0f,0.0f,0.0f);                     // Rotate On The X Axis By xrot
    glRotatef(yrot,0.0f,1.0f,0.0f);                     // Rotate On The Y Axis By yrot

    drawObject();

    xrot += xspeed;                        // Add xspeed To xrot
    yrot += yspeed;                       // Add yspeed To yrot

    showFPS();
}

void MyGLWidget::keyReleaseEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_L:
        lp = false;
        break;
    case Qt::Key_I:
        fp = false;
        break;
    case Qt::Key_G:
        gp = false;
        break;
    default:
        QGLWidget::keyReleaseEvent(e);
    }
}

void MyGLWidget::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_I:
        if (!fp) {
        fp = true;
        filter += 1;
        if (filter > 2)
            filter = 0;
        }
        break;
    case Qt::Key_G:
        if (!gp) {
        gp = true;
        fogfilter += 1;
        if (fogfilter > 2)
            fogfilter = 0;
        glFogi (GL_FOG_MODE, fogMode[fogfilter]);
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
    case Qt::Key_L:
        if (!lp) {
            lp=true;                // lp Becomes TRUE
            light=!light;               // Toggle Light TRUE/FALSE
            if (!light)             // If Not Light
            {
                glDisable(GL_LIGHTING);     // Disable Lighting
            }
            else                    // Otherwise
            {
                glEnable(GL_LIGHTING);      // Enable Lighting
            }
        }
        break;
    case Qt::Key_PageUp:
        z -= 0.02f;
        break;
    case Qt::Key_PageDown:
        z += 0.02f;
        break;
    case Qt::Key_Up:
         xspeed -= 0.01f;
         break;
    case Qt::Key_Down:
        xspeed += 0.01f;
        break;
    case Qt::Key_Right:
        yspeed += 0.01f;
        break;
    case Qt::Key_Left:
        yspeed -= 0.01f;
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
