#include "CApp.h"

void CApp::OnEvent(SDL_Event *Event)
{
    CEvent::OnEvent(Event);
}

void CApp::OnExit()
{
    Running = false;
}

void CApp::OnResize(int w, int h)
{
    if (h == 0)
        h = 1;

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0f, (GLfloat)w/(GLfloat)h,0.1f,100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    objCamera.mWindowWidth = w;
    objCamera.mWindowHeight = h;

}

void CApp::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode)
{
    switch (sym) {
    case SDLK_UP:
        objCamera.Move_Camera(CAMERASPEED);
        CLogger::info("UP");
        break;
    case SDLK_DOWN:
        objCamera.Move_Camera(-CAMERASPEED);
        CLogger::info("DOWN");
        break;
    case SDLK_LEFT:
        objCamera.Rotate_View(0, -CAMERASPEED, 0);
        CLogger::info("LEFT");
        break;
    case SDLK_RIGHT:
        objCamera.Rotate_View(0, CAMERASPEED, 0);
        CLogger::info("RIGHT");
        break;
    default:
        break;
    }
}
