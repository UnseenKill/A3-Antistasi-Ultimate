#include "..\..\script_component.hpp"
/* ----------------------------------------------------------------------------
Function: A3U_fnc_registerObjectDefinition

Description:
    Add object definition to the registry. This is used by object definitions
    to register themselves during preInit.

    Will throw an exception if:
        - The object definition is missing required fields
        - The object definition class name is already registered
        - The object registry is sealed (postInit has run)

Parameters:
    0: _definitionName - "Class" name <STRING>
    1: _definitionBody - "Class" definition as described in `createHashMapObject` documentation <ARRAY,HASHMAP>

Optional:

Example:
    (begin example)
    ["MyClass", [ definition ]] call A3U_fnc_registerObjectDefinition;
    (end example)

Returns:
    Nothing

Environment:
    Client/Server, Unscheduled

Author:
    UnseenKill/gor3Splatter
---------------------------------------------------------------------------- */
TRACE_1(QFUNC(registerObjectDefinition),_this#0);

if !assert(params[
    ["_definitionName", nil, [""]],
    ["_definitionBody", nil, [[], createHashMap]]
]) exitWith {};

if (_definitionName in GVAR(objectRegistry))
    throw format ["Object definition with name %1 is already registered", _definitionName];

if (isFinal GVAR(objectRegistry))
    throw "Object registry is sealed. No further definitions can be registered.";

if (_definitionBody isEqualType []) then {
    _definitionBody = createHashMapFromArray _definitionBody;
};

GVAR(objectRegistry) set[_definitionName, _definitionBody];

nil;
