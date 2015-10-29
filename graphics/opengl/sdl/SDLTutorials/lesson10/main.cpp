#include <iostream>
#include <string>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

/**
  * 按钮状态测试
  */

using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

//The surfaces that will be used
SDL_Surface *background = NULL;
SDL_Surface *upKey = NULL;
SDL_Surface *downKey = NULL;
SDL_Surface *leftKey = NULL;
SDL_Surface *rightKey = NULL;
SDL_Surface *screen = NULL;
//event
SDL_Event event;

//font
TTF_Font *font = NULL;
//the colore of the font
SDL_Color textColor = { 0, 0, 0 };

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

    SDL_WM_SetCaption("Key State Test", NULL);

    return true;
}

bool load_files()
{
    //load images
    background = load_image("background.png");

    if (background == NULL)
        return false;

    font = load_font("lazy.ttf", 72);
    if (font == NULL)
        return false;

    return true;
}

void clean_up()
{
    //Free the surfaces
    SDL_FreeSurface(background);
    SDL_FreeSurface(upKey);
    SDL_FreeSurface(downKey);
    SDL_FreeSurface(leftKey);
    SDL_FreeSurface(rightKey);

   //Close the font that was used
   TTF_CloseFont(font);

   //Quit SDL_ttf
   TTF_Quit();

   //Quit SDL
   SDL_Quit();
}

int main(int argc, char *argv[])
{
    //设置工程目录
    putenv("PROJECT_PATH=/home/fuyajun/myplayground/sdl/SDLTutorials/lesson10");

    bool quit = false;

    if (init() == false)
        return 1;

    if (load_files() == false)
        return 1;

    //Render the text
    upKey = TTF_RenderText_Solid( font, "Up", textColor );
    downKey = TTF_RenderText_Solid( font, "Down", textColor );
    leftKey = TTF_RenderText_Solid( font, "Left", textColor );
    rightKey = TTF_RenderText_Solid( font, "Right", textColor );

    apply_surface(0, 0, background, screen);

    if (SDL_Flip(screen) == -1)
        return 1;


    while (quit == false) {

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        //Apply the background
        apply_surface( 0, 0, background, screen );

        //Get the keystates
       Uint8 *keystates = SDL_GetKeyState( NULL );

       //If up is pressed
       if( keystates[ SDLK_UP ] )
       {
           apply_surface( ( SCREEN_WIDTH - upKey->w ) / 2, ( SCREEN_HEIGHT / 2 - upKey->h ) / 2, upKey, screen );
       }

       //If down is pressed
       if( keystates[ SDLK_DOWN ] )
       {
           apply_surface( ( SCREEN_WIDTH - downKey->w ) / 2, ( SCREEN_HEIGHT / 2 - downKey->h ) / 2 + ( SCREEN_HEIGHT / 2 ), downKey, screen );
       }

       //If left is pressed
       if( keystates[ SDLK_LEFT ] )
       {
           apply_surface( ( SCREEN_WIDTH / 2 - leftKey->w ) / 2, ( SCREEN_HEIGHT - leftKey->h ) / 2, leftKey, screen );
       }

       //If right is pressed
       if( keystates[ SDLK_RIGHT ] )
       {
           apply_surface( ( SCREEN_WIDTH / 2 - rightKey->w ) / 2 + ( SCREEN_WIDTH / 2 ), ( SCREEN_HEIGHT - rightKey->h ) / 2, rightKey, screen );
       }

       //Update the screen
       if( SDL_Flip( screen ) == -1 )
       {
           return 1;
       }

    }

    clean_up();

    return 0;
}

