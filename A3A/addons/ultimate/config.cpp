#include "script_component.hpp"

class CfgPatches 
{
    class ADDON 
    {
        name = COMPONENT_NAME;
        units[] = {
            "A3U_Rebels_Base", "A3U_Rebels_Rifleman", "A3U_Rebels_SquadLeader", "A3U_Rebels_staticCrew", "A3U_Rebels_Medic", "A3U_Rebels_Engineer", "A3U_Rebels_ExplosivesExpert",
            "A3U_Rebels_Grenadier", "A3U_Rebels_LAT", "A3U_Rebels_AT", "A3U_Rebels_AA", "A3U_Rebels_MachineGunner", "A3U_Rebels_Marksman", "A3U_Rebels_Sniper", "A3U_Rebels_Unarmed",

            "A3U_Occupants_Base", "A3U_Occupants_Militia_Rifleman", "A3U_Occupants_Militia_SquadLeader", "A3U_Occupants_Militia_staticCrew", "A3U_Occupants_Militia_Medic", "A3U_Occupants_Militia_Engineer",
            "A3U_Occupants_Militia_ExplosivesExpert", "A3U_Occupants_Militia_Grenadier", "A3U_Occupants_Militia_LAT", "A3U_Occupants_Militia_AT", "A3U_Occupants_Militia_AA", "A3U_Occupants_Militia_MachineGunner",
            "A3U_Occupants_Militia_Marksman", "A3U_Occupants_Militia_Sniper", "A3U_Occupants_Militia_PatrolSniper", "A3U_Occupants_Militia_PatrolSpotter",
            "A3U_Occupants_Military_Rifleman", "A3U_Occupants_Military_SquadLeader", "A3U_Occupants_Military_staticCrew", "A3U_Occupants_Military_Medic", "A3U_Occupants_Military_Engineer",
            "A3U_Occupants_Military_ExplosivesExpert", "A3U_Occupants_Military_Grenadier", "A3U_Occupants_Military_LAT", "A3U_Occupants_Military_AT", "A3U_Occupants_Military_AA", "A3U_Occupants_Military_MachineGunner",
            "A3U_Occupants_Military_Marksman", "A3U_Occupants_Military_Sniper", "A3U_Occupants_Military_PatrolSniper", "A3U_Occupants_Military_PatrolSpotter",
            "A3U_Occupants_Elite_Rifleman", "A3U_Occupants_Elite_SquadLeader", "A3U_Occupants_Elite_staticCrew", "A3U_Occupants_Elite_Medic", "A3U_Occupants_Elite_Engineer", "A3U_Occupants_Elite_ExplosivesExpert",
            "A3U_Occupants_Elite_Grenadier", "A3U_Occupants_Elite_LAT", "A3U_Occupants_Elite_AT", "A3U_Occupants_Elite_AA", "A3U_Occupants_Elite_MachineGunner", "A3U_Occupants_Elite_Marksman", "A3U_Occupants_Elite_Sniper",
            "A3U_Occupants_SpecialForces_Rifleman", "A3U_Occupants_SpecialForces_SquadLeader", "A3U_Occupants_SpecialForces_staticCrew", "A3U_Occupants_SpecialForces_Medic", "A3U_Occupants_SpecialForces_Engineer",
            "A3U_Occupants_SpecialForces_ExplosivesExpert", "A3U_Occupants_SpecialForces_Grenadier", "A3U_Occupants_SpecialForces_LAT", "A3U_Occupants_SpecialForces_AT", "A3U_Occupants_SpecialForces_AA", "A3U_Occupants_SpecialForces_MachineGunner",
            "A3U_Occupants_SpecialForces_Marksman", "A3U_Occupants_SpecialForces_Sniper", "A3U_Occupants_SpecialForces_PatrolSniper", "A3U_Occupants_SpecialForces_PatrolSpotter",
            "A3U_Occupants_Police_Standard", "A3U_Occupants_Police_SquadLeader",
            "A3U_Occupants_Other_Crew", "A3U_Occupants_Other_Pilot", "A3U_Occupants_Other_Official", "A3U_Occupants_Other_Traitor", "A3U_Occupants_Other_Unarmed"
        };
        weapons[] = {"TFAR_SCR536"};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"A3A_Events", "A3_Characters_F"};
        author = AUTHOR;
        authors[] = { AUTHORS };
        authorUrl = "";
        VERSION_CONFIG;
    };
};

#include "CfgFunctions.hpp"
#include "patches\cfgFactionClasses.hpp"
#include "patches\cfgEditorSubcategories.hpp"
#include "patches\cfgVehicles.hpp"
#include "patches\cfgGroups.hpp"

class cfgWeapons
{
    class ItemRadio;
    #include "patches\cfgWeapons.hpp"
};

class RscBackPicture;
class RscEditLCD;
class HiddenButton;
class HiddenRotator;
class HiddenFlip;

/* #Mosecu
$[
	1.063,
	["ree",[[0,0,1,1],0.025,0.04,"GUI_GRID"],0,0,0],
	[-1200,"background: RscBackPicture",[1,"x\A3A\addons\ultimate\patches\data\radio_co.paa",["0.123594 * safezoneW + safezoneX","0.00499991 * safezoneH + safezoneY","0.252656 * safezoneW","0.781 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[-1201,"image: RscBackPicture",[1,"x\A3A\addons\ultimate\patches\data\radio_paper_background_ca.paa",["0.304062 * safezoneW + safezoneX","0.225 * safezoneH + safezoneY","0.175313 * safezoneW","0.154 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1002,"enter: HiddenButton",[1,"",["0.438125 * safezoneW + safezoneX","0.346 * safezoneH + safezoneY","0.020625 * safezoneW","0.022 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"Set frequency","-1"],["idc = 100300;","onButtonClick = |[((ctrlParent (_this select 0))) displayCtrl 100500] call TFAR_handhelds_fnc_onButtonClick_Enter;|;","action = ||;"]],
	[1003,"clear: HiddenButton",[1,"",["0.324687 * safezoneW + safezoneX","0.335 * safezoneH + safezoneY","0.0309375 * safezoneW","0.022 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"Clear frequency","-1"],["idc = 100400;","action = |ctrlSetText [100500,^^]; ctrlSetFocus ((findDisplay 100400) displayCtrl 100500);|;"]],
	[1004,"edit: RscEditLCD",[1,"",["0.365937 * safezoneW + safezoneX","0.236 * safezoneH + safezoneY","0.0928125 * safezoneW","0.044 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"Current frequency","-1"],["idc = 100500;","canModify = 1;","onKeyUp = |if (_this select 1 in [28,156]) then { [((ctrlParent (_this select 0))) displayCtrl 100500] call TFAR_handhelds_fnc_onButtonClick_Enter; };|;"]],
	[1005,"channel_edit: RscEditLCD",[1,"",["0.407187 * safezoneW + safezoneX","0.28 * safezoneH + safezoneY","0.061875 * safezoneW","0.044 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"Current channel","-1"],["idc = 100600;","canModify = 0;"]],
	[1006,"channel_up: HiddenButton",[1,"",["0.396875 * safezoneW + safezoneX","0.335 * safezoneH + safezoneY","0.020625 * safezoneW","0.022 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"Next channel","-1"],["idc = 100700;","action = |[1, false] call TFAR_fnc_setChannelViaDialog;|;"]],
	[1007,"channel_down: HiddenButton",[1,"",["0.371094 * safezoneW + safezoneX","0.346 * safezoneH + safezoneY","0.020625 * safezoneW","0.022 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"Previous channel","-1"],["idc = 100800;","action = |[0, false] call TFAR_fnc_setChannelViaDialog;|;"]]
]
*/

class scr536_radio_dialog
{
	idd=100000;
	movingEnable=1;
	controlsBackground[]={};
	objects[]={};
	onUnload="['OnRadioOpen', [player, TF_sw_dialog_radio, false, 'scr536_radio_dialog', false]] call TFAR_fnc_fireEventHandlers;";
	// onLoad="if (sunOrMoon < 0.2) then { ((_this select 0) displayCtrl 67676) ctrlSetText '\z\tfar\addons\handhelds\fadak\ui\fadak_n.paa';};";
	controls[]=
	{
		"background",
        "image",
        "enter",
        "clear",
        "edit",
        // "channel_edit",
        "channel_up",
        "channel_down"
	};
    class background: RscBackPicture
    {
        idc = 100100;
        text = "x\A3A\addons\ultimate\patches\data\radio_ca.paa";
        moving = 1;
        x = 0.0978125 * safezoneW + safezoneX;
        y = -0.00599999 * safezoneH + safezoneY;
        w = 0.252656 * safezoneW;
        h = 0.891 * safezoneH;
    };
    class image: RscBackPicture
    {
        idc = 100200;
        text = "x\A3A\addons\ultimate\patches\data\radio_paper_background_ca.paa";
        moving = 1;
        x = 0.304062 * safezoneW + safezoneX;
        y = 0.225 * safezoneH + safezoneY;
        w = 0.175313 * safezoneW;
        h = 0.154 * safezoneH;
    };
    class edit: RscEditLCD
    {
        idc = 100500;
        canModify = 1;
        onKeyUp = "if (_this select 1 in [28,156]) then { [((ctrlParent (_this select 0))) displayCtrl 100500] call TFAR_handhelds_fnc_onButtonClick_Enter; };";

        x = 0.365937 * safezoneW + safezoneX;
        y = 0.247 * safezoneH + safezoneY;
        w = 0.0979687 * safezoneW;
        h = 0.033 * safezoneH;
        tooltip = "Current frequency";
    };
    // class channel_edit: RscEditLCD
    // {
    //     idc = 100600;
    //     canModify = 0;

    //     x = 0.407187 * safezoneW + safezoneX;
    //     y = 0.291 * safezoneH + safezoneY;
    //     w = 0.061875 * safezoneW;
    //     h = 0.033 * safezoneH;
    //     tooltip = "Current channel";
    // };
    class enter: HiddenButton
    {
        idc = 100300;
        onButtonClick = "[((ctrlParent (_this select 0))) displayCtrl 100500] call TFAR_handhelds_fnc_onButtonClick_Enter;";
        action = "";

        x = 0.438125 * safezoneW + safezoneX;
        y = 0.335 * safezoneH + safezoneY;
        w = 0.020625 * safezoneW;
        h = 0.022 * safezoneH;
        tooltip = "Set frequency";
    };
    class clear: HiddenButton
    {
        idc = 100400;
        action = "ctrlSetText [100500,'']; ctrlSetFocus ((findDisplay 100400) displayCtrl 100500);";

        x = 0.324687 * safezoneW + safezoneX;
        y = 0.335 * safezoneH + safezoneY;
        w = 0.0309375 * safezoneW;
        h = 0.022 * safezoneH;
        tooltip = "Clear frequency";
    };
    class channel_up: HiddenButton
    {
        idc = 100700;
        action = "[1, false] call TFAR_fnc_setChannelViaDialog;";

        x = 0.396875 * safezoneW + safezoneX;
        y = 0.335 * safezoneH + safezoneY;
        w = 0.020625 * safezoneW;
        h = 0.022 * safezoneH;
        tooltip = "Next channel";
    };
    class channel_down: HiddenButton
    {
        idc = 100800;
        action = "[0, false] call TFAR_fnc_setChannelViaDialog;";

        x = 0.371094 * safezoneW + safezoneX;
        y = 0.335 * safezoneH + safezoneY;
        w = 0.020625 * safezoneW;
        h = 0.022 * safezoneH;
        tooltip = "Previous channel";
    };
};

// to-do: move the radio stuff into a seperate folder inside patches, let arma load it as its own addon

class A3U
{
    #include "config\plane\cfgPlaneLoadouts.hpp"
    #include "config\cfgForbiddenItems.hpp"
    #include "config\trader\cfgTraderMods.hpp"
};

class Extended_PreInit_EventHandlers 
{
    class A3U_init
	{
        init = "call A3U_fnc_init";
    };
};