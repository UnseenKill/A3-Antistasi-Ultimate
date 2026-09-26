#include "..\..\script_component.hpp"
/* ----------------------------------------------------------------------------
Function: A3U_fnc_interpolateColor

Description:
    Interpolates between a number of colors based on a value between 0 and 1

Parameters:
    0: _value - Value between 0 and 1 <NUMBER>
    1: _color0 - RGBA array <ARRAY>
    2: _color1 - RGBA array <ARRAY>
    n: _colorN - RGBA array <ARRAY>

Optional:

Example:
    (begin example)
    [0.5, [1,0,0,1], [0,1,0,1]] call A3U_fnc_interpolateColor;
    [0.5, [1,0,0,1], [0,1,0,1], [0,0,1,1]] call A3U_fnc_interpolateColor;
    (end example)

Returns:
    <ARRAY> RGBA array

Environment:
    Client/Server, Unscheduled

Author:
    UnseenKill/gor3Splatter
---------------------------------------------------------------------------- */
if !assert(params[
    ["_value", nil, [0]]
]) exitWith {[0,0,0,0]};

private _colors = _this;
_colors deleteAt 0;

private _count = count _colors;

// Edge cases
if (_count == 0) exitWith {[0,0,0,1]};
if (_count == 1) exitWith {_colors select 0};

_value = _value max 0 min 1;

// Scale v to segment range
private _scaled = _value * (_count - 1);
private _i = floor _scaled;
private _t = _scaled - _i;

// Clamp index to valid range
if (_i >= _count - 1) exitWith {_colors select -1};

_colors select _i params["_fromR", "_fromG", "_fromB", "_fromA"];
_colors select (_i + 1) params["_toR", "_toG", "_toB", "_toA"];

// Linear interpolation
[
    _fromR + (_toR - _fromR) * _t,
    _fromG + (_toG - _fromG) * _t,
    _fromB + (_toB - _fromB) * _t,
    _fromA + (_toA - _fromA) * _t
];
