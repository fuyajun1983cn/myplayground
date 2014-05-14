#include "fyjcamera.h"

using namespace FYJ;

Camera::Camera()
{
}

Camera::~Camera()
{
}

void Camera::translate(float x, float y, float z)
{
	mMVMatrix = glm::translate(mMVMatrix, glm::vec3(x, y, z));
	mNormalMatrix = glm::inverseTranspose(glm::mat3(mMVMatrix));
}

void Camera::scale(float x, float y, float z)
{
	mMVMatrix = glm::scale(mMVMatrix, glm::vec3(x , y, z));
	mNormalMatrix = glm::inverseTranspose(glm::mat3(mMVMatrix));
}

void Camera::rotate(float angle, float x, float y, float z)
{
	mMVMatrix = glm::rotate(mMVMatrix, angle, glm::vec3(x, y, z));
	mNormalMatrix = glm::inverseTranspose(glm::mat3(mMVMatrix));
}

void Camera::setLookAt(float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ)
{
	mMVMatrix = glm::lookAt(glm::vec3(eyeX, eyeY, eyeZ), glm::vec3(centerX, centerY, centerZ), glm::vec3(upX, upY, upZ));
	mResetValueForMV = mMVMatrix;
	mNormalMatrix = glm::inverseTranspose(glm::mat3(mMVMatrix));
}

void Camera::setPerspective(float fovy, float aspect, float near, float far)
{
	mProjMatrix = glm::perspective(fovy, aspect, near, far);
}

void Camera::setOrtho(float left, float right, float bottom, float top)
{
	mProjMatrix = glm::ortho(left, right, bottom, top);
}

void Camera::reset()
{
	mMVMatrix = mResetValueForMV;
	mNormalMatrix = glm::inverseTranspose(glm::mat3(mMVMatrix));
}

void Camera::setLightPos(float x,float y,float z,float w)
{
	mLightPos = glm::vec4(x, y, z, w);
}

void *Camera::vPtrForMVP()
{
	glm::mat4 tempMatrix = mProjMatrix * mMVMatrix;
	return glm::value_ptr(tempMatrix);
}

void *Camera::vPtrForMV()
{
	return glm::value_ptr(mMVMatrix);
}

void *Camera::vPtrForProj()
{
	return glm::value_ptr(mProjMatrix);
}

void *Camera::vPtrForNM()
{
	//MV矩阵左上角3X3子矩阵转置的逆
	//glm::mat3 nm = glm::inverseTranspose(glm::mat3(mMVMatrix));
	return glm::value_ptr(mNormalMatrix);
}

void *Camera::vPtrForLightPos()
{
	return glm::value_ptr(mLightPos);
}


