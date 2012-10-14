#ifndef CCAMERA_H
#define CCAMERA_H

#include <SDL.h>

#include "CDefine.h"

enum {
    TARGET_MODE_NORMAL = 0,
    TARGET_MODE_CENTER
};

class CCamera
{
    public:
        CCamera();
        virtual ~CCamera();

 public:
        static CCamera CameraControl;

    private:
        int X;
        int Y;

        int* TargetX;
        int* TargetY;

    public:
        int TargetMode;

    public:
        void OnMove(int MoveX, int MoveY);

    public:
        int GetX();
        int GetY();

    public:
        void SetPos(int X, int Y);

        void SetTarget(int* X, int* Y);
};

#endif // CCAMERA_H
