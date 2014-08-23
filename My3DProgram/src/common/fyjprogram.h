#ifndef FYJPROGRAM_H
#define FYJPROGRAM_H

#include "fyjstd.h"
#include "platform.h"
#include "os.h"
#include "fyjstring.h"

namespace FYJ
{

	/**
	  *  A GL Program holding usefull function to privode access 
	  *  to vertex to query attributes and uniforms
	  *
	  */

	class FYJ_API Program
	{
		public:

			enum AttributeType{
				POSITION = 0,
				NORMAL,
				COLOR,
				TEX_COORD0,
				TEX_COORD1,
				TEX_COORD2,
				TEX_COORD3,
				AttributeType_COUNT
			};

			enum UniformType {
				MODEL = AttributeType_COUNT,
				VIEW,
				PROJECT,
				MV,
				MVP,
				NM, //normal matrix
				TM, //texture matrix
				LIGHT_POS,
				COLOR2,
				SAMPLER2D, 
				SAMPLER2D_1,
				SAMPLER2D_2,
				SAMPLER2D_3,
				UniformType_COUNT
			};
			
			Program(const String &vertex,  const String &fragment);
			virtual ~Program();

			//bind this program to GL context
			virtual void use();
			//unbind
			virtual void abandon();

			//get attribute location
			GLuint getAttribute(AttributeType type, const String &name);

			void enableVertexAttribArray();

			//get uniform location			
			GLuint getUniform(UniformType type, const String &name);

			bool isInitialized() const {
				return m_initialized;
			}

		protected:
			GLuint addAttribute(AttributeType type, const String &name);
			
			GLuint addUniform(UniformType type, const String &name);
						

		private:
			//compiles the specified shader of the specified type
			GLuint buildShader(const String &source, GLenum type);
			//name of the OpenGL program
			GLuint id;
			//attribute
			GLuint attributes[AttributeType_COUNT];
			//uniform
			GLuint uniforms[UniformType_COUNT-AttributeType_COUNT];

			//name of the shaders
			GLuint vertexShader;
			GLuint fragmentShader;

			bool m_initialized;
			
	};
	
}

#endif
