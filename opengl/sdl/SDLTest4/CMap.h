#ifndef CMAP_H
#define CMAP_H

#include <SDL/SDL.h>
#include <vector>

#include "CTile.h"
#include "CSurface.h"

class CMap
{
    public:
        SDL_Surface* Surf_Tileset;

    private:
        std::vector<CTile> TileList;

    public:
        CMap();
        ~CMap();

    public:
        bool OnLoad(char* File);

        void OnRender(SDL_Surface* Surf_Display, int MapX, int MapY);
};

#endif // CMAP_H
