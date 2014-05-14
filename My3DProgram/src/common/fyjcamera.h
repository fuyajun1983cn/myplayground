#ifndef FYJCAMERA_H
#define FYJCAMERA_H

#include "fyjstd.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace FYJ
{
	class FYJ_API Camera
	{
		public:
			Camera();
			virtual ~Camera();

			void translate(float x, float y, float z);
			void scale(float x, float y, float z);
			void rotate(float angle, float x, float y, float z);
			void setLookAt(float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ);
			void setPerspective(float fovy, float aspect, float near, float far);
			void setOrtho(float left, float right, float bottom, float top);
			void reset();
			void setLightPos(float x, float y, float z, float w);

			void *vPtrForMVP();
			void *vPtrForMV();
			void *vPtrForProj();
			void *vPtrForNM(); //normal matrix
			void *vPtrForLightPos();

		private:
			glm::mat4 mMVMatrix;
			glm::mat4 mResetValueForMV;
			glm::mat4 mProjMatrix;
			glm::mat3 mNormalMatrix;

			//light position
			glm::vec4 mLightPos;
	};
}

#endif
