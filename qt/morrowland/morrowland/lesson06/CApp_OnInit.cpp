#include "CApp.h"

bool CApp::OnInit()
{
    //设置工程目录
    putenv("PROJECT_PATH=/home/fuyajun/myplayground/qt/morrowland/morrowland/lesson06");

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE,            8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,          8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,           8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,          8);

    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,          16);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,            32);

    SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE,        8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE,    8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE,        8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE,    8);

    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS,  1);

    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES,  2);

    if ((Surf_Display = SDL_SetVideoMode(600, 480, 32, SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL)) == NULL) {
        return false;
    }

    if(glewInit()  !=  GLEW_OK)
    {
        CLogger::err("Failed to init glew!");
        return false;
    }

    CLogger::info("Initializing...");

    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    glEnable(GL_BLEND);			// Enable Blending
    glBlendFunc(GL_ONE, GL_ONE);	// Set The Blending To A Nice 50/50 Mode

    glEnable(GL_TEXTURE_2D);
    if (tex1.loadTexture2D("texture/image.bmp")) {
        tex1.setFiltering(TEXTURE_FILTER_MAG_NEAREST, TEXTURE_FILTER_MIN_NEAREST);
        CLogger::info("load texture 1 successfully!");
    } else {
        CLogger::warn("failed to load texture 1");
    }

    if (tex2.loadTexture2D("texture/star.bmp")) {
        tex2.setFiltering(TEXTURE_FILTER_MAG_NEAREST, TEXTURE_FILTER_MIN_NEAREST);
        CLogger::info("load texture 2 successfully!");
    } else {
         CLogger::warn("failed to load texture 1");
    }

    OnResize(640, 480);

    return true;
}
