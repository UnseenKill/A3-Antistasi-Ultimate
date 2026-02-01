/*
Maintainer: Wurzel0701
    Activates undercover if possible and controls its status till undercover is broken/ended

Arguments:
    <NIL>

Return Value:
    <NIL>

Scope: Local
Environment: Scheduled
Public: Yes
Dependencies:
    <HashMap> A3A_faction_civ
    <HashMap> A3A_faction_reb
    <ARRAY> controlsX
    <ARRAY> airportsX
    <ARRAY> outposts
    <ARRAY> seaports
    <ARRAY> undercoverVehicles
    <BOOL> A3A_hasACE
    <SIDE> Occupants
    <SIDE> Invaders
    <ARRAY> detectionAreas
    <NAMESPACE> sidesX
    <SIDE> teamPlayer
    <NUMBER> aggressionOccupants
    <NUMBER> aggressionInvaders
    <NUMBER> tierWar

Example:
    [] call A3A_fnc_goUndercover;
*/
#include "..\..\script_component.hpp"
FIX_LINE_NUMBERS()

private _result = [] call A3A_fnc_canGoUndercover;

if(!(_result select 0)) exitWith
{
    if((_result select 1) == "Spotted by enemies") then
    {
        if !(isNull (objectParent player)) then
        {
            (objectParent player) setVariable ["A3A_reported", true, true];
            {
                if ((isPlayer _x) && (captive _x)) then
                {
                    [_x, false] remoteExec["setCaptive", _x];
                };
            } forEach ((crew(objectParent player)) + (assignedCargo(objectParent player)) - [player]);
        };
    };
};

if (_result select 0 isEqualTo false) exitWith {["Undercover", _result select 1] call A3A_fnc_customHint};

private _layer = ["A3A_infoCenter"] call BIS_fnc_rscLayer;
[(localize "STR_antistasi_dialogs_radio_comm_undercover"), 0, 0, 4, 0, 0, _layer] spawn bis_fnc_dynamicText;

player setCaptive true;
[] spawn A3A_fnc_statistics;
if (player == leader group player) then
{
    {
        if ((!isplayer _x) && (local _x) && (_x getVariable["owner", _x] == player)) then
        {
            [_x] spawn A3A_fnc_undercoverAI;
        };
    } forEach units group player;
};

private _secureBases = (
    (airportsX + outposts + seaports + milbases + (controlsX select {isOnRoad(getMarkerPos _x)})) select {sidesX getVariable [_x, sideUnknown] != teamPlayer}
) + (milAdministrationsX select {sidesX getVariable [_x,sideUnknown] == Occupants});

private _lastBaseInside = "";
private _reason = "";
["Undercover", [""]] call EFUNC(Events,triggerEvent);

while {_reason == ""} do
{
    private _healingTarget = objNull;
    if !(isNil {player getVariable "ace_medical_treatment_endInAnim"}) then
    {
        _healingTarget = currentAceTarget;
    };

    sleep 1;

    if (!captive player) exitWith
    {
        _reason = "Reported";
    };

    private _veh = objectParent player;
    if !(isNull _veh) then
    {
        private _vehType = typeOf _veh;
        if (!(_vehType in undercoverVehicles)) exitWith
        {
            _reason = "VNoCivil"
        };

        if (_veh getVariable ["A3A_reported", false]) exitWith
        {
            _reason = "VCompromised"
        };

        if (_veh getVariable ["SA_Tow_Ropes", []] isNotEqualTo []) exitWith
        {
            _reason = "VTowRopes"
        };

        if (A3A_hasACE) then
        {
            if (((position player nearObjects["DemoCharge_Remote_Ammo", 5]) select 0) mineDetectedBy Occupants) exitWith
            {
                _reason = "SpotBombTruck";
            };
            if (((position player nearObjects["SatchelCharge_Remote_Ammo", 5]) select 0) mineDetectedBy Occupants) exitWith
            {
                _reason = "SpotBombTruck";
            };
        };

        if(_reason != "") exitWith {};

        if(_veh getVariable ["NoFlyZoneDetected", ""] != "") exitWith
        {
            _reason = "NoFly";
        };

        if (_vehType isKindOf "Land") then
        {
            if (!(isOnRoad position _veh) && {count (_veh nearRoads 50) == 0}) then
            {
                if ({((side _x == Invaders) || (side _x == Occupants)) && ((_x knowsAbout player > 1.4) || (_x distance player < 350))} count allUnits > 0) then
                {
                    _reason = "Highway";
                };
            };
        };
    }
    else
    {
        if (_healingTarget != objNull && {side _healingTarget != civilian && {_healingTarget isKindOf "Man"}}) exitWith
        {
            if ({((side _x == Invaders) or(side _x == Occupants)) and((_x knowsAbout player > 1.4) or(_x distance player < 350))} count allUnits > 0) then
            {
                _reason = "BadMedic2";
            }
            else
            {
                _reason = "BadMedic";
            };
        };
        if ((primaryWeapon player != "") || (secondaryWeapon player != "") || (handgunWeapon player != "") || (vest player != "") || (getNumber(configfile >> "CfgWeapons" >> headgear player >> "ItemInfo" >> "HitpointsProtectionInfo" >> "Head" >> "armor") > 2) || (hmd player != "") || (!(uniform player in (A3A_faction_civ get "uniforms")))) exitWith
        {
            if ({((side _x == Invaders) or (side _x == Occupants)) and ((_x knowsAbout player > 1.4) or (_x distance player < 350))} count allUnits > 0) then
            {
                _reason = "clothes2"
            }
            else
            {
                _reason = "clothes"
            };
        };
        if (dateToNumber date < (player getVariable ["compromised", 0])) exitWith
        {
            _reason = "Compromised";
        };
        if (!isNull (player getVariable ["SA_Tow_Ropes_Vehicle", objNull])) exitWith
        {
            _reason = "TowRopes";
        };
    };
    if (_reason != "") exitWith {};

    // Don't do location checks on air vehicles. AirspaceControl handles that.
    if (!isNull _veh and { _veh isKindOf "Air" }) then { continue };

    private _base = [_secureBases, player] call BIS_fnc_nearestPosition;
    // If player is _onDetectionMarker, the detectionArea they are in should also be less than 700m away from _base (which should only be an airport).
    private _onDetectionMarker = detectionAreas findIf {player inArea _x && (_base in airportsX) && {((getMarkerPos _x) distance2D (getMarkerPos _base)) <= 700}} != -1;
    private _onBaseMarker = player inArea _base;
    private _baseSide = sidesX getVariable [_base, sideUnknown];
    if ((_onBaseMarker || _onDetectionMarker) && (_baseSide != teamPlayer) && (_base != _lastBaseInside)) then
    {
        if (_base in airportsX || _onDetectionMarker) exitWith
        {
            _reason = "Airport";
        };
        if ("outpost" in _base || _onDetectionMarker) exitWith
        {
            _reason = "Outpost";
        };
        if ("seaport" in _base || _onDetectionMarker) exitWith
        {
            _reason = "Seaport";
        };
        if ("milbase" in _base || _onDetectionMarker) exitWith
        {
            _reason = "Milbase";
        };

        private _aggro = if (_baseSide == Occupants) then {aggressionOccupants + (tierWar * 10)} else {aggressionInvaders + (tierWar * 10)};
        if (random 100 < _aggro) exitWith
        {
            private _roadblocks = controlsX select {isOnRoad(getMarkerPos _x)};
            if (_base in _roadblocks || _onDetectionMarker) then {
                _reason = "Roadblock";
            };
        };
        _lastBaseInside = _base; // Don't check this base again once we passed the check
    };
};

if (captive player) then
{
    player setCaptive false;
};

if !(isNull (objectParent player)) then
{
    {
        if (isPlayer _x) then
        {
            [_x, false] remoteExec["setCaptive", _x];
        }
    } forEach((assignedCargo(vehicle player)) + (crew(vehicle player)) - [player]);
};

private _layer = ["A3A_infoCenter"] call BIS_fnc_rscLayer;
[localize "STR_A3A_fn_undercover_goUn_off", 0, 0, 4, 0, 0, _layer] spawn bis_fnc_dynamicText;
[] spawn A3A_fnc_statistics;

// Make a record of reasons and when last shown. Return `true` if notification
// should be shown.
private _recordReason = {
    params["_reason"];

    if (isNil { player getVariable QGVAR(undercoverRecord) }) then {
        player setVariable[QGVAR(undercoverRecord), createHashMap];
    };

    private _record = player getVariable QGVAR(undercoverRecord);
    private _entry = _record getOrDefault[_reason, [0, -1], true];

    _entry params["_count","_cooldown"];

    Verbose_3("Undercover reason %1 has been recorded %2 times, cooldown until %3",str _reason,_count,_cooldown);

    if (_cooldown > diag_tickTime) exitWith { false };
    _count = _count + 1;

    if (_reason isEqualTo "clothes") then {
        // Cooldown the generic message you get e.g. when exiting a car after
        // the third time.
        if (_count >= 3) then {
            _cooldown = diag_tickTime + 900; // 15 minutes
            _count = 0;
        };
    };

    _entry set[0, _count];
    _entry set[1, _cooldown];
    true;
};

private _notificationText = switch (_reason) do
{
    case "Reported":
    {
        if !(isNull objectParent player) then {
            objectParent player setVariable ["A3A_reported", true, true];
        } else {
            player setVariable["compromised", (dateToNumber[date select 0, date select 1, date select 2, date select 3, (date select 4) + 30])];
        };

        localize "STR_A3A_fn_undercover_goUn_reported";
    };
    case "VNoCivil":
    {
        localize "STR_A3A_fn_undercover_goUn_entered_veh1";
    };
    case "VCompromised":
    {
        localize "STR_A3A_fn_undercover_goUn_entered_veh2";
    };
    case "VTowRopes":
    {
        localize "STR_A3A_fn_undercover_goUn_no_towrope1";
    };
    case "TowRopes":
    {
        localize "STR_A3A_fn_undercover_goUn_no_towrope2";
    };
    case "SpotBombTruck":
    {
        if !(isNull objectParent player) then {
            objectParent player setVariable ["A3A_reported", true, true];
        };
        localize "STR_A3A_fn_undercover_goUn_no_explo";
    };
    case "Highway":
    {
        if !(isNull objectParent player) then {
            objectParent player setVariable ["A3A_reported", true, true];
        };
        localize "STR_A3A_fn_undercover_goUn_no_distance";
    };
    case "clothes":
    {
        localize "STR_A3A_fn_undercover_goUn_no_reason_1";
    };
    case "clothes2":
    {
        player setVariable["compromised", dateToNumber[date select 0, date select 1, date select 2, date select 3, (date select 4) + 30]];
        localize "STR_A3A_fn_undercover_goUn_no_reason_2";
    };
    case "BadMedic":
    {
        localize "STR_A3A_fn_undercover_goUn_no_reason_3";
    };
    case "BadMedic2":
    {
        player setVariable["compromised", dateToNumber[date select 0, date select 1, date select 2, date select 3, (date select 4) + 30]];
        localize "STR_A3A_fn_undercover_goUn_no_reason_4";
    };
    case "Compromised":
    {
        localize "STR_A3A_fn_undercover_goUn_leftveh";
    };
    case "Airport"; case "Roadblock"; case "Outpost"; case "Seaport"; case "Milbase":
    {
        if !(isNull objectParent player) then {
            (objectParent player) setVariable ["A3A_reported", true, true];
        } else {
            player setVariable["compromised", (dateToNumber[date select 0, date select 1, date select 2, date select 3, (date select 4) + 30])];
        };

        localize(switch (_reason) do {
            case "Airport": {"STR_A3A_fn_undercover_goUn_trespass"};
            case "Outpost": {"STR_A3A_fn_undercover_goUn_detect_outp"};
            case "Milbase": {"STR_A3A_fn_undercover_goUn_detect_milb"};
            case "Seaport": {"STR_A3A_fn_undercover_goUn_detect_outp"};
            case "Roadblock": {"STR_A3A_fn_undercover_goUn_detect_roadb"};
        });
    };
    case "NoFly":
    {
        private _veh = objectParent player;
        private _detectedBy = _veh getVariable "NoFlyZoneDetected";
        
        _veh setVariable ["A3A_reported", true, true];
        _veh setVariable ["NoFlyZoneDetected", nil, true];

        format[localize "STR_A3A_fn_undercover_goUn_detect_airspace", [_detectedBy] call A3A_fnc_localizar];
    };
    default
    {
        Error_1("Unknown reason given, was %1", _reason);
        localize "STR_A3A_fn_undercover_goUn_Error";
    };
};

if ([_reason, _notificationText] call _recordReason) then {
    ["Undercover", _notificationText] call A3A_fnc_customHint;
};

["Undercover", [_reason]] call EFUNC(Events,triggerEvent);

nil;
