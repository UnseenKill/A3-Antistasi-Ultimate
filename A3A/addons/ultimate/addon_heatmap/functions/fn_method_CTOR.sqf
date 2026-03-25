#include "..\script_component.hpp"
/* ----------------------------------------------------------------------------
Function: A3U_ultimate_addon_heatmap_fnc_method_CTOR

Description:
    Heatmap constructor method.

Parameters:
    0: _mapScale - Map resolution scale <NUMBER>

Optional:

Returns:
    Nothing

Environment:
    Client/Server, Unscheduled

Author:
    UnseenKill/gor3Splatter
---------------------------------------------------------------------------- */
METHOD_PREAMBLE(CTOR);

if !assert(params[
    ["_mapScale", nil, [0]]
]) exitWith {};

// Init propertiesd
_self set["_scale", _mapScale];
_self set["_dimensions", [ceil(2 * worldSize / _mapScale), ceil(worldSize / _mapScale)]];

_self call["initializeHeatmap", []];

nil;
