#include "myglwidget.h"
#include <QTimer>
#include <QKeyEvent>
#include <QMessageBox>
#include <QApplication>
#include <QPainter>
#include <QDebug>
#include <GL/glu.h>

namespace {
/* Number of textures to load */
#define NUM_TEXTURES 6

/* Whether or not lighting is on */
int light = FALSE;

GLfloat xrot;      /* X Rotation            */
GLfloat yrot;      /* Y Rotation            */
GLfloat xspeed;    /* X Rotation Speed      */
GLfloat yspeed;    /* Y Rotation Speed      */
GLfloat z = -5.0f; /* Depth Into The Screen */

/* Ambient Light Values */
GLfloat LightAmbient[]  = { 0.5f, 0.5f, 0.5f, 1.0f };
/* Diffuse Light Values */
GLfloat LightDiffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
/* Light Position */
GLfloat LightPosition[] = { 0.0f, 0.0f, 2.0f, 1.0f };

GLUquadricObj *quadratic;     /* Storage For Our Quadratic Objects */
GLuint object = 3;            /* Which Object To Draw              */

GLuint filter = 0;            /* Which Filter To Use               */
GLuint texture[NUM_TEXTURES]; /* Storage for 3 textures            */

void drawCube()
{
    /* Start Drawing Quads */
     glBegin( GL_QUADS );
       /* Front Face */
       glNormal3f( 0.0f, 0.0f, 0.5f );
       glTexCoord2f( 1.0f, 0.0f ); glVertex3f( -1.0f, -1.0f,  1.0f );
       glTexCoord2f( 0.0f, 0.0f ); glVertex3f(  1.0f, -1.0f,  1.0f );
       glTexCoord2f( 0.0f, 1.0f ); glVertex3f(  1.0f,  1.0f,  1.0f );
       glTexCoord2f( 1.0f, 1.0f ); glVertex3f( -1.0f,  1.0f,  1.0f );

       /* Back Face */
       glNormal3f( 0.0f, 0.0f, -0.5f);
       glTexCoord2f( 0.0f, 0.0f ); glVertex3f( -1.0f, -1.0f, -1.0f );
       glTexCoord2f( 0.0f, 1.0f ); glVertex3f( -1.0f,  1.0f, -1.0f );
       glTexCoord2f( 1.0f, 1.0f ); glVertex3f(  1.0f,  1.0f, -1.0f );
       glTexCoord2f( 1.0f, 0.0f ); glVertex3f(  1.0f, -1.0f, -1.0f );

       /* Top Face */
       glNormal3f( 0.0f, 0.5f, 0.0f );
       glTexCoord2f( 1.0f, 1.0f ); glVertex3f( -1.0f,  1.0f, -1.0f );
       glTexCoord2f( 1.0f, 0.0f ); glVertex3f( -1.0f,  1.0f,  1.0f );
       glTexCoord2f( 0.0f, 0.0f ); glVertex3f(  1.0f,  1.0f,  1.0f );
       glTexCoord2f( 0.0f, 1.0f ); glVertex3f(  1.0f,  1.0f, -1.0f );

       /* Bottom Face */
       glNormal3f( 0.0f, -0.5f, 0.0f );
       glTexCoord2f( 0.0f, 1.0f ); glVertex3f( -1.0f, -1.0f, -1.0f );
       glTexCoord2f( 1.0f, 1.0f ); glVertex3f(  1.0f, -1.0f, -1.0f );
       glTexCoord2f( 1.0f, 0.0f ); glVertex3f(  1.0f, -1.0f,  1.0f );
       glTexCoord2f( 0.0f, 0.0f ); glVertex3f( -1.0f, -1.0f,  1.0f );

       /* Right face */
       glNormal3f( 0.5f, 0.0f, 0.0f);
       glTexCoord2f( 0.0f, 0.0f ); glVertex3f( 1.0f, -1.0f, -1.0f );
       glTexCoord2f( 0.0f, 1.0f ); glVertex3f( 1.0f,  1.0f, -1.0f );
       glTexCoord2f( 1.0f, 1.0f ); glVertex3f( 1.0f,  1.0f,  1.0f );
       glTexCoord2f( 1.0f, 0.0f ); glVertex3f( 1.0f, -1.0f,  1.0f );

       /* Left Face*/
       glNormal3f( -0.5f, 0.0f, 0.0f );
       glTexCoord2f( 1.0f, 0.0f ); glVertex3f( -1.0f, -1.0f, -1.0f );
       glTexCoord2f( 0.0f, 0.0f ); glVertex3f( -1.0f, -1.0f,  1.0f );
       glTexCoord2f( 0.0f, 1.0f ); glVertex3f( -1.0f,  1.0f,  1.0f );
       glTexCoord2f( 1.0f, 1.0f ); glVertex3f( -1.0f,  1.0f, -1.0f );
     glEnd();
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
    QImage image[2];
    if (image[0].load(":/bg.bmp") && image[1].load(":/reflect.bmp")) {
        convertToGLFormat(image[0]);
        convertToGLFormat(image[1]);
        /* Create The Texture */
        glGenTextures( NUM_TEXTURES, &texture[0] );

        for(int loop = 0; loop <= 1; loop++ )
        {
           /* Create Nearest Filtered Texture */
           glBindTexture( GL_TEXTURE_2D, texture[loop] ); /* Gen Tex 0 And 1 */
           glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_NEAREST );
           glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_NEAREST );
           glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, image[loop].width(), image[loop].height(),
               0, GL_RGBA, GL_UNSIGNED_BYTE, image[loop].bits() );

           /* Create Linear Filtered Texture */
           glBindTexture( GL_TEXTURE_2D, texture[loop+2] ); /* Gen Tex 2 And 3 */
           glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
           glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
           glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, image[loop].width(), image[loop].height(),
               0, GL_RGBA, GL_UNSIGNED_BYTE, image[loop].bits() );

           /* Create MipMapped Texture */
           glBindTexture( GL_TEXTURE_2D, texture[loop+4] ); /* Gen Tex 4 and 5 */
           glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
           glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST );
           gluBuild2DMipmaps( GL_TEXTURE_2D, GL_RGBA, image[loop].width(), image[loop].height(),
               GL_RGBA, GL_UNSIGNED_BYTE, image[loop].bits() );
        }
    }
}

MyGLWidget::MyGLWidget(QWidget *parent) :
    QGLWidget(parent), fullscreen(false)
{
    setWindowTitle(tr("nehe----lesson23"));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer->start(10);
    fpsUpdater = QTime::currentTime();
    fpsUpdater.start();
}

void MyGLWidget::initializeGL()
{
    loadTextures();
    glEnable( GL_TEXTURE_2D );
    glShadeModel(GL_SMOOTH);   // Enables Smooth Shading
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);  // Black Background
    glClearDepth(1.0f);             // Depth Buffer Setup
    glEnable(GL_DEPTH_TEST);        // Enables Depth Testing
    glDepthFunc(GL_LEQUAL);        // The Type Of Depth Test To Do
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Really Nice Perspective Calculations

    /* Setup The Ambient Light */
    glLightfv( GL_LIGHT1, GL_AMBIENT, LightAmbient );

    /* Setup The Diffuse Light */
    glLightfv( GL_LIGHT1, GL_DIFFUSE, LightDiffuse );

    /* Position The Light */
    glLightfv( GL_LIGHT1, GL_POSITION, LightPosition );

    /* Enable Light One */
    glEnable( GL_LIGHT1 );

    /* Set The Texture Generation Mode For S To Sphere Mapping */
    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
    /* Set The Texture Generation Mode For T To Sphere Mapping */
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);

    /* Create A Pointer To The Quadric Object */
    quadratic = gluNewQuadric( );
    /* Create Smooth Normals */
    gluQuadricNormals( quadratic, GLU_SMOOTH );
    /* Create Texture Coords */
    gluQuadricTexture( quadratic, GL_TRUE );
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
    glTranslatef( 0.0f, 0.0f, z );

    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);

    glBindTexture( GL_TEXTURE_2D, texture[filter*2 + 1] );
    glPushMatrix();

    glRotatef( xrot, 1.0f, 0.0f, 0.0f);
    glRotatef( yrot, 0.0f, 1.0f, 0.0f);

    /* Determine what object to draw */
    switch( object )
    {
    case 0:
        /* Draw our cube */
        drawCube( );
        break;
    case 1:
        /* Draw a cylinder */
        glTranslatef( 0.0f, 0.0f, -1.5f );
        gluCylinder( quadratic, 1.0f, 1.0f, 3.0f, 32, 32 );
        break;
    case 2:
        /* Draw a sphere */
        gluSphere( quadratic, 1.3f, 32, 32 );
        break;
    case 3:
        /* Draw a cone */
        glTranslatef( 0.0f, 0.0f, -1.5f );
        gluCylinder( quadratic, 1.0f, 0.0f, 3.0f, 32, 32 );
        break;
    };

    glPopMatrix();

    /* Disable Texture Coord Generation For S */
    glDisable( GL_TEXTURE_GEN_S );
    /* Disable Texture Coord Generation For T */
    glDisable( GL_TEXTURE_GEN_T );

    /* This Will Select The BG Texture */
    glBindTexture( GL_TEXTURE_2D, texture[filter*2] );
    glPushMatrix();
        glTranslatef( 0.0f, 0.0f, -29.0f );
        glBegin( GL_QUADS );
            glNormal3f( 0.0f, 0.0f, 1.0f);
            glTexCoord2f( 0.0f, 0.0f ); glVertex3f( -13.3f, -10.0f,  10.0f );
            glTexCoord2f( 1.0f, 0.0f ); glVertex3f(  13.3f, -10.0f,  10.0f );
            glTexCoord2f( 1.0f, 1.0f ); glVertex3f(  13.3f,  10.0f,  10.0f );
            glTexCoord2f( 0.0f, 1.0f ); glVertex3f( -13.3f,  10.0f,  10.0f );
        glEnd();
    glPopMatrix();

    xrot += xspeed; /* Add xspeed To xrot */
    yrot += yspeed; /* Add yspeed To yrot */

    showFPS();
}

void MyGLWidget::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_I:
         filter = ( filter + 1 ) % 3;
         break;
    case Qt::Key_L:
        light = !light;
        if ( !light )
        glDisable( GL_LIGHTING );
        else
        glEnable( GL_LIGHTING );
        break;
    case Qt::Key_Space:
        object = ( object + 1 ) % 4;
        break;
    case Qt::Key_PageDown:
         z += 0.02f;
         break;
    case Qt::Key_PageUp:
         z -= 0.02f;
         break;
    case Qt::Key_Up:
        xspeed -= 0.01f;
        break;
    case Qt::Key_Down:
        xspeed += 0.01f;
        break;
    case Qt::Key_Left:
        yspeed -= 0.01f;
        break;
    case Qt::Key_Right:
        yspeed += 0.01f;
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
