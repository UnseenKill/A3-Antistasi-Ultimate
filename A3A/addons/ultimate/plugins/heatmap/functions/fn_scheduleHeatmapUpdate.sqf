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
    GVAR(heatmapUpdateQueue) pushBack(+_this);
};

GVAR(heatmapUpdateQueue) = [+_this];

waitUntil { diag_tickTime > GVAR(heatmapUpdateTime) };

private _updateRegion = createHashMap;

GVAR(heatmapUpdateQueueWorking) = true;
GVAR(heatmapUpdateQueue) apply {
    _x params["_side","_position","_intensity","_size"];

    private _region = (GVAR(heatMaps) get _side) call["addHeatSpot", [_position, _size, _intensity, false]];
    private _currentRegion = _updateRegion getOrDefault[_side, _region, true];
    
    _updateRegion set[_side, [
        (_currentRegion select 0) min (_region select 0),
        (_currentRegion select 1) max (_region select 1),
        (_currentRegion select 2) min (_region select 2),
        (_currentRegion select 3) max (_region select 3)
    ]];
};

_updateRegion apply {
    private _side = _x;
    private _region = _y;

    (GVAR(heatMaps) get _side) call["updateTriangles", _region];
};

GVAR(heatmapUpdateQueue) = nil;
GVAR(heatmapUpdateQueueWorking) = nil;

nil;
