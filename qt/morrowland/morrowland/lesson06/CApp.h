#ifndef CAPP_H_INCLUDED
#define CAPP_H_INCLUDED

#include <SDL/SDL.h>
#include <GL/glew.h>
#include "CEvent.h"
#include "CTexture.h"
#include "CLogger.h"


class CApp : public CEvent
{
private:
    bool Running;
    SDL_Surface *Surf_Display;

    CTexture tex1;
    CTexture tex2;
    float rot_angle;

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
    void OnResize(int w, int h);
};


#endif // CAPP_H_INCLUDED
