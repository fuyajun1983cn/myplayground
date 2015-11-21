#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

static void error(lua_State *L, const char *fmt, ...)
{
    va_list argp;
    va_start(argp, fmt);
    vfprintf(stderr, fmt, argp);
    va_end(argp);

    lua_close(L);

    exit(EXIT_FAILURE);
}

static void stackDump(lua_State *L)
{
    int i;
    int top = lua_gettop(L);
    for (i = 1; i <= top; i++) {
        int t = lua_type(L, i);
        switch (t) {
        case LUA_TSTRING:
            printf("'%s'", lua_tostring(L, i));
            break;
        case LUA_TBOOLEAN:
           printf(lua_toboolean(L, i) ? "true" : "false");
          break;
        case LUA_TNUMBER:
           printf("%g", lua_tonumber(L, i)); 
           break;
        default:
           printf("%s", lua_typename(L, i));
           break;
        }
        printf("  ");
    }
    printf("\n");
}

int main(int argc, const char *argv[])
{
    char buff[20];
    int error;

    lua_State *L = lua_open();
    
    lua_pushboolean(L, 1);
    lua_pushnumber(L, 10);
    lua_pushnil(L);
    lua_pushstring(L, "Hello, World");
    stackDump(L);

    lua_pushvalue(L, -4);
    stackDump(L);

    lua_replace(L, 3);
    stackDump(L);

    lua_settop(L, 6);
    stackDump(L);

    lua_remove(L, -3);
    stackDump(L);

    lua_settop(L, -5);
    stackDump(L);
    

    lua_close(L);

    return 0;
}
