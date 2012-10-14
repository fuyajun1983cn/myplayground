#ifndef CAPP_H_INCLUDED
#define CAPP_H_INCLUDED

#include <SDL/SDL.h>
#include <GL/glew.h>
#include "CEvent.h"
#include "CTexture.h"
#include "CLogger.h"
#include "CCamera.h"

#define CAMERASPEED	0.3f				// The Camera Speed

#define SKYFRONT 0						// Give Front ID = 0
#define SKYBACK  1						// Give Back  ID = 1
#define SKYLEFT  2						// Give Left  ID = 2
#define SKYRIGHT 3						// Give Right ID = 3
#define SKYUP    4						// Give Up    ID = 4
#define SKYDOWN  5						// Give Down  ID = 5

class CApp : public CEvent
{
private:
    bool Running;
    SDL_Surface *Surf_Display;

    CTexture tex[6];
    Camera objCamera;

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
    void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);

private:
    void DrawGrid();
    void DrawSkyBox(float x, float y, float z, float width, float height, float length);
};


#endif // CAPP_H_INCLUDED
