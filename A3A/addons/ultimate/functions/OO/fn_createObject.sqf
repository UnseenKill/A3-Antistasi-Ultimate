#include "..\..\script_component.hpp"
/* ----------------------------------------------------------------------------
Function: A3U_fnc_createObject

Description:
    Create an instance of a registered object definition.

Parameters:
    0: _className - "Class" name <STRING>

Optional:
    1: _ctorParams - Constructor parameters <ARRAY>

Example:
    (begin example)
    ["MyClass"] call A3U_fnc_createObject;
    ["MyClass", ["param1", "param2"]] call A3U_fnc_createObject;
    (end example)

Returns:
    <HASHMAP> Object instance

Environment:
    Client/Server, Unscheduled

Author:
    UnseenKill/gor3Splatter
---------------------------------------------------------------------------- */
TRACE_1(QFUNC(createObject),_this);

if !assert(params[
    ["_className", nil, [""]]
]) exitWith {};

private _ctorParams = param[1, [], [[]]];

if !assert(_className in GVAR(objectRegistry))
    throw format["Class %1 is not registered.", str _className];

private _classDef = GVAR(objectRegistry) get _className;

createHashMapObject[_classDef, _ctorParams];
