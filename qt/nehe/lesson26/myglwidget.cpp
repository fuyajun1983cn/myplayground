#include "myglwidget.h"
#include <QTimer>
#include <QKeyEvent>
#include <QMessageBox>
#include <QApplication>
#include <QPainter>
#include <QDebug>

#include <GL/glu.h>

namespace
{
    // Light Parameters
    static GLfloat	LightAmb[] = {0.7f, 0.7f, 0.7f, 1.0f};				// Ambient Light
    static GLfloat	LightDif[] = {1.0f, 1.0f, 1.0f, 1.0f};				// Diffuse Light
    static GLfloat	LightPos[] = {4.0f, 4.0f, 6.0f, 1.0f};				// Light Position

    GLUquadricObj	*q;								// Quadratic For Drawing A Sphere

    GLfloat		xrot		=  0.0f;					// X Rotation
    GLfloat		yrot		=  0.0f;					// Y Rotation
    GLfloat		xrotspeed	=  0.0f;					// X Rotation Speed
    GLfloat		yrotspeed	=  0.0f;					// Y Rotation Speed
    GLfloat		zoom		= -7.0f;					// Depth Into The Screen
    GLfloat		heightOfBall=  2.0f;					// Height Of Ball From Floor

    GLuint		texture[3];							// 3 Textures

    void drawObject()
    {
        glColor3f(1.0f, 1.0f, 1.0f);						// Set Color To White
        glBindTexture(GL_TEXTURE_2D, texture[1]);				// Select Texture 2 (1)
        gluSphere(q, 0.35f, 32, 16);						// Draw First Sphere

        glBindTexture(GL_TEXTURE_2D, texture[2]);				// Select Texture 3 (2)
        glColor4f(1.0f, 1.0f, 1.0f, 0.4f);					// Set Color To White With 40% Alpha
        glEnable(GL_BLEND);							// Enable Blending
        glBlendFunc(GL_SRC_ALPHA, GL_ONE);					// Set Blending Mode To Mix Based On SRC Alpha
        glEnable(GL_TEXTURE_GEN_S);						// Enable Sphere Mapping
        glEnable(GL_TEXTURE_GEN_T);						// Enable Sphere Mapping

        gluSphere(q, 0.35f, 32, 16);						// Draw Another Sphere Using New Texture
                                            // Textures Will Mix Creating A MultiTexture Effect (Reflection)
        glDisable(GL_TEXTURE_GEN_S);						// Disable Sphere Mapping
        glDisable(GL_TEXTURE_GEN_T);						// Disable Sphere Mapping
        glDisable(GL_BLEND);							// Disable Blending
    }

    void DrawFloor()								// Draws The Floor
    {
        glBindTexture(GL_TEXTURE_2D, texture[0]);				// Select Texture 1 (0)
        glBegin(GL_QUADS);							// Begin Drawing A Quad
            glNormal3f(0.0, 1.0, 0.0);					// Normal Pointing Up
            glTexCoord2f(0.0f, 1.0f);					// Bottom Left Of Texture
            glVertex3f(-2.0, 0.0, 2.0);					// Bottom Left Corner Of Floor

            glTexCoord2f(0.0f, 0.0f);					// Top Left Of Texture
            glVertex3f(-2.0, 0.0,-2.0);					// Top Left Corner Of Floor

            glTexCoord2f(1.0f, 0.0f);					// Top Right Of Texture
            glVertex3f( 2.0, 0.0,-2.0);					// Top Right Corner Of Floor

            glTexCoord2f(1.0f, 1.0f);					// Bottom Right Of Texture
            glVertex3f( 2.0, 0.0, 2.0);					// Bottom Right Corner Of Floor
        glEnd();								// Done Drawing The Quad
    }
}

void MyGLWidget::loadTextures()
{
    QImage image;
    glGenTextures(3, texture);
    if (image.load(":/Envwall.bmp")) {
        image =  convertToGLFormat(image);
        glBindTexture(GL_TEXTURE_2D, texture[0]);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.width(), image.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.bits());
    }

    if (image.load(":/Ball.bmp")) {
        image =  convertToGLFormat(image);
        glBindTexture(GL_TEXTURE_2D, texture[1]);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.width(), image.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.bits());
    }

    if (image.load(":/Envball.bmp")) {
        image =  convertToGLFormat(image);
        glBindTexture(GL_TEXTURE_2D, texture[2]);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.width(), image.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.bits());
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

MyGLWidget::MyGLWidget(QWidget *parent) :
    QGLWidget(parent), fullscreen(false)
{
    setWindowTitle(tr("nehe----lesson26"));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer->start(10);
    fpsUpdater = QTime::currentTime();
    fpsUpdater.start();
}

void MyGLWidget::initializeGL()
{
    loadTextures();
    glShadeModel(GL_SMOOTH);   // Enables Smooth Shading
    glClearColor(0.2f, 0.5f, 1.0f, 1.0f);  //  Background
    glClearDepth(1.0f);             // Depth Buffer Setup
    glEnable(GL_DEPTH_TEST);        // Enables Depth Testing
    glDepthFunc(GL_LEQUAL);        // The Type Of Depth Test To Do
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Really Nice Perspective Calculations
    glEnable(GL_TEXTURE_2D);

    glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmb);				// Set The Ambient Lighting For Light0
    glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDif);				// Set The Diffuse Lighting For Light0
    glLightfv(GL_LIGHT0, GL_POSITION, LightPos);				// Set The Position For Light0

    glEnable(GL_LIGHT0);							// Enable Light 0
    glEnable(GL_LIGHTING);							// Enable Lighting

    q = gluNewQuadric();							// Create A New Quadratic
    gluQuadricNormals(q, GL_SMOOTH);                // Generate Smooth Normals For The Quad
    gluQuadricTexture(q, GL_TRUE);                  // Enable Texture Coords For The Quad

    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);			// Set Up Sphere Mapping
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);			// Set Up Sphere Mapping


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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);  // Clear The Screen And The Depth Buffer
    glLoadIdentity();       // Reset The Current Modelview Matrix

    // Clip Plane Equations
    double eqr[] = {0.0f,-1.0f, 0.0f, 0.0f};				// Plane Equation To Use For The Reflected
    glTranslatef(0.0f, -0.6f, zoom);					// Zoom And Raise Camera Above The Floor (Up 0.6 Units)
    glColorMask(0,0,0,0);							// Set Color Mask

    glEnable(GL_STENCIL_TEST);						// Enable Stencil Buffer For "marking" The Floor
    glStencilFunc(GL_ALWAYS, 1, 1);						// Always Passes, 1 Bit Plane, 1 As Mask
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);				// We Set The Stencil Buffer To 1 Where We Draw Any Polygon
                                        // Keep If Test Fails, Keep If Test Passes But Buffer Test Fails
                                        // Replace If Test Passes
    glDisable(GL_DEPTH_TEST);						// Disable Depth Testing
    DrawFloor();								// Draw The Floor (Draws To The Stencil Buffer)
                                        // We Only Want To Mark It In The Stencil B

    glEnable(GL_DEPTH_TEST);						// Enable Depth Testing
    glColorMask(1,1,1,1);							// Set Color Mask to TRUE, TRUE, TRUE, TRUE
    glStencilFunc(GL_EQUAL, 1, 1);                  // We Draw Only Where The Stencil Is 1
                                        // (I.E. Where The Floor Was Drawn)
    glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);					// Don't Change The Stencil Buffer
    glEnable(GL_CLIP_PLANE0);						// Enable Clip Plane For Removing Artifacts
                                        // (When The Object Crosses The Floor)
    glClipPlane(GL_CLIP_PLANE0, eqr);					// Equation For Reflected Objects
    glPushMatrix();								// Push The Matrix Onto The Stack
        glScalef(1.0f, -1.0f, 1.0f);					// Mirror Y Axis
        glLightfv(GL_LIGHT0, GL_POSITION, LightPos);			// Set Up Light0
        glTranslatef(0.0f, heightOfBall, 0.0f);				// Position The Object
        glRotatef(xrot, 1.0f, 0.0f, 0.0f);				// Rotate Local Coordinate System On X Axis
        glRotatef(yrot, 0.0f, 1.0f, 0.0f);				// Rotate Local Coordinate System On Y Axis
        drawObject();							// Draw The Sphere (Reflection)
    glPopMatrix();								// Pop The Matrix Off The Stack
    glDisable(GL_CLIP_PLANE0);						// Disable Clip Plane For Drawing The Floor
    glDisable(GL_STENCIL_TEST);						// We Don't Need The Stencil Buffer Any Mor

    glLightfv(GL_LIGHT0, GL_POSITION, LightPos);				// Set Up Light0 Position
    glEnable(GL_BLEND);							// Enable Blending (Otherwise The Reflected Object Wont Show)
    glDisable(GL_LIGHTING);							// Since We Use Blending, We Disable Lighting
    glColor4f(1.0f, 1.0f, 1.0f, 0.8f);					// Set Color To White With 80% Alpha
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);			// Blending Based On Source Alpha And 1 Minus Dest Alpha
    DrawFloor();								// Draw The Floor To The Screen

    glEnable(GL_LIGHTING);							// Enable Lighting
    glDisable(GL_BLEND);							// Disable Blending
    glTranslatef(0.0f, heightOfBall, 0.0f);					// Position The Ball At Proper Height
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);					// Rotate On The X Axis
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);					// Rotate On The Y Axis
    drawObject();								// Draw The Ball

    showFPS();
    xrot += xrotspeed;							// Update X Rotation Angle By xrotspeed
    yrot += yrotspeed;							// Update Y Rotation Angle By yrotspeed
    glFlush();								// Flush The GL Pipeline

}

void MyGLWidget::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_Right:
        xrotspeed += 0.08f;
        break;
    case Qt::Key_Left:
        xrotspeed -= 0.08f;
        break;
    case Qt::Key_Down:
        yrotspeed += 0.08f;
        break;
    case Qt::Key_Up:
        yrotspeed -= 0.08f;
        break;
    case Qt::Key_A:
        zoom += 0.05f;
        break;
    case Qt::Key_Z:
        zoom -= 0.05f;
        break;
    case Qt::Key_PageDown:
        heightOfBall -= 0.03f;
        break;
    case Qt::Key_PageUp:
        heightOfBall += 0.03f;
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
