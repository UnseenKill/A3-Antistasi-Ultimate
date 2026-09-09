#include "..\script_component.hpp"
/* ----------------------------------------------------------------------------
Function: A3U_ultimate_addon_heatmap_fnc_method_initializeHeatmap

Description:
    Initialize heatmap array based on dimensions and scale properties.

Parameters:

Optional:

Returns:
    Nothing

Environment:
    Client/Server, Unscheduled

Author:
    UnseenKill/gor3Splatter
---------------------------------------------------------------------------- */
METHOD_PREAMBLE(initializeHeatmap);

// Init heatmap array
private _t = diag_tickTime;
_self get "_dimensions" params["_width", "_height"];

private _total = _width * _height;
private _heatmap = [];

_heatmap resize[_total, 0];

/*
for "_i" from 0 to (_width - 1) do {
    _heatmap set[_i, linearConversion[0, _width, _i, 0, 1]];
};
*/

_self set["_heatmap", _heatmap];

LOG_1("Initialized heatmap in %1 seconds",diag_tickTime - _t);

nil;
