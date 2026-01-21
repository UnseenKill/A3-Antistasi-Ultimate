#include "\x\cba\addons\main\script_macros_common.hpp"
//#include "script_macros_undef.hpp"

// Client-only event; after client initialization; params=[]
#define CBA_EVENT_CLIENT_INIT_DONE QUOTE(TRIPLES(PREFIX,event,clientInitDone))
// Client-only event; on personal save loaded; params=[Hashmap saveData]
#define CBA_EVENT_CLIENT_PLAYER_LOAD QUOTE(TRIPLES(PREFIX,event,clientPlayerLoad))
// Client-only event; on personal save; params=[Hashmap saveData]
#define CBA_EVENT_CLIENT_PLAYER_SAVE QUOTE(TRIPLES(PREFIX,event,clientPlayerSave))
// Server-only event; after server initialization; params=[]
#define CBA_EVENT_SERVER_INIT_DONE QUOTE(TRIPLES(PREFIX,event,serverInitDone))
// Server-only event; on game save; params=[]
#define CBA_EVENT_SERVER_GAME_SAVED QUOTE(TRIPLES(PREFIX,event,serverGameSaved))

#define PATCHNAME(x) TRIPLES(PREFIX,COMPONENT,x)

#ifdef SUBCOMPONENT
    #undef COMPILE_FILE
    #define COMPILE_FILE(var1) COMPILE_FILE_SYS(PREFIX,COMPONENT_F\SUBCOMPONENT,var1)

    #undef COMPILE_FILE_CFG
    #define COMPILE_FILE_CFG(var1) COMPILE_FILE_CFG_SYS(PREFIX,COMPONENT_F\SUBCOMPONENT,var1)

    #undef COMPILE_SCRIPT
    #define COMPILE_SCRIPT(var1) compileScript ['PATHTO_SYS(PREFIX,COMPONENT_F\SUBCOMPONENT,var1)']

    #undef FUNC
    #define FUNC(var1) TRIPLES(SUBADDON,fnc,var1)

    #undef GVAR
    #define GVAR(var1) DOUBLES(SUBADDON,var1)

    #undef LOG_SYS_FORMAT
    #define LOG_SYS_FORMAT(LEVEL,MESSAGE) format ['[%1] (%2) %3: %4', toUpper 'PREFIX', 'SUBADDON', LEVEL, MESSAGE]

    #undef PATHTOF
    #define PATHTOF(var1) PATHTOF_SYS(PREFIX,COMPONENT\SUBCOMPONENT,var1)

    // Localization strings macros
    #undef CSTRING
    #define CSTRING(var1) QUOTE(TRIPLES($STR,SUBADDON,var1))
    #undef LSTRING
    #define LSTRING(var1) QUOTE(TRIPLES(STR,SUBADDON,var1))
    #undef LLSTRING
    #define LLSTRING(var1) (localize LSTRING(var1))
#endif // SUBCOMPONENT

#undef PREP
#undef PREPSUB
#define PREP(fncName) FUNC(fncName) = compile preprocessFileLineNumbers QPATHTOF(functions\DOUBLES(fn,fncName).sqf)
#define PREPSUB(folder,fncName) FUNC(fncName) = compile preprocessFileLineNumbers QPATHTOF(folder\DOUBLES(fn,fncName).sqf)

#undef VARDEF
#define VARDEF(a,b) RETDEF(a,b)

/* -------------------------------------------
Macro: XOR
    Evaluates to true if exactly one of both values is true

Parameters:
    VAR1 - the first variable to evaluate
    VAR2 - the second variable to evaluate

Example:
    (begin example)
        // return "true" if exactly one of a and b is true
        XOR(a, b);
    (end)

Author:
    Bohemia Interactive (https://community.bistudio.com/wiki/Operators)
------------------------------------------- */
#define XOR(VAR1,VAR2) (((VAR1) || (VAR2)) && !((VAR1) && (VAR2)))
