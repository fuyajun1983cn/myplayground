#include <stdio.h>
#include <string.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>


int main(int argc, const char *argv[])
{
    char buff[20];
    int error;

    lua_State *L = lua_open();
    
    luaopen_base(L);
    luaL_openlibs(L);
    while (fgets(buff, sizeof(buff), stdin) != NULL) {
        error = luaL_loadbuffer(L, buff, strlen(buff), "line") || lua_pcall(L, 0, 0, 0);
        if (error) {
            fprintf(stderr, "%s", lua_tostring(L, -1));
            lua_pop(L, 1);
        }
    }
    lua_close(L);

    return 0;
}
