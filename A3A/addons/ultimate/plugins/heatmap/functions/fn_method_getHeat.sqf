#include "..\script_component.hpp"
/* ----------------------------------------------------------------------------
Function: A3U_ultimate_addon_heatmap_fnc_method_getHeat

Description:
    Get heat value at cell position.
    
    Argument is local cell position. To convert world position to local cell
    position, use `positionToCell` method. Optional radius argument gets heat
    value in radius around cell position.

Parameters:
    0: _position - Cell position <ARRAY>

Optional:
    1: _radius - Radius around cell position to get heat value in <NUMBER>

Example:
    (begin example)
    // Get heat at player position
    private _position = position player;
    private _cellPos = _heatmap call["positionToCell", [_position]];
    private _heat = _heatmap call["getHeat", [_cellPos]];
    (end example)

Returns:
    <NUMBER> Accumulated heat value at/around cell position

Environment:
    Client/Server, Unscheduled

Author:
    UnseenKill/gor3Splatter
---------------------------------------------------------------------------- */
METHOD_PREAMBLE(getHeat);

if !assert(params[
    ["_position", nil, [[]], [2,3]]
]) exitWith {};

private _radius = param[1, 1, [0]];

if (_radius <= 1) exitWith { _self call["getValue", _position] };

_position params["_cx", "_cy"];

private _heatmap = _self get "_heatmap";
_self get "_dimensions" params["_width", "_height"];

private _minX = floor(_cx - _radius) max 0 min(_width - 1);
private _maxX = ceil(_cx + _radius) max 0 min(_width - 1);
private _minY = floor(_cy - _radius) max 0 min(_height - 1);
private _maxY = ceil(_cy + _radius) max 0 min(_height - 1);

private _total = 0;
private _count = 0;
for "_py" from _minY to _maxY do {
    for "_px" from _minX to _maxX do {
        private _index = _px + _width * _py;
        private _value = _heatmap select _index;

        if (_value > 0) then {
            private _dist = sqrt((_px - _cx) ^ 2 + (_py - _cy) ^ 2);
            if (_dist <= _radius) then {
                _total = _total + _value;
                _count = _count + 1;
            };
        };
    };
};

if (_count > 0) then { _total = _total / _count };

_total;
