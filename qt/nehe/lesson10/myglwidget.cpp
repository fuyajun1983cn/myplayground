#include "myglwidget.h"
#include <QTimer>
#include <QKeyEvent>
#include <QMessageBox>
#include <QApplication>
#include <QPainter>
#include <QDebug>
#include <GL/glu.h>
#include <math.h>

namespace {
    bool fp;			// F pressed?

    const float piover180 = 0.0174532925f;
    float heading;
    float xpos;
    float zpos;

    GLfloat	yrot;                   // Y Rotation
    GLfloat walkbias = 0;
    GLfloat walkbiasangle = 0;
    GLfloat lookupdown = 0.0f;

    GLuint filter;			// Which filter to use
    GLuint texture[3];		// Storage for 3 textures

    typedef struct tagVERTEX
    {
        float x, y, z;
        float u, v;
    } VERTEX;

    typedef struct tagTRIANGLE
    {
        VERTEX vertex[3];
    } TRIANGLE;

    typedef struct tagSECTOR
    {
        int numtriangles;
        TRIANGLE* triangle;
    } SECTOR;

    SECTOR sector1;         // Our model goes here:

    const char* readstr(QFile &f)
   {
       QByteArray line = f.readLine();

       while (line.at(0) == '/' || line.at(0) == '\n') {
           line = f.readLine();
       }
       return line.constData();
   }

   void SetupWorld()
   {
       float x, y, z, u, v;
       int numtriangles;

       const char *oneline;

       QFile filein(":/World.txt");
       if (!filein.open(QIODevice::ReadOnly | QIODevice::Text)) {
           qDebug("failed to open file");
       } else {
           qDebug("open file successfully");
       }

       oneline = readstr(filein);
       sscanf(oneline, "NUMPOLLIES %d\n", &numtriangles);

       sector1.triangle = new TRIANGLE[numtriangles];
       sector1.numtriangles = numtriangles;
       for (int loop = 0; loop < numtriangles; loop++)
       {
           for (int vert = 0; vert < 3; vert++)
           {
               oneline = readstr(filein);
               sscanf(oneline, "%f %f %f %f %f", &x, &y, &z, &u, &v);
               sector1.triangle[loop].vertex[vert].x = x;
               sector1.triangle[loop].vertex[vert].y = y;
               sector1.triangle[loop].vertex[vert].z = z;
               sector1.triangle[loop].vertex[vert].u = u;
               sector1.triangle[loop].vertex[vert].v = v;
           }
       }
       filein.close();
       return;
   }
}

void MyGLWidget::loadTextures()
{
    QImage image;
    if (image.load(":/Mud.bmp")) {
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
    setWindowTitle(tr("nehe----lesson10"));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer->start(10);
    fpsUpdater = QTime::currentTime();
    fpsUpdater.start();
}

void MyGLWidget::initializeGL()
{
    SetupWorld();
    loadTextures();
    glShadeModel(GL_SMOOTH);   // Enables Smooth Shading
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);  // Black Background
    glClearDepth(1.0f);             // Depth Buffer Setup
    glEnable(GL_DEPTH_TEST);        // Enables Depth Testing
    glDepthFunc(GL_LEQUAL);        // The Type Of Depth Test To Do
    glEnable(GL_TEXTURE_2D);
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
    //glOrtho(0.0f,width,0,height,-1.0f,1.0f);

    glMatrixMode(GL_MODELVIEW);      // Select The Modelview Matrix
    glLoadIdentity();                // Reset The Modelview Matrix

}

void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     // Clear the screen and the depth buffer
    glLoadIdentity();                   // Reset the view

    GLfloat x_m, y_m, z_m, u_m, v_m;
    GLfloat xtrans = -xpos;
    GLfloat ztrans = -zpos;
    GLfloat ytrans = -walkbias-0.25f;
    GLfloat sceneroty = 360.0f - yrot;

    int numtriangles;

    glRotatef(lookupdown,1.0f,0,0);
    glRotatef(sceneroty,0,1.0f,0);

    glTranslatef(xtrans, ytrans, ztrans);
    glBindTexture(GL_TEXTURE_2D, texture[filter]);

    numtriangles = sector1.numtriangles;

    // Process each triangle
    for (int loop_m = 0; loop_m < numtriangles; loop_m++)
    {
        glBegin(GL_TRIANGLES);
            glNormal3f( 0.0f, 0.0f, 1.0f);
            x_m = sector1.triangle[loop_m].vertex[0].x;
            y_m = sector1.triangle[loop_m].vertex[0].y;
            z_m = sector1.triangle[loop_m].vertex[0].z;
            u_m = sector1.triangle[loop_m].vertex[0].u;
            v_m = sector1.triangle[loop_m].vertex[0].v;
            glTexCoord2f(u_m,v_m); glVertex3f(x_m,y_m,z_m);

            x_m = sector1.triangle[loop_m].vertex[1].x;
            y_m = sector1.triangle[loop_m].vertex[1].y;
            z_m = sector1.triangle[loop_m].vertex[1].z;
            u_m = sector1.triangle[loop_m].vertex[1].u;
            v_m = sector1.triangle[loop_m].vertex[1].v;
            glTexCoord2f(u_m,v_m); glVertex3f(x_m,y_m,z_m);

            x_m = sector1.triangle[loop_m].vertex[2].x;
            y_m = sector1.triangle[loop_m].vertex[2].y;
            z_m = sector1.triangle[loop_m].vertex[2].z;
            u_m = sector1.triangle[loop_m].vertex[2].u;
            v_m = sector1.triangle[loop_m].vertex[2].v;
            glTexCoord2f(u_m,v_m); glVertex3f(x_m,y_m,z_m);
        glEnd();
    }

    showFPS();
}

void MyGLWidget::keyReleaseEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_I:
        fp = false;
        break;
    default:
        QGLWidget::keyReleaseEvent(e);
    }
}

void MyGLWidget::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_I:
        fp = true;
        filter += 1;
        if (filter > 2)
            filter = 0;
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
    case Qt::Key_Right:
        yrot -= 1.5f;
        break;
    case Qt::Key_Left:
        yrot += 1.5f;
        break;
    case Qt::Key_Up:
        xpos -= (float)sin(heading*piover180) * 0.05f;          // Move On The X-Plane Based On Player Direction
        zpos -= (float)cos(heading*piover180) * 0.05f;          // Move On The Z-Plane Based On Player Direction
        if (walkbiasangle >= 359.0f)                 // Is walkbiasangle>=359?
        {
            walkbiasangle = 0.0f;                   // Make walkbiasangle Equal 0
        }
        else                                // Otherwise
        {
             walkbiasangle+= 10;                    // If walkbiasangle < 359 Increase It By 10
        }
        walkbias = (float)sin(walkbiasangle * piover180)/20.0f;     // Causes The Player To Bounce
        break;
    case Qt::Key_Down:
        xpos += (float)sin(heading*piover180) * 0.05f;          // Move On The X-Plane Based On Player Direction
        zpos += (float)cos(heading*piover180) * 0.05f;          // Move On The Z-Plane Based On Player Direction
        if (walkbiasangle <= 1.0f)                   // Is walkbiasangle<=1?
        {
            walkbiasangle = 359.0f;                 // Make walkbiasangle Equal 359
        }
        else                                // Otherwise
        {
            walkbiasangle-= 10;                 // If walkbiasangle > 1 Decrease It By 10
        }
        walkbias = (float)sin(walkbiasangle * piover180)/20.0f;     // Causes The Player To Bounce
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
