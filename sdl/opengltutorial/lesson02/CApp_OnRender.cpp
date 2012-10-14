#include "CApp.h"

void CApp::OnRender()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();


   // Triangle render
    glBindVertexArray(uiVAO[0]);
    glDrawArrays(GL_TRIANGLES, 0, 3);


   // Quad render using triangle strip
   glBindVertexArray(uiVAO[1]);
   glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    SDL_GL_SwapBuffers();
}
