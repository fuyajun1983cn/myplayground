#include "CFPS.h"

CFPS CFPS::FPSControl;

CFPS::CFPS()
{
    //ctor
    OldTime     = 0;
    LastTime    = 0;

    SpeedFactor    = 0;

    Frames      = 0;
    NumFrames   = 0;
}

CFPS::~CFPS()
{
    //dtor
}

void CFPS::OnLoop() {
    if(OldTime + 1000 < SDL_GetTicks()) {
        OldTime = SDL_GetTicks();

        NumFrames = Frames;

        Frames = 0;
    }

    SpeedFactor = ((SDL_GetTicks() - LastTime) / 1000.0f) * 32.0f;

    LastTime = SDL_GetTicks();

    Frames++;
}

int CFPS::GetFPS() {
    return NumFrames;
}

float CFPS::GetSpeedFactor() {
    return SpeedFactor;
}
