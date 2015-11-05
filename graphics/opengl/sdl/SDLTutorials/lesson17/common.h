#ifndef COMMON_H
#define COMMON_H

#include <SDL/SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

//The frame rate
const int FRAMES_PER_SECOND = 20;

//The surfaces that will be used
extern SDL_Surface *square ;
extern SDL_Surface *screen ;
//event
extern SDL_Event event;

extern SDL_Rect wall;

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL );

bool check_collision( SDL_Rect A, SDL_Rect B );

#endif // COMMON_H
