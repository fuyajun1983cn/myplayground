#include <stdio.h>
#include <string.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

#define CONFIG_FILE  "../config.lua"

void error(lua_State *L, const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);

    exit(-1);
}

void load(char *filename, int *width, int *height)
{
    lua_State *L = luaL_newstate(); //berfore 5.2, use lua_open()
    luaL_openlibs(L);

    if (luaL_loadfile(L, filename) || lua_pcall(L, 0, 0, 0)) {
        error(L, "cannot run configuration file: %s\n", lua_tostring(L, -1));
    }

    lua_getglobal(L, "width");
    lua_getglobal(L, "height");
    if (!lua_isnumber(L, -2))
        error(L, "width should be a number\n");
    if (!lua_isnumber(L, -1))
        error(L, "height should be a number\n");

    *width = (int)lua_tonumber(L, -2);
    *height = (int)lua_tonumber(L, -1);

    lua_close(L);

}

int main(int argc, const char *argv[])
{
    int width, height;

    load(CONFIG_FILE, &width, &height);

    printf("widht = %d, height = %d\n", width, height);

    return 0;
}


