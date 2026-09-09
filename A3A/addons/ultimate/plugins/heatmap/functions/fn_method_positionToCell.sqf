#include "..\script_component.hpp"
/* ----------------------------------------------------------------------------
Function: A3U_ultimate_addon_heatmap_fnc_method_positionToCell

Description:
    Convert world position to cell position.

Parameters:
    0: _position - World position <ARRAY>

Optional:

Example:
    (begin example)
    private _cellPos = _heatmap call["positionToCell", [position player]];
    (end example)

Returns:
    Cell position <ARRAY>

Environment:
    Client/Server, Unscheduled

Author:
    UnseenKill/gor3Splatter
---------------------------------------------------------------------------- */
METHOD_PREAMBLE(positionToCell);

if !assert(params[
    ["_position", nil, [[]], 2]
]) exitWith {};

_position params["_px", "_py"];
private _w = _self get "_scale";

// Square cell
private _col = floor(_px / _w);
private _row = floor(_py / _w);

// Local coords
private _localX = _px - (_col * _w);
private _localY = _py - (_row * _w);

// diagonal: y = x
private _isFirstTriangle = (_localY < _localX);

// Sequential index
private _offset = parseNumber _isFirstTriangle;
private _triX = _col * 2 + _offset;
private _triY = _row;

[_triX, _triY];
