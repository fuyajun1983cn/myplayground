#ifndef CANIMATION_H
#define CANIMATION_H

#include <SDL/SDL.h>

class CAnimation
{
    private:
        int CurrentFrame;
        int FrameInc;

    private:
        int FrameRate;//Millisends
        long OldTime;

    public:
        int MaxFrames;
        bool Oscillate;

    public:
        CAnimation();
        virtual ~CAnimation();
        void OnAnimation();

    public:
        void SetFrameRate(int Rate);
        void SetCurrentFrame(int Frame);
        int GetCurrentFrame();
};

#endif // CANIMATION_H
