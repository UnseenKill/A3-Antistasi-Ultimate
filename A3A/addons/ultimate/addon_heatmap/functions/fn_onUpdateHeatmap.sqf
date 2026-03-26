#include "..\script_component.hpp"
/* ----------------------------------------------------------------------------
Function: A3A_ultimate_addon_heatmap_fnc_onUpdateHeatmap

Description:
    ADDON_EVENT_SERVER_UPDATE_HEATMAP event handler.

Parameters:
    0: _entitySide - The side of the entity to update the heatmap for <SIDE>
    1: _entityKilled - The entity that was killed <OBJECT>

Optional:

Returns:
    Nothing

Environment:
    Server, Unscheduled

Author:
    UnseenKill/gor3Splatter
---------------------------------------------------------------------------- */
Trace_1(QFUNC(onUpdateHeatmap),_this);

if !assert(params[
    ["_entitySide", nil, [sideUnknown]],
    ["_entityKilled", nil, [objNull]]
]) exitWith {};

if !assert(!isNull _entityKilled) exitWith {};
if !assert(_entitySide in keys GVAR(heatmap)) exitWith {};

private _heatmap = GVAR(heatmap) get _entitySide;
private _intensity = [_entityKilled] call FUNC(calculateHeatIntensity);
private _position = _heatmap call["positionToCell", [position _entityKilled]];
private _size = [_entityKilled] call FUNC(calculateHeatRange);
private _scale = _heatmap call["getScale", []];

_size = _size vectorMultiply(1 / _scale);

[_entitySide, _position, _intensity, _size] spawn FUNC(scheduleHeatmapUpdate);

nil;
