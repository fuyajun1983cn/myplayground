#include "CApp.h"

void CApp::OnRender()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0, 0,-5.0f);


    glActiveTexture(GL_TEXTURE0);
    glEnable(GL_TEXTURE_2D);
    tex2.bindTexture();


   glActiveTexture(GL_TEXTURE1);
   glEnable(GL_TEXTURE_2D);
    tex1.bindTexture();

    glBegin(GL_QUADS);
        // top left vertex
        glMultiTexCoord2f(GL_TEXTURE0, 0.0f, 1.0f);
        glMultiTexCoord2f(GL_TEXTURE1, 0.0f, 1.0f);
        glVertex3f(-1, 1, 0);
        // bottom left vertex
        glMultiTexCoord2f(GL_TEXTURE0, 0.0f, 0.0f);
        glMultiTexCoord2f(GL_TEXTURE1, 0.0f, 0.0f);
        glVertex3f(-1, -1, 0);
        // bottom right vertex
        glMultiTexCoord2f(GL_TEXTURE0, 1.0f, 0.0f);
        glMultiTexCoord2f(GL_TEXTURE1, 1.0f, 0.0f);
        glVertex3f(1, -1, 0);
        // top right vertex
        glMultiTexCoord2f(GL_TEXTURE0, 1.0f, 1.0f);
        glMultiTexCoord2f(GL_TEXTURE1, 1.0f, 1.0f);
        glVertex3f(1, 1, 0);
    glEnd();

    SDL_GL_SwapBuffers();
}
