#include "myglwidget.h"
#include <QTimer>
#include <QKeyEvent>
#include <QMessageBox>
#include <QApplication>
#include <QVector3D>
#include <QDebug>

#include <math.h>
#include <GL/glu.h>

namespace {
    struct BEZIER_PATCH
    {
        QVector3D anchors[4][4]; //Anchor Points
        GLuint dlBPatch;// Display List For Bezier Patch
        GLuint texture;
    };

    GLfloat         rotz = 0.0f;    // Rotation About The Z Axis
    BEZIER_PATCH        mybezier;
    bool      showCPoints = true;
    int       divs = 7;


    /*  Calculates 3rd degree polynomial based on array of 4 points */
    /*  and a single variable (u) which is generally between 0 and 1 */
    QVector3D Bernstein(float u, QVector3D *p) {
        QVector3D	a, b, c, d, r;

        a = p[0];
        a *= pow(u, 3);
        b = p[1];
        b *= 3*pow(u,2)*(1-u);
        c = p[2];
        c *= 3*u*pow((1-u),2);
        d = p[3];
        d *= pow((1-u),3);

        r = a + b + c + d;

        return r;
    }

    /*  Generates a display list based on the data in the patch */
    /*  and the number of divisions */
    GLuint genBezier(BEZIER_PATCH patch, int divs) {
        int			u = 0, v;
        float		py, px, pyold;
        GLuint		drawlist = glGenLists(1);		/*  make the display list */
        QVector3D	temp[4];
        QVector3D	*last = (QVector3D*)malloc(sizeof(QVector3D)*(divs+1));
                                                    /*  array of points to mark the first line of polys */

        if (patch.dlBPatch != 0)					/*  get rid of any old display lists */
            glDeleteLists(patch.dlBPatch, 1);

        temp[0] = patch.anchors[0][3];				/*  the first derived curve (along x axis) */
        temp[1] = patch.anchors[1][3];
        temp[2] = patch.anchors[2][3];
        temp[3] = patch.anchors[3][3];

        for (v=0;v<=divs;v++) {						/*  create the first line of points */
            px = ((float)v)/((float)divs);			/*  percent along y axis */
        /*  use the 4 points from the derives curve to calculate the points along that curve */
            last[v] = Bernstein(px, temp);
        }

        glNewList(drawlist, GL_COMPILE);				/*  Start a new display list */
        glBindTexture(GL_TEXTURE_2D, patch.texture);	/*  Bind the texture */

        for (u=1;u<=divs;u++) {
            py	  = ((float)u)/((float)divs);			/*  Percent along Y axis */
            pyold = ((float)u-1.0f)/((float)divs);		/*  Percent along old Y axis */

            temp[0] = Bernstein(py, patch.anchors[0]);	/*  Calculate new bezier points */
            temp[1] = Bernstein(py, patch.anchors[1]);
            temp[2] = Bernstein(py, patch.anchors[2]);
            temp[3] = Bernstein(py, patch.anchors[3]);

            glBegin(GL_TRIANGLE_STRIP);					/*  Begin a new triangle strip */

            for (v=0;v<=divs;v++) {
                px = ((float)v)/((float)divs);			/*  Percent along the X axis */

                glTexCoord2f(pyold, px);				/*  Apply the old texture coords */
                glVertex3d(last[v].x(), last[v].y(), last[v].z());	/*  Old Point */

                last[v] = Bernstein(px, temp);			/*  Generate new point */
                glTexCoord2f(py, px);					/*  Apply the new texture coords */
                glVertex3d(last[v].x(), last[v].y(), last[v].z());	/*  New Point */
            }

            glEnd();									/*  END the triangle srip */
        }

        glEndList();								/*  END the list */

        free(last);									/*  Free the old vertices array */
        return drawlist;							/*  Return the display list */
    }

    /************************************************************************************/

    void initBezier(void) {
        mybezier.anchors[0][0] = QVector3D(-0.75,	-0.75,	-0.5);	/*  set the bezier vertices */
        mybezier.anchors[0][1] = QVector3D(-0.25,	-0.75,	0.0);
        mybezier.anchors[0][2] = QVector3D(0.25,	-0.75,	0.0);
        mybezier.anchors[0][3] = QVector3D(0.75,	-0.75,	-0.5);
        mybezier.anchors[1][0] = QVector3D(-0.75,	-0.25,	-0.75);
        mybezier.anchors[1][1] = QVector3D(-0.25,	-0.25,	0.5);
        mybezier.anchors[1][2] = QVector3D(0.25,	-0.25,	0.5);
        mybezier.anchors[1][3] = QVector3D(0.75,	-0.25,	-0.75);
        mybezier.anchors[2][0] = QVector3D(-0.75,	0.25,	0.0);
        mybezier.anchors[2][1] = QVector3D(-0.25,	0.25,	-0.5);
        mybezier.anchors[2][2] = QVector3D(0.25,	0.25,	-0.5);
        mybezier.anchors[2][3] = QVector3D(0.75,	0.25,	0.0);
        mybezier.anchors[3][0] = QVector3D(-0.75,	0.75,	-0.5);
        mybezier.anchors[3][1] = QVector3D(-0.25,	0.75,	-1.0);
        mybezier.anchors[3][2] = QVector3D(0.25,	0.75,	-1.0);
        mybezier.anchors[3][3] = QVector3D(0.75,	0.75,	-0.5);
        mybezier.dlBPatch = 0;
    }

}

void MyGLWidget::loadTextures()
{
    QImage image;
    if (image.load(":/NeHe.bmp")) {
        image = convertToGLFormat(image);
        glGenTextures(1, &mybezier.texture);   /* create the texture */
        glBindTexture(GL_TEXTURE_2D, mybezier.texture);
        /* actually generate the texture */
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.width(), image.height(), 0,
            GL_RGBA, GL_UNSIGNED_BYTE, image.bits());
        /* enable linear filtering */
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
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
    setWindowTitle(tr("nehe----lesson28"));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer->start(10);
    fpsUpdater = QTime::currentTime();
    fpsUpdater.start();
}

void MyGLWidget::initializeGL()
{
    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_SMOOTH);   // Enables Smooth Shading
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);  // Black Background
    glClearDepth(1.0f);             // Depth Buffer Setup
    glEnable(GL_DEPTH_TEST);        // Enables Depth Testing
    glDepthFunc(GL_LEQUAL);        // The Type Of Depth Test To Do
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Really Nice Perspective Calculations

    initBezier();
    loadTextures();
    mybezier.dlBPatch = genBezier(mybezier, divs);

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
    glTranslatef(0.0f,0.0f,-4.0f);
    glRotatef(-75.0f,1.0f,0.0f,0.0f);
    glRotatef(rotz,0.0f,0.0f,1.0f);
    glCallList(mybezier.dlBPatch);

    if (showCPoints) {
        glDisable(GL_TEXTURE_2D);
        glColor3f(1.0f,0.0f,0.0f);
        for(int i=0;i<4;i++) {				/*  draw the horizontal lines */
            glBegin(GL_LINE_STRIP);
            for(int j=0;j<4;j++)
                glVertex3d(mybezier.anchors[i][j].x(), mybezier.anchors[i][j].y(), mybezier.anchors[i][j].z());
            glEnd();
        }
        for(int i=0;i<4;i++) {				/*  draw the vertical lines */
            glBegin(GL_LINE_STRIP);
            for(int j=0;j<4;j++)
                glVertex3d(mybezier.anchors[j][i].x(), mybezier.anchors[j][i].y(), mybezier.anchors[j][i].z());
            glEnd();
        }
        glColor3f(1.0f,1.0f,1.0f);
        glEnable(GL_TEXTURE_2D);
    }

    showFPS();
}

void MyGLWidget::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_Left:
         rotz -= 0.8f;
         break;
    case Qt::Key_Right:
        rotz += 0.8f;
        break;
    case Qt::Key_Up:
        divs++;				/*  Update the patch */
        mybezier.dlBPatch = genBezier(mybezier, divs);
        break;
    case Qt::Key_Down:
        divs--;
        mybezier.dlBPatch = genBezier(mybezier, divs);
        break;
    case Qt::Key_Space:
        showCPoints = !showCPoints;
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
