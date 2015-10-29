#include "myglwidget.h"
#include <QTimer>
#include <QKeyEvent>
#include <QMessageBox>
#include <QApplication>
#include <QVector3D>
#include <qmath.h>
#include <QDebug>
#include <GL/glu.h>

namespace {
    #define EPSILON 1.0e-8

    #define ZERO EPSILON

    #define M_PI 3.1415926535

    GLfloat spec[]={1.0, 1.0 ,1.0 ,1.0};      //sets specular highlight of balls
    GLfloat posl[]={0,400,0,1};               //position of ligth source
    GLfloat amb[]={0.2f, 0.2f, 0.2f ,1.0f};   //global ambient
    GLfloat amb2[]={0.3f, 0.3f, 0.3f ,1.0f};  //ambient of lightsource

    QVector3D init_dir(0,0,-10);                     //initial direction of camera
    QVector3D init_pos(0,-50,1000);                  //initial position of camera
    float camera_rotation=0;                  //holds rotation around the Y axis

    QVector3D veloc(0.5,-0.1,0.5);              //initial velocity of balls
    QVector3D accel(0,-0.05,0);                 //acceleration ie. gravity of balls

    QVector3D ArrayVel[10];                     //holds velocity of balls
    QVector3D ArrayPos[10];                     //position of balls
    QVector3D OldPos[10];                       //old position of balls
    int NrOfBalls;                            //sets the number of balls
    double TimeStep=0.6;                          //timestep of simulation
    int hook_toball1=0, sounds=1;             //hook camera on ball, and sound on/off

    struct Plane
    {
        QVector3D _Normal; //平面法线
        QVector3D _Position; //平面中的某点
    };

    //Cylinder structure
    struct Cylinder{
        QVector3D _Position;
        QVector3D _Axis;
        double _Radius;
    };

    class Ray {
    private:
        QVector3D _P;//any point in the line
        QVector3D _V;//direction of the line

    public:
        Ray() {}
        Ray(const QVector3D &point1, const QVector3D &point2)
            :_P(point1)
        {
            if (point2.length() == 1)
                _V = point2;
            else
                _V = point2.normalized();
        }

        // Selectors
        QVector3D P() const { return _P; }
        QVector3D V() const { return _V; }
        int isValid() const
        {
            if (V().length() == 1 && !P().isNull())
                return true;
            return false;
        }

        bool adjacentPoints(const Ray &ray, QVector3D &point1, QVector3D &point2) const
        {
            if (isValid() && ray.isValid()) {
                double temp = QVector3D::dotProduct(_V, ray.V());//两射线的余弦值
                double temp2 = 1.0 - qSqrt(temp);//正弦的平方值

                QVector3D tv;

                //判断两线是否平行
                if (qAbs(temp2) < EPSILON) {
                    double mu = QVector3D::dotProduct(_V, _P - ray.P())/temp;
                    point1 = _P;
                    tv = ray.P() + ray.V() * mu;
                } else {
                    tv = ray.P() - P();
                    double a = QVector3D::dotProduct(_V, tv);
                    tv = P() - ray.P();
                    double b = QVector3D::dotProduct(ray.V(), tv);
                    double mu = (b + temp * a) / temp2;
                    double lambda = (a + temp*b)/temp2;
                    tv = _V * lambda;
                    point1 = _P + tv;
                    tv = ray.V() * mu;
                    point2 = ray.P() + tv;
                }
                return true;
            }
            return false;
        }

        //两线之间的距离
        double dist(const Ray &ray) const
        {
            QVector3D point1, point2;
            if (adjacentPoints(ray, point1, point2)) {
                QVector3D results = point1 - point2;
                return results.length();
            }
            return 0;
        }

        //点与线之间的距离
        double dist(const QVector3D &point) const {
            if (isValid() && !point.isNull()) {
                QVector3D tv, point2;
                double lambda = QVector3D::dotProduct(_V, point - _P);
                tv = _V * lambda;
                point2 = _P + tv;
                return (point - point2).length();
            }
            return 0;
        }
    };

    //Explosion structure
    struct Explosion {
        QVector3D _Position;
        float   _Alpha;
        float   _Scale;
    };

    Plane pl1,pl2,pl3,pl4,pl5;                //the 5 planes of the room
    Cylinder cyl1,cyl2,cyl3;                  //the 2 cylinders of the room
    GLUquadricObj *cylinder_obj;              //Quadratic object to render the cylinders
    GLuint texture[4], dlist;                 //stores texture objects and display list
    Explosion ExplosionArray[20];             //holds max 20 explosions at once

    /* @func 测试射线与平面相交
     * @param plane 相关平面
     * @param position 点
     * @param direction 射线方向向量
     * @param lamda 相交点距离
     * @param pNormal
     */
    int TestIntersionPlane(const Plane& plane,const QVector3D& position,const QVector3D& direction, double& lamda, QVector3D& pNormal)
    {
        //计算平面法线与射线方向向量的点积
        double DotProduct=QVector3D::dotProduct(direction, plane._Normal);   // Dot Product Between Plane Normal And Ray Direction
        double l2;

        // Determine If Ray Parallel To Plane
        if ((DotProduct < ZERO)&&(DotProduct > -ZERO))
            return 0;
        //计算与相交点的距离
        l2 = QVector3D::dotProduct(plane._Normal, plane._Position - position) / DotProduct;

        //相交点位于起点之后
        if (l2 < -ZERO)                            // Test If Collision Behind Start
            return 0;

        pNormal=plane._Normal;
        lamda=l2;
        return 1;
    }

    int TestIntersionCylinder(const Cylinder& cylinder,const QVector3D& position,const QVector3D& direction, double& lamda, QVector3D& pNormal,QVector3D& newposition)
    {
        QVector3D RC;
        double d;
        double t,s;
        QVector3D n,D,O;
        double ln;
        double in,out;

        RC = position - cylinder._Position;
        n = QVector3D::crossProduct(direction, cylinder._Axis);

        ln=n.length();

        if ( (ln<ZERO)&&(ln>-ZERO) ) return 0;

        n.normalize();

        d= qAbs(QVector3D::dotProduct(RC, n));

        if (d<=cylinder._Radius)
        {
            O = QVector3D::crossProduct(RC, cylinder._Axis);
            t = - QVector3D::dotProduct(O, n)/ln;
            O = QVector3D::crossProduct(n, cylinder._Axis);
            O.normalize();
            s = qFabs( qSqrt(cylinder._Radius*cylinder._Radius - d*d) / QVector3D::dotProduct(direction, O));

            in = t-s;
            out = t+s;

            if (in<-ZERO){
                if (out<-ZERO) return 0;
                else lamda = out;
            }
            else
            if (out<-ZERO) {
                      lamda=in;
            }
            else
            if (in<out) lamda=in;
            else lamda=out;

            newposition = position+direction*lamda;
            QVector3D HB = newposition-cylinder._Position;
            pNormal = HB - cylinder._Axis*QVector3D::dotProduct(HB,cylinder._Axis);
            pNormal.normalize();

            return 1;
        }

        return 0;
    }

    int FindBallCol(QVector3D& point, double& TimePoint, double Time2, int& BallNr1, int& BallNr2)
    {
        QVector3D RelativeV;
        Ray rays;
        double MyTime=0.0, Add=Time2/150.0, Timedummy=10000, Timedummy2=-1;
        QVector3D posi;

        //Test all balls against eachother in 150 small steps
        for (int i=0;i<NrOfBalls-1;i++)
        {
         for (int j=i+1;j<NrOfBalls;j++)
         {
                RelativeV=ArrayVel[i]-ArrayVel[j];
                rays=Ray(OldPos[i],RelativeV.normalized());
                MyTime=0.0;

                if ( (rays.dist(OldPos[j])) > 40) continue;

                while (MyTime<Time2)
                {
                   MyTime+=Add;
                   posi=OldPos[i]+RelativeV*MyTime;
                   if ((posi-OldPos[j]).length()<=40) {
                                               point=posi;
                                               if (Timedummy>(MyTime-Add)) Timedummy=MyTime-Add;
                                               BallNr1=i;
                                               BallNr2=j;
                                               break;
                                            }

                }
         }

        }

        if (Timedummy!=10000) { TimePoint=Timedummy;
                                return 1;
        }

        return 0;
    }

    void idle()
    {
      double rt,rt2,rt4,lamda=10000;
      QVector3D norm,uveloc;
      QVector3D normal,point,time;
      double RestTime,BallTime;
      QVector3D Pos2;
      int BallNr=0,dummy=0,BallColNr1,BallColNr2;
      QVector3D Nc;
      int j;

      if (!hook_toball1)
      {
          camera_rotation+=0.1f;
          if (camera_rotation>360)
              camera_rotation=0;
      }

      RestTime=TimeStep;
      lamda=1000;

    //Compute velocity for next timestep using Euler equations
    for (j=0;j<NrOfBalls;j++)
      ArrayVel[j]+=accel*RestTime;

        //While timestep not over
        while (RestTime > ZERO)
        {
           lamda=10000;   //initialize to very large value

           //For all the balls find closest intersection between balls and planes/cylinders
           for (int i=0;i<NrOfBalls;i++)
           {
                  //compute new position and distance
                  OldPos[i]=ArrayPos[i];
                  uveloc = ArrayVel[i].normalized();
                  ArrayPos[i]=ArrayPos[i]+ArrayVel[i]*RestTime;
                  rt2=(OldPos[i]-ArrayPos[i]).length();

                  //Test if collision occured between ball and all 5 planes
                  if (TestIntersionPlane(pl1,OldPos[i],uveloc,rt,norm))
                  {
                      //Find intersection time
                      rt4=rt*RestTime/rt2;

                      //if smaller than the one already stored replace and in timestep
                      if (rt4<=lamda)
                      {
                        if (rt4<=RestTime+ZERO)
                             if (! ((rt<=ZERO)&&(QVector3D::dotProduct(uveloc,norm)>ZERO)) )
                              {
                                normal=norm;
                                point=OldPos[i]+uveloc*rt;
                                lamda=rt4;
                                BallNr=i;
                              }
                      }
                  }

                  if (TestIntersionPlane(pl2,OldPos[i],uveloc,rt,norm))
                  {
                       rt4=rt*RestTime/rt2;

                      if (rt4<=lamda)
                      {
                        if (rt4<=RestTime+ZERO)
                            if (! ((rt<=ZERO)&&(QVector3D::dotProduct(uveloc, norm)>ZERO)) )
                             {
                                normal=norm;
                                point=OldPos[i]+uveloc*rt;
                                lamda=rt4;
                                BallNr=i;
                                dummy=1;
                             }
                      }

                  }

                  if (TestIntersionPlane(pl3,OldPos[i],uveloc,rt,norm))
                  {
                      rt4=rt*RestTime/rt2;

                      if (rt4<=lamda)
                      {
                        if (rt4<=RestTime+ZERO)
                            if (! ((rt<=ZERO)&&(QVector3D::dotProduct(uveloc, norm)>ZERO)) )
                             {
                                normal=norm;
                                point=OldPos[i]+uveloc*rt;
                                lamda=rt4;
                                BallNr=i;
                             }
                      }
                  }

                  if (TestIntersionPlane(pl4,OldPos[i],uveloc,rt,norm))
                  {
                      rt4=rt*RestTime/rt2;

                      if (rt4<=lamda)
                      {
                        if (rt4<=RestTime+ZERO)
                            if (! ((rt<=ZERO)&&(QVector3D::dotProduct(uveloc,norm)>ZERO)) )
                             {
                                normal=norm;
                                point=OldPos[i]+uveloc*rt;
                                lamda=rt4;
                                BallNr=i;
                             }
                      }
                  }

                  if (TestIntersionPlane(pl5,OldPos[i],uveloc,rt,norm))
                  {
                      rt4=rt*RestTime/rt2;

                      if (rt4<=lamda)
                      {
                        if (rt4<=RestTime+ZERO)
                            if (! ((rt<=ZERO)&&(QVector3D::dotProduct(uveloc, norm)>ZERO)) )
                             {
                                normal=norm;
                                point=OldPos[i]+uveloc*rt;
                                lamda=rt4;
                                BallNr=i;
                             }
                      }
                  }

                  //Now test intersection with the 3 cylinders
                  if (TestIntersionCylinder(cyl1,OldPos[i],uveloc,rt,norm,Nc))
                  {
                      rt4=rt*RestTime/rt2;

                      if (rt4<=lamda)
                      {
                        if (rt4<=RestTime+ZERO)
                            if (! ((rt<=ZERO)&&(QVector3D::dotProduct(uveloc, norm)>ZERO)) )
                             {
                                normal=norm;
                                point=Nc;
                                lamda=rt4;
                                BallNr=i;
                             }
                      }

                  }
                  if (TestIntersionCylinder(cyl2,OldPos[i],uveloc,rt,norm,Nc))
                  {
                      rt4=rt*RestTime/rt2;

                      if (rt4<=lamda)
                      {
                        if (rt4<=RestTime+ZERO)
                            if (! ((rt<=ZERO)&&(QVector3D::dotProduct(uveloc, norm)>ZERO)) )
                             {
                                normal=norm;
                                point=Nc;
                                lamda=rt4;
                                BallNr=i;
                             }
                      }

                  }
                  if (TestIntersionCylinder(cyl3,OldPos[i],uveloc,rt,norm,Nc))
                  {
                      rt4=rt*RestTime/rt2;

                      if (rt4<=lamda)
                      {
                        if (rt4<=RestTime+ZERO)
                            if (! ((rt<=ZERO)&&(QVector3D::dotProduct(uveloc,norm)>ZERO)) )
                             {
                                normal=norm;
                                point=Nc;
                                lamda=rt4;
                                BallNr=i;
                             }
                      }

                  }
           }

           //After all balls were teste with planes/cylinders test for collision
           //between them and replace if collision time smaller
           if (FindBallCol(Pos2,BallTime,RestTime,BallColNr1,BallColNr2))
          {
              if ( (lamda==10000) || (lamda>BallTime) )
              {
                  RestTime=RestTime-BallTime;

                  QVector3D pb1,pb2,xaxis,U1x,U1y,U2x,U2y,V1x,V1y,V2x,V2y;
                  double a,b;

                  pb1=OldPos[BallColNr1]+ArrayVel[BallColNr1]*BallTime;
                  pb2=OldPos[BallColNr2]+ArrayVel[BallColNr2]*BallTime;
                  xaxis=(pb2-pb1).normalized();

                  a=QVector3D::dotProduct(xaxis, ArrayVel[BallColNr1]);
                  U1x=xaxis*a;
                  U1y=ArrayVel[BallColNr1]-U1x;

                  xaxis=(pb1-pb2).normalized();
                  b=QVector3D::dotProduct(xaxis, ArrayVel[BallColNr2]);
                  U2x=xaxis*b;
                  U2y=ArrayVel[BallColNr2]-U2x;

                  V1x=(U1x+U2x-(U1x-U2x))*0.5;
                  V2x=(U1x+U2x-(U2x-U1x))*0.5;
                  V1y=U1y;
                  V2y=U2y;

                  for (j=0;j<NrOfBalls;j++)
                    ArrayPos[j]=OldPos[j]+ArrayVel[j]*BallTime;

                  ArrayVel[BallColNr1]=V1x+V1y;
                  ArrayVel[BallColNr2]=V2x+V2y;

                  //Update explosion array
                  for(j=0;j<20;j++)
                  {
                      if (ExplosionArray[j]._Alpha<=0)
                      {
                          ExplosionArray[j]._Alpha=1;
                          ExplosionArray[j]._Position=ArrayPos[BallColNr1];
                          ExplosionArray[j]._Scale=1;
                          break;
                      }
                  }

                  continue;
              }
          }

#if 1
            //End of tests
            //If test occured move simulation for the correct timestep
            //and compute response for the colliding ball
            if (lamda!=10000)
            {
                  RestTime-=lamda;

                  for (j=0;j<NrOfBalls;j++)
                  ArrayPos[j]=OldPos[j]+ArrayVel[j]*lamda;

                  rt2=ArrayVel[BallNr].length();
                  ArrayVel[BallNr].normalize();
                  ArrayVel[BallNr]=(normal*(2*QVector3D::dotProduct(normal, -ArrayVel[BallNr])) + ArrayVel[BallNr] ).normalized();
                  ArrayVel[BallNr]=ArrayVel[BallNr]*rt2;

                  //Update explosion array
                  for(j=0;j<20;j++)
                  {
                      if (ExplosionArray[j]._Alpha<=0)
                      {
                          ExplosionArray[j]._Alpha=1;
                          ExplosionArray[j]._Position=point;
                          ExplosionArray[j]._Scale=1;
                          break;
                      }
                  }
            }
            else RestTime=0;
#endif
        }

    }

    void InitVars()
    {
        int i;

         //create palnes
        pl1._Position=QVector3D(0,-300,0);
        pl1._Normal=QVector3D(0,1,0);
        pl2._Position=QVector3D(300,0,0);
        pl2._Normal=QVector3D(-1,0,0);
        pl3._Position=QVector3D(-300,0,0);
        pl3._Normal=QVector3D(1,0,0);
        pl4._Position=QVector3D(0,0,300);
        pl4._Normal=QVector3D(0,0,-1);
        pl5._Position=QVector3D(0,0,-300);
        pl5._Normal=QVector3D(0,0,1);


        //create cylinders
        cyl1._Position=QVector3D(0,0,0);
        cyl1._Axis=QVector3D(0,1,0);
        cyl1._Radius=60+20;
        cyl2._Position=QVector3D(200,-300,0);
        cyl2._Axis=QVector3D(0,0,1);
        cyl2._Radius=60+20;
        cyl3._Position=QVector3D(-200,0,0);
        cyl3._Axis=QVector3D(0,1,1);
        cyl3._Axis.normalize();
        cyl3._Radius=30+20;
        //create quadratic object to render cylinders
        cylinder_obj= gluNewQuadric();
        gluQuadricTexture(cylinder_obj, GL_TRUE);

        //Set initial positions and velocities of balls
        //also initialize array which holds explosions
        NrOfBalls=10;
        ArrayVel[0]=veloc;
        ArrayPos[0]=QVector3D(199,180,10);
        ExplosionArray[0]._Alpha=0;
        ExplosionArray[0]._Scale=1;
        ArrayVel[1]=veloc;
        ArrayPos[1]=QVector3D(0,150,100);
        ExplosionArray[1]._Alpha=0;
        ExplosionArray[1]._Scale=1;
        ArrayVel[2]=veloc;
        ArrayPos[2]=QVector3D(-100,180,-100);
        ExplosionArray[2]._Alpha=0;
        ExplosionArray[2]._Scale=1;
        for (i=3; i<10; i++)
        {
             ArrayVel[i]=veloc;
             ArrayPos[i]=QVector3D(-500+i*75, 300, -500+i*50);
             ExplosionArray[i]._Alpha=0;
             ExplosionArray[i]._Scale=1;
        }
        for (i=10; i<20; i++)
        {
             ExplosionArray[i]._Alpha=0;
             ExplosionArray[i]._Scale=1;
        }
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
           GLfloat seconds = (GLfloat)t / 1000.0;
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
    glGenTextures(4, texture);

    if (image.load(":/marble.bmp")) {
        image =  convertToGLFormat(image);
        // Create Nearest Filtered Texture
        glBindTexture(GL_TEXTURE_2D, texture[0]);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); /* scale linearly when image bigger than texture*/
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); /* scale linearly when image smalled than texture*/
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.width(), image.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.bits());

    }

    if (image.load(":/spark.bmp")) {
        /* Create Texture	******************************************/
        glBindTexture(GL_TEXTURE_2D, texture[1]);   /* 2d texture (x and y size)*/

        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); /* scale linearly when image bigger than texture*/
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); /* scale linearly when image smalled than texture*/
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.width(), image.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.bits());
    }

    if (image.load(":/boden.bmp")) {
        glBindTexture(GL_TEXTURE_2D, texture[2]);   /* 2d texture (x and y size)*/

        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); /* scale linearly when image bigger than texture*/
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); /* scale linearly when image smalled than texture*/
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.width(), image.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.bits());
    }

    if (image.load(":/wand.bmp")) {
        glBindTexture(GL_TEXTURE_2D, texture[3]);   /* 2d texture (x and y size)*/

        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); /* scale linearly when image bigger than texture*/
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); /* scale linearly when image smalled than texture*/
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.width(), image.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.bits());
    }
}

MyGLWidget::MyGLWidget(QWidget *parent) :
    QGLWidget(parent), fullscreen(false)
{
    setWindowTitle(tr("nehe----lesson30"));
    InitVars();
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer->start(10);
    fpsUpdater = QTime::currentTime();
    fpsUpdater.start();
}

void MyGLWidget::initializeGL()
{
    float df=100.0;

    glClearDepth(1.0f);									// Depth Buffer Setup
    glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
    glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

    glClearColor(0,0,0,0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glShadeModel(GL_SMOOTH);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);


    glMaterialfv(GL_FRONT,GL_SPECULAR,spec);
    glMaterialfv(GL_FRONT,GL_SHININESS,&df);

    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0,GL_POSITION,posl);
    glLightfv(GL_LIGHT0,GL_AMBIENT,amb2);
    glEnable(GL_LIGHT0);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,amb);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);

    glEnable(GL_TEXTURE_2D);
    loadTextures();

    //Construct billboarded explosion primitive as display list
    //4 quads at right angles to each other
    glNewList(dlist=glGenLists(1), GL_COMPILE);
    glBegin(GL_QUADS);
        glRotatef(-45,0,1,0);
        glNormal3f(0,0,1);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-50,-40,0);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(50,-40,0);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(50,40,0);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-50,40,0);
        glNormal3f(0,0,-1);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-50,40,0);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(50,40,0);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(50,-40,0);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-50,-40,0);

        glNormal3f(1,0,0);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(0,-40,50);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(0,-40,-50);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(0,40,-50);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(0,40,50);
        glNormal3f(-1,0,0);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(0,40,50);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(0,40,-50);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(0,-40,-50);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(0,-40,50);
    glEnd();
    glEndList();
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
    gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,10.f,1700.0f);
   // glOrtho(0.0f,width,0,height,-1.0f,1.0f);

    glMatrixMode(GL_MODELVIEW);      // Select The Modelview Matrix
    glLoadIdentity();                // Reset The Modelview Matrix

}

void MyGLWidget::paintGL()
{
    int i;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Clear The Screen And The Depth Buffer
    glLoadIdentity();       // Reset The Current Modelview Matrix

    //set camera in hookmode
    if (hook_toball1)
    {
        QVector3D unit_followvector=ArrayVel[0];
        unit_followvector.normalize();
        gluLookAt(ArrayPos[0].x()+250,ArrayPos[0].y()+250 ,ArrayPos[0].z(), ArrayPos[0].x()+ArrayVel[0].x() ,ArrayPos[0].y()+ArrayVel[0].y() ,ArrayPos[0].z()+ArrayVel[0].z() ,0,1,0);

    } else {
        gluLookAt(init_pos.x(), init_pos.y(), init_pos.z(), init_pos.x() + init_dir.x(), init_pos.y() + init_dir.y(), init_pos.z() + init_dir.z(), 0,1.0,0.0);
    }
    glRotatef(camera_rotation,0,1,0);

#if 1
    //画彩球
    for (i=0;i<NrOfBalls;i++)
    {
        switch(i){
        case 1: glColor3f(1.0f,1.0f,1.0f);
                   break;
        case 2: glColor3f(1.0f,1.0f,0.0f);
                   break;
        case 3: glColor3f(0.0f,1.0f,1.0f);
                   break;
        case 4: glColor3f(0.0f,1.0f,0.0f);
                   break;
        case 5: glColor3f(0.0f,0.0f,1.0f);
                   break;
        case 6: glColor3f(0.65f,0.2f,0.3f);
                   break;
        case 7: glColor3f(1.0f,0.0f,1.0f);
                   break;
        case 8: glColor3f(0.0f,0.7f,0.4f);
                   break;
        default: glColor3f(1.0f,0,0);
        }
        glPushMatrix();
        glTranslated(ArrayPos[i].x(),ArrayPos[i].y(),ArrayPos[i].z());
        gluSphere(cylinder_obj,20,20,20);
        glPopMatrix();
    }
#endif
    glEnable(GL_TEXTURE_2D);

    //render walls(planes) with texture
    glBindTexture(GL_TEXTURE_2D, texture[3]);
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(320,320,320);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(320,-320,320);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-320,-320,320);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-320,320,320);

    glTexCoord2f(1.0f, 0.0f); glVertex3f(-320,320,-320);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-320,-320,-320);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(320,-320,-320);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(320,320,-320);

    glTexCoord2f(1.0f, 0.0f); glVertex3f(320,320,-320);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(320,-320,-320);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(320,-320,320);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(320,320,320);

    glTexCoord2f(1.0f, 0.0f); glVertex3f(-320,320,320);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-320,-320,320);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-320,-320,-320);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-320,320,-320);
    glEnd();

    //render floor (plane) with colours
    glBindTexture(GL_TEXTURE_2D, texture[2]);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-320,-320,320);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(320,-320,320);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(320,-320,-320);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-320,-320,-320);
    glEnd();

#if 1
    //render columns(cylinders)
    glBindTexture(GL_TEXTURE_2D, texture[0]);   /* choose the texture to use.*/
    glColor3f(0.5,0.5,0.5);
    glPushMatrix();
    glRotatef(90, 1,0,0);
    glTranslatef(0,0,-500);
    gluCylinder(cylinder_obj, 60, 60, 1000, 20, 2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(200,-300,-500);
    gluCylinder(cylinder_obj, 60, 60, 1000, 20, 2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-200,0,0);
    glRotatef(135, 1,0,0);
    glTranslatef(0,0,-500);
    gluCylinder(cylinder_obj, 30, 30, 1000, 20, 2);
    glPopMatrix();
#endif
#if 1
    //render/blend explosions
    glEnable(GL_BLEND);
    glDepthMask(GL_FALSE);
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    for(i=0; i<20; i++)
    {
        if(ExplosionArray[i]._Alpha>=0)
        {
           glPushMatrix();
           ExplosionArray[i]._Alpha-=0.01f;
           ExplosionArray[i]._Scale+=0.03f;
           glColor4f(1,1,0,ExplosionArray[i]._Alpha);
           glScalef(ExplosionArray[i]._Scale,ExplosionArray[i]._Scale,ExplosionArray[i]._Scale);
           glTranslatef((float)ExplosionArray[i]._Position.x()/ExplosionArray[i]._Scale, (float)ExplosionArray[i]._Position.y()/ExplosionArray[i]._Scale, (float)ExplosionArray[i]._Position.z()/ExplosionArray[i]._Scale);
           glCallList(dlist);
           glPopMatrix();
        }
    }
    glDepthMask(GL_TRUE);
    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);
#endif

    //detect collision
    idle();

    showFPS();
}

void MyGLWidget::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_Up:
        init_pos += QVector3D(0, 0, -10);
        break;
    case Qt::Key_Down:
        init_pos += QVector3D(0, 0, 10);
        break;
    case Qt::Key_Left:
        camera_rotation += 10;
        break;
    case Qt::Key_Right:
        camera_rotation -= 10;
        break;
    case Qt::Key_PageUp:
        TimeStep += 0.1;
        break;
    case Qt::Key_PageDown:
        TimeStep -= 0.1;
        break;
    case Qt::Key_F3:
        hook_toball1 ^= 1;
        camera_rotation = 0;
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
