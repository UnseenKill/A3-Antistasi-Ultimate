#include "..\script_component.hpp"
/* ----------------------------------------------------------------------------
Function: A3A_ultimate_addon_heatmap_fnc_onServerGameSave

Description:
    CBA_EVENT_SERVER_GAME_SAVE event handler.

Parameters:

Optional:

Returns:
    Nothing

Environment:
    Server, Unscheduled

Author:
    UnseenKill/gor3Splatter
---------------------------------------------------------------------------- */
TRACE_1(QFUNC(onServerGameSave),_this);

GVAR(heatMaps) apply {
    private _key = format["%1_%2", QGVAR(heatMap), _x];
    private _value = _y call["getHeatmapData", []];

    TRACE_2(QFUNC(onServerGameSave),_key,count _value);

    [_key, _value] call A3A_fnc_setStatVariable;
};

nil;
