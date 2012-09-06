#include "CApp.h"

bool CApp::OnInit()
{
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

    if ((Surf_Display = SDL_SetVideoMode(600, 600, 32, SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL)) == NULL) {
        return false;
    }

    if(glewInit()  !=  GLEW_OK)
    {
        printf("Failed to init glew!\n");
        return false;
    }

    glClearColor(0, 0, 1, 0);
    glClearDepth(1.0f);

    glViewport(0, 0, 640, 480);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0, 640, 480, 0, 1, -1);

    glMatrixMode(GL_MODELVIEW);

    glEnable(GL_TEXTURE_2D);

    glLoadIdentity();

    float fVert[9];
   fVert[0] = 100; fVert[1] = 100; fVert[2] = 0;
   fVert[3] = 100;  fVert[4] = 200; fVert[5] = 0;
   fVert[6] = 200;  fVert[7] = 200; fVert[8] = 0;

   // Generate VAO
   glGenVertexArrays(1, &uiVAOid);
   // Setup of VAO
   glBindVertexArray(uiVAOid);

   glGenBuffers(1, &uiVBOid);

   glBindBuffer(GL_ARRAY_BUFFER, uiVBOid);
   glBufferData(GL_ARRAY_BUFFER, 9*sizeof(GLfloat), fVert, GL_STATIC_DRAW);
   glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
   glEnableVertexAttribArray(0);

    return true;
}
