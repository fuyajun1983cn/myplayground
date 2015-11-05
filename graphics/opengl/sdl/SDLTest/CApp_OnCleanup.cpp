#include "CApp.h"

void CApp::OnCleanup()
{
    SDL_FreeSurface(Surf_Grid);
    SDL_FreeSurface(Surf_O);
    SDL_FreeSurface(Surf_X);
    SDL_FreeSurface(Surf_Display);
    SDL_Quit();
}
