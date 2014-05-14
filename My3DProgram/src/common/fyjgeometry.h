#ifndef FYJ_GEOMETRY_H
#define FYJ_GEOMETRY_H
#include "fyjstd.h"
#include "math3d.h"
#include "fyjshader.h"

namespace FYJ
{
class Program;
//base class for all 3d objects
class FYJ_API Geometry
{
	public:
		virtual void draw() = 0;
};

class Shape : public Geometry
{
	public:
		Shape(bool hasColor = true, bool hasNormal = false, bool hasTexture = false);
		virtual ~Shape();

		virtual void draw();
		void begin(GLenum primitive, GLuint nVertexCount = 0, GLuint nTextureUnits = 0);
		void end();

		Shader getShader() { return shaderInUse; } 
		void setShader(Shader s) ;
		Program* getProgram() { return program; }

		virtual void setColor(FYJVector4D color);
		virtual void setVertexData(FYJVector3D *vertices);
		virtual void setColorData(FYJVector4D *colors);
		virtual void setNormalData(FYJVector3D *normals);
		virtual void setTexCoordData(GLuint textureUnit, FYJVector2D *vTexCoord);

		bool isTextured() { return hasTexture; }

		void clearData();

	protected:
		bool hasTexture;
		bool hasNormal;
		bool hasColor;

		//gl properites
		GLenum primitiveType; //What am I drawing
		GLuint vertexBuffer;
		GLuint colorBuffer;
		GLuint normalBuffer;
		GLuint *texCoordBuffers;
		GLuint *texHandles;

		GLuint nNumTextureUnits;// Number of texture coordinate sets
		GLuint nNumVertexCount;

		Program *program;
		Shader shaderInUse;
		FYJVector4D color;

};

class Triangle : public Shape 
{
public:
	Triangle(bool hasColor = true, bool hasNormal = false, bool hasTexture = false);
	~Triangle();
	void setup(Shader shader = FYJ_SHADER_IDENTITY);
	void draw();
};

class Square : public Shape
{
public :
	Square(bool hasColor = true, bool hasNormal = false, bool hasTexture = false);
	~Square();
	void setup(Shader shader = FYJ_SHADER_IDENTITY);
};

class Cube : public Shape
{
public:
	Cube(bool hasColor = true, bool hasNormal = false, bool hasTexture = false);
	~Cube();
	void setup(Shader shader = FYJ_SHADER_IDENTITY);
};

class Sphere: public Shape
{
	public:
		Sphere(float radius, int stacks, int slices, bool hasColor = false, bool hasNormal = true, bool hasTexture = true);
		~Sphere();
		void setup(Shader shader = FYJ_SHADER_IDENTITY,  bool isWired=false);
		void draw();
		void setVertexData(FYJVector3D *vertices);
		void setColorData(FYJVector4D *colors);
		void setNormalData(FYJVector3D *normals);
		void setTexCoordData(GLuint textureUnit, FYJVector2D *vTexCoord);

	private:
		void makeSphere();
		
		int stacks;
		int slices;
		float radius;

		int currentVerts;

};

class Torus: public Shape
{
	public:
		Torus(float majorRadius, float minorRadius, int numMajor, int numMinor, bool hasColor = false, bool hasNormal = true, bool hasTexture = true);
		~Torus();
		void setup(Shader shader = FYJ_SHADER_IDENTITY,  bool isWired=false);
		void draw();
		void setVertexData(FYJVector3D *vertices);
		void setNormalData(FYJVector3D *normals);
		void setTexCoordData(GLuint textureUnit, FYJVector2D *vTexCoord);

	private:
		void makeTorus();
		
		float majorRadius;
		float minorRadius;
		int numMajor;
		int numMinor;
		float radius;

		int currentVerts;

};


}
#endif
