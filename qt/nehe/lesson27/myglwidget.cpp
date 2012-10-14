#include "myglwidget.h"
#include <QTimer>
#include <QKeyEvent>
#include <QMessageBox>
#include <QApplication>
#include <QVector3D>
#include <QVector4D>
#include <QMatrix4x4>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <GL/glu.h>

namespace
{
    // Definition Of "INFINITY" For Calculating The Extension Vector For The Shadow Volume
    const int INFINITY = 100;

    // Structure Describing An Object's Face
    struct Face
    {
        int vertexIndices[3];           // Index Of Each Vertex Within An Object That Makes Up The Triangle Of This Face
        QVector3D normals[3];         // Normals To Each Vertex
        QVector4D planeEquation;            // Equation Of A Plane That Contains This Triangle
        int neighbourIndices[3];        // Index Of Each Face That Neighbours This One Within The Object
        bool visible;               // Is The Face Visible By The Light?
    };

    struct ShadowedObject
    {
        int nVertices;
        QVector3D *pVertices;         // Will Be Dynamically Allocated

        int nFaces;
        Face *pFaces;               // Will Be Dynamically Allocated
    };

    ShadowedObject obj;									// Object
    GLfloat		xrot=0, xspeed=0;							// X Rotation & X Speed
    GLfloat		yrot=0, yspeed=0;							// Y Rotation & Y Speed

    float LightPos[] = { 0.0f, 5.0f,-4.0f, 1.0f};			// Light Position
    float LightAmb[] = { 0.2f, 0.2f, 0.2f, 1.0f};			// Ambient Light Values
    float LightDif[] = { 0.6f, 0.6f, 0.6f, 1.0f};			// Diffuse Light Values
    float LightSpc[] = {-0.2f, -0.2f, -0.2f, 1.0f};			// Specular Light Values

    float MatAmb[] = {0.4f, 0.4f, 0.4f, 1.0f};				// Material - Ambient Values
    float MatDif[] = {0.2f, 0.6f, 0.9f, 1.0f};				// Material - Diffuse Values
    float MatSpc[] = {0.0f, 0.0f, 0.0f, 1.0f};				// Material - Specular Values
    float MatShn[] = {0.0f};								// Material - Shininess

    float ObjPos[] = {-2.0f,-2.0f,-5.0f};					// Object Position

    GLUquadricObj	*q;										// Quadratic For Drawing A Sphere
    float SpherePos[] = {-4.0f,-5.0f,-6.0f};

    bool readObject( const QString &filename, ShadowedObject& object )
    {
        QFile file(filename);
        if (!file.open(QIODevice::ReadOnly)) {
            qDebug()<<"Unable to open the object file: "
                      <<file.errorString();
            return false;
        }
        QTextStream text(&file);
        text>>object.nVertices;
        qDebug()<<"nVertices: "<<object.nVertices;
        object.pVertices = new QVector3D[object.nVertices];
        for ( int i = 0; i < object.nVertices; i++ )
        {
            float x, y, z;
            text>>x>>y>>z;
            object.pVertices[i].setX(x);
            object.pVertices[i].setY(y);
            object.pVertices[i].setZ(z);
        }

        text>>object.nFaces;
        object.pFaces = new Face[object.nFaces];
        for ( int i = 0; i < object.nFaces; i++ )
        {
            int j;
            Face *pFace = &object.pFaces[i];

            for ( int j = 0; j < 3; j++ )
                pFace->neighbourIndices[j] = -1; // No Neigbours Set Up Yet

            for ( int j = 0; j < 3; j++ )
            {
                text>>pFace->vertexIndices[j];
                pFace->vertexIndices[j]--;       // Files Specify Them With A 1 Array Base, But We Use A 0 Array Base
            }

            for ( int j = 0; j < 3; j++ )
            {
                float x, y, z;
                text>>x>>y>>z;
                pFace->normals[j].setX(x);
                pFace->normals[j].setY(y);
                pFace->normals[j].setZ(z);
            }
        }
        return true;
    }

    void killObject( ShadowedObject& object )
    {
        delete[] object.pFaces;
        object.pFaces = NULL;
        object.nFaces = 0;

        delete[] object.pVertices;
        object.pVertices = NULL;
        object.nVertices = 0;
    }

    void SetConnectivity(ShadowedObject *o){
        unsigned int p1i, p2i, p1j, p2j;
        unsigned int P1i, P2i, P1j, P2j;
        unsigned int i,j,ki,kj;

        for(i=0;i<o->nFaces-1;i++)
            for(j=i+1;j<o->nFaces;j++)
                for(ki=0;ki<3;ki++)
                    if(!o->pFaces[i].neighbourIndices[ki]){
                        for(kj=0;kj<3;kj++){
                            p1i=ki;
                            p1j=kj;
                            p2i=(ki+1)%3;
                            p2j=(kj+1)%3;

                            p1i=o->pFaces[i].vertexIndices[p1i];
                            p2i=o->pFaces[i].vertexIndices[p2i];
                            p1j=o->pFaces[j].vertexIndices[p1j];
                            p2j=o->pFaces[j].vertexIndices[p2j];

                            P1i=((p1i+p2i)-abs(p1i-p2i))/2;
                            P2i=((p1i+p2i)+abs(p1i-p2i))/2;
                            P1j=((p1j+p2j)-abs(p1j-p2j))/2;
                            P2j=((p1j+p2j)+abs(p1j-p2j))/2;

                            if((P1i==P1j) && (P2i==P2j)){  //they are neighbours
                                o->pFaces[i].neighbourIndices[ki] = j+1;
                                o->pFaces[j].neighbourIndices[kj] = i+1;
                            }
                        }
                    }
    }

    // Draw An Object - Simply Draw Each Triangular Face.
    void drawObject( const ShadowedObject& object )
    {
        glBegin( GL_TRIANGLES );
        for ( int i = 0; i < object.nFaces; i++ )
        {
            const Face& face = object.pFaces[i];

            for ( int j = 0; j < 3; j++ )
            {
                const QVector3D& vertex = object.pVertices[face.vertexIndices[j]];

                glNormal3f( face.normals[j].x(), face.normals[j].y(), face.normals[j].z() );
                glVertex3f( vertex.x(), vertex.y(), vertex.z() );
            }
        }
        glEnd();
    }

    void calculatePlane( const ShadowedObject& object, Face& face )
    {
        // Get Shortened Names For The Vertices Of The Face
        const QVector3D& v1 = object.pVertices[face.vertexIndices[0]];
        const QVector3D& v2 = object.pVertices[face.vertexIndices[1]];
        const QVector3D& v3 = object.pVertices[face.vertexIndices[2]];

        face.planeEquation.setX(v1.y()*(v2.z()-v3.z()) + v2.y()*(v3.z()-v1.z()) + v3.y()*(v1.z()-v2.z()));
        face.planeEquation.setY(v1.z()*(v2.x()-v3.x()) + v2.z()*(v3.x()-v1.x()) + v3.z()*(v1.x()-v2.x()));
        face.planeEquation.setZ(v1.x()*(v2.y()-v3.y()) + v2.x()*(v3.y()-v1.y()) + v3.x()*(v1.y()-v2.y()));
        face.planeEquation.setW(-( v1.x()*( v2.y()*v3.z() - v3.y()*v2.z() ) +
                    v2.x()*(v3.y()*v1.z() - v1.y()*v3.z()) +
                    v3.x()*(v1.y()*v2.z() - v2.y()*v1.z()) ));
    }

    void doShadowPass( ShadowedObject& object, QVector4D lightPosition )
    {
        for ( int i = 0; i < object.nFaces; i++ )
        {
            const Face& face = object.pFaces[i];

            if ( face.visible )
            {
                // Go Through Each Edge
                for ( int j = 0; j < 3; j++ )
                {
                    int neighbourIndex = face.neighbourIndices[j];
                    // If There Is No Neighbour, Or Its Neighbouring Face Is Not Visible, Then This Edge Casts A Shadow
                    if ( neighbourIndex == -1 || object.pFaces[neighbourIndex].visible == false )
                    {
                        // Get The Points On The Edge
                        const QVector3D& v1 = object.pVertices[face.vertexIndices[j]];
                        const QVector3D& v2 = object.pVertices[face.vertexIndices[( j+1 )%3]];

                        // Calculate The Two Vertices In Distance
                        QVector3D v3, v4;

                        v3.setX(( v1.x()-lightPosition.x() )*INFINITY);
                        v3.setY(( v1.y()-lightPosition.y() )*INFINITY);
                        v3.setZ(( v1.z()-lightPosition.z() )*INFINITY);

                        v4.setX(( v2.x()-lightPosition.x() )*INFINITY);
                        v4.setY(( v2.y()-lightPosition.y() )*INFINITY);
                        v4.setZ(( v2.z()-lightPosition.z() )*INFINITY);

                        // Draw The Quadrilateral (As A Triangle Strip)
                        glBegin( GL_TRIANGLE_STRIP );
                            glVertex3f( v1.x(), v1.y(), v1.z() );
                            glVertex3f( v1.x()+v3.x(), v1.y()+v3.y(), v1.z()+v3.z() );
                            glVertex3f( v2.x(), v2.y(), v2.z() );
                            glVertex3f( v2.x()+v4.x(), v2.y()+v4.y(), v2.z()+v4.z() );
                        glEnd();
                    }
                }
            }
        }
    }

    void castShadow( ShadowedObject& object, QVector4D lightPosition )
    {
        // Determine Which Faces Are Visible By The Light.
        for ( int i = 0; i < object.nFaces; i++ )
        {
            const QVector4D& plane = object.pFaces[i].planeEquation;

            GLfloat side = plane.x()*lightPosition.x()+
                plane.y()*lightPosition.y()+
                plane.z()*lightPosition.z()+
                plane.w();

            if ( side > 0 )
                object.pFaces[i].visible = true;
            else
                object.pFaces[i].visible = false;
        }

        glPushAttrib( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_ENABLE_BIT | GL_POLYGON_BIT | GL_STENCIL_BUFFER_BIT );
        glDisable( GL_LIGHTING );					// Turn Off Lighting
        glDepthMask( GL_FALSE );					// Turn Off Writing To The Depth-Buffer
        glDepthFunc( GL_LEQUAL );
        glEnable( GL_STENCIL_TEST );					// Turn On Stencil Buffer Testing
        glColorMask( GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE );		// Don't Draw Into The Colour Buffer
        glStencilFunc( GL_ALWAYS, 1, 0xFFFFFFFFL );

        // First Pass. Increase Stencil Value In The Shadow
        glFrontFace( GL_CCW );
        glStencilOp( GL_KEEP, GL_KEEP, GL_INCR );
        doShadowPass( object, lightPosition );
        // Second Pass. Decrease Stencil Value In The Shadow
        glFrontFace( GL_CW );
        glStencilOp( GL_KEEP, GL_KEEP, GL_DECR );
        doShadowPass( object, lightPosition );

        glFrontFace( GL_CCW );
        glColorMask( GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE );  // Enable Rendering To Colour Buffer For All Components

       // Draw A Shadowing Rectangle Covering The Entire Screen
       glColor4f( 0.0f, 0.0f, 0.0f, 0.4f );
       glEnable( GL_BLEND );
       glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
       glStencilFunc( GL_NOTEQUAL, 0, 0xFFFFFFFFL );
       glStencilOp( GL_KEEP, GL_KEEP, GL_KEEP );
       glPushMatrix();
       glLoadIdentity();
       glBegin( GL_TRIANGLE_STRIP );
           glVertex3f(-0.1f, 0.1f,-0.10f);
           glVertex3f(-0.1f,-0.1f,-0.10f);
           glVertex3f( 0.1f, 0.1f,-0.10f);
           glVertex3f( 0.1f,-0.1f,-0.10f);
       glEnd();
       glPopMatrix();
       glPopAttrib();
    }

    void DrawGLRoom()                           // Draw The Room (Box)
    {
        glBegin(GL_QUADS);                      // Begin Drawing Quads
            // Floor
            glNormal3f(0.0f, 1.0f, 0.0f);               // Normal Pointing Up
            glVertex3f(-10.0f,-10.0f,-20.0f);           // Back Left
            glVertex3f(-10.0f,-10.0f, 20.0f);           // Front Left
            glVertex3f( 10.0f,-10.0f, 20.0f);           // Front Right
            glVertex3f( 10.0f,-10.0f,-20.0f);           // Back Right
            // Ceiling
            glNormal3f(0.0f,-1.0f, 0.0f);               // Normal Point Down
            glVertex3f(-10.0f, 10.0f, 20.0f);           // Front Left
            glVertex3f(-10.0f, 10.0f,-20.0f);           // Back Left
            glVertex3f( 10.0f, 10.0f,-20.0f);           // Back Right
            glVertex3f( 10.0f, 10.0f, 20.0f);           // Front Right
            // Front Wall
            glNormal3f(0.0f, 0.0f, 1.0f);               // Normal Pointing Away From Viewer
            glVertex3f(-10.0f, 10.0f,-20.0f);           // Top Left
            glVertex3f(-10.0f,-10.0f,-20.0f);           // Bottom Left
            glVertex3f( 10.0f,-10.0f,-20.0f);           // Bottom Right
            glVertex3f( 10.0f, 10.0f,-20.0f);           // Top Right
            // Back Wall
            glNormal3f(0.0f, 0.0f,-1.0f);               // Normal Pointing Towards Viewer
            glVertex3f( 10.0f, 10.0f, 20.0f);           // Top Right
            glVertex3f( 10.0f,-10.0f, 20.0f);           // Bottom Right
            glVertex3f(-10.0f,-10.0f, 20.0f);           // Bottom Left
            glVertex3f(-10.0f, 10.0f, 20.0f);           // Top Left
            // Left Wall
            glNormal3f(1.0f, 0.0f, 0.0f);               // Normal Pointing Right
            glVertex3f(-10.0f, 10.0f, 20.0f);           // Top Front
            glVertex3f(-10.0f,-10.0f, 20.0f);           // Bottom Front
            glVertex3f(-10.0f,-10.0f,-20.0f);           // Bottom Back
            glVertex3f(-10.0f, 10.0f,-20.0f);           // Top Back
            // Right Wall
            glNormal3f(-1.0f, 0.0f, 0.0f);              // Normal Pointing Left
            glVertex3f( 10.0f, 10.0f,-20.0f);           // Top Back
            glVertex3f( 10.0f,-10.0f,-20.0f);           // Bottom Back
            glVertex3f( 10.0f,-10.0f, 20.0f);           // Bottom Front
            glVertex3f( 10.0f, 10.0f, 20.0f);           // Top Front
        glEnd();                            // Done Drawing Quads
    }

    void VMatMult(QMatrix4x4 MM, QVector4D v)
    {
        GLfloat res[4];                        // Hold Calculated Results
        qreal *M = MM.data();
        res[0]=M[ 0]*v.x()+M[4]*v.y()+M[ 8]*v.z()+M[12]*v.w();
        res[1]=M[ 1]*v.x()+M[5]*v.y()+M[ 9]*v.z()+M[13]*v.w();
        res[2]=M[ 2]*v.x()+M[6]*v.y()+M[10]*v.z()+M[14]*v.w();
        res[3]=M[ 3]*v.x()+M[7]*v.y()+M[11]*v.z()+M[15]*v.w();
        v.setX(res[0]);                            // Results Are Stored Back In v[]
        v.setY(res[1]);
        v.setZ(res[2]);
        v.setW(res[3]);                            // Homogenous Coordinate
    }

    bool InitGLObjects()                         // Initialize Objects
    {
        if (!readObject(":/data/Object1.txt", obj))           // Read Object2 Into obj
        {
            return false;                       // If Failed Return False
        }

        SetConnectivity(&obj);                       // Set Face To Face Connectivity

        for ( int i=0;i < obj.nFaces;i++)                // Loop Through All Object Faces
            calculatePlane(obj, obj.pFaces[i]);         // Compute Plane Equations For All Faces

        return true;                            // Return True
    }

    void KillGLObjects()
    {
        killObject( obj );
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
    setWindowTitle(tr("nehe----lesson27"));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer->start(10);
    fpsUpdater = QTime::currentTime();
    fpsUpdater.start();
}

MyGLWidget::~MyGLWidget()
{
    KillGLObjects();
}

void MyGLWidget::initializeGL()
{
    if (!InitGLObjects()) {
        qDebug("Failed to init gl objects!");
        return;
    }
    glShadeModel(GL_SMOOTH);   // Enables Smooth Shading
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);  // Black Background
    glClearDepth(1.0f);             // Depth Buffer Setup
    glClearStencil(0);
    glEnable(GL_DEPTH_TEST);        // Enables Depth Testing
    glDepthFunc(GL_LEQUAL);        // The Type Of Depth Test To Do
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Really Nice Perspective Calculations

    glLightfv(GL_LIGHT1, GL_POSITION, LightPos);		// Set Light1 Position
    glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmb);			// Set Light1 Ambience
    glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDif);			// Set Light1 Diffuse
    glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpc);		// Set Light1 Specular
    glEnable(GL_LIGHT1);								// Enable Light1
    glEnable(GL_LIGHTING);								// Enable Lighting

    glMaterialfv(GL_FRONT, GL_AMBIENT, MatAmb);			// Set Material Ambience
    glMaterialfv(GL_FRONT, GL_DIFFUSE, MatDif);			// Set Material Diffuse
    glMaterialfv(GL_FRONT, GL_SPECULAR, MatSpc);		// Set Material Specular
    glMaterialfv(GL_FRONT, GL_SHININESS, MatShn);		// Set Material Shininess

    glCullFace(GL_BACK);								// Set Culling Face To Back Face
    glEnable(GL_CULL_FACE);								// Enable Culling
    glClearColor(0.1f, 1.0f, 0.5f, 1.0f);				// Set Clear Color (Greenish Color)

    q = gluNewQuadric();								// Initialize Quadratic
    gluQuadricNormals(q, GL_SMOOTH);					// Enable Smooth Normal Generation
    gluQuadricTexture(q, GL_FALSE);						// Disable Auto Texture Coords

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
 //   glOrtho(0.0f,width,0,height,-1.0f,1.0f);

    glMatrixMode(GL_MODELVIEW);      // Select The Modelview Matrix
    glLoadIdentity();                // Reset The Modelview Matrix

}

void MyGLWidget::paintGL()
{
    QMatrix4x4 Minv;
    QVector4D wlp, lp;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);  // Clear The Screen And The Depth Buffer

    glLoadIdentity();                       // Reset Modelview Matrix
    glTranslatef(0.0f, 0.0f, -20.0f);               // Zoom Into Screen 20 Units
    glLightfv(GL_LIGHT1, GL_POSITION, LightPos);            // Position Light1
    glTranslatef(SpherePos[0], SpherePos[1], SpherePos[2]);     // Position The Sphere
    gluSphere(q, 1.5f, 32, 16);                 // Draw A Sphere

    glLoadIdentity();                       // Reset Matrix
    glRotatef(-yrot, 0.0f, 1.0f, 0.0f);             // Rotate By -yrot On Y Axis
    glRotatef(-xrot, 1.0f, 0.0f, 0.0f);             // Rotate By -xrot On X Axis
    GLfloat *temp = (GLfloat*)Minv.data();
    glGetFloatv(GL_MODELVIEW_MATRIX, temp);              // Retrieve ModelView Matrix (Stores In Minv)
    lp.setX(LightPos[0]);                        // Store Light Position X In lp[0]
    lp.setY(LightPos[1]);                        // Store Light Position Y In lp[1]
    lp.setZ(LightPos[2]);                        // Store Light Position Z In lp[2]
    lp.setW(LightPos[3]);                        // Store Light Direction In lp[3]
    VMatMult(Minv, lp);                     // We Store Rotated Light Vector In 'lp' Array
    glTranslatef(-ObjPos[0], -ObjPos[1], -ObjPos[2]);       // Move Negative On All Axis Based On ObjPos[] Values (X, Y, Z)
    temp = (GLfloat*)Minv.data();
    glGetFloatv(GL_MODELVIEW_MATRIX, temp);
    wlp.setX(0.0f);										// World Local Coord X To 0
    wlp.setY(0.0f);										// World Local Coord Y To 0
    wlp.setZ(0.0f);										// World Local Coord Z To 0
    wlp.setW(1.0f);
    VMatMult(Minv, wlp);

    lp.setX(lp.x() + wlp.x());
    lp.setY(lp.y() + wlp.y());
    lp.setZ(lp.z() + wlp.z());
    lp.setW(lp.w() + wlp.w());

    glColor4f(0.7f, 0.4f, 0.0f, 1.0f);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -20.0f);
    DrawGLRoom();
    glTranslatef(ObjPos[0], ObjPos[1], ObjPos[2]);
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
    drawObject(obj);
    castShadow(obj, lp);

    glColor4f(0.7f, 0.4f, 0.0f, 1.0f);              // Set Color To An Orange
    glDisable(GL_LIGHTING);                     // Disable Lighting
    glDepthMask(GL_FALSE);                      // Disable Depth Mask
    glTranslatef(lp.x(), lp.y(), lp.z());              // Translate To Light's Position
                                    // Notice We're Still In Local Coordinate System
    gluSphere(q, 0.2f, 16, 8);                  // Draw A Little Yellow Sphere (Represents Light)
    glEnable(GL_LIGHTING);                      // Enable Lighting
    glDepthMask(GL_TRUE);                       // Enable Depth Mask

    xrot += xspeed;                         // Increase xrot By xspeed
    yrot += yspeed;                         // Increase yrot By yspeed

    glFlush();                          // Flush The OpenGL Pipeline

    showFPS();
}

void MyGLWidget::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_Left:
        yspeed -= 0.1f;
        break;
    case Qt::Key_Right:
        yspeed += 0.1f;
        break;
    case Qt::Key_Up:
        xspeed -= 0.1f;
        break;
    case Qt::Key_Down:
        xspeed += 0.1f;
        break;
    case Qt::Key_L:
        LightPos[0] += 0.05f;
        break;
    case Qt::Key_J:
        LightPos[0] -= 0.05f;
        break;
    case Qt::Key_I:
        LightPos[1] += 0.05f;
        break;
    case Qt::Key_K:
        LightPos[1] -= 0.05f;
        break;
    case Qt::Key_O:
        LightPos[2] += 0.05f;
        break;
    case Qt::Key_U:
        LightPos[2] -= 0.05f;
        break;
    case Qt::Key_6:
        ObjPos[0] += 0.05f;
        break;
    case Qt::Key_4:
        ObjPos[0] -= 0.05f;
        break;
    case Qt::Key_8:
        ObjPos[1] += 0.05f;
        break;
    case Qt::Key_5:
        ObjPos[1] -= 0.05f;
        break;
    case Qt::Key_9:
        ObjPos[2] += 0.05f;
        break;
    case Qt::Key_7:
        ObjPos[2] -= 0.05f;
        break;
    case Qt::Key_D:
        SpherePos[0] += 0.05f;
        break;
    case Qt::Key_A:
        SpherePos[0] -= 0.05f;
        break;
    case Qt::Key_W:
        SpherePos[1] += 0.05f;
        break;
    case Qt::Key_S:
        SpherePos[1] -= 0.05f;
        break;
    case Qt::Key_E:
        SpherePos[2] += 0.05f;
        break;
    case Qt::Key_Q:
        SpherePos[2] -= 0.05f;
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
