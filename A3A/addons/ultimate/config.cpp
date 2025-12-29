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
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"A3A_Events", "A3_Characters_F"};
        author = AUTHOR;
        authors[] = { AUTHORS };
        authorUrl = "";
        VERSION_CONFIG;
    };
};

class CBA_Extended_EventHandlers_base; // Needed for CfgVehicles.hpp

#include "CfgFunctions.hpp"
#include "patches\cfgFactionClasses.hpp"
#include "patches\cfgEditorSubcategories.hpp"
#include "patches\cfgVehicles.hpp"
#include "patches\cfgGroups.hpp"

class A3U
{
    #include "config\plane\cfgPlaneLoadouts.hpp"
    #include "config\cfgForbiddenItems.hpp"
    #include "config\trader\cfgTraderMods.hpp"
};

class CfgVehicles
{
    #include "CfgVehicles.hpp"
};

class Extended_InitPost_EventHandlers
{
    class A3AU_TerrainSmoother_Base_F 
    {
        class ADDON 
        {
            clientInit = QUOTE(call A3A_fnc_handlerTerrainObjectHiderPostInitClient);
        };
    };

    class A3AU_VegetationCleaner_Base_F 
    {
        class ADDON 
        {
            clientInit = QUOTE(call A3A_fnc_handlerTerrainObjectHiderPostInitClient);
        };
    };

    class GVAR(BB_TerrainObjectHider_Base) 
    {
        class ADDON 
        {
            clientInit = QUOTE(call A3A_fnc_handlerTerrainObjectHiderPostInitClient);
        };
    };
};

class Extended_PreInit_EventHandlers 
{
    class A3U_init
	{
        init = "call A3U_fnc_init";
    };
};