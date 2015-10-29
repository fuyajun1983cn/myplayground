#include "CApp.h"

void CApp::OnRender()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0, 0,-5.0f);

    tex1.bindTexture();
    glBegin(GL_QUADS);
        // top left vertex
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-1, 1, 0);
        // bottom left vertex
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-1, -1, 0);
        // bottom right vertex
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(1, -1, 0);
        // top right vertex
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(1, 1, 0);
    glEnd();

    glPushMatrix();
    glRotatef(rot_angle, 0, 0, 1);
    tex2.bindTexture();
    glBegin(GL_QUADS);
        // top left vertex
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-1, 1, 0);
        // bottom left vertex
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-1, -1, 0);
        // bottom right vertex
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(1, -1, 0);
        // top right vertex
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(1, 1, 0);
    glEnd();
    glPopMatrix();

    SDL_GL_SwapBuffers();
}
