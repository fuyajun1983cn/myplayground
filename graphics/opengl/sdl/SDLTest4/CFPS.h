#ifndef CFPS_H
#define CFPS_H

#include <SDL/SDL.h>

class CFPS
{
    public:
        static CFPS FPSControl;

    private:
        int     OldTime;
        int     LastTime;

        float     SpeedFactor;

        int    NumFrames;
        int     Frames;

    public:
        CFPS();
        virtual ~CFPS();

        void OnLoop();

    public:
        int     GetFPS();

        float   GetSpeedFactor();
};

#endif // CFPS_H
