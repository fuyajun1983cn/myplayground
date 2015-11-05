#include <iostream>
#include <string>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

/**
  * 演示SDL_image扩展库的使用
  */

using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

//The surfaces that will be used
SDL_Surface *logo = NULL;
SDL_Surface *preview = NULL;
SDL_Surface *screen = NULL;

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

int main(int argc, char *argv[])
{
    //设置工程目录
    putenv("PROJECT_PATH=/home/fuyajun/myplayground/sdl/SDLTutorials/lesson03");

    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
        return 1;

    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
    if (screen == NULL)
        return 1;

    SDL_WM_SetCaption("加载多种格式图片", NULL);

    //load images
    logo = load_image("logo.jpg");
    preview = load_image("preview.png");

    apply_surface(0, 0, preview, screen);

    apply_surface( 180, 140, logo, screen );

    if (SDL_Flip(screen) == -1)
        return 1;

    //pause 2 seconds
    SDL_Delay(2000);

     //Free the surfaces
    SDL_FreeSurface( logo );
    SDL_FreeSurface( preview );

    //Quit SDL
    SDL_Quit();

    return 0;
}

