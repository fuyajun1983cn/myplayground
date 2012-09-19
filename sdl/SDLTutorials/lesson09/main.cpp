#include <iostream>
#include <string>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

/**
  * 演示鼠标检测
  */

using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

//The surfaces that will be used
SDL_Surface *buttonSheet = NULL;
SDL_Surface *background = NULL;
SDL_Surface *screen = NULL;
//event
SDL_Event event;

#define CLIP_MOUSEOVER 0
#define CLIP_MOUSEOUT 1
#define CLIP_MOUSEDOWN 2
#define CLIP_MOUSEUP 3

SDL_Rect clips[4];

void set_clips()
{
    //Clip the sprite sheet
    clips[ CLIP_MOUSEOVER ].x = 0;
    clips[ CLIP_MOUSEOVER ].y = 0;
    clips[ CLIP_MOUSEOVER ].w = 320;
    clips[ CLIP_MOUSEOVER ].h = 240;

    clips[ CLIP_MOUSEOUT ].x = 320;
    clips[ CLIP_MOUSEOUT ].y = 0;
    clips[ CLIP_MOUSEOUT ].w = 320;
    clips[ CLIP_MOUSEOUT ].h = 240;

    clips[ CLIP_MOUSEDOWN ].x = 0;
    clips[ CLIP_MOUSEDOWN ].y = 240;
    clips[ CLIP_MOUSEDOWN ].w = 320;
    clips[ CLIP_MOUSEDOWN ].h = 240;

    clips[ CLIP_MOUSEUP ].x = 320;
    clips[ CLIP_MOUSEUP ].y = 240;
    clips[ CLIP_MOUSEUP ].w = 320;
    clips[ CLIP_MOUSEUP ].h = 240;
}

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


class Button
{
private:
    //按键属性
    SDL_Rect box;

    //不同状态下按钮显示的图标
    SDL_Rect *clip;

public:
    //初始化变量
    Button(int x, int y, int w, int h);

    //处理鼠标事件,显示按钮图标
    void handle_events();

    //显示按钮
    void show();
};


Button::Button(int x, int y, int w, int h)
{
    box.x = x;
    box.y = y;
    box.w = w;
    box.h = h;

    //设置默认图标
    clip = &clips[CLIP_MOUSEOUT];
}

void Button::handle_events()
{
    int x = 0, y = 0;

    if (event.type == SDL_MOUSEMOTION) {
        //Get the mouse offsets
        x = event.motion.x;
        y = event.motion.y;

        //鼠标是否上按钮上面
        if ( x > box.x && x < (box.x + box.w)
             && y > box.y && y < (box.y + box.h)) {
            clip = &clips[CLIP_MOUSEOVER];
        } else {
            clip = &clips[CLIP_MOUSEOUT];
        }
    }

    if (event.type == SDL_MOUSEBUTTONDOWN) {
        if (event.button.button == SDL_BUTTON_LEFT) {
            x = event.button.x;
            y = event.button.y;

            //鼠标是否上按钮上面
            if ( x > box.x && x < (box.x + box.w)
                 && y > box.y && y < (box.y + box.h)) {
                clip = &clips[CLIP_MOUSEDOWN];
            }
        }
    }

    if (event.type == SDL_MOUSEBUTTONUP) {
        if (event.button.button == SDL_BUTTON_LEFT) {
            x = event.button.x;
            y = event.button.y;

            //鼠标是否上按钮上面
            if ( x > box.x && x < (box.x + box.w)
                 && y > box.y && y < (box.y + box.h)) {
                clip = &clips[CLIP_MOUSEUP];
            }
        }
    }
}

void Button::show()
{
    apply_surface(box.x, box.y, buttonSheet, screen, clip);
}


bool init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
        return false;

    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
    if (screen == NULL)
        return false;

    SDL_WM_SetCaption("Mouse Test", NULL);

    return true;
}

bool load_files()
{
    //load images
    background = load_image("background.png");

    if (background == NULL)
        return false;

    buttonSheet = load_image("button.png");
    if (buttonSheet == NULL)
        return false;

    return true;
}

void clean_up()
{
    //Free the surfaces
   SDL_FreeSurface(background);
   SDL_FreeSurface(buttonSheet);

   //Quit SDL
   SDL_Quit();
}

int main(int argc, char *argv[])
{
    //设置工程目录
    putenv("PROJECT_PATH=/home/fuyajun/myplayground/sdl/SDLTutorials/lesson09");

    bool quit = false;

    if (init() == false)
        return 1;

    if (load_files() == false)
        return 1;

    set_clips();

    Button *btn = new Button(170, 120, 320, 240);

    while (quit == false) {

        while (SDL_PollEvent(&event)) {

            btn->handle_events();

            if (event.type == SDL_QUIT) {
                quit = true;
                break;
            }
        }

        apply_surface(0, 0, background, screen);

        btn->show();

        if (SDL_Flip(screen) == -1)
            return 1;
    }

    delete btn;
    clean_up();

    return 0;
}

