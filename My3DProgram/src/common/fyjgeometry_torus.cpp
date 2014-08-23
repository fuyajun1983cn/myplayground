#include "fyjgeometry.h"

using namespace FYJ;


static void normalize(FYJVector3D &vNormal)
{
	float c = sqrt(vNormal.x * vNormal.x + vNormal.y * vNormal.y + vNormal.z * vNormal.z);
	vNormal.x = (float)vNormal.x/c;
	vNormal.y = (float)vNormal.y/c;
	vNormal.z = (float)vNormal.z/c;
}
/////////////////////////////////////////////////////////////////////////////////////////////////
// Make a torus
void Torus::makeTorus()
{
	double majorStep = 2.0f*M3D_PI / numMajor;
	  double minorStep = 2.0f*M3D_PI / numMinor;
	  int i, j;

	  for (i=0; i<numMajor; ++i) 
		  {
		  double a0 = i * majorStep;
		  double a1 = a0 + majorStep;
		  GLfloat x0 = (GLfloat) cos(a0);
		  GLfloat y0 = (GLfloat) sin(a0);
		  GLfloat x1 = (GLfloat) cos(a1);
		  GLfloat y1 = (GLfloat) sin(a1);
	
		  FYJVector3D vVertex[4];
		  FYJVector3D vNormal[4];
		  FYJVector2D vTexture[4];
		  
		  for (j=0; j<=numMinor; ++j) 
		 {
			  double b = j * minorStep;
			  GLfloat c = (GLfloat) cos(b);
			  GLfloat r = minorRadius * c + majorRadius;
			  GLfloat z = minorRadius * (GLfloat) sin(b);
			  
			  // First point
			  vTexture[0][0] = (float)(i)/(float)(numMajor);
			  vTexture[0][1] = (float)(j)/(float)(numMinor);
			  vNormal[0][0] = x0*c;
			  vNormal[0][1] = y0*c;
			  vNormal[0][2] = z/minorRadius;
			  normalize(vNormal[0]);
			  vVertex[0][0] = x0 * r;
			  vVertex[0][1] = y0 * r;
			  vVertex[0][2] = z;
			  
			  // Second point
			  vTexture[1][0] = (float)(i+1)/(float)(numMajor);
			  vTexture[1][1] = (float)(j)/(float)(numMinor);
			  vNormal[1][0] = x1*c;
			  vNormal[1][1] = y1*c;
			  vNormal[1][2] = z/minorRadius;
			  normalize(vNormal[1]);
			  vVertex[1][0] = x1*r;
			  vVertex[1][1] = y1*r;
			  vVertex[1][2] = z;
	
			  // Next one over
			  b = (j+1) * minorStep;
			  c = (GLfloat) cos(b);
			  r = minorRadius * c + majorRadius;
			  z = minorRadius * (GLfloat) sin(b);
						  
			  // Third (based on first)
			  vTexture[2][0] = (float)(i)/(float)(numMajor);
			  vTexture[2][1] = (float)(j+1)/(float)(numMinor);
			  vNormal[2][0] = x0*c;
			  vNormal[2][1] = y0*c;
			  vNormal[2][2] = z/minorRadius;
			  normalize(vNormal[2]);
			  vVertex[2][0] = x0 * r;
			  vVertex[2][1] = y0 * r;
			  vVertex[2][2] = z;
			  
			  // Fourth (based on second)
			  vTexture[3][0] = (float)(i+1)/(float)(numMajor);
			  vTexture[3][1] = (float)(j+1)/(float)(numMinor);
			  vNormal[3][0] = x1*c;
			  vNormal[3][1] = y1*c;
			  vNormal[3][2] = z/minorRadius;
			  normalize(vNormal[3]);
			  vVertex[3][0] = x1*r;
			  vVertex[3][1] = y1*r;
			  vVertex[3][2] = z;

			setVertexData(vVertex);
			if (hasNormal) 
				setNormalData(vNormal);
			if (hasTexture) {
				for (int k = 0; k < nNumTextureUnits; k++)
					setTexCoordData(k,vTexture);		
			}	  
			  
			currentVerts += 3;

			vVertex[0] = vVertex[1];
			vNormal[0] = vNormal[1];
			vTexture[0] = vTexture[1];

			vVertex[1] = vVertex[3];
			vNormal[1] = vNormal[3];
			vTexture[1] = vTexture[3];
					
			setVertexData(vVertex);
			if (hasNormal) 
				setNormalData(vNormal);
			if (hasTexture) {
				for (int k = 0; k < nNumTextureUnits; k++)
					setTexCoordData(k,vTexture);		
			}
			currentVerts += 3;		  
		}
	}

  }

Torus::Torus(float majorRadius, float minorRadius, int numMajor, int numMinor, bool hasColor , bool hasNormal , bool hasTexture )
	:Shape(hasColor, hasNormal, hasTexture)
{
	currentVerts = 0;
	this->majorRadius = majorRadius;
	this->minorRadius = minorRadius;
	this->numMajor = numMajor;
	this->numMinor = numMinor;
}

Torus::~Torus()
{
}

void Torus::draw()
{
	glDrawArrays(primitiveType, 0, nNumVertexCount);
}

void Torus::setVertexData(FYJVector3D *vertices)
{
	if (vertexBuffer == 0) {
		glGenBuffers(1, &vertexBuffer);
	         glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	         glBufferData(GL_ARRAY_BUFFER, sizeof(FYJVector3D) * nNumVertexCount,  vertices, GL_DYNAMIC_DRAW);
	} else {
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	         glBufferSubData(GL_ARRAY_BUFFER, sizeof(FYJVector3D) * currentVerts,  sizeof(FYJVector3D) * 3, vertices);
	}
}

void Torus::setNormalData(FYJVector3D *normals)
{
	if (!hasNormal) {
		WARN("hasNormal has already been set to false, no need to set normal data");
		return;
	}

	if (normalBuffer == 0) {
		glGenBuffers(1, &normalBuffer);
	         glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
	         glBufferData(GL_ARRAY_BUFFER, sizeof(FYJVector3D) * nNumVertexCount ,  normals, GL_DYNAMIC_DRAW);

	} else {
		glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
		glBufferSubData(GL_ARRAY_BUFFER, sizeof(FYJVector3D) * currentVerts,  sizeof(FYJVector3D) * 3, normals);
	}

}

void Torus::setTexCoordData(GLuint textureUnit, FYJVector2D *vTexCoord)
{
	if (!hasTexture) {
		WARN("hasTexture has already been set to false, no need to set texture coords.");
		return;
	}

	if (nNumTextureUnits <=0 ) {
		ERROR("setting texCoords while nNumTextureUnits <=0, are you forgetting something?");
		return;
	}
	
	if (texCoordBuffers[textureUnit] == 0) {
		glGenBuffers(1, &texCoordBuffers[textureUnit]);
		glBindBuffer(GL_ARRAY_BUFFER, texCoordBuffers[textureUnit]);
		glBufferData(GL_ARRAY_BUFFER,sizeof(FYJVector2D) * nNumVertexCount ,  vTexCoord, GL_DYNAMIC_DRAW);
	} else {
		glBindBuffer(GL_ARRAY_BUFFER, texCoordBuffers[textureUnit]);
		glBufferSubData(GL_ARRAY_BUFFER,sizeof(FYJVector2D) * currentVerts, sizeof(FYJVector2D) * 3,  vTexCoord);
	}
		

}

void Torus::setup(Shader shader, bool isWired)
{
	setShader(shader);

	if (hasTexture) 
		begin(GL_TRIANGLES, numMajor * (numMinor+1) * 6, 1);
	else {
		if (isWired)
			begin(GL_LINE_LOOP,numMajor * (numMinor+1) * 6, 0);
		else
			begin(GL_TRIANGLES, numMajor * (numMinor+1) * 6, 0);
	}

	makeTorus();
	
	end();

	

}

