#include "CCamera.h"

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
void Camera::Rotate_View(float x, float y , float z)
{
    Vector3D vVector = mView - mPos;

    if(x)
    {
        mView.z = (float)(mPos.z + sin(x)*vVector.y + cos(x)*vVector.z);
        mView.y = (float)(mPos.y + cos(x)*vVector.y - sin(x)*vVector.z);
    }
    if(y)
    {
        mView.z = (float)(mPos.z + sin(y)*vVector.x + cos(y)*vVector.z);
        mView.x = (float)(mPos.x + cos(y)*vVector.x - sin(y)*vVector.z);
    }
    if(z)
    {
        mView.x = (float)(mPos.x + sin(z)*vVector.y + cos(z)*vVector.x);
        mView.y = (float)(mPos.y + cos(z)*vVector.y - sin(z)*vVector.x);
    }
}

void Camera::Mouse_Move(int mouse_x, int mouse_y, int wndWidth, int wndHeight)
{
    int mid_x = wndWidth  >> 1;
    int mid_y = wndHeight >> 1;
    float angle_y  = 0.0f;
    float angle_z  = 0.0f;

    if( (mouse_x == mid_x) && (mouse_y == mid_y) ) return;


    // Get the direction from the mouse cursor, set a resonable maneuvering speed
    angle_y = (float)( (mid_x - mouse_x) ) / 1000;
    angle_z = (float)( (mid_y - mouse_y) ) / 1000;

    // The higher the value is the faster the camera looks around.
    mView.y += angle_z * 2;

    // limit the rotation around the x-axis
    if((mView.y - mPos.y) > 8)  mView.y = mPos.y + 8;
    if((mView.y - mPos.y) <-8)  mView.y = mPos.y - 8;

 //   Rotate_View(-angle_y); // Rotate
}

void Camera::Strafe_Camera(float speed)
{
    Vector3D vVector = mView - mPos;	// Get the view vector
    Vector3D vOrthoVector;              // Orthogonal vector for the view vector

    vOrthoVector.x = -vVector.z;
    vOrthoVector.z =  vVector.x;

    // left positive cameraspeed and right negative -cameraspeed.
    mPos.x  = mPos.x  + vOrthoVector.x * speed;
    mPos.z  = mPos.z  + vOrthoVector.z * speed;
    mView.x = mView.x + vOrthoVector.x * speed;
    mView.z = mView.z + vOrthoVector.z * speed;
}

void Camera::Rotate_Position(float speed)
{
    Vector3D vVector = mPos - mView;

    mPos.z = (float)(mView.z + sin(speed)*vVector.x + cos(speed)*vVector.z);
    mPos.x = (float)(mView.x + cos(speed)*vVector.x - sin(speed)*vVector.z);
}
