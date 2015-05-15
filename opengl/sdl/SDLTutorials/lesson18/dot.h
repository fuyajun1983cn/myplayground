#ifndef DOT_H
#define DOT_H

#include "common.h"
#include <vector>

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

     //The collision boxes of the dot
    std::vector<SDL_Rect> box;

    void shift_boxes();

public:
    Dot(int x, int y);

    void handle_input();

    void move( std::vector<SDL_Rect> &rects);

    void show();

    //Gets the collision boxes
    std::vector<SDL_Rect> &get_rects();
};

#endif // DOT_H
