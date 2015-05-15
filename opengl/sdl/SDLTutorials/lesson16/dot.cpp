#include "dot.h"

Dot::Dot()
{
    x = 0;
    y = 0;

    xVel = 0;
    yVel = 0;
}

void Dot::handle_input()
{
    if (event.type == SDL_KEYDOWN) {
        //Adjust the velocity
        switch( event.key.keysym.sym ) {
        case SDLK_UP: yVel -= DOT_HEIGHT / 2; break;
        case SDLK_DOWN: yVel += DOT_HEIGHT / 2; break;
        case SDLK_LEFT: xVel -= DOT_WIDTH / 2; break;
        case SDLK_RIGHT: xVel += DOT_WIDTH / 2; break;
        default:
            break;
        }
    } else if (event.type == SDL_KEYUP) {
        switch( event.key.keysym.sym ) {
        case SDLK_UP: yVel += DOT_HEIGHT / 2; break;
        case SDLK_DOWN: yVel -= DOT_HEIGHT / 2; break;
        case SDLK_LEFT: xVel += DOT_WIDTH / 2; break;
        case SDLK_RIGHT: xVel -= DOT_WIDTH / 2; break;
        default:
            break;
        }
    }

}

void Dot::move()
{
    x += xVel;

    if( ( x < 0 ) || ( x + DOT_WIDTH > SCREEN_WIDTH ) ) {
        x -= xVel;
    }

    y += yVel;

    if( ( y < 0 ) || ( y + DOT_HEIGHT > SCREEN_HEIGHT ) ) {
        y -= yVel;
    }
}

void Dot::show()
{
    apply_surface(x, y, dot, screen);
}
