#include "..\script_component.hpp"
/* ----------------------------------------------------------------------------
Function: A3A_ultimate_addon_heatmap_fnc_createHeatMapObject

Description:
    Instantiate a heat map object.

Parameters:
    0: _mapScale - Map resolution scale <NUMBER>

Optional:

Example:
    (begin example)
    // Cells every 125m
    [125] call A3A_ultimate_addon_heatmap_fnc_createHeatMapObject;
    (end example)

Returns:
    <HASHMAP> Heatmap hashmap object

Environment:
    Client/Server, Unscheduled

Author:
    UnseenKill/gor3Splatter
---------------------------------------------------------------------------- */
TRACE_1(QFUNC(createHeatMapObject),_this);

if !assert(params[
    ["_mapScale", nil, [0]]
]) exitWith {};

[HEATMAP_CLASS, [_mapScale]] call A3U_fnc_createObject;
