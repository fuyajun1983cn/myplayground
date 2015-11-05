#include "timer.h"
#include <SDL/SDL.h>

Timer::Timer()
{
    startTicks = 0;
    pausedTicks = 0;
    paused = false;
    started = false;
}

void Timer::start()
{
    //Start the timer
    started = true;
    //Unpause the timer
    paused = false;
    //Get the current clock time
    startTicks = SDL_GetTicks();
}

void Timer::stop()
{
    started = false;
    paused = false;
}

int Timer::get_ticks()
{
    if (started == true) {
        if (paused == true) {
            return pausedTicks;
        } else {
            return SDL_GetTicks() - startTicks;
        }
    }
    return 0;
}

void Timer::pause()
{
    if (started == true && paused == false) {
        paused = true;
        pausedTicks = SDL_GetTicks() - startTicks;
    }
}

void Timer::unpause()
{
    if (paused == true) {
        paused = false;
        startTicks = SDL_GetTicks() - startTicks;
        pausedTicks = 0;
    }
}

bool Timer::is_paused()
{
    return paused;
}

bool Timer::is_started()
{
    return started;
}

