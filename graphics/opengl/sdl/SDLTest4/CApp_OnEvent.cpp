#include "CApp.h"

void CApp::OnEvent(SDL_Event *Event)
{
    CEvent::OnEvent(Event);
}

void CApp::OnExit()
{
    Running = false;
}

void CApp::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
    switch(sym) {
        #if 0
        case SDLK_UP:      CCamera::CameraControl.OnMove( 0,  5); break;
        case SDLK_DOWN:  CCamera::CameraControl.OnMove( 0, -5); break;
        case SDLK_LEFT:  CCamera::CameraControl.OnMove( 5,  0); break;
        case SDLK_RIGHT: CCamera::CameraControl.OnMove(-5,  0); break;
        #endif
        default: {
        }
    }
}
