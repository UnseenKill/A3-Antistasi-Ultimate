#include "..\..\script_component.hpp"
/* ----------------------------------------------------------------------------
Function: A3U_fnc_interpolateColors

Description:
    Interpolates between a number of colors based on a value between 0 and 1

Parameters:
    0: _value - Value between 0 and 1 <NUMBER>
    1: _colors - Array of RGBA arrays <ARRAY>

Optional:

Example:
    (begin example)
    [0.5, [[1,0,0,1], [0,1,0,1]]] call A3U_fnc_interpolateColors;
    [0.5, [[1,0,0,1], [0,1,0,1], [0,0,1,1]]] call A3U_fnc_interpolateColors;
    (end example)

Returns:
    <ARRAY> RGBA array

Environment:
    Client/Server, Unscheduled

Author:
    UnseenKill/gor3Splatter
---------------------------------------------------------------------------- */
if !assert(params[
    ["_value", nil, [0]],
    ["_colors", nil, [[]]]
]) exitWith {[0,0,0,0]};

([_value] + _colors) call A3U_fnc_interpolateColor;
