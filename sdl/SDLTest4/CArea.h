#ifndef CAREA_H
#define CAREA_H

#include "CMap.h"

class CArea
{
    public:
        static CArea            AreaControl;

    public:
        std::vector<CMap>       MapList;

    private:
        int                     AreaSize;

        SDL_Surface*        Surf_Tileset;

    public:
        CArea();
        virtual ~CArea();

        bool    OnLoad(char* File);

        void    OnRender(SDL_Surface* Surf_Display, int CameraX, int CameraY);

        void    OnCleanup();
};

#endif // CAREA_H
