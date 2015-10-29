#include "CApp.h"

namespace
{
    float floorColor[]	  = {1.0f,1.0f,1.0f,0.7f};			// Floor material color alpha = 0.7f
}

void CApp::DrawModel()
{
    tex[1].bindTexture();
    glBegin(GL_QUADS);
        // Front Face
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0f,  10.0f,  10.0f);	// Bottom Left Of The Texture and Quad
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 10.0f,  10.0f,  10.0f);	// Bottom Right Of The Texture and Quad
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 10.0f,  30.0f,  10.0f);	// Top Right Of The Texture and Quad
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0f,  30.0f,  10.0f);	// Top Left Of The Texture and Quad
        // Back Face
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-10.0f,  10.0f, -10.0f);	// Bottom Right Of The Texture and Quad
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-10.0f,  30.0f, -10.0f);	// Top Right Of The Texture and Quad
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 10.0f,  30.0f, -10.0f);	// Top Left Of The Texture and Quad
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 10.0f,  10.0f, -10.0f);	// Bottom Left Of The Texture and Quad
        // Top Face
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0f,  30.0f, -10.0f);	// Top Left Of The Texture and Quad
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0f,  30.0f,  10.0f);	// Bottom Left Of The Texture and Quad
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 10.0f,  30.0f,  10.0f);	// Bottom Right Of The Texture and Quad
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 10.0f,  30.0f, -10.0f);	// Top Right Of The Texture and Quad
        // Bottom Face
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-10.0f,  10.0f, -10.0f);	// Top Right Of The Texture and Quad
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 10.0f,  10.0f, -10.0f);	// Top Left Of The Texture and Quad
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 10.0f,  10.0f,  10.0f);	// Bottom Left Of The Texture and Quad
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-10.0f,  10.0f,  10.0f);	// Bottom Right Of The Texture and Quad
        // Right face
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 10.0f,  10.0f, -10.0f);	// Bottom Right Of The Texture and Quad
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 10.0f,  30.0f, -10.0f);	// Top Right Of The Texture and Quad
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 10.0f,  30.0f,  10.0f);	// Top Left Of The Texture and Quad
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 10.0f,  10.0f,  10.0f);	// Bottom Left Of The Texture and Quad
        // Left Face
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0f,  10.0f, -10.0f);	// Bottom Left Of The Texture and Quad
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-10.0f,  10.0f,  10.0f);	// Bottom Right Of The Texture and Quad
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-10.0f,  30.0f,  10.0f);	// Top Right Of The Texture and Quad
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0f,  30.0f, -10.0f);	// Top Left Of The Texture and Quad
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

    static float rot =0;
    rot +=0.2f;

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
    glBegin(GL_QUADS);
        glNormal3f(0,1.0f,0);
        glVertex3f( 50.0f, 0,-50.0f);
        glVertex3f(-50.0f, 0,-50.0f);
        glVertex3f(-50.0f, 0, 50.0f);
        glVertex3f( 50.0f, 0, 50.0f);
    glEnd();

    // Turn on Color Buffer and Depth Buffer
    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
    glDepthMask(GL_TRUE);

    // Only write to the Stencil Buffer where 1 is set
    glStencilFunc(GL_EQUAL, 1, 0xFFFFFFFF);
    // Keep the content of the Stencil Buffer
    glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);

    glPushMatrix();
    // We want to flip the y-axis on the "reflection" model
    glScalef(1.0f, -1.0f, 1.0f);
    // Translate the reflection model just below the floor surface (not necessary)
    glTranslatef(0,-9.9f,0);
    glRotatef(rot,0,1.0f,0);
    // Draw reflection model
    DrawModel();
    glPopMatrix();

    glEnable(GL_BLEND);

    // Draw the floor blended with the reflection model
    // We use our floor color with alpha value = 0.7f
    glMaterialfv(GL_FRONT, GL_SPECULAR, floorColor);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, floorColor);
    glMaterialf(GL_FRONT, GL_SHININESS, 180.0);
    tex[0].bindTexture();
    glBegin(GL_QUADS);
        glNormal3f(0,1.0f,0);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 50.0f, 0,-50.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-50.0f, 0,-50.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-50.0f, 0, 50.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 50.0f, 0, 50.0f);
    glEnd();


    // Dissable Stencil Buffer
    glDisable(GL_STENCIL_TEST);
    glDisable(GL_BLEND);

    glPushMatrix();
    glRotatef(rot,0,1.0f,0);
    // Draw our model
    DrawModel();
    glPopMatrix();

    SDL_GL_SwapBuffers();
}
