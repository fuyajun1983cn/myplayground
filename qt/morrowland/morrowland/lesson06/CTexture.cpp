#include "CTexture.h"
#include <SDL/SDL_image.h>
#include <iostream>

CTexture::CTexture()
{
    //ctor

}

bool CTexture::loadTexture2D(string a_sPath, bool bGenerateMipMaps)
{
    string current_dir = string(getenv("PROJECT_PATH"));
    if (current_dir.at(current_dir.length()-1) != '/')
            current_dir += '/';
    sPath = current_dir + a_sPath;

    SDL_Surface *temp;
    if ((temp = IMG_Load(sPath.c_str())) == NULL) {
        return false;
    }

   iWidth = temp->w; // Get the image width and height
   iHeight = temp->h;
   iBPP =  temp->format->BitsPerPixel;

   unsigned char * bDataPointer =  reinterpret_cast<unsigned char *>(temp->pixels);

   // If somehow one of these failed (they shouldn't), return failure
   if(bDataPointer == NULL || iWidth == 0 || iHeight == 0)
      return false;

   // Generate an OpenGL texture ID for this texture
   glGenTextures(1, &uiTexture);
   glBindTexture(GL_TEXTURE_2D, uiTexture);

   int iFormat = iBPP == 24 ? GL_BGR : iBPP == 8 ? GL_LUMINANCE : 0;
   int iInternalFormat = iBPP == 24 ? GL_RGB : GL_DEPTH_COMPONENT;

   glTexImage2D(GL_TEXTURE_2D, 0, iInternalFormat, iWidth, iHeight, 0, iFormat, GL_UNSIGNED_BYTE, bDataPointer);

   if(bGenerateMipMaps)glGenerateMipmap(GL_TEXTURE_2D);

   //采样器,可以与多个纹理单元关联
   glGenSamplers(1, &uiSampler);

   bMipMapsGenerated = bGenerateMipMaps;

   SDL_free(temp);

   return true; // Success
}

void CTexture::setFiltering(int a_tfMagnification, int a_tfMinification)
{
   // Set magnification filter
   if(a_tfMagnification == TEXTURE_FILTER_MAG_NEAREST)
      glSamplerParameteri(uiSampler, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
   else if(a_tfMagnification == TEXTURE_FILTER_MAG_BILINEAR)
      glSamplerParameteri(uiSampler, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

   // Set minification filter
   if(a_tfMinification == TEXTURE_FILTER_MIN_NEAREST)
      glSamplerParameteri(uiSampler, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
   else if(a_tfMinification == TEXTURE_FILTER_MIN_BILINEAR)
      glSamplerParameteri(uiSampler, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
   else if(a_tfMinification == TEXTURE_FILTER_MIN_NEAREST_MIPMAP)
      glSamplerParameteri(uiSampler, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
   else if(a_tfMinification == TEXTURE_FILTER_MIN_BILINEAR_MIPMAP)
      glSamplerParameteri(uiSampler, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
   else if(a_tfMinification == TEXTURE_FILTER_MIN_TRILINEAR)
      glSamplerParameteri(uiSampler, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

   tfMinification = a_tfMinification;
   tfMagnification = a_tfMagnification;
}

void CTexture::bindTexture(int iTextureUnit)
{
    glBindTexture(GL_TEXTURE_2D, uiTexture);
    glBindSampler(iTextureUnit, uiSampler);
}

int CTexture::getMagnificationFilter()
{
    return tfMagnification;
}

int CTexture::getMinificationFilter()
{
    return tfMinification;
}

void CTexture::releaseTexture()
{
    glDeleteSamplers(1, &uiSampler);
    glDeleteTextures(1, &uiTexture);
}
