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

    glClearColor(0, 0, 0, 0);
    glClearDepth(1.0f);

    glViewport(0, 0, 640, 480);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-1, 1, -1, 1, 1, -1);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

   glClearColor(0.0f, 0.5f, 1.0f, 1.0f);

   float fTriangle[9]; // Data to render triangle (3 vertices, each has 3 floats)
   float fQuad[12]; // Data to render quad using triangle strips (4 vertices, each has 3 floats)

   // Setup triangle vertices
   fTriangle[0] = -0.4f; fTriangle[1] = 0.1f; fTriangle[2] = 0.0f;
   fTriangle[3] = 0.4f; fTriangle[4] = 0.1f; fTriangle[5] = 0.0f;
   fTriangle[6] = 0.0f; fTriangle[7] = 0.7f; fTriangle[8] = 0.0f;

   // Setup quad vertices

   fQuad[0] = -0.2f; fQuad[1] = -0.1f; fQuad[2] = 0.0f;
   fQuad[3] = -0.2f; fQuad[4] = -0.6f; fQuad[5] = 0.0f;
   fQuad[6] = 0.2f; fQuad[7] = -0.1f; fQuad[8] = 0.0f;
   fQuad[9] = 0.2f; fQuad[10] = -0.6f; fQuad[11] = 0.0f;

   // Now we create two VBOs
   glGenBuffers(2, uiVBO);

   glBindBuffer(GL_ARRAY_BUFFER, uiVBO[0]);
   glBufferData(GL_ARRAY_BUFFER, 9*sizeof(float), fTriangle, GL_STATIC_DRAW);

   glBindBuffer(GL_ARRAY_BUFFER, uiVBO[1]);
   glBufferData(GL_ARRAY_BUFFER, 12*sizeof(float), fQuad, GL_STATIC_DRAW);

    return true;
}
