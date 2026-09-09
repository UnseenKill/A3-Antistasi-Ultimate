#include "..\script_component.hpp"
/* ----------------------------------------------------------------------------
Function: A3U_ultimate_addon_heatmap_fnc_method_cellToPosition

Description:
    Convert cell position to world position.

Parameters:
    0: _position - Local cell position <ARRAY>

Optional:

Example:
    (begin example)
    private _pos = _heatmap call["cellToPosition", [10, 5]];
    (end example)

Returns:
    World position <ARRAY>

Environment:
    Client/Server, Unscheduled

Author:
    UnseenKill/gor3Splatter
---------------------------------------------------------------------------- */
METHOD_PREAMBLE(cellToPosition);

if !assert(params[
    ["_col", nil, [0]],
    ["_row", nil, [0]]
]) exitWith {[]};

private _scale = _self get "_scale";

[_col * _scale * 0.5, _row * _scale];
