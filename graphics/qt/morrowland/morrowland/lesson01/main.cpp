
#include <iostream>
#include <GL/freeglut.h>

#include "camera.h"

Camera objCamera;


void init(void)
{
   glClearColor (0.0, 0.0, 0.0, 0.5);
   glClearDepth(1.0f);
   glShadeModel (GL_SMOOTH);
   glEnable(GL_DEPTH_TEST);
   glDepthFunc(GL_LEQUAL);
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

   objCamera.Position_Camera(0, 0.5f, 5,	0, 0.5f, 0,   0, 1, 0);

}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
    glLoadIdentity();									// Reset The Current Modelview Matrix

    // use this function for opengl target camera
    gluLookAt(objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,
              objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,
              objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);



    glTranslatef(0.0f, 0.0f,-6.0f);
    glBegin(GL_TRIANGLES);
         glColor3f(1.0f, 0.0f, 0.0f);
         glVertex3f( 0.0f, 1.0f, 0.0f);
         glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-1.0f,-1.0f, 0.0f);
         glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f( 1.0f,-1.0f, 0.0f);
    glEnd();

    glFlush();

}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(40.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void mouse(int button, int state, int x, int y)
{

}

void specialKeyFunc(int key, int x, int y)
{
    switch (key) {
    case GLUT_KEY_UP:
        objCamera.Move_Camera(0.1);std::cout<<"This is a test";
        glutPostRedisplay();
        break;
    case GLUT_KEY_DOWN:
        objCamera.Move_Camera(-0.1);
        glutPostRedisplay();
        break;
    }
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
   case 27:
        exit(0);
        break;
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Camera Part I");
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutMouseFunc(mouse);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(specialKeyFunc);
   glutMainLoop();
   return 0;
}

