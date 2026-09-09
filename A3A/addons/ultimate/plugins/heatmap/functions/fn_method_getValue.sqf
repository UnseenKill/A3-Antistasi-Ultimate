#include "..\script_component.hpp"
/* ----------------------------------------------------------------------------
Function: A3U_ultimate_addon_heatmap_fnc_method_getValue

Description:
    Internal function to get heat value of a cell.

Parameters:
    0: _col - Cell column <NUMBER>
    1: _row - Cell row <NUMBER>

Optional:

Returns:
    <NUMBER> Heat value of the cell

Environment:
    Client/Server, Unscheduled

Author:
    UnseenKill/gor3Splatter
---------------------------------------------------------------------------- */
METHOD_PREAMBLE(getValue);

if !assert(params[
    ["_col", nil, [0]],
    ["_row", nil, [0]]
]) exitWith {0};

_self get "_dimensions" params["_width"];

private _index = _col + _row * _width;
(_self get "_heatmap") select _index;
