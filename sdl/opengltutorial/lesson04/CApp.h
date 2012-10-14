#ifndef CAPP_H_INCLUDED
#define CAPP_H_INCLUDED

#include <SDL/SDL.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "CSurface.h"
#include "CEvent.h"
#include "CShader.h"
#include "CShaderProgram.h"

class CApp : public CEvent
{
private:
    bool Running;
    SDL_Surface *Surf_Display;

    GLuint uiVBOHeightmapData;
    GLuint uiVBOIndices;
    GLuint uiVAOHeightmap;
    CShader shVertex, shFragment;
    CShaderProgram spMain;
    float fRotationAngle;

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
