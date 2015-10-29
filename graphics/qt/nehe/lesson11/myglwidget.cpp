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
#include <math.h>

namespace {
GLfloat     xrot = 0;             // X Rotation
GLfloat     yrot = 0;             // Y Rotation
GLfloat     zrot = 0;             // Z Rotation

float points[45][45][3];     // The Array For The Points On The Grid Of Our "Wave"
int wiggle_count = 0;           // Counter Used To Control How Fast Flag Waves
GLfloat hold;                   // Temporarily Holds A Floating Point Value

GLuint      texture[1];       // Storage For One Texture ( NEW )
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
    texture[0] = bindTexture(QString(":/Tim.bmp"),
                             GL_TEXTURE_2D,
                             GL_RGBA);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // Linear Filtering
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // Linear Filtering
}

MyGLWidget::MyGLWidget(QWidget *parent) :
    QGLWidget(parent), fullscreen(false)
{
    setWindowTitle(tr("nehe----lesson11"));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer->start(10);
    fpsUpdater = QTime::currentTime();
    fpsUpdater.start();
}

void MyGLWidget::initializeGL()
{
    loadTextures();
    glEnable(GL_TEXTURE_2D);    // Enable Texture Mapping ( NEW )

    glShadeModel(GL_SMOOTH);   // Enables Smooth Shading
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);  // Black Background
    glClearDepth(1.0f);             // Depth Buffer Setup
    glEnable(GL_DEPTH_TEST);        // Enables Depth Testing
    glDepthFunc(GL_LEQUAL);        // The Type Of Depth Test To Do
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Really Nice Perspective Calculations

    glPolygonMode( GL_BACK, GL_FILL );      // Back Face Is Filled In
    glPolygonMode( GL_FRONT, GL_LINE );     // Front Face Is Drawn With Lines
    // Loop Through The X Plane
    for(int x=0; x<45; x++) {
        // Loop Through The Y Plane
        for(int y=0; y<45; y++) {
            // Apply The Wave To Our Mesh
            points[x][y][0] = float((x/5.0f)-4.5f);
            points[x][y][1] = float((y/5.0f)-4.5f);
            points[x][y][2] = float(sin((((x/5.0f)*40.0f)/360.0f)*3.141592654*2.0f));
        }
    }
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
    int x , y;                       // Loop Variables
    float float_x, float_y, float_xb, float_yb;     // Used To Break The Flag Into Tiny Quads
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Clear The Screen And The Depth Buffer
    glLoadIdentity();       // Reset The Current Modelview Matrix
    glTranslatef(0.0f,0.0f,-15.0f);       // Move Into The Screen 12 Units

    glRotatef(xrot,1.0f,0.0f,0.0f);     // Rotate On The X Axis
    glRotatef(yrot,0.0f,1.0f,0.0f);   // Rotate On The Y Axis
    glRotatef(zrot,0.0f,0.0f,1.0f);       // Rotate On The Z Axis

    glBindTexture(GL_TEXTURE_2D, texture[0]);       // Select Our Texture
    glBegin(GL_QUADS);
        for(x = 0; x < 44; x++ ) {
            for (y = 0; y < 44; y++) {
                float_x = float(x)/44.0f;       // Create A Floating Point X Value
                float_y = float(y)/44.0f;       // Create A Floating Point Y Value
                float_xb = float(x+1)/44.0f;        // Create A Floating Point Y Value+0.0227f
                float_yb = float(y+1)/44.0f;        // Create A Floating Point Y Value+0.0227f

                glTexCoord2f( float_x, float_y);    // First Texture Coordinate (Bottom Left)
                glVertex3f( points[x][y][0], points[x][y][1], points[x][y][2] );

                glTexCoord2f( float_x, float_yb );  // Second Texture Coordinate (Top Left)
                glVertex3f( points[x][y+1][0], points[x][y+1][1], points[x][y+1][2] );

                glTexCoord2f( float_xb, float_yb ); // Third Texture Coordinate (Top Right)
                glVertex3f( points[x+1][y+1][0], points[x+1][y+1][1], points[x+1][y+1][2] );

                glTexCoord2f( float_xb, float_y );  // Fourth Texture Coordinate (Bottom Right)
                glVertex3f( points[x+1][y][0], points[x+1][y][1], points[x+1][y][2] );
            }
        }
    glEnd();
    if( wiggle_count == 2 ) {                // Used To Slow Down The Wave (Every 2nd Frame Only)
        for( y = 0; y < 45; y++ ) {           // Loop Through The Y Plane
                hold=points[0][y][2];           // Store Current Value One Left Side Of Wave
                for( x = 0; x < 44; x++) {    // Loop Through The X Plane
                    // Current Wave Value Equals Value To The Right
                    points[x][y][2] = points[x+1][y][2];
                }
                points[44][y][2]=hold;          // Last Value Becomes The Far Left Stored Value
            }
            wiggle_count = 0;               // Set Counter Back To Zero
    }
    wiggle_count++;                     // Increase The Counter

    xrot += 0.3f;                             // X Axis Rotation
    yrot += 0.2f;                             // Y Axis Rotation
    zrot += 0.4f;                             // Z Axis Rotation

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
