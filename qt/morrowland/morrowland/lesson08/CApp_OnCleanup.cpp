#include "CApp.h"

void CApp::OnCleanup()
{

    for (int i = 0; i < 6; i++)
        tex[i].releaseTexture();

    SDL_FreeSurface(Surf_Display);
    SDL_Quit();
}
