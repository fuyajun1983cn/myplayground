#include "dot.h"
#include <iostream>

Dot::Dot(int _x, int _y)
{
    x = _x;
    y = _y;

    xVel = 0;
    yVel = 0;

    box.resize(11);

    //Initialize the collision boxes' width and height
    box[ 0 ].w = 6; box[ 0 ].h = 1;
    box[ 1 ].w = 10; box[ 1 ].h = 1;
    box[ 2 ].w = 14; box[ 2 ].h = 1;
    box[ 3 ].w = 16; box[ 3 ].h = 2;
    box[ 4 ].w = 18; box[ 4 ].h = 2;
    box[ 5 ].w = 20; box[ 5 ].h = 6;
    box[ 6 ].w = 18; box[ 6 ].h = 2;
    box[ 7 ].w = 16; box[ 7 ].h = 2;
    box[ 8 ].w = 14; box[ 8 ].h = 1;
    box[ 9 ].w = 10; box[ 9 ].h = 1;
    box[ 10 ].w = 6; box[ 10 ].h = 1;

    //Move the collision boxes to their proper spot
    shift_boxes();
}

void Dot::handle_input()
{
    if (event.type == SDL_KEYDOWN) {
        //Adjust the velocity
        switch( event.key.keysym.sym ) {
        case SDLK_UP: yVel -= 1; break;
        case SDLK_DOWN: yVel += 1; break;
        case SDLK_LEFT: xVel -= 1; break;
        case SDLK_RIGHT: xVel += 1; break;
        default:
            break;
        }
    } else if (event.type == SDL_KEYUP) {
        switch( event.key.keysym.sym ) {
        case SDLK_UP: yVel += 1; break;
        case SDLK_DOWN: yVel -= 1; break;
        case SDLK_LEFT: xVel += 1; break;
        case SDLK_RIGHT: xVel -= 1; break;
        default:
            break;
        }
    }

}

void Dot::move(std::vector<SDL_Rect> &rects)
{
    x += xVel;
    shift_boxes();
    if( ( x < 0 ) || ( x + DOT_WIDTH > SCREEN_WIDTH ) || check_collision( box, rects ) ) {
        x -= xVel;
        shift_boxes();
    }

    y += yVel;
    shift_boxes();

    if( ( y < 0 ) || ( y + DOT_HEIGHT > SCREEN_HEIGHT ) || check_collision( box, rects )  ) {
        y -= yVel;
        shift_boxes();
    }
}

void Dot::show()
{
    apply_surface(x, y, dot, screen);
}

void Dot::shift_boxes()
{
     //The row offset
    int r = 0;

    //Go through the dot's collision boxes
    for( int set = 0; set < box.size(); set++ ) {
        //Center the collision box
        box[ set ].x = x + ( DOT_WIDTH - box[ set ].w ) / 2;
        //Set the collision box at its row offset
        box[ set ].y = y + r;
        //Move the row offset down the height of the collision box
        r += box[ set ].h;
    }
}

std::vector<SDL_Rect> &Dot::get_rects()
{
    //Retrieve the collision boxes
    return box;
}
