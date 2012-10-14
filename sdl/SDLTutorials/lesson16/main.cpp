#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>
#include <sstream>
#include <iostream>

#include "timer.h"
#include "dot.h"

//The surfaces that will be used
SDL_Surface *dot = NULL ;
SDL_Surface *screen = NULL ;
//event
SDL_Event event;

/**
  * 在屏幕上移动一个点
  */

using namespace std;

SDL_Surface *load_image(string filename)
{
    SDL_Surface *loadedImage = NULL;

    SDL_Surface *optimizedImage = NULL;

    string current_dir = string(getenv("PROJECT_PATH"));
    if (current_dir.at(current_dir.length()-1) != '/')
            current_dir += '/';
    string sPath = current_dir + filename;

    //加载图片(PNG, JPG, BMP etc)
    loadedImage = IMG_Load(sPath.c_str());
    if (loadedImage != NULL) {
        //创建优化后的图像
        optimizedImage = SDL_DisplayFormat(loadedImage);

        //释放旧的图片
        SDL_FreeSurface(loadedImage);

        if (optimizedImage != NULL) {
            int colorkey = SDL_MapRGB(optimizedImage->format, 0, 0xff, 0xff);
             //Set all pixels of color R 0, G 0xFF, B 0xFF to be transparent
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );
        }
    }

    return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}

bool init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
        return false;

    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
    if (screen == NULL)
        return false;

    SDL_WM_SetCaption("Motion Test", NULL);

    return true;
}

bool load_files()
{
    //load images
    dot = load_image("dot.bmp");

    if (dot == NULL)
        return false;

    return true;
}

void clean_up()
{
    //Free the surfaces
    SDL_FreeSurface(dot);

   //Quit SDL
   SDL_Quit();
}

int main(int argc, char *argv[])
{
    //设置工程目录
    putenv("PROJECT_PATH=/home/fuyajun/myplayground/sdl/SDLTutorials/lesson16");

    int frame = 0;

    Timer fps;
    Dot myDot;

    bool quit = false;

    if (init() == false)
        return 1;

    if (load_files() == false)
        return 1;

    fps.start();

    while (quit == false) {

        while (SDL_PollEvent(&event)) {
            myDot.handle_input();
            if (event.type == SDL_QUIT) {
                quit = true;
                break;
            }
        }

        myDot.move();

        //Rendering
        SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );

        myDot.show();

        if (SDL_Flip(screen) == -1)
            return 1;

        while( fps.get_ticks() < 1000 / FRAMES_PER_SECOND ){}
    }

    clean_up();

    return 0;
}
