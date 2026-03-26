#include "..\script_component.hpp"
/* ----------------------------------------------------------------------------
Function: A3A_ultimate_addon_heatmap_fnc_scheduleHeatmapUpdate

Description:
    Queue and process heatmap updates

Parameters:
    0: _side - The side of the entity to update the heatmap for <SIDE>
    1: _position - The position of the heatmap update <ARRAY>
    2: _intensity - The intensity of the heatmap update <NUMBER>
    3: _size - The size of the heatmap update <ARRAY>

Optional:

Returns:
    Nothing

Environment:
    Server, Scheduled

Author:
    UnseenKill/gor3Splatter
---------------------------------------------------------------------------- */
Trace_1(QFUNC(scheduleHeatmapUpdate),_this);

if !assert(params[
    ["_side", nil, [sideUnknown]],
    ["_position", nil, [[]], 2],
    ["_intensity", nil, [0]],
    ["_size", nil, [[]], 2]
]) exitWith {};

waitUntil { isNil QGVAR(heatmapUpdateQueueWorking) };

GVAR(heatmapUpdateTime) = diag_tickTime + HEATMAP_UPDATE_DELAY;

if !(isNil QGVAR(heatmapUpdateQueue)) exitWith {
    GVAR(heatmapUpdateQueue) pushBack _this;
};

GVAR(heatmapUpdateQueue) = [+_this];

waitUntil { diag_tickTime > GVAR(heatmapUpdateTime) };

GVAR(heatmapUpdateQueueWorking) = true;
GVAR(heatmapUpdateQueue) apply {
    _x params["_side","_position","_intensity","_size"];

    (GVAR(heatMaps) get _side) call["addHeatSpot", [_position, _size, _intensity]];
};

missionNamespace setVariable[QVAR(heatmapUpdateQueue), nil];
missionNamespace setVariable[QVAR(heatmapUpdateQueueWorking), nil];

nil;
