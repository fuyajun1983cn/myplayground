#include "fyjgeometry.h"

using namespace FYJ;

/////////////////////////////////////////////////////////////////////////////////////////////////
// Make a sphere
void Sphere::makeSphere()
{

    	GLfloat drho = (GLfloat)(3.141592653589) / (GLfloat) stacks;
    	GLfloat dtheta = 2.0f * (GLfloat)(3.141592653589) / (GLfloat) slices;
	GLfloat ds = 1.0f / (GLfloat) slices;
	GLfloat dt = 1.0f / (GLfloat) stacks;
	GLfloat t = 1.0f;	
	GLfloat s = 0.0f;
    	GLint i, j;     // Looping variables
    
	for (i = 0; i < stacks; i++) 
	{
		GLfloat rho = (GLfloat)i * drho;
		GLfloat srho = (GLfloat)(sin(rho));
		GLfloat crho = (GLfloat)(cos(rho));
		GLfloat srhodrho = (GLfloat)(sin(rho + drho));
		GLfloat crhodrho = (GLfloat)(cos(rho + drho));
		
        // Many sources of OpenGL sphere drawing code uses a triangle fan
        // for the caps of the sphere. This however introduces texturing 
        // artifacts at the poles on some OpenGL implementations
        		s = 0;
		FYJVector3D vVertex[4];
		FYJVector3D vNormal[4];
		FYJVector2D vTexture[4];

		for ( j = 0; j < slices; j++) 
		{
			GLfloat theta = (j == slices) ? 0.0f : j * dtheta;
			GLfloat stheta = (GLfloat)(-sin(theta));
			GLfloat ctheta = (GLfloat)(cos(theta));
			
			GLfloat x = stheta * srho;
			GLfloat y = ctheta * srho;
			GLfloat z = crho;
        
			vTexture[0].s= s;
			vTexture[0].t = t;
			vNormal[0].x = x;
			vNormal[0].y = y;
			vNormal[0].z = z;
			vVertex[0].x = x * radius;
			vVertex[0].y = y * radius;
			vVertex[0].z = z * radius;
			
            		x = stheta * srhodrho;
			y = ctheta * srhodrho;
			z = crhodrho;

 			vTexture[1].s = s;
			vTexture[1].t = t - dt;
			vNormal[1].x = x;
			vNormal[1].y = y;
			vNormal[1].z = z;
			vVertex[1].x = x * radius;
			vVertex[1].y = y * radius;
			vVertex[1].z = z * radius;
			

			theta = ((j+1) == slices) ? 0.0f : (j+1) * dtheta;
			stheta = (GLfloat)(-sin(theta));
			ctheta = (GLfloat)(cos(theta));
			
			x = stheta * srho;
			y = ctheta * srho;
			z = crho;
        
            		s += ds;
			vTexture[2].s = s;
			vTexture[2].t = t;
			vNormal[2].x = x;
			vNormal[2].y = y;
			vNormal[2].z = z;
			vVertex[2].x = x * radius;
			vVertex[2].y= y * radius;
			vVertex[2].z= z * radius;
			
           		 x = stheta * srhodrho;
			y = ctheta * srhodrho;
			z = crhodrho;

 			vTexture[3].s = s;
			vTexture[3].t = t - dt;
			vNormal[3].x = x;
			vNormal[3].y = y;
			vNormal[3].z = z;
			vVertex[3].x = x * radius;
			vVertex[3].y = y * radius;
			vVertex[3].z = z * radius;

			setVertexData(vVertex);
			//normalize
			if (hasNormal) {
				for(int k = 0; k < 4; k++) {
					float c = sqrt(vNormal[k].x * vNormal[k].x + vNormal[k].y * vNormal[k].y + vNormal[k].z * vNormal[k].z);
					vNormal[k].x = (float)vNormal[k].x/c;
					vNormal[k].y = (float)vNormal[k].y/c;
					vNormal[k].z = (float)vNormal[k].z/c;
				}
				setNormalData(vNormal);
			}
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
        		t -= dt;
        }

   }

Sphere::Sphere(float radius, int stacks, int slices, bool hasColor ,bool hasNormal  ,bool hasTexture ) : Shape(hasColor, hasNormal, hasTexture)
{
	currentVerts = 0;
	this->stacks = stacks;
	this->slices = slices;
	this->radius = radius;
}

Sphere::~Sphere()
{
}

void Sphere::draw()
{
	glDrawArrays(primitiveType, 0, nNumVertexCount);
}

void Sphere::setVertexData(FYJVector3D *vertices)
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

void Sphere::setColorData(FYJVector4D *colors)
{

}

void Sphere::setNormalData(FYJVector3D *normals)
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

void Sphere::setTexCoordData(GLuint textureUnit, FYJVector2D *vTexCoord)
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

void Sphere::setup(Shader shader, bool isWired)
{
	setShader(shader);

	if (hasTexture) 
		begin(GL_TRIANGLES, stacks* slices * 6, 1);
	else {
		if (isWired)
			begin(GL_LINE_LOOP, stacks * slices * 6, 0);
		else
			begin(GL_TRIANGLES, stacks* slices * 6, 0);
	}

	makeSphere();
	
	end();

	

}


