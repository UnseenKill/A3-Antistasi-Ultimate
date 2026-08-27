#include "..\..\script_component.hpp"
FIX_LINE_NUMBERS()

if !assert(params[
	["_marker", nil, [""]]
]) exitWith { false };

if (markerShape _marker isEqualTo "") exitWith {
    Warning_1("No such marker: %1",str _marker);
    false;
};

private _markerSide = sidesX getVariable[_marker, sideUnknown];
private _markerPos = markerPos _marker;

(airportsX + outposts + seaports + milbases + ["Synd_HQ"]) select {
	sidesX getVariable[_x, sideUnknown] isNotEqualTo _markerSide;
} findIf {
	_markerPos distance markerPos _x < A3A_frontLineDistance
} != -1;
