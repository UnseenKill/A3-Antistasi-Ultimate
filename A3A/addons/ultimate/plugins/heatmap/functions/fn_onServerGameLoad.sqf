#include "..\script_component.hpp"
/* ----------------------------------------------------------------------------
Function: A3A_ultimate_addon_heatmap_fnc_onServerGameLoad

Description:
    CBA_EVENT_SERVER_GAME_LOAD event handler.

Parameters:

Optional:

Returns:
    Nothing

Environment:
    Server, Unscheduled

Author:
    UnseenKill/gor3Splatter
---------------------------------------------------------------------------- */
TRACE_1(QFUNC(onServerGameLoad),_this);

GVAR(heatMaps) apply {
    private _key = format["%1_%2", QGVAR(heatMap), _x];
    private _value = [_key] call A3A_fnc_returnSavedStat;

    TRACE_2(QFUNC(onServerGameLoad),_key,RETNIL(_value));

    if (!isNil "_value") then {
        _y call["setHeatmapData", [_value]];
    };
};

nil;
