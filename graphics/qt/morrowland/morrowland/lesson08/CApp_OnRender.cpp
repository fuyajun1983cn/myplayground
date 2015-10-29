#include "CApp.h"

void CApp::DrawGrid()
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

void CApp::DrawSkyBox(float x, float y, float z, float width, float height, float length)
{
    // Center the Skybox around the given x,y,z position
    x = x - width  / 2;
    y = y - height / 2;
    z = z - length / 2;


    // Draw Front side
    tex[SKYFRONT].bindTexture();
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(x,		  y,		z+length);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(x,		  y+height, z+length);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(x+width, y+height, z+length);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(x+width, y,		z+length);
    glEnd();

    // Draw Back side
    tex[SKYBACK].bindTexture();
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(x+width, y,		z);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(x+width, y+height, z);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(x,		  y+height,	z);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(x,		  y,		z);
    glEnd();

    // Draw Left side
    tex[SKYLEFT].bindTexture();
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(x,		  y+height,	z);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(x,		  y+height,	z+length);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(x,		  y,		z+length);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(x,		  y,		z);
    glEnd();

    // Draw Right side
    tex[SKYRIGHT].bindTexture();
    glBegin(GL_QUADS);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(x+width, y,		z);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(x+width, y,		z+length);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(x+width, y+height,	z+length);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(x+width, y+height,	z);
    glEnd();

    // Draw Up side
    tex[SKYUP].bindTexture();
    glBegin(GL_QUADS);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(x+width, y+height, z);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(x+width, y+height, z+length);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(x,		  y+height,	z+length);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(x,		  y+height,	z);
    glEnd();

    // Draw Down side
    tex[SKYDOWN].bindTexture();
    glBegin(GL_QUADS);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(x,		  y,		z);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(x,		  y,		z+length);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(x+width, y,		z+length);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(x+width, y,		z);
    glEnd();

}

void CApp::OnRender()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

 //   glTranslatef(0, 0,-5.0f);

    gluLookAt(objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,
                  objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,
                  objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);

    DrawGrid();
    DrawSkyBox(0, 0, 0, 100, 100, 100);

    SDL_GL_SwapBuffers();
}
