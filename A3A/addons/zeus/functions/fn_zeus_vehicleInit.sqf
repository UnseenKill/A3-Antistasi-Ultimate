/*
	Author:
		jwoodruff40
	
	Description:
		Initializes a vehicle spawned by Zeus with appropriate vehicle class and assigns AI crew.
	
	Params:
		_emptyVeh <OBJ> : The empty vehicle placeholder spawned by Zeus, replace with an appropriate vehicle from the faction template.
		_vehFaction <STR> : The faction of the vehicle to spawn.
		_vehType <STR> : The type of vehicle to spawn.
	
	Dependencies: // ! Update
		N/A
	
	Scope: // ! Update
		N/A
	
	Environment: // ! Update
		N/A
	
	Usage:
		Only intended to be called from the PostInit event handler of Zeus-spawned A3U vehicles.
		[_vehObj, "reb", "vehiclesLightArmed"] call A3U_fnc_zeus_vehicleInit;
	
	Return:
		Nothing
*/

#include "..\script_component.hpp"
FIX_LINE_NUMBERS()

params ["_emptyVeh", "_vehFaction", "_vehType"];

private _faction = missionNamespace getVariable ("A3A_Faction_" + _vehFaction);
if (isNil "_faction") exitWith {};

private _group = group _emptyVeh;
private _veh = (selectRandom (_faction get _vehType)) createVehicle (position _emptyVeh);
deleteVehicle _emptyVeh;
_group addVehicle _veh;
[_veh, side _veh] call A3A_fnc_AIVEHinit;
{ _x moveInAny _veh } forEach (units _group);

{ _x addCuratorEditableObjects [[_veh], true] } forEach (allCurators); // QoL; required since the vehicle wasn't technically spawned by Zeus (_emptyVeh was)
