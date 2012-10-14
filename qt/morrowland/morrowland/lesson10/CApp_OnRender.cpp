#include "CApp.h"


void CApp::ShadowMatrix(float shadowMat[4][4], float groundplane[], float lightpos[])
{
    // Find the dot product between the light position vector and the ground plane normal
      float dot = groundplane[X] * lightpos[X] + groundplane[Y] * lightpos[Y] + groundplane[Z] * lightpos[Z] + groundplane[W] * lightpos[W];

      shadowMat[0][0] = dot - lightpos[X] * groundplane[X];
      shadowMat[1][0] = 0.f - lightpos[X] * groundplane[Y];
      shadowMat[2][0] = 0.f - lightpos[X] * groundplane[Z];
      shadowMat[3][0] = 0.f - lightpos[X] * groundplane[W];

      shadowMat[X][1] = 0.f - lightpos[Y] * groundplane[X];
      shadowMat[1][1] = dot - lightpos[Y] * groundplane[Y];
      shadowMat[2][1] = 0.f - lightpos[Y] * groundplane[Z];
      shadowMat[3][1] = 0.f - lightpos[Y] * groundplane[W];

      shadowMat[X][2] = 0.f - lightpos[Z] * groundplane[X];
      shadowMat[1][2] = 0.f - lightpos[Z] * groundplane[Y];
      shadowMat[2][2] = dot - lightpos[Z] * groundplane[Z];
      shadowMat[3][2] = 0.f - lightpos[Z] * groundplane[W];

      shadowMat[X][3] = 0.f - lightpos[W] * groundplane[X];
      shadowMat[1][3] = 0.f - lightpos[W] * groundplane[Y];
      shadowMat[2][3] = 0.f - lightpos[W] * groundplane[Z];
      shadowMat[3][3] = dot - lightpos[W] * groundplane[W];
}

void CApp::DrawModel()
{
    tex[1].bindTexture();
    glBegin(GL_QUADS);
        // Front Face
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0f,   0.0f,  10.0f);	// Bottom Left Of The Texture and Quad
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 10.0f,   0.0f,  10.0f);	// Bottom Right Of The Texture and Quad
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 10.0f,  20.0f,  10.0f);	// Top Right Of The Texture and Quad
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0f,  20.0f,  10.0f);	// Top Left Of The Texture and Quad
        // Back Face
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-10.0f,   0.0f, -10.0f);	// Bottom Right Of The Texture and Quad
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-10.0f,  20.0f, -10.0f);	// Top Right Of The Texture and Quad
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 10.0f,  20.0f, -10.0f);	// Top Left Of The Texture and Quad
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 10.0f,   0.0f, -10.0f);	// Bottom Left Of The Texture and Quad
        // Top Face
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0f,  20.0f, -10.0f);	// Top Left Of The Texture and Quad
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0f,  20.0f,  10.0f);	// Bottom Left Of The Texture and Quad
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 10.0f,  20.0f,  10.0f);	// Bottom Right Of The Texture and Quad
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 10.0f,  20.0f, -10.0f);	// Top Right Of The Texture and Quad
        // Bottom Face
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-10.0f,   0.0f, -10.0f);	// Top Right Of The Texture and Quad
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 10.0f,   0.0f, -10.0f);	// Top Left Of The Texture and Quad
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 10.0f,   0.0f,  10.0f);	// Bottom Left Of The Texture and Quad
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-10.0f,   0.0f,  10.0f);	// Bottom Right Of The Texture and Quad
        // Right face
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 10.0f,   0.0f, -10.0f);	// Bottom Right Of The Texture and Quad
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 10.0f,  20.0f, -10.0f);	// Top Right Of The Texture and Quad
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 10.0f,  20.0f,  10.0f);	// Top Left Of The Texture and Quad
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 10.0f,   0.0f,  10.0f);	// Bottom Left Of The Texture and Quad
        // Left Face
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0f,   0.0f, -10.0f);	// Bottom Left Of The Texture and Quad
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-10.0f,   0.0f,  10.0f);	// Bottom Right Of The Texture and Quad
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-10.0f,  20.0f,  10.0f);	// Top Right Of The Texture and Quad
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0f,  20.0f, -10.0f);	// Top Left Of The Texture and Quad
    glEnd();
}

void CApp::OnRender()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    // Clear Screen, Depth Buffer and Stencil Buffer
    glLoadIdentity();

    gluLookAt(objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,
                  objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,
                  objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);

    // Turn off writing to the Color Buffer and Depth Buffer
    // We want to draw to the Stencil Buffer only
    glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
    glDepthMask(GL_FALSE);

    // Enable the Stencil Buffer
    glEnable(GL_STENCIL_TEST);

    // Set 1 into the stencil buffer
    glStencilFunc(GL_ALWAYS, 1, 0xFFFFFFFF);
    glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);

    // Draw the floor
    tex[0].bindTexture();
    glBegin(GL_QUADS);
        glNormal3f(0,1.0f,0);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 100.0f, 0,-100.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-100.0f, 0,-100.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-100.0f, 0, 100.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 100.0f, 0, 100.0f);
    glEnd();

    // Turn on Color Buffer and Depth Buffer
    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
    glDepthMask(GL_TRUE);

    // Only write to the Stencil Buffer where 1 is set
    glStencilFunc(GL_EQUAL, 1, 0xFFFFFFFF);
    // Keep the content of the Stencil Buffer
    glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);

    // Draw the floor
    tex[0].bindTexture();
    glBegin(GL_QUADS);
        glNormal3f(0,1.0f,0);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 100.0f, 0,-100.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-100.0f, 0,-100.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-100.0f, 0, 100.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 100.0f, 0, 100.0f);
    glEnd();

    glPushMatrix();

    glColor4f(0.0, 0.0, 0.0, 0.5f);

    // Disable light
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    // Enable blending
    glEnable(GL_BLEND);

    glStencilOp(GL_KEEP, GL_KEEP, GL_INCR);
    // Calculate the projected shadow
    ShadowMatrix(floorShadow, groundplane, lightPosition);
    glMultMatrixf((float *)floorShadow);
    // Draw our model
    glRotatef(20.0f,0,1.0f,0);
    DrawModel();

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_BLEND);
    glEnable(GL_LIGHTING);
    glPopMatrix();



    glPushMatrix();
    // Dissable Stencil Buffer
    glDisable(GL_STENCIL_TEST);

    glRotatef(20.0f,0,1.0f,0);
    DrawModel();

    glPopMatrix();


    // Draw light source as a 5x5 point
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    glColor3f(1.0f,0,0);
    glBegin(GL_POINTS);
      glVertex3f(lightPosition[0],lightPosition[1],lightPosition[2]);
    glEnd();
    glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);

    SDL_GL_SwapBuffers();
}
