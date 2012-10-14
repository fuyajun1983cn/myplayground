#include "CApp.h"

bool CApp::OnInit()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    if ((Surf_Display = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }

    if(Entity1.OnLoad("./gfx/yoshi.bmp", 64, 64, 8) == false) {
        return false;
    }

    if(Entity2.OnLoad("./gfx/yoshi.bmp", 64, 64, 8) == false) {
        return false;
    }

    Entity2.X = 100;

    CEntity::EntityList.push_back(&Entity1);
    CEntity::EntityList.push_back(&Entity2);

    if(CArea::AreaControl.OnLoad("./maps/1.area") == false) {
        return false;
    }

    SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);

    return true;
}
