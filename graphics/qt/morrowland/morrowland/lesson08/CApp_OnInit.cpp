#include "CApp.h"

bool CApp::OnInit()
{
    //设置工程目录
    putenv("PROJECT_PATH=/home/fuyajun/myplayground/qt/morrowland/morrowland/lesson08");

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

    CLogger::info("Initializing GL...");

    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);


    glEnable(GL_TEXTURE_2D);

    objCamera.Position_Camera(0, 2.5f, 5,	0, 2.5f, 0,   0, 1, 0);

    if (tex[SKYFRONT].loadTexture2D("texture/front.jpg")) {
        tex[SKYFRONT].setFiltering(TEXTURE_FILTER_MAG_NEAREST, TEXTURE_FILTER_MIN_NEAREST);
        CLogger::info("load front texture successfully!");
    } else {
        CLogger::warn("failed to load front texture");
    }

    if (tex[SKYBACK].loadTexture2D("texture/back.jpg")) {
        tex[SKYBACK].setFiltering(TEXTURE_FILTER_MAG_NEAREST, TEXTURE_FILTER_MIN_NEAREST);
        CLogger::info("load back texture successfully!");
    } else {
        CLogger::warn("failed to load back texture");
    }

    if (tex[SKYLEFT].loadTexture2D("texture/left.jpg")) {
        tex[SKYLEFT].setFiltering(TEXTURE_FILTER_MAG_NEAREST, TEXTURE_FILTER_MIN_NEAREST);
        CLogger::info("load left texture successfully!");
    } else {
        CLogger::warn("failed to load left texture");
    }

    if (tex[SKYRIGHT].loadTexture2D("texture/right.jpg")) {
        tex[SKYRIGHT].setFiltering(TEXTURE_FILTER_MAG_NEAREST, TEXTURE_FILTER_MIN_NEAREST);
        CLogger::info("load right texture successfully!");
    } else {
        CLogger::warn("failed to load right texture");
    }

    if (tex[SKYUP].loadTexture2D("texture/up.jpg")) {
        tex[SKYUP].setFiltering(TEXTURE_FILTER_MAG_NEAREST, TEXTURE_FILTER_MIN_NEAREST);
        CLogger::info("load up texture successfully!");
    } else {
        CLogger::warn("failed to load up texture");
    }

    if (tex[SKYDOWN].loadTexture2D("texture/down.jpg")) {
        tex[SKYDOWN].setFiltering(TEXTURE_FILTER_MAG_NEAREST, TEXTURE_FILTER_MIN_NEAREST);
        CLogger::info("load down texture successfully!");
    } else {
        CLogger::warn("failed to load down texture");
    }

    OnResize(640, 480);

    return true;
}
