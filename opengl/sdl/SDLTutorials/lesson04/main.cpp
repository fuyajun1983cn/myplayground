#include <iostream>
#include <string>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

/**
  * 演示SDL_event的使用
  */

using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

//The surfaces that will be used
SDL_Surface *image = NULL;
SDL_Surface *screen = NULL;
//event
SDL_Event event;

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
    }

    return optimizedImage;
}

void apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination)
{
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    SDL_BlitSurface(source, NULL, destination, &offset);
}

bool init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
        return false;

    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
    if (screen == NULL)
        return false;

    SDL_WM_SetCaption("Event Test", NULL);

    return true;
}

bool load_files()
{
    //load images
    image = load_image("preview.jpg");

    if (image == NULL)
        return false;
    return true;
}

void clean_up()
{
    //Free the surfaces
   SDL_FreeSurface( image );

   //Quit SDL
   SDL_Quit();
}

int main(int argc, char *argv[])
{
    //设置工程目录
    putenv("PROJECT_PATH=/home/fuyajun/myplayground/sdl/SDLTutorials/lesson04");

    bool quit = false;

    if (init() == false)
        return 1;

    if (load_files() == false)
        return 1;

    apply_surface(0, 0, image, screen);

    if (SDL_Flip(screen) == -1)
        return 1;


    while (quit == false) {

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    clean_up();

    return 0;
}

