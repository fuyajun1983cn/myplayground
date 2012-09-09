#include <iostream>
#include <SDL/SDL.h>

using namespace std;

int main(int argc, char *argv[])
{
   //图片
   SDL_Surface *hello = NULL;
   SDL_Surface *screen = NULL;

   //初始化SDL
   SDL_Init(SDL_INIT_EVERYTHING);

   //设置屏幕模式
   screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);

   //加载图片
   hello = SDL_LoadBMP("/home/fuyajun/myplayground/sdl/SDLTutorials/lesson01/hello.bmp");
   if (hello == NULL) {
       cout<<"加载图片失败!"<<endl;
   }

   //将图片应用到屏幕上
   SDL_BlitSurface(hello, NULL, screen, NULL);

   //更新屏幕
   SDL_Flip(screen);

   //Pause
   SDL_Delay(2000);

   SDL_FreeSurface(hello);

   SDL_Quit();

   return 0;
}

