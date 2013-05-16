#include "fyjgeometry.h"
#include "fyjprogram.h"

using namespace FYJ;

Shape::Shape(bool hasColor ,bool hasNormal ,bool hasTexture ):vertexBuffer(0), colorBuffer(0), nNumTextureUnits(0),nNumVertexCount(0),
	texCoordBuffers(NULL)
{
	this->hasColor = hasColor;
	this->hasNormal = hasNormal;
	this->hasTexture = hasTexture;
#if 0
	if (hasColor && hasTexture) {
		WARN("both hasColor and hasTexture are set to true, it's invalid, set hasTexture to false now");
		hasTexture = false;
	}	

	if (!hasColor && !hasTexture) {
		WARN("hasColor and hasTexture cannot be set to false at the same time, set hasColor to true now");
		hasColor = true;
	}
#endif
	shaderInUse = FYJ_SHADER_IDENTITY;

	program = fyj_new Program(shaderInUse.VS, shaderInUse.FS);

	INFO("Shape init finished!");
}

Shape::~Shape()
{
	if (program != NULL)
		fyj_delete program;
	clearData();
}

void Shape::setShader(Shader s)
{
	shaderInUse = s;

	if (program != NULL)
		fyj_delete program;


	program = fyj_new Program(shaderInUse.VS, shaderInUse.FS);

	clearData();

}

void Shape::draw()
{
	int n = nNumVertexCount/4;
	for (int i = 0; i < n; i++)
		glDrawArrays(primitiveType, 4*i , 4);
}

void Shape::begin(GLenum primitive, GLuint nVertexCount, GLuint nTextureUnits )
{
	primitiveType = primitive;
	nNumVertexCount = nVertexCount;
	if (hasTexture)
		nNumTextureUnits = nTextureUnits;
	else 
		nNumTextureUnits = 0;

	if (nNumTextureUnits > 4)
		nNumTextureUnits = 4;//only support 4 texture units

	if(nNumTextureUnits != 0) {
		texCoordBuffers = new GLuint[nNumTextureUnits];
		texHandles = new GLuint[nNumTextureUnits];

		// An array of pointers to texture coordinate arrays
		for(unsigned int i = 0; i < nNumTextureUnits; i++) {
			texCoordBuffers[i] = 0;
			texHandles[i] = -1;
		}
	}

}

void Shape::end()
{
	program->use();
	
	if (vertexBuffer != 0) {
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		GLuint loc = program->getAttribute(Program::POSITION, shaderInUse.POSITION);
		glVertexAttribPointer(loc, 3, GL_FLOAT, GL_FALSE, 0, 0);
	}

	if (colorBuffer != 0) {
		glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
		GLuint loc = program->getAttribute(Program::COLOR, shaderInUse.COLOR);
		glVertexAttribPointer(loc, 4, GL_FLOAT, GL_FALSE, 0, 0);
	}

	if (normalBuffer != 0) {
		glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
		GLuint loc = program->getAttribute(Program::NORMAL, shaderInUse.NORMAL);
		glVertexAttribPointer(loc, 3, GL_FLOAT, GL_FALSE, 0, 0);
	}

	// How many texture units
	for(unsigned int i = 0; i < nNumTextureUnits; i++) {
		if(texCoordBuffers[i] != 0) {
			glBindBuffer(GL_ARRAY_BUFFER, texCoordBuffers[i]);
			String tex_coods = shaderInUse.map(Program::TEX_COORD0 + i);
			if (tex_coods.empty())
				WARN("TEX COORD NAME is empty, Are you forgetting someting?");
			GLuint loc = program->getAttribute(Program::AttributeType(Program::TEX_COORD0 + i), tex_coods);
			glVertexAttribPointer(loc, 2, GL_FLOAT, GL_FALSE, 0, 0);

		}

		String sampler_name = shaderInUse.map(Program::SAMPLER2D);
		if (sampler_name.empty())
			WARN("Sampler name is empty, Are you forget setting it?");
		GLuint texHandle = program->getUniform(Program::UniformType(Program::SAMPLER2D+i),  sampler_name);
		glActiveTexture(GL_TEXTURE0 + i);
		glUniform1f(texHandle, i);
	}

	GLuint loc = program->getUniform(Program::COLOR2, shaderInUse.COLOR2);
	if (loc != -1) {
		GLfloat colors[4];
		colors[0] = color.r;
		colors[1] = color.g;
		colors[2] = color.b;
		colors[3] = color.a;
		glUniform1fv(loc, 4, colors);
	}
		

	program->enableVertexAttribArray();
	
}

void Shape::setColor(FYJVector4D color)
{
	if (!hasColor)
		return;
	
	this->color = color;
}


void Shape::setVertexData(FYJVector3D *vVerts)
{
	if (vertexBuffer == 0) {
		glGenBuffers(1, &vertexBuffer);
	         glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	         glBufferData(GL_ARRAY_BUFFER, sizeof(FYJVector3D) * nNumVertexCount,  vVerts, GL_DYNAMIC_DRAW);
	}else {
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

	        // Copy the data in
	        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(FYJVector3D) * nNumVertexCount,  vVerts);
	}
}

void Shape::setColorData(FYJVector4D *vColor)
{
	if (!hasColor) {
		WARN("hasColor has already been set to false, no need to set color data");
		return;
	}
		
	if (colorBuffer == 0) {
		glGenBuffers(1, &colorBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(FYJVector4D)  * nNumVertexCount,  &vColor[0], GL_DYNAMIC_DRAW);
	} else {
		glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(FYJVector4D)  * nNumVertexCount,  vColor);
	}
}

void Shape::setNormalData(FYJVector3D *vNormal)
{
	if (!hasNormal) {
		WARN("hasNormal has already been set to false, no need to set normal data");
		return;
	}

	if (normalBuffer == 0) {
		glGenBuffers(1, &normalBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(FYJVector3D) * nNumVertexCount,  vNormal, GL_DYNAMIC_DRAW);
	}else {
		glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);

	        // Copy the data in
	        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(FYJVector3D) * nNumVertexCount, vNormal);
	}
}

void Shape::setTexCoordData(GLuint textureUnit, FYJVector2D *vTexCoord)
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
		glBufferData(GL_ARRAY_BUFFER,sizeof(FYJVector2D) * nNumVertexCount, vTexCoord, GL_DYNAMIC_DRAW);
	} else {
		glBindBuffer(GL_ARRAY_BUFFER, texCoordBuffers[textureUnit]);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(FYJVector2D) * nNumVertexCount, vTexCoord);
	}
			
}

void Shape::clearData()
{
	if (vertexBuffer != 0) {
		glDeleteBuffers(1, &vertexBuffer);
		vertexBuffer = 0;
	}

	if (colorBuffer != 0) {
		glDeleteBuffers(1, &colorBuffer);
		colorBuffer = 0;
	}

	if (normalBuffer != 0) {
		glDeleteBuffers(1, &normalBuffer);
		normalBuffer = 0;
	}

	if(nNumTextureUnits != 0) {
		glDeleteBuffers(nNumTextureUnits , texCoordBuffers);

		// An array of pointers to texture coordinate arrays
		for(unsigned int i = 0; i < nNumTextureUnits; i++) {
			texCoordBuffers[i] = 0;
		}
	}
}

Triangle::Triangle(bool hasColor ,bool hasNormal  ,bool hasTexture ) : Shape(hasColor, hasNormal, hasTexture)
{
	INFO("Leaveing Triangle init...");
}

Triangle::~Triangle()
{
}
void Triangle::setup(Shader shader)
{
	setShader(shader);
	//triangle
	FYJVector3D tri_vertices[] = {
		FYJVector3D(-1.0f, 0, 0),
		FYJVector3D(1.0f, 0, 0),
		FYJVector3D(0, 1.0f, 0)
	};
	FYJVector4D tri_colors[] = {
		FYJVector4D(1.0f, 0, 0, 1.0f),
		FYJVector4D(0.0f, 1, 0, 1.0f),
		FYJVector4D(0.0f, 0, 1.0f, 1.0f)
	};
	FYJVector2D tri_texCoords[] = {
		FYJVector2D(0, 0),
		FYJVector2D(1, 0),
		FYJVector2D(0.5f, 1)
	};
	if (hasTexture)
		begin(GL_TRIANGLE_STRIP, 3, 1);
	else 
		begin(GL_TRIANGLE_STRIP, 3, 0);

	setVertexData(tri_vertices);

	if (hasColor)
		setColorData(tri_colors); 

	if (hasTexture) {
		setTexCoordData(0, tri_texCoords);	
	}
	end();

}

void Triangle::draw()
{
	glDrawArrays(primitiveType, 0 , nNumVertexCount);
}

Square::Square(bool hasColor ,bool hasNormal  ,bool hasTexture ) : Shape(hasColor, hasNormal, hasTexture)
{
}

Square::~Square()
{
}

void Square::setup(Shader shader)
{
	setShader(shader);
	//square
	FYJVector3D square_vertices[] = {
		FYJVector3D(-1.0f, -1.0f,  0.0f), 
		FYJVector3D(1.0f, -1.0f,	0.0f), 
		FYJVector3D(-1.0f,  1.0f,  0.0f),
		FYJVector3D(1.0f,  1.0f,  0.0f),
	};
	FYJVector4D square_colors[] = {
		FYJVector4D(1.0f, 0, 0, 1.0f),
		FYJVector4D(0.0f, 1, 0, 1.0f),
		FYJVector4D(0.0f, 0, 1.0f, 1.0f),
		FYJVector4D(1.0f, 0, 1.0f, 1.0f)
	};
	FYJVector2D square_texCoords[] = {
		FYJVector2D(1.0f, 1.0f), 
		FYJVector2D(0.0f, 1.0f), 
		FYJVector2D(1.0f, 0.0f),
		FYJVector2D(0.0f, 0.0f),
	};

	if (hasTexture)
		begin(GL_TRIANGLE_STRIP, 4, 1);
	else 
		begin(GL_TRIANGLE_STRIP, 4, 0);

	setVertexData(square_vertices);

	if (hasColor)
		setColorData(square_colors); 

	if (hasTexture) {
		setTexCoordData(0, square_texCoords);	
	}
	end();

	

}

Cube::Cube(bool hasColor ,bool hasNormal  ,bool hasTexture ) : Shape(hasColor, hasNormal, hasTexture)
{
}

Cube::~Cube()
{
}

void Cube::setup(Shader shader )
{
	setShader(shader);
	//cube
	FYJVector3D cube_vertices[] = {
		FYJVector3D(-1.0f, -1.0f,  1.0f), FYJVector3D(1.0f, -1.0f,  1.0f), FYJVector3D(-1.0f,  1.0f,  1.0f),FYJVector3D(1.0f,  1.0f,  1.0f),
		FYJVector3D(-1.0f, -1.0f, -1.0f), FYJVector3D(-1.0f,  1.0f, -1.0f), FYJVector3D(1.0f,  -1.0f, -1.0f), FYJVector3D(1.0f, 1.0f, -1.0f),
		FYJVector3D(-1.0f,  1.0f, -1.0f), FYJVector3D(-1.0f,  1.0f,  1.0f), FYJVector3D(1.0f,  1.0f,  -1.0f),FYJVector3D(1.0f,  1.0f, 1.0f),
		FYJVector3D(-1.0f, -1.0f, -1.0f), FYJVector3D(1.0f, -1.0f, -1.0f), FYJVector3D(-1.0f, -1.0f,  1.0f), FYJVector3D(1.0f, -1.0f,  1.0f),
		FYJVector3D(1.0f, -1.0f, -1.0f), FYJVector3D(1.0f,  1.0f, -1.0f), FYJVector3D(1.0f,  -1.0f,  1.0f), FYJVector3D(1.0f, 1.0f,  1.0f), 
		FYJVector3D(-1.0f, -1.0f, -1.0f), FYJVector3D(-1.0f, -1.0f,  1.0f), FYJVector3D(-1.0f,  1.0f,  -1.0f), FYJVector3D(-1.0f,  1.0f, 1.0f), 
	};
	
	FYJVector4D cube_colors[] = {
		FYJVector4D(1.0f, 0, 0, 1.0f), FYJVector4D(1.0f, 0, 0, 1.0f), FYJVector4D(1.0f, 0, 0, 1.0f),FYJVector4D(1.0f, 0, 0, 1.0f),
		FYJVector4D(0.0f, 1, 0, 1.0f), FYJVector4D(0.0f, 1, 0, 1.0f), FYJVector4D(0.0f, 1, 0, 1.0f), FYJVector4D(0.0f, 1, 0, 1.0f),
		FYJVector4D(0.0f, 0, 1.0f, 1.0f), FYJVector4D(0.0f, 0, 1.0f, 1.0f), FYJVector4D(0.0f, 0, 1.0f, 1.0f),FYJVector4D(0.0f, 0, 1.0f, 1.0f),
		FYJVector4D(1.0f, 0, 0, 1.0f), FYJVector4D(1.0f, 0, 0, 1.0f), FYJVector4D(1.0f, 0, 0, 1.0f),FYJVector4D(1.0f, 0, 0, 1.0f),
		FYJVector4D(0.0f, 1, 0, 1.0f), FYJVector4D(0.0f, 1, 0, 1.0f), FYJVector4D(0.0f, 1, 0, 1.0f), FYJVector4D(0.0f, 1, 0, 1.0f),
		FYJVector4D(0.0f, 0, 1.0f, 1.0f), FYJVector4D(0.0f, 0, 1.0f, 1.0f), FYJVector4D(0.0f, 0, 1.0f, 1.0f),FYJVector4D(0.0f, 0, 1.0f, 1.0f),
	};
	
	FYJVector2D cube_texCoords[] = {
		FYJVector2D(1.0f, 1.0f), FYJVector2D(1.0f, 0.0f), FYJVector2D(0.0f, 1.0f),FYJVector2D(0.0f, 0.0f),
		FYJVector2D(1.0f, 1.0f), FYJVector2D(1.0f, 0.0f), FYJVector2D(0.0f, 1.0f),FYJVector2D(0.0f, 0.0f),
		FYJVector2D(1.0f, 1.0f), FYJVector2D(1.0f, 0.0f), FYJVector2D(0.0f, 1.0f),FYJVector2D(0.0f, 0.0f),
		FYJVector2D(1.0f, 1.0f), FYJVector2D(1.0f, 0.0f), FYJVector2D(0.0f, 1.0f),FYJVector2D(0.0f, 0.0f),
		FYJVector2D(1.0f, 1.0f), FYJVector2D(1.0f, 0.0f), FYJVector2D(0.0f, 1.0f),FYJVector2D(0.0f, 0.0f),
		FYJVector2D(1.0f, 1.0f), FYJVector2D(1.0f, 0.0f), FYJVector2D(0.0f, 1.0f),FYJVector2D(0.0f, 0.0f),
	};

	if (hasTexture)
		begin(GL_TRIANGLE_STRIP, 24, 1);
	else 
		begin(GL_TRIANGLE_STRIP, 24, 0);

	setVertexData(cube_vertices);

	if (hasColor)
		setColorData(cube_colors); 

	if (hasTexture) {
		setTexCoordData(0, cube_texCoords);	
	}
	end();
}
