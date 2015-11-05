#include "CApp.h"

void CApp::OnCleanup()
{
    SDL_FreeSurface(Surf_Display);
    SDL_Quit();
}
