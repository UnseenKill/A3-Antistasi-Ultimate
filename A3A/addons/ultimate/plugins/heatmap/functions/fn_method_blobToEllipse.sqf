#include "..\script_component.hpp"
/* ----------------------------------------------------------------------------
Function: A3U_ultimate_addon_heatmap_fnc_method_blobToEllipse

Description:
    Convert blob of cells to ellipse parameters for drawing.

Parameters:
    0: _cells - Array of cells representing the blob <ARRAY>

Optional:
    1: _blowup - Scale factor to make ellipse larger than blob (default: [1.15, 1.15]) <ARRAY>

Returns:
    <ARRAY> Ellipse parameters: [[centerX, centerY], [radiusX, radiusY], rotation]

    Return values are in cell coordinates, not world coordinates.

Environment:
    Client/Server, Unscheduled

Author:
    UnseenKill/gor3Splatter
---------------------------------------------------------------------------- */
METHOD_PREAMBLE(blobToEllipse);

if !assert(params[
    ["_cells", nil, [[]]]
]) exitWith {[]};

private _n = count _cells;
// scale factor to make ellipse slightly larger than blob since it's an approximation
private _blowup = param[1, [1.15, 1.15], [[]], 2];

// --- Compute centroid ---
private _sumX = 0;
private _sumY = 0;

_cells apply {
    _sumX = _sumX + (_x select 0);
    _sumY = _sumY + (_x select 1);
};

private _cx = _sumX / _n;
private _cy = _sumY / _n;

// --- Covariance matrix ---
private _sxx = 0;
private _syy = 0;
private _sxy = 0;

_cells apply {
    private _dx = (_x select 0) - _cx;
    private _dy = (_x select 1) - _cy;

    ADD(_sxx,_dx ^ 2);
    ADD(_syy,_dy ^ 2);
    ADD(_sxy,_dx * _dy);
};

_sxx = _sxx / _n;
_syy = _syy / _n;
_sxy = _sxy / _n;

// --- Eigenvalues (ellipse axes) ---
private _trace = _sxx + _syy;
private _det = _sxx * _syy - _sxy ^ 2;

private _temp = sqrt((_trace ^ 2 / 4) - _det);

private _lambda1 = _trace / 2 + _temp;
private _lambda2 = _trace / 2 - _temp;

// Radii (scaled)
private _rx = sqrt(_lambda1) * 2;
private _ry = sqrt(_lambda2) * 2;

// --- Rotation angle ---
private _angle = 0;
if (round(_sxy * 1e5) != 0) then {
    _angle = 0.5 * ((2 * _sxy) atan2 (_sxx - _syy)) + 90;
};

[
    [_cx, _cy],
    [_rx, _ry] vectorMultiply _blowup,
    _angle
];
