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


static void load(char *filename, int *width, int *height)
{
    lua_State *L = lua_open();
    luaopen_base(L);
    luaL_openlibs(L);

    if (luaL_loadfile(L, filename) || lua_pcall(L, 0, 0, 0)) {
        error(L, "cannot run configuration file: %s", lua_tostring(L, -1));
    }

    lua_getglobal(L, "width");
    lua_getglobal(L, "height");

    if (!lua_isnumber(L, -2))
        error(L, "width should be a number");
    if (!lua_isnumber(L, -1))
        error(L, "height should be a number");

    *width = lua_tonumber(L, -2);
    *height = lua_tonumber(L, -1);

    lua_close(L);

}

int main(int argc, const char *argv[])
{
    int width, height;
    load("config.lua", &width, &height);
    printf("Width = %d, height = %d\n", width, height);
    return 0;
}
