#include "..\script_component.hpp"
/* ----------------------------------------------------------------------------
Function: A3U_ultimate_addon_heatmap_fnc_method_getVertex

Description:
    Describe function

Parameters:
    0: _col - Cell column <NUMBER>
    1: _row - Cell row <NUMBER>

Optional:

Returns:
    <ARRAY>|Nothing Vertex information for cell position. `nil` if cell position
    is out of bounds or not initialized.

Environment:
    Client/Server, Unscheduled

Author:
    UnseenKill/gor3Splatter
---------------------------------------------------------------------------- */
METHOD_PREAMBLE(getVertex);

if !assert(params[
    ["_col", nil, [0]],
    ["_row", nil, [0]]
]) exitWith {};

_self get "_dimensions" params["_width"];

private _index = _col + _row * _width;
(_self get "_vertices") select _index;
