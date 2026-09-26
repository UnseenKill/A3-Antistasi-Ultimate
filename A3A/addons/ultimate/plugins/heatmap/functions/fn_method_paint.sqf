#define PREAMBLE_TRACE_SKIP
#include "..\script_component.hpp"
/* ----------------------------------------------------------------------------
Function: A3U_ultimate_addon_heatmap_fnc_method_paint

Description:
    Paint the heatmap on a map control.

Parameters:
    0: _control - Map control to paint the heatmap on <CONTROL>

Optional:

Example:
    (begin example)
    // Use global GVAR(heatMap) to draw
    _map ctrlAddEventHandler["Draw", {
        params["_control"];

        GVAR(heatMap) call["paint", [_control]];
    }];
    (end example)

Returns:
    Nothing

Environment:
    Client/Server, Unscheduled

Author:
    UnseenKill/gor3Splatter
---------------------------------------------------------------------------- */
METHOD_PREAMBLE(paint);

if !assert(params[
    ["_control", nil, [controlNull]]
]) exitWith {};

private _heatmap = _self get "_heatmap";
private _vertices = _self get "_vertices";
private _showEmpty = _self get "_showEmpty";

{
    if (isNil "_x") then { continue };
    private _value = _heatmap select _foreachIndex;
    if (_value > 0) then {
        _x params["_color","_colorStr","_triangle"];
        _control drawTriangle[_triangle, _color, _colorStr];
    } else {
        if (_showEmpty) then {
            _x params["","","_triangle"];
            _control drawTriangle[_triangle, [0, 0, 0, 1], ""];
        };
    };
} forEach _vertices;

nil;
