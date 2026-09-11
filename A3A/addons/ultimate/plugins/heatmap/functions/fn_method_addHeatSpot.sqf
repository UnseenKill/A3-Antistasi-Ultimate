#include "..\script_component.hpp"
/* ----------------------------------------------------------------------------
Function: A3U_ultimate_addon_heatmap_fnc_method_addHeatSpot

Description:
    Add heat value to cell position with fall-off based on distance from center.

Parameters:
    0: _center - Cell position <ARRAY>
    1: _radii - Radii for heat fall-off <ARRAY>
    2: _intensity - Heat intensity <NUMBER>

Optional:
    3: _updateTriangles - Whether to update the triangles after adding the heat spot <BOOL> (default: true)

Example:
    (begin example)
    // Increase heat at player position with radius 20x5 by intensity 0.5
    private _cell = _heatmap call["positionToCell", [position player]];
    _heatmap call["addHeatSpot", [_cell, [20, 5], 0.5]];
    (end example)

Returns:
    <ARRAY> of affected cells boundaries [minX, maxX, minY, maxY]

Environment:
    Client/Server, Unscheduled

Author:
    UnseenKill/gor3Splatter
---------------------------------------------------------------------------- */
METHOD_PREAMBLE(addHeatSpot);

if !assert(params[
    ["_center", nil, [[]], 2],
    ["_radii", nil, [[]], 2],
    ["_intensity", nil, [0]]
]) exitWith {};

private _updateTriangles = param[3, true, [true]];

_self get "_dimensions" params["_width", "_height"];
_center params["_cx", "_cy"];
_radii params["_rx", "_ry"];

private _heatmap = _self get "_heatmap";
private _value = _self call["getHeat", [_center, 3]];
private _mult = switch true do {
    case (_value >= 0.95): { 3.5 };
    case (_value >= 0.9): { 2.5 };
    case (_value >= 0.75): { 1.5 };
    default { 1 };
};

_rx = _rx * _mult;
_ry = _ry * _mult;

// Bounding box to avoid looping entire map
private _minX = floor(_cx - _rx) max 0 min(_width - 1);
private _maxX = ceil(_cx + _rx) max 0 min(_width - 1);
private _minY = floor(_cy - _ry) max 0 min(_height - 1);
private _maxY = ceil(_cy + _ry) max 0 min(_height - 1);

for "_py" from _minY to _maxY do {
    for "_px" from _minX to _maxX do {
        private _dx = _px - _cx;
        private _dy = _py - _cy;

        // Normalized ellipse distance
        private _distNorm = (_dx / _rx) ^ 2 + (_dy / _ry) ^ 2;

        if (_distNorm <= 1) then {
            // sqrt _distNorm: 0 center → 1 edge
            private _heat = _intensity * (1 - sqrt _distNorm);
            private _index = _px + _width * _py;
            private _newValue = (_heatmap select _index) + _heat;

            _heatmap set[_index, _newValue min 1];
        };
    };
};

if (_updateTriangles) then {
    _self call["calcTriangles", [_minX, _maxX, _minY, _maxY]];
};

[_minX, _maxX, _minY, _maxY];
