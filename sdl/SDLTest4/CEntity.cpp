#include "CEntity.h"

std::vector<CEntity*> CEntity::EntityList;

CEntity::CEntity()
{
    Surf_Entity = NULL;

    X = Y = 0.0f;

    Width = Height = 0;

    AnimState = 0;
}

CEntity::~CEntity()
{

}

bool CEntity::OnLoad(char* File, int Width, int Height, int MaxFrames) {
    if((Surf_Entity = CSurface::OnLoad(File)) == NULL) {
        return false;
    }

    CSurface::Transparent(Surf_Entity, 255, 0, 255);

    this->Width = Width;
    this->Height = Height;

    Anim_Control.MaxFrames = MaxFrames;

    return true;
}

void CEntity::OnLoop() {
    Anim_Control.OnAnimation();
}

void CEntity::OnRender(SDL_Surface* Surf_Display) {
    if(Surf_Entity == NULL || Surf_Display == NULL) return;

    CSurface::OnDraw(Surf_Display, Surf_Entity, X, Y, AnimState * Width, Anim_Control.GetCurrentFrame() * Height, Width, Height);
}

void CEntity::OnCleanup() {
    if(Surf_Entity) {
        SDL_FreeSurface(Surf_Entity);
    }

    Surf_Entity = NULL;
}
