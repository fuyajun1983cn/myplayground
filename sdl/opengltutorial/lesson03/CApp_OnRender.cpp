#include "CApp.h"


void CApp::OnRender()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glBindVertexArray(uiVAO[0]);

    int iModelViewLoc = glGetUniformLocation(spMain.getProgramID(), "modelViewMatrix");
   int iProjectionLoc = glGetUniformLocation(spMain.getProgramID(), "projectionMatrix");
   glUniformMatrix4fv(iProjectionLoc, 1, GL_FALSE, glm::value_ptr(glm::perspective(45.0f,  (float)640/480, 0.01f, 100.0f)));

   glm::mat4 mModelView = glm::lookAt(glm::vec3(0, -1, -2.0f), glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

   // Render rotating pyramid in the middle

   glm::mat4 mCurrent = glm::rotate(mModelView, fRotationAngle, glm::vec3(0.0f, 1.0f, 0.0f));
   glUniformMatrix4fv(iModelViewLoc, 1, GL_FALSE, glm::value_ptr(mCurrent));
   glDrawArrays(GL_TRIANGLES, 0, 54);

#if 1
   // Render translating pyramids

   // One on the left
   mCurrent = glm::translate(mModelView, glm::vec3(-0.5f, 1.0f*float(sin(fRotationAngle*PIover180)), 0.0f));
   glUniformMatrix4fv(iModelViewLoc, 1, GL_FALSE, glm::value_ptr(mCurrent));
   glDrawArrays(GL_TRIANGLES, 0, 54);

   // One on the right
   mCurrent = glm::translate(mModelView, glm::vec3(0.5f, -1.0f*float(sin(fRotationAngle*PIover180)), 0.0f));
   glUniformMatrix4fv(iModelViewLoc, 1, GL_FALSE, glm::value_ptr(mCurrent));
   glDrawArrays(GL_TRIANGLES, 0, 54);

   // And one translating and rotating on top

   mCurrent = glm::translate(mModelView, glm::vec3(2.0f*float(sin(fRotationAngle*PIover180)), 0.5f, 0.0f));
   mCurrent = glm::rotate(mCurrent, fRotationAngle, glm::vec3(1.0f, 0.0f, 0.0f));
   glUniformMatrix4fv(iModelViewLoc, 1, GL_FALSE, glm::value_ptr(mCurrent));
   glDrawArrays(GL_TRIANGLES, 0, 54);

   // And lastly - render scaling pyramid that rotates

   float fScaleValue = 1.5f+float(sin(fRotationAngle*PIover180))*0.5f;
   mCurrent = glm::translate(mModelView, glm::vec3(0.0f, -10.0f, 0.0f));
   mCurrent = glm::scale(mCurrent, glm::vec3(fScaleValue, fScaleValue, fScaleValue));
   mCurrent = glm::rotate(mCurrent, fRotationAngle, glm::vec3(1.0f, 0.0f, 0.0f));
   mCurrent = glm::rotate(mCurrent, fRotationAngle, glm::vec3(0.0f, 1.0f, 0.0f));
   mCurrent = glm::rotate(mCurrent, fRotationAngle, glm::vec3(0.0f, 0.0f, 1.0f));
   glUniformMatrix4fv(iModelViewLoc, 1, GL_FALSE, glm::value_ptr(mCurrent));
   glDrawArrays(GL_TRIANGLES, 0, 54);
#endif

   fRotationAngle += 0.02f;
#if 0
   // Add some handlers - with F2, you can toggle FPS showing, with F3 you can toggle V-Sync

   if(Keys::onekey(VK_F2))
   {
      bShowFPS = !bShowFPS;
      if(!bShowFPS)SetWindowText(appMain.hWnd, "04.) Going 3D With Transformations - Tutorial by Michal Bubnar (www.mbsoftworks.sk)");
   }
   if(Keys::onekey(VK_F3))
   {
      bVerticalSync = !bVerticalSync;
      oglControl->setVerticalSynchronization(bVerticalSync);
   }
   if(bShowFPS)
   {
      char buf[55]; sprintf(buf, "FPS: %d, V-Sync: %s", oglControl->getFPS(), bVerticalSync ? "On": "Off");
      SetWindowText(appMain.hWnd, buf);
   }
#endif
    SDL_GL_SwapBuffers();
}
