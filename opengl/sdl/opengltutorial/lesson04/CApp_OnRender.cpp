#include "CApp.h"


void CApp::OnRender()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    int iModelViewLoc = glGetUniformLocation(spMain.getProgramID(), "modelViewMatrix");
   int iProjectionLoc = glGetUniformLocation(spMain.getProgramID(), "projectionMatrix");
   glUniformMatrix4fv(iProjectionLoc, 1, GL_FALSE, glm::value_ptr(glm::perspective(45.0f,  (float)640/480, 0.01f, 100.0f)));


    glm::mat4 mModelView = glm::lookAt(glm::vec3(0, 60, 30), glm::vec3(0, 0, 0), glm::vec3(0.0f, 1.0f, 0.0f));

    glm::mat4 mCurrent = glm::rotate(mModelView, fRotationAngle, glm::vec3(0.0f, 1.0f, 0.0f));
    glUniformMatrix4fv(iModelViewLoc, 1, GL_FALSE, glm::value_ptr(mCurrent));
    glBindVertexArray(uiVAOHeightmap);
    //glDrawElements(GL_TRIANGLE_STRIP, HM_SIZE_X*(HM_SIZE_Y-1)*2+HM_SIZE_Y-1, GL_UNSIGNED_INT, 0);
    glDrawElements(GL_TRIANGLE_STRIP, 28, GL_UNSIGNED_INT, 0);
    SDL_GL_SwapBuffers();
}
