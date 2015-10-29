#ifndef CCAMERA_H
#define CCAMERA_H

#include "CMaths.h"

class Camera
{
public:

    Vector3D mPos;		// camera position
    Vector3D mView;		// camera view(target)
    Vector3D mUp;		// camera upvector(tilt)

    int mWindowWidth;
    int mWindowHeight;

    // This function makes it possible to rotate around a given point
    void Rotate_Position(float speed);

    void Strafe_Camera(float speed);

    void Mouse_Move(int mouse_x, int mouse_y, int wndWidth, int wndHeight);

    void Rotate_View(float x, float y, float z);

    // This function will move the camera depending on the camera speed
    void Move_Camera(float speed);

    // This function sets the camera position
    void Position_Camera(float pos_x,  float pos_y,  float pos_z,
                         float view_x, float view_y, float view_z,
                         float up_x,   float up_y,   float up_z);
};

#endif // CCAMERA_H
