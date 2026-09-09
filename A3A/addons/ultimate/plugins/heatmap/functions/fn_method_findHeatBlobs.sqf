#include "..\script_component.hpp"
/* ----------------------------------------------------------------------------
Function: A3U_ultimate_addon_heatmap_fnc_method_findHeatBlobs

Description:
    Find contiguous areas of heat values above threshold and return array of
    cells, boundaries.

Parameters:
    0: _threshold - Heat value threshold <NUMBER>

Optional:
    1: _diag - Whether to consider diagonal neighbors as connected (default: true) <BOOL>

Example:
    (begin example)
    private _blobs = _heatmap call["findHeatBlobs", [0.5]];
    (end example)

Returns:
    <ARRAY> of blobs:
        [
            [
                cells,        // [[x,y], ...]
                boundary      // [[x,y], ...]
            ],
            ...
        ]

Environment:
    Client/Server/Both, Unscheduled/Scheduled, ...

Author:
    UnseenKill/gor3Splatter
---------------------------------------------------------------------------- */
METHOD_PREAMBLE(findHeatBlobs);

if !assert(params[
    ["_threshold", nil, [0]]
]) exitWith {[]};
private _diag = param[1, true, [true]];
_self get "_dimensions" params["_width", "_height"];

private _visited = [];
_visited resize[_width * _height, false];

private _blobs = [];
private _heatmap = _self get "_heatmap";

// Neighbor offsets
private _neighbors = if (_diag) then {
    [
        [-1,0],[1,0],[0,-1],[0,1],
        [-1,-1],[1,-1],[-1,1],[1,1]
    ]
} else {
    [
        [-1,0],[1,0],[0,-1],[0,1]
    ]
};

for "_py" from 0 to (_height - 1) do {
    for "_px" from 0 to (_width - 1) do {
        private _index = _px + _width * _py;

        if (
            !(_visited select _index) &&
            { (_heatmap select _index) >= _threshold }
        ) then {
            // --- Flood fill ---
            private _stack = [[_px, _py]];
            private _cells = [];

            while { _stack isNotEqualTo [] } do {
                _stack deleteAt [-1] params["_pop"];
                _pop params["_cx", "_cy"];

                private _cIndex = _cx + _width * _cy;

                if (
                    !(_visited select _cIndex) &&
                    { (_heatmap select _cIndex) >= _threshold }
                ) then {
                    _visited set[_cIndex, true];
                    _cells pushBack[_cx, _cy];

                    _neighbors apply {
                        _x params["_dx", "_dy"];
                        private _nx = _cx + _dx;
                        private _ny = _cy + _dy;

                        if (_nx >= 0 && { _nx < _width } && { _ny >= 0 } && { _ny < _height }) then {
                            _stack pushBack[_nx, _ny];
                        };
                    };
                };
            };

            // --- Boundary extraction ---
            private _boundary = [];

            _cells apply {
                _x params["_cx", "_cy"];

                private _isEdge = _neighbors findIf {
                    _x params["_dx", "_dy"];
                    private _nx = _cx + _dx;
                    private _ny = _cy + _dy;

                    _nx < 0 || { _nx >= _width } ||
                    { _ny < 0 } || { _ny >= _height } ||
                    { (_heatmap select (_nx + _width * _ny)) < _threshold }
                } != -1;

                if (_isEdge) then {
                    _boundary pushBack[_cx, _cy];
                };
            };

            _blobs pushBack[_cells, _boundary];
        };
    };
};

_blobs;
