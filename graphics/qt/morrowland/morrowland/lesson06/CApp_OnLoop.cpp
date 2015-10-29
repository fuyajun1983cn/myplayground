#include "CApp.h"

void CApp::OnLoop()
{
    rot_angle = rot_angle + 0.01f;
    if (rot_angle > 360)
        rot_angle = 0;
}
