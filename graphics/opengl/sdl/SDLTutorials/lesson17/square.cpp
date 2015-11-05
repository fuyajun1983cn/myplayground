#include "square.h"
#include "common.h"
#include <iostream>

//The attributes of the square
const int SQUARE_WIDTH = 20;
const int SQUARE_HEIGHT = 20;

Square::Square()
{
    //Initialize the offsets
     box.x = 0;
     box.y = 0;

     //Set the square's dimensions
     box.w = SQUARE_WIDTH;
     box.h = SQUARE_HEIGHT;

     //Initialize the velocity
     xVel = 0;
     yVel = 0;
}

void Square::move()
{
    //Move the square left or right
    box.x += xVel;
    std::cout<<"x = "<<box.x<<std::endl;
    //If the square went too far to the left or right or has collided with the wall
    if( ( box.x < 0 ) || ( box.x + SQUARE_WIDTH > SCREEN_WIDTH ) || ( check_collision( box, wall ) ) )
    {
        //Move back
        box.x -= xVel;
    }

    box.y += yVel;

    if( ( box.y < 0 ) || ( box.y + SQUARE_HEIGHT > SCREEN_HEIGHT ) || ( check_collision( box, wall ) ) )
    {
        box.y -= yVel;
    }
}

void Square::show()
{
    //Show the square
    apply_surface( box.x, box.y, square, screen );
}

void Square::handle_input()
{
    //If a key was pressed
    if( event.type == SDL_KEYDOWN )
    {
        //Adjust the velocity
        switch( event.key.keysym.sym )
        {
            case SDLK_UP: yVel -= SQUARE_HEIGHT / 2; break;
            case SDLK_DOWN: yVel += SQUARE_HEIGHT / 2; break;
            case SDLK_LEFT: xVel -= SQUARE_WIDTH / 2; break;
            case SDLK_RIGHT: xVel += SQUARE_WIDTH / 2; break;
        }
    }
    //If a key was released
    else if( event.type == SDL_KEYUP )
    {
        //Adjust the velocity
        switch( event.key.keysym.sym )
        {
            case SDLK_UP: yVel += SQUARE_HEIGHT / 2; break;
            case SDLK_DOWN: yVel -= SQUARE_HEIGHT / 2; break;
            case SDLK_LEFT: xVel += SQUARE_WIDTH / 2; break;
            case SDLK_RIGHT: xVel -= SQUARE_WIDTH / 2; break;
        }
    }
}
