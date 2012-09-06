#include "camera.h"
#include <math.h>


void Camera::Position_Camera(float pos_x,  float pos_y,  float pos_z,
                              float view_x, float view_y, float view_z,
                              float up_x,   float up_y,   float up_z)
{
    mPos	= Vector3D(pos_x,  pos_y,  pos_z ); // set position
    mView	= Vector3D(view_x, view_y, view_z); // set view
    mUp		= Vector3D(up_x,   up_y,   up_z  ); // set the up vector
}



void Camera::Move_Camera(float speed)
{
    Vector3D vVector = mView - mPos;	// Get the view vector

    // forward positive camera speed and backward negative camera speed.
    mPos.x  = mPos.x  + vVector.x * speed;
    mPos.z  = mPos.z  + vVector.z * speed;
    mView.x = mView.x + vVector.x * speed;
    mView.z = mView.z + vVector.z * speed;
}

//旋转摄像机
void Camera::Rotate_View(float speed)
{
    Vector3D vVector = mView - mPos;	// the view vector

    mView.z = (float)(mPos.z + sin(speed)*vVector.x + cos(speed)*vVector.z);
    mView.x = (float)(mPos.x + cos(speed)*vVector.x - sin(speed)*vVector.z);
}
