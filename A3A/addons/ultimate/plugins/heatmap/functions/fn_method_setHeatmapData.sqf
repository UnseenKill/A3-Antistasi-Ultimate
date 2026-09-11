#define PREAMBLE_TRACE_NO_ARGS
#include "..\script_component.hpp"
/* ----------------------------------------------------------------------------
Function: A3A_ultimate_addon_heatmap_fnc_setHeatmapData

Description:
    Restore heatmap data from persistence.

Parameters:
    0: _heatmapData - Heatmap data to restore <ARRAY>

Optional:

Returns:
    Nothing

Environment:
    Client/Server, Unscheduled

Author:
    UnseenKill/gor3Splatter
---------------------------------------------------------------------------- */
METHOD_PREAMBLE(setHeatmapData);

if !assert(params[
    ["_heatmapData", nil, [[]]]
]) exitWith {};

_self set["_heatmap", _heatmapData];
_self call["calcTriangles", []];

nil;
