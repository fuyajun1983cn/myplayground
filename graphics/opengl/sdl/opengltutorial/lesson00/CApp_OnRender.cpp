#include "CApp.h"

void CApp::OnRender()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glBindVertexArray(uiVAOid);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    SDL_GL_SwapBuffers();
}
