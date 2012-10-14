#ifndef CAPP_H_INCLUDED
#define CAPP_H_INCLUDED

#include <SDL/SDL.h>
#include "CSurface.h"
#include "CEvent.h"
#include "CAnimation.h"
#include "CEntity.h"
#include "CDefine.h"
#include "CArea.h"
#include "CCamera.h"

class CApp : public CEvent
{
private:
    bool Running;
    SDL_Surface *Surf_Display;

    CEntity Entity1;
    CEntity Entity2;

public:
    CApp();
    int onExecute();

public:
    bool OnInit();
    void OnEvent(SDL_Event *Event);
    void OnExit();
    void OnLoop();
    void OnRender();
    void OnCleanup();

    void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
};


#endif // CAPP_H_INCLUDED
