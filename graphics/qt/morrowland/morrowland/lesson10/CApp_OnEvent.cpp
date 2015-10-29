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
        lightPosition[2] -= 0.5f;
        CLogger::info("UP");
        break;
    case SDLK_DOWN:
        lightPosition[2] += 0.5f;
        CLogger::info("DOWN");
        break;
    case SDLK_LEFT:
        lightPosition[0] -= 0.5f;
        CLogger::info("LEFT");
        break;
    case SDLK_RIGHT:
        lightPosition[0] += 0.5f;
        CLogger::info("RIGHT");
        break;
    case SDLK_w:
        lightPosition[1] += 0.5f;
        CLogger::info("w");
        break;
    case SDLK_s:
        lightPosition[1] -= 0.5f;
        CLogger::info("s");
        break;
    default:
        break;
    }
}
