#ifndef CTEXTURE_H
#define CTEXTURE_H

#include <string>
#include <GL/glew.h>

using namespace std;

const int TEXTURE_FILTER_MAG_NEAREST = 0x01;
const int TEXTURE_FILTER_MAG_BILINEAR = 0x02;
const int TEXTURE_FILTER_MIN_NEAREST = 0x11;
const int TEXTURE_FILTER_MIN_BILINEAR = 0x12;
const int TEXTURE_FILTER_MIN_NEAREST_MIPMAP = 0x13;
const int TEXTURE_FILTER_MIN_BILINEAR_MIPMAP = 0x14;
const int TEXTURE_FILTER_MIN_TRILINEAR = 0x15;

class CTexture
{
public:
   bool loadTexture2D(string a_sPath, bool bGenerateMipMaps = false);
   void bindTexture(int iTextureUnit = 0);

   void setFiltering(int a_tfMagnification, int a_tfMinification);

   int getMinificationFilter();
   int getMagnificationFilter();

   void releaseTexture();

   CTexture();
private:
   int iWidth, iHeight, iBPP; // Texture width, height, and bytes per pixel
   GLuint uiTexture; // Texture name
   GLuint uiSampler; // Sampler name
   bool bMipMapsGenerated;

   int tfMinification, tfMagnification;

   string sPath;
};



#endif // CTEXTURE_H
