#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <string>
#include <sstream>
#include <iostream>
/**
  * 帧率调整测试
  */

class Timer
{
private:
    int startTicks;//计时器启动时的微秒数

    int pausedTicks;//计时器暂停时的微秒数

    //the Timer status
    bool paused;
    bool started;

public:
    //init
    Timer();

    //the various clock actions
    void start();
    void stop();
    void pause();
    void unpause();

    //Gets the Timer's times;
    int get_ticks();

    //check the timer's status
    bool is_started();
    bool is_paused();
};

Timer::Timer()
{
    startTicks = 0;
    pausedTicks = 0;
    paused = false;
    started = false;
}

void Timer::start()
{
    //Start the timer
    started = true;
    //Unpause the timer
    paused = false;
    //Get the current clock time
    startTicks = SDL_GetTicks();
}

void Timer::stop()
{
    started = false;
    paused = false;
}

int Timer::get_ticks()
{
    if (started == true) {
        if (paused == true) {
            return pausedTicks;
        } else {
            return SDL_GetTicks() - startTicks;
        }
    }
    return 0;
}

void Timer::pause()
{
    if (started == true && paused == false) {
        paused = true;
        pausedTicks = SDL_GetTicks() - startTicks;
    }
}

void Timer::unpause()
{
    if (paused == true) {
        paused = false;
        startTicks = SDL_GetTicks() - startTicks;
        pausedTicks = 0;
    }
}

bool Timer::is_paused()
{
    return paused;
}

bool Timer::is_started()
{
    return started;
}


using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

const int FRAMES_PER_SECOND = 20;

//The surfaces that will be used
SDL_Surface *background = NULL;
SDL_Surface *seconds = NULL;
SDL_Surface *message = NULL;
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

    SDL_WM_SetCaption("Frame Rate Test", NULL);

    return true;
}

bool load_files()
{
    //load images
    background = load_image("background.png");

    if (background == NULL)
        return false;

    font = load_font("lazy.ttf", 50);
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
   TTF_CloseFont(font);

   //Quit SDL_ttf
   TTF_Quit();

   //Quit SDL
   SDL_Quit();
}

int main(int argc, char *argv[])
{
    //设置工程目录
    putenv("PROJECT_PATH=/home/fuyajun/myplayground/sdl/SDLTutorials/lesson13");

    int frame = 0;
    bool cap = true;

    Timer fps;

    bool quit = false;

    if (init() == false)
        return 1;

    if (load_files() == false)
        return 1;

    //Render the text
    message = TTF_RenderText_Solid( font, "Testing Frame Rate", textColor );

    while (quit == false) {
        fps.start();
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_RETURN) {
                    cap = ( !cap );
                }
            } else if (event.type == SDL_QUIT) {
                quit = true;
                break;
            }
        }

        //Apply the background
        apply_surface( 0, 0, background, screen );

        //Apply the message
        apply_surface( ( SCREEN_WIDTH - message->w ) / 2, ( ( SCREEN_HEIGHT + message->h * 2 ) / FRAMES_PER_SECOND ) * ( frame % FRAMES_PER_SECOND ) - message->h, message, screen );

        if (SDL_Flip(screen) == -1)
            return 1;

        frame++;

        //If we want to cap the frame rate  如果帧率小于20, 就要延迟一下,以保证最小帧率20
        if( ( cap == true ) && ( fps.get_ticks() < 1000 / FRAMES_PER_SECOND ) ) {
            //Sleep the remaining frame time
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
        }
    }

    clean_up();

    return 0;
}

