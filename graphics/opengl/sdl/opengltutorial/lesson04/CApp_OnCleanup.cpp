#include "CApp.h"

void CApp::OnCleanup()
{
    SDL_FreeSurface(Surf_Display);
    spMain.deleteProgram();
    glDeleteBuffers(1, &uiVBOHeightmapData);
	glDeleteBuffers(1, &uiVBOIndices);
	glDeleteVertexArrays(1, &uiVAOHeightmap);
	shVertex.deleteShader();
	shFragment.deleteShader();
    SDL_Quit();
}
