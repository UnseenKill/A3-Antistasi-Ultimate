#include "..\script_component.hpp"
/* ----------------------------------------------------------------------------
Function: A3U_ultimate_addon_heatmap_fnc_method_calcTriangles

Description:
    Calculate triangle vertices, color shading for selected heatmap cells or entire map.

Parameters:

Optional:
    0: _xLeft - Update rectangle left X boundary (cell index, not world position) <NUMBER>
    1: _xRight - Update rectangle right X boundary (cell index, not world position) <NUMBER>
    2: _yTop - Update rectangle top Y boundary (cell index, not world position) <NUMBER>
    3: _yBottom - Update rectangle bottom Y boundary (cell index, not world position) <NUMBER>

Returns:
    Nothing

Environment:
    Client/Server, Unscheduled

Author:
    UnseenKill/gor3Splatter
---------------------------------------------------------------------------- */
METHOD_PREAMBLE(calcTriangles);

private _t = diag_tickTime;
_self get "_dimensions" params["_width", "_height"];

params[
    ["_xLeft", 0, [0]],
    ["_xRight", _width - 1, [0]],
    ["_yTop", 0, [0]],
    ["_yBottom", _height - 1, [0]]
];

private _n = 0;
private _heatmap = _self get "_heatmap";
private _scale = _self get "_scale";
private _vertices = _self get "_vertices";
private _colors = _self call["getColors", []];

for "_py" from _yTop to _yBottom do {
    INC(_n);
    private _offset = [_scale * (ceil(_xLeft * 0.5) - 1), _scale * _py];

    for "_px" from _xLeft to _xRight do {
        if ((_px % 2) == 0) then {
            _offset = _offset vectorAdd[_scale, 0];
        };

        private _index = _px + _py * _width;
        private _value = _heatmap select _index;
        private _color = [_value, _colors] call A3U_fnc_interpolateColors;
        private _colorStr = format["#(rgb,1,1,1)color(%1,%2,%3,%4)", _color select 0, _color select 1, _color select 2, _color select 3];

        _vertices set[_index, [_color, _colorStr, if ((_px % 2) == 0) then {[
            _offset vectorAdd[0, 0],
            _offset vectorAdd[0, _scale],
            _offset vectorAdd[_scale, _scale]
        ]} else {[
            _offset vectorAdd[_scale, _scale],
            _offset vectorAdd[_scale, 0],
            _offset vectorAdd[0, 0]
        ]}]];
    };
};

LOG_2("Calculated %1 triangles in %2 seconds",_n,diag_tickTime - _t);

nil;
