#ifndef CAPP_H_INCLUDED
#define CAPP_H_INCLUDED

#include <SDL/SDL.h>
#include <GL/glew.h>
#include "CEvent.h"
#include "CTexture.h"
#include "CLogger.h"
#include "CCamera.h"


class CApp : public CEvent
{
private:
    bool Running;
    SDL_Surface *Surf_Display;

    float floorShadow[4][4];	// matrix used to calculate our projected floor shadow
    CTexture tex[2];
    Camera objCamera;

    float groundplane[4]  ; // The normal of the floor

    float lightPosition[4] ;	// Holds our light position
    float lightAmbient[4]  ;	// Ambient light
    float lightDiffuse[4]  ;	// Diffuse light
    float lightSpecular[4] ;	// Specular light

    enum { X, Y, Z, W };

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
    void DrawModel();
    void ShadowMatrix(float shadowMat[4][4], float groundplane[4], float lightpos[4]);
};


#endif // CAPP_H_INCLUDED
