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

class CFunctions;

#ifndef __CFUNCTIONS_H
#define __CFUNCTIONS_H

#include <stdio.h>

#include "include/ILuaModuleManager.h"
extern ILuaModuleManager10 *pModuleManager;

class CFunctions
{
public:
        static int      System          ( lua_State* luaVM );

};
#endif
