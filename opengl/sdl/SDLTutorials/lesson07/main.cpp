#include <iostream>
#include <string>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

/**
  * 演示SDL_ttf, 显示字体
  */

using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

//The surfaces that will be used
SDL_Surface *background = NULL;
SDL_Surface *message = NULL;
SDL_Surface *screen = NULL;
//event
SDL_Event event;

//font
TTF_Font *font = NULL;
//the colore of the font
SDL_Color textColor = { 255, 255, 255 };

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

TTF_Font *load_font(string filename, int size)
{
    string current_dir = string(getenv("PROJECT_PATH"));
    if (current_dir.at(current_dir.length()-1) != '/')
            current_dir += '/';
    string sPath = current_dir + filename;

    TTF_Font *font = TTF_OpenFont(sPath.c_str(), size);

    return font;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
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

    //Initialize SDL ttf
    if (TTF_Init() == -1)
        return false;

    SDL_WM_SetCaption("TTF Test", NULL);

    return true;
}

bool load_files()
{
    //load images
    background = load_image("background.png");

    if (background == NULL)
        return false;

    font = load_font("lazy.ttf", 28);
    if (font == NULL)
        return false;

    return true;
}

void clean_up()
{
    //Free the surfaces
    SDL_FreeSurface(background);
   SDL_FreeSurface(message);

   //Close the font that was used
   TTF_CloseFont( font );

   //Quit SDL_ttf
   TTF_Quit();

   //Quit SDL
   SDL_Quit();
}

int main(int argc, char *argv[])
{
    //设置工程目录
    putenv("PROJECT_PATH=/home/fuyajun/myplayground/sdl/SDLTutorials/lesson07");

    bool quit = false;

    if (init() == false)
        return 1;

    if (load_files() == false)
        return 1;

    //Render the text
    message = TTF_RenderText_Solid( font, "The quick brown fox jumps over the lazy dog", textColor );
    if (message == NULL)
        return 1;

    apply_surface(0, 0, background, screen);
    apply_surface( 0, 150, message, screen );

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

