#include "CApp.h"

void CApp::OnRender()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glEnableVertexAttribArray(0);
   // Triangle render
   glBindBuffer(GL_ARRAY_BUFFER, uiVBO[0]);
   glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
   glDrawArrays(GL_TRIANGLES, 0, 3);

   // Quad render using triangle strip
   glBindBuffer(GL_ARRAY_BUFFER, uiVBO[1]);
   glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
   glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    SDL_GL_SwapBuffers();
}
