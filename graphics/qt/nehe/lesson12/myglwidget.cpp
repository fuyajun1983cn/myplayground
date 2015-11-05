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

namespace {
    GLfloat     xrot = 0;             // X Rotation ( NEW )
    GLfloat     yrot = 0;             // Y Rotation ( NEW )

    GLuint      texture[1];       // Storage For One Texture ( NEW )

    QVector<QVector3D> vertices;
    QVector<QVector2D> texCoords;

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

          glVertexPointer(3, GL_FLOAT, 0, vertices.constData());
          glTexCoordPointer(2, GL_FLOAT, 0, texCoords.constData());

    }

    void drawObject()
    {
          glEnableClientState(GL_VERTEX_ARRAY);
          glEnableClientState(GL_TEXTURE_COORD_ARRAY);
          glDrawArrays(GL_QUADS, 0, vertices.size());
          glDisableClientState(GL_VERTEX_ARRAY);
          glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    }

    GLuint box, top;

    static GLfloat boxcol[5][3]=     // Array For Box Colors
    {
        // Bright:  Red, Orange, Yellow, Green, Blue
        {1.0f,0.0f,0.0f},{1.0f,0.5f,0.0f},{1.0f,1.0f,0.0f},{0.0f,1.0f,0.0f},{0.0f,1.0f,1.0f}
    };

    static GLfloat topcol[5][3]=     // Array For Top Colors
    {
        // Dark:  Red, Orange, Yellow, Green, Blue
        {.5f,0.0f,0.0f},{0.5f,0.25f,0.0f},{0.5f,0.5f,0.0f},{0.0f,0.5f,0.0f},{0.0f,0.5f,0.5f}
    };

    GLfloat LightAmbient[]= { 0.5f, 0.5f, 0.5f, 1.0f };             // Ambient Light Values ( NEW )
    GLfloat LightDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };              // Diffuse Light Values ( NEW )
    GLfloat LightPosition[]= { 0.0f, 0.0f, 2.0f, 1.0f };            // Light Position ( NEW )

    GLvoid BuildLists()             // Build Box Display List
    {
        box=glGenLists(2);          // Building Two Lists
        glNewList(box,GL_COMPILE);       // New Compiled box Display List
        glBegin(GL_QUADS);
            // Front Face
            glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
            glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
            glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);  // Top Right Of The Texture and Quad
            glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);  // Top Left Of The Texture and Quad
            // Back Face
            glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  // Bottom Right Of The Texture and Quad
            glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);  // Top Right Of The Texture and Quad
            glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);  // Top Left Of The Texture and Quad
            glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);  // Bottom Left Of The Texture and Quad
            // Top Face
            glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);  // Top Left Of The Texture and Quad
            glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
            glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
            glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);  // Top Right Of The Texture and Quad
            // Bottom Face
            glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  // Top Right Of The Texture and Quad
            glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);  // Top Left Of The Texture and Quad
            glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
            glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
            // Right face
            glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);  // Bottom Right Of The Texture and Quad
            glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);  // Top Right Of The Texture and Quad
            glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);  // Top Left Of The Texture and Quad
            glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
            // Left Face
            glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  // Bottom Left Of The Texture and Quad
            glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
            glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);  // Top Right Of The Texture and Quad
            glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);  // Top Left Of The Texture and Quad
        glEnd();
        glEndList();

        top = box + 1;
        glNewList(top,GL_COMPILE);
        // Top Face
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);  // Top Left Of The Texture and Quad
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);  // Top Right Of The Texture and Quad
        glEndList();

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
    texture[0] = bindTexture(QString(":/Cube.bmp"),
                             GL_TEXTURE_2D,
                             GL_RGBA);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // Linear Filtering
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // Linear Filtering
}

MyGLWidget::MyGLWidget(QWidget *parent) :
    QGLWidget(parent), fullscreen(false)
{
    setWindowTitle(tr("nehe----lesson12"));
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
    BuildLists();
    glEnable(GL_TEXTURE_2D);    // Enable Texture Mapping ( NEW )

    glShadeModel(GL_SMOOTH);   // Enables Smooth Shading
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);  // Black Background
    glClearDepth(1.0f);             // Depth Buffer Setup
    glEnable(GL_DEPTH_TEST);        // Enables Depth Testing
    glDepthFunc(GL_LEQUAL);        // The Type Of Depth Test To Do
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Really Nice Perspective Calculations

    glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);             // Setup The Ambient Light
    glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);
    glLightfv(GL_LIGHT1, GL_POSITION,LightPosition);            // Position The Light
    glEnable(GL_LIGHT1);                            // Enable Light One
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);   //important !
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
    glTranslatef(0.0f,0.0f,-5.0f);       // Move Into The Screen 5 Units

    glBindTexture(GL_TEXTURE_2D, texture[0]);       // Select Our Texture

    for (int yloop=1;yloop<6;yloop++) {
        for (int xloop=0;xloop<yloop;xloop++) {
            glLoadIdentity();
            glTranslatef(1.4f+(float(xloop)*2.8f)-(float(yloop)*1.4f),((6.0f-float(yloop))*2.4f)-7.0f,-20.0f);
            glRotatef(45.0f-(2.0f*yloop)+xrot,1.0f,0.0f,0.0f);      // Tilt The Cubes Up And Down
            glRotatef(45.0f+yrot,0.0f,1.0f,0.0f);               // Spin Cubes Left And Right
            glColor3fv(boxcol[yloop-1]);                    // Select A Box Color
            glCallList(box);
            glColor3fv(topcol[yloop-1]);                    // Select The Top Color
            glCallList(top);                        // Draw The Top
        }
    }

    xrot += 0.3f;                             // X Axis Rotation
    yrot += 0.2f;                             // Y Axis Rotation

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
