#ifndef DOT_H
#define DOT_H

#include "common.h"

//The dimensions of the dot
const int DOT_WIDTH = 20;
const int DOT_HEIGHT = 20;

class Dot
{
private:
    //X Y 偏移量
    int x, y;

    //the velocity of the dot
    int xVel, yVel;

public:
    Dot();

    void handle_input();

    void move();

    void show();
};

#endif // DOT_H
