#include "..\script_component.hpp"
/* ----------------------------------------------------------------------------
Function: A3A_ultimate_addon_heatmap_fnc_onServerEntityPostMortem

Description:
    CBA_EVENT_SERVER_ENTITY_POSTMORTEM event handler

Parameters:
    0: _entityKilled - The entity that was killed <OBJECT>

Optional:
    1: _killer - The entity responsible for the kill <OBJECT>

Returns:
    Nothing

Environment:
    Server, Unscheduled

Author:
    UnseenKill/gor3Splatter
---------------------------------------------------------------------------- */
Trace_1(QFUNC(onServerEntityPostMortem),_this);

if !assert(params[
    ["_entityKilled", nil, [objNull]]
]) exitWith {};
private _killer = params[1, objNull, [objNull]];

if (isNull _killer || {_killer isEqualTo _entityKilled}) exitWith {
    Verbose_1("Entity %1 has no killer or unalived itself; skipping",_entityKilled);
};

if (side _killer isNotEqualTo teamPlayer) exitWith {
    Verbose_2("Killer %1 is not on a side we track (side=%2); skipping",_killer,side _killer);
};

if !(side _entityKilled in keys GVAR(heatmap)) exitWith {
    Verbose_2("Entity %1 is not on a side we track (side=%2); skipping",_entityKilled,side _entityKilled);
};

[ADDON_EVENT_SERVER_UPDATE_HEATMAP, [side _entityKilled, _entityKilled]] call FUNCMAIN(triggerLocalEvent);

nil;
