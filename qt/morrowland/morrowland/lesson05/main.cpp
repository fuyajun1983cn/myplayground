
#include <iostream>
#include <GL/freeglut.h>

#include "camera.h"

#define CAMERASPEED 0.1

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

static void Draw_Grid()
{

    for(float i = -500; i <= 500; i += 5)
    {
        glBegin(GL_LINES);
            glColor3ub(150, 190, 150);
            glVertex3f(-500, 0, i);
            glVertex3f(500, 0, i);
            glVertex3f(i, 0,-500);
            glVertex3f(i, 0, 500);
        glEnd();
    }
}

static void Draw_Character()
{
    glScalef(0.3f,1.0f,0.3f);
    glTranslatef(0,1.0f,0);
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f,0.0f,0.0f);
        glVertex3f( 0.0f, 1.0f, 0.0f);
        glVertex3f(-1.0f,-1.0f, 1.0f);
        glVertex3f( 1.0f,-1.0f, 1.0f);
        glVertex3f( 0.0f, 1.0f, 0.0f);
        glVertex3f( 1.0f,-1.0f, 1.0f);
        glVertex3f( 1.0f,-1.0f, -1.0f);
        glVertex3f( 0.0f, 1.0f, 0.0f);
        glVertex3f( 1.0f,-1.0f, -1.0f);
        glVertex3f(-1.0f,-1.0f, -1.0f);
        glVertex3f( 0.0f, 1.0f, 0.0f);
        glVertex3f(-1.0f,-1.0f,-1.0f);
        glVertex3f(-1.0f,-1.0f, 1.0f);
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
    glLoadIdentity();									// Reset The Current Modelview Matrix

    // use this function for opengl target camera
    gluLookAt(objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,
              objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,
              objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);

    glPushMatrix();
            // Always keep the character in the view
            glTranslatef(objCamera.mView.x,0.0f,objCamera.mView.z);
            Draw_Character();
        glPopMatrix();


        Draw_Grid();

        glPushMatrix();
        glScalef(0.5f, 0.5f, 0.5f);
        glTranslatef(0,1.0f,0);
        glBegin(GL_QUADS);
            glColor3f(0.0f,1.0f,0.0f);
            glVertex3f( 1.0f, 1.0f,-1.0f);
            glVertex3f(-1.0f, 1.0f,-1.0f);
            glVertex3f(-1.0f, 1.0f, 1.0f);
            glVertex3f( 1.0f, 1.0f, 1.0f);
            glColor3f(1.0f,0.5f,0.0f);
            glVertex3f( 1.0f,-1.0f, 1.0f);
            glVertex3f(-1.0f,-1.0f, 1.0f);
            glVertex3f(-1.0f,-1.0f,-1.0f);
            glVertex3f( 1.0f,-1.0f,-1.0f);
            glColor3f(1.0f,0.0f,0.0f);
            glVertex3f( 1.0f, 1.0f, 1.0f);
            glVertex3f(-1.0f, 1.0f, 1.0f);
            glVertex3f(-1.0f,-1.0f, 1.0f);
            glVertex3f( 1.0f,-1.0f, 1.0f);
            glColor3f(1.0f,1.0f,0.0f);
            glVertex3f( 1.0f,-1.0f,-1.0f);
            glVertex3f(-1.0f,-1.0f,-1.0f);
            glVertex3f(-1.0f, 1.0f,-1.0f);
            glVertex3f( 1.0f, 1.0f,-1.0f);
            glColor3f(0.0f,0.0f,1.0f);
            glVertex3f(-1.0f, 1.0f, 1.0f);
            glVertex3f(-1.0f, 1.0f,-1.0f);
            glVertex3f(-1.0f,-1.0f,-1.0f);
            glVertex3f(-1.0f,-1.0f, 1.0f);
            glColor3f(1.0f,0.0f,1.0f);
            glVertex3f( 1.0f, 1.0f,-1.0f);
            glVertex3f( 1.0f, 1.0f, 1.0f);
            glVertex3f( 1.0f,-1.0f, 1.0f);
            glVertex3f( 1.0f,-1.0f,-1.0f);
        glEnd();
    glPopMatrix();

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
    objCamera.Mouse_Move(x, y, 640, 480);
    glutPostRedisplay();
}

void specialKeyFunc(int key, int x, int y)
{
    switch (key) {
    case GLUT_KEY_UP:
        objCamera.Move_Camera(CAMERASPEED);
        glutPostRedisplay();
        break;
    case GLUT_KEY_DOWN:
        objCamera.Move_Camera(-CAMERASPEED);
        glutPostRedisplay();
        break;
    case GLUT_KEY_LEFT:
        objCamera.Strafe_Camera(-CAMERASPEED);
        glutPostRedisplay();
        break;
    case GLUT_KEY_RIGHT:
        objCamera.Strafe_Camera(CAMERASPEED);
        glutPostRedisplay();
        break;
    default:
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
   glutInitWindowSize (640, 480);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Camera Part VI");
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutMouseFunc(mouse);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(specialKeyFunc);
   glutMainLoop();
   return 0;
}

