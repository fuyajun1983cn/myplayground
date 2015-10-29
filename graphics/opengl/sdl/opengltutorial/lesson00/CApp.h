#ifndef CAPP_H_INCLUDED
#define CAPP_H_INCLUDED

#include <SDL/SDL.h>
#include <GL/glew.h>
#include "CSurface.h"
#include "CEvent.h"

class CApp : public CEvent
{
private:
    bool Running;
    SDL_Surface *Surf_Display;

    GLuint uiVAOid;
    GLuint uiVBOid;

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
};


#endif // CAPP_H_INCLUDED
