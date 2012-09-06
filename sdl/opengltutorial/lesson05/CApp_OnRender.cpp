#include "CApp.h"

void CApp::OnRender()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    static float rot = 0;

    int iModelViewLoc = glGetUniformLocation(spMain.getProgramID(), "modelViewMatrix");
   int iProjectionLoc = glGetUniformLocation(spMain.getProgramID(), "projectionMatrix");
   glUniformMatrix4fv(iProjectionLoc, 1, GL_FALSE, glm::value_ptr(glm::perspective(45.0f,  (float)640/480, 0.01f, 100.0f)));

    glm::mat4 mModelView = glm::lookAt(glm::vec3(0, 0, -5), glm::vec3(0, 0, 0), glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 mCurrent = glm::rotate(mModelView, rot, glm::vec3(1.0f, 1.0f, 0.0f));
    mCurrent = glm::scale(mCurrent, glm::vec3(0.5f, 0.5f, 0.5f));
    glUniformMatrix4fv(iModelViewLoc, 1, GL_FALSE, glm::value_ptr(mCurrent));

    uiTexture.bindTexture(0);

   // Triangle render
    glBindVertexArray(uiVAO[0]);
    for (int i = 0; i < 6; i++)
        glDrawArrays(GL_QUADS, 4*i, 4);

    rot += 0.01;

   // Quad render using triangle strip
  // glBindVertexArray(uiVAO[1]);
 //  glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_SHORT, 0);

    SDL_GL_SwapBuffers();
}
