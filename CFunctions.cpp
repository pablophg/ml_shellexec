/*********************************************************
*
*  Multi Theft Auto: San Andreas
*
*  Shellexecute module which can execute commands and return output.
*  Based on ml_system by x86 <sebasdevelopment@gmx.com>
*  Linux only.
*
*  Developers:
*  Pablo PHG <contact@pablophg.net>
*
*********************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include "CFunctions.h"
#include "extra/CLuaArguments.h"

string GetStdoutFromCommand(string cmd)
{
    string data;
    FILE * stream;
    const int max_buffer = 256;
    char buffer[max_buffer];
    cmd.append(" 2>&1");

    stream = popen(cmd.c_str(), "r");
    if (stream)
    {
        while (!feof(stream))
        if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
        pclose(stream);
    }
    return data;
}

int CFunctions::System ( lua_State* luaVM )
{
    if ( luaVM )
    {
        if (lua_type(luaVM, 1) == LUA_TSTRING)
        {
            const char* m_bCommand = lua_tostring(luaVM, 1);

            string result = GetStdoutFromCommand(m_bCommand);

			const char * cResult = result.c_str();
			lua_pushstring(luaVM, cResult);
            return 1;
            
        }
    }

    lua_pushboolean(luaVM, false);
    return 1;
}