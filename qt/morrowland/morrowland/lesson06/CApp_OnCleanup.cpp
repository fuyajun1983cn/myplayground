#include "CApp.h"

void CApp::OnCleanup()
{
    tex1.releaseTexture();
    tex2.releaseTexture();

    SDL_FreeSurface(Surf_Display);
    SDL_Quit();
}
