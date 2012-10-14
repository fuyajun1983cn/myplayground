#ifndef SQUARE_H
#define SQUARE_H

#include <SDL/SDL.h>

class Square
{
private:
    //the collison box of the square
    SDL_Rect box;

    //The velocity of the square
    int xVel, yVel;

public:
    //initialize the variables
    Square();

    //Takes key presses and adjusts the square's velocity
    void handle_input();

    //Moves the square
    void move();

    //Shows the square on the screen
    void show();
};

#endif // SQUARE_H
