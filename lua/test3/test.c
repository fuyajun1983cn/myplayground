#include <stdio.h>  
#include "lua.h"  
#include "lualib.h"  
#include "lauxlib.h"  

/*Lua解释器指针*/  
lua_State* L;  

int main ( int argc, char *argv[] )
{  
    /*初始化Lua*/  
    L = luaL_newstate();  
    /*载入Lua基本库*/  
    luaL_openlibs(L);  
    /*加载lua脚本*/  
/*
    int iError = luaL_loadfile(L, "../test.lua");  
    if (iError) {
        printf("lua_dofile failed\n");
        lua_close(L);  
        return 1;  
    }
    iError = lua_pcall(L, 0, 0, 0);  
    if (iError)  
    {  
        printf("lua_pcall failed\n");
        lua_close(L);  
        return 1;  
    }  
*/
    int iError = luaL_dofile(L, "../test.lua");
    if (iError) {
        printf("luaL_dofile failed\n");
        lua_close(L);
        return 1;
    }

    /*调用lua中的函数sum*/  
    int a = 11 ;  
    int b = 12 ;  
    lua_getglobal(L,"sum");               
    lua_pushinteger(L,a) ;  
    lua_pushinteger(L,b) ;  
    int ret = lua_pcall(L,2,1,0) ;  
    if ( ret != 0 ) { 
        printf("call lua function failed\n");
        return 0;  
    }
    printf("sum:%d + %d = %ld\n",a,b,lua_tointeger(L,-1)) ;  
    lua_pop(L,1);  

    /* 清除Lua */  
    lua_close(L);  

    return 0;  
 }  
