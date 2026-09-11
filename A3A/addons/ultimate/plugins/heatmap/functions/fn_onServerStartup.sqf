#include "..\script_component.hpp"
/* ----------------------------------------------------------------------------
Function: A3A_ultimate_addon_heatmap_fnc_onServerStartup

Description:
    CBA_EVENT_SERVER_STARTUP event handler.

Parameters:

Optional:

Returns:
    Nothing

Environment:
    Server, Unscheduled

Author:
    UnseenKill/gor3Splatter
---------------------------------------------------------------------------- */
TRACE_1(QFUNC(onServerStartup),_this);

if !GVAR(useHeatMaps) exitWith {
    Debug_1("Heat maps feature disabled via %1 parameter.",str QGVAR(useHeatMaps));
};

Debug_1("Heat maps feature enabled via %1 parameter.",str QGVAR(useHeatMaps));

[CBA_EVENT_SERVER_GAME_LOAD, LINKFUNC(onServerGameLoad)] call FUNCMAIN(addEventHandler);
[CBA_EVENT_SERVER_GAME_SAVE, LINKFUNC(onServerGameSave)] call FUNCMAIN(addEventHandler);
[CBA_EVENT_SERVER_INIT_DONE, LINKFUNC(onServerInitDone)] call FUNCMAIN(addEventHandler);

// One heat map for occupiers side
Info("Creating heat map object for occupiers side");
GVAR(heatMaps) set[west, [GVAR(mapScale)] call FUNC(createHeatMapObject)];

// One heat map for invaders side, but only if not Reb. vs. Occ. mode
if (gameMode != 3) then {
    Info("Creating heat map object for invaders side");
    GVAR(heatMaps) set[east, [GVAR(mapScale)] call FUNC(createHeatMapObject)];
};

nil;
