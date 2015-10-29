#include "myglwidget.h"
#include <QTimer>
#include <QKeyEvent>
#include <QMessageBox>
#include <QApplication>
#include <QPainter>
#include <QDebug>
#include <GL/glu.h>

namespace {
    bool    twinkle;                        // Twinkling Stars
    bool    tp;                         // 'T' Key Pressed?
    const   int num = 50;                         // Number Of Stars To Draw

    typedef struct                          // Create A Structure For Star
    {
        int r, g, b;                        // Stars Color
        GLfloat dist;                       // Stars Distance From Center
        GLfloat angle;                      // Stars Current Angle
    }stars;                              // Structures Name Is Stars
    stars star[num];                    // Make 'star' Array Of 'num' Using Info From The Structure

    GLfloat zoom=-15.0f;                        // Viewing Distance Away From Stars
    GLfloat tilt=90.0f;                     // Tilt The View
    GLfloat spin;                           // Spin Twinkling Stars

    GLuint  loop;                           // General Loop Variable
    GLuint  texture[1];                     // Storage For One Texture
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
    setWindowTitle(tr("nehe----lesson09"));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer->start(10);
    fpsUpdater = QTime::currentTime();
    fpsUpdater.start();
}

void MyGLWidget::loadTextures()
{
    texture[0] = bindTexture(QString(":/Star.bmp"),
                                 GL_TEXTURE_2D,
                                 GL_RGBA);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // Linear Filtering
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // Linear Filtering
}

void MyGLWidget::initializeGL()
{
    loadTextures();
    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_SMOOTH);   // Enables Smooth Shading
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);  // Black Background
    glClearDepth(1.0f);             // Depth Buffer Setup
 //   glEnable(GL_DEPTH_TEST);        // Enables Depth Testing
 //   glDepthFunc(GL_LEQUAL);        // The Type Of Depth Test To Do
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Really Nice Perspective Calculations
    glBlendFunc(GL_SRC_ALPHA,GL_ONE);           // Set The Blending Function For Translucency
    glEnable(GL_BLEND);                 // Enable Blending

    for (loop=0; loop<num; loop++)               // Create A Loop That Goes Through All The Stars
    {
        star[loop].angle=0.0f;              // Start All The Stars At Angle Zero
        star[loop].dist=(float(loop)/num)*5.0f;     // Calculate Distance From The Center
        star[loop].r=rand()%256;            // Give star[loop] A Random Red Intensity
        star[loop].g=rand()%256;            // Give star[loop] A Random Green Intensity
        star[loop].b=rand()%256;            // Give star[loop] A Random Blue Intensity
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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Clear The Screen And The Depth Buffer
    glLoadIdentity();       // Reset The Current Modelview Matrix
    glBindTexture(GL_TEXTURE_2D, texture[0]);       // Select Our Texture

    for (loop=0; loop<num; loop++)               // Loop Through All The Stars
    {
        glLoadIdentity();               // Reset The View Before We Draw Each Star
        glTranslatef(0.0f,0.0f,zoom);           // Zoom Into The Screen (Using The Value In 'zoom')
        glRotatef(tilt,1.0f,0.0f,0.0f);         // Tilt The View (Using The Value In 'tilt')
        glRotatef(star[loop].angle,0.0f,1.0f,0.0f); // Rotate To The Current Stars Angle
        glTranslatef(star[loop].dist,0.0f,0.0f);    // Move Forward On The X Plane
        glRotatef(-star[loop].angle,0.0f,1.0f,0.0f);    // Cancel The Current Stars Angle
        glRotatef(-tilt,1.0f,0.0f,0.0f);        // Cancel The Screen Tilt

        if (twinkle)                    // Twinkling Stars Enabled
        {
            // Assign A Color Using Bytes
            glColor4ub(star[(num-loop)-1].r,star[(num-loop)-1].g,star[(num-loop)-1].b,255);
            glBegin(GL_QUADS);          // Begin Drawing The Textured Quad
                glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,-1.0f, 0.0f);
                glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,-1.0f, 0.0f);
                glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 0.0f);
                glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 0.0f);
            glEnd();                // Done Drawing The Textured Quad
        }

        glRotatef(spin,0.0f,0.0f,1.0f);         // Rotate The Star On The Z Axis
        // Assign A Color Using Bytes
        glColor4ub(star[loop].r,star[loop].g,star[loop].b,255);
        glBegin(GL_QUADS);              // Begin Drawing The Textured Quad
            glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,-1.0f, 0.0f);
            glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,-1.0f, 0.0f);
            glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 0.0f);
            glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 0.0f);
        glEnd();                    // Done Drawing The Textured Quad

        spin+=0.01f;                    // Used To Spin The Stars
        star[loop].angle += float(loop)/num;      // Changes The Angle Of A Star
        star[loop].dist -= 0.01f;             // Changes The Distance Of A Star

        if (star[loop].dist<0.0f)            // Is The Star In The Middle Yet
        {
           star[loop].dist += 5.0f;          // Move The Star 5 Units From The Center
           star[loop].r = rand()%256;        // Give It A New Red Value
           star[loop].g = rand()%256;        // Give It A New Green Value
           star[loop].b = rand()%256;        // Give It A New Blue Value
        }
    }
    showFPS();
}

void MyGLWidget::keyReleaseEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_T:
            tp = false;
            break;
    default:
        QGLWidget::keyReleaseEvent(e);
        break;
    }
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
    case Qt::Key_T:
            if (!tp) {
                tp = TRUE;
                twinkle = !twinkle;
            }
            break;
    case Qt::Key_Up:
        tilt -= 0.5f;
        break;
    case Qt::Key_Down:
        tilt += 0.5f;
        break;
    case Qt::Key_PageUp:
        zoom -= 0.2f;
        break;
    case Qt::Key_PageDown:
        zoom += 0.2f;
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
