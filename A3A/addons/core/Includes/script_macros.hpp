#include "script_macros_common.hpp"

#undef PREP
#undef PREPSUB
#define PREP(fncName) FUNC(fncName) = compile preprocessFileLineNumbers QPATHTOF(functions\DOUBLES(fn,fncName).sqf)
#define PREPSUB(folder,fncName) FUNC(fncName) = compile preprocessFileLineNumbers QPATHTOF(folder\DOUBLES(fn,fncName).sqf)

#undef VARDEF
#define VARDEF(Var, Def) (if (isNil #Var) then {Def} else {Var})

#define ADDONLOADED(addon) EADDONLOADED(A3A,addon)
#define EADDONLOADED(prefix,addon)(isClass (configFile/QUOTE(CfgPatches)/QDOUBLES(prefix,addon)))

#define SET_PUBLIC_VAR(var,value) \
    var = value; \
    publicVariable QUOTE(var); \

/* Args: String|Boolean _serverID, String _campaignID, String _mapName
 * Target: server
 * Sent-by: server
 */
#define A3A_EVENT_SERVER_INIT_COMPLETE QUOTE(DOUBLES(PREFIX,serverLoadComplete))
