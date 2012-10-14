#include "CApp.h"

CApp::CApp()
{
    Surf_Display = NULL;
    Surf_Grid = NULL;
    Surf_O = NULL;
    Surf_X = NULL;
    Running = true;
}

int CApp::onExecute()
{
    if (OnInit() == false) {
        return -1;
    }

    SDL_Event Event;
    while(Running) {
        while (SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }
        OnLoop();
        OnRender();
    }
    OnCleanup();

    return 0;
}

void CApp::Reset()
{
    for(int i = 0;i < 9;i++) {
        Grid[i] = GRID_TYPE_NONE;
    }
}

void CApp::SetCell(int ID, int Type) {
    if(ID < 0 || ID >= 9) return;
    if(Type < 0 || Type > GRID_TYPE_O) return;

    Grid[ID] = Type;
}

int main(int argc, char *argv[])
{
    CApp theApp;
    return theApp.onExecute();
}
