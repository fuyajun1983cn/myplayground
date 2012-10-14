#include "CApp.h"

void CApp::OnCleanup()
{
    shVertex.deleteShader();
    shFragment.deleteShader();
    spMain.deleteProgram();
    uiTexture.releaseTexture();
    SDL_FreeSurface(Surf_Display);
    SDL_Quit();
}
