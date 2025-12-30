	// ---------- Occupants ---------- //
    class B_Soldier_base_F : SoldierWB {
        class EventHandlers;
    };
    class A3U_Occupants_Base : B_Soldier_base_F {
        scope = 1;
        scopeCurator = 1;
        scopeArsenal = 1;
        faction = "A3U_Occupants";
        //icon = "";
        //picture = "";
        //role = "";
        //nameSound = "";
        //textSingular = "";
        //textPlural = "";
        uniformClass = "";
        backpack = "";
        items[] = {};
        respawnItems[] = {};
        linkedItems[] = {};
        respawnLinkedItems[] = {};
        weapons[] = {"Throw", "Put"};
        respawnWeapons[] = {"Throw", "Put"};
        magazines[] = {};
        respawnMagazines[] = {};
        //genericNames = "";
        //identityTypes[] = {};
        GVAR(unitFaction) = QUOTE(occ);
        class EventHandlers {
            class ADDON {
                PostInit = QUOTE([ARR_4(_this#0,getText(configOf(_this#0) >> QQGVAR(unitFaction)),getText(configOf(_this#0) >> QQGVAR(unitPrefix)),getText(configOf(_this#0) >> QQGVAR(unitType)))] call A3U_fnc_zeus_unitInit);
            };
        };
    };
    class A3U_Occupants_Militia_Rifleman: A3U_Occupants_Base {
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "A3U_Militia";
        role = "Rifleman";
        nameSound = "veh_infantry_s";
        textSingular = "infantry";
        textPlural = "infantry";
        GVAR(unitPrefix) = QUOTE(militia);
        GVAR(unitType) = QUOTE(Rifleman);
    };
    class A3U_Occupants_Militia_SquadLeader : A3U_Occupants_Militia_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_SquadLeader;
        role = "SquadLeader";
        GVAR(unitType) = QUOTE(SquadLeader);
    };
    class A3U_Occupants_Militia_Radioman : A3U_Occupants_Militia_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_Radioman;
        role = "RadioOperator";
        GVAR(unitType) = QUOTE(Radioman);
    };
    class A3U_Occupants_Militia_Medic : A3U_Occupants_Militia_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_Medic;
        role = "CombatLifeSaver";
        GVAR(unitType) = QUOTE(Medic);
    };
    class A3U_Occupants_Militia_Engineer : A3U_Occupants_Militia_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_Engineer;
        role = "Sapper";
        GVAR(unitType) = QUOTE(Engineer);
    };
    class A3U_Occupants_Militia_ExplosivesExpert : A3U_Occupants_Militia_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_EExpert;
        role = "ExplosiveSpecialist";
        GVAR(unitType) = QUOTE(ExplosivesExpert);
    };
    class A3U_Occupants_Militia_Grenadier : A3U_Occupants_Militia_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_Grenadier;
        role = "Grenadier";
        GVAR(unitType) = QUOTE(Grenadier);
    };
    class A3U_Occupants_Militia_LAT : A3U_Occupants_Militia_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_LAT;
        role = "MissileSpecialist";
        GVAR(unitType) = QUOTE(LAT);
    };
    class A3U_Occupants_Militia_AT : A3U_Occupants_Militia_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_ATSpecialist;
        role = "ATSpecialist";
        GVAR(unitType) = QUOTE(AT);
    };
    class A3U_Occupants_Militia_AA : A3U_Occupants_Militia_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_AASpecialist;
        role = "AASpecialist";
        GVAR(unitType) = QUOTE(AA);
    };
    class A3U_Occupants_Militia_MachineGunner : A3U_Occupants_Militia_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_MachineGunner;
        role = "MachineGunner";
        GVAR(unitType) = QUOTE(MachineGunner);
    };
    class A3U_Occupants_Militia_Marksman : A3U_Occupants_Militia_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_Marksman;
        role = "Marksman";
        GVAR(unitType) = QUOTE(Marksman);
    };
    class A3U_Occupants_Militia_Sniper : A3U_Occupants_Militia_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_Sniper;
        role = "Sniper";
        GVAR(unitType) = QUOTE(Sniper);
    };
    class A3U_Occupants_Militia_PatrolSniper : A3U_Occupants_Militia_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_PSniper;
        role = "Sniper";
        GVAR(unitType) = QUOTE(PatrolSniper);
    };
    class A3U_Occupants_Militia_PatrolSpotter : A3U_Occupants_Militia_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_PSpotter;
        role = "Spotter";
        GVAR(unitType) = QUOTE(PatrolSpotter);
    };
    class A3U_Occupants_Military_Rifleman : A3U_Occupants_Militia_Rifleman {
        editorSubcategory = "A3U_Military";
        GVAR(unitPrefix) = QUOTE(military);
        GVAR(unitType) = QUOTE(Rifleman);
    };
    class A3U_Occupants_Military_SquadLeader : A3U_Occupants_Military_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_SquadLeader;
        role = "SquadLeader";
        GVAR(unitType) = QUOTE(SquadLeader);
    };
    class A3U_Occupants_Military_Radioman : A3U_Occupants_Military_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_Radioman;
        role = "RadioOperator";
        GVAR(unitType) = QUOTE(Radioman);
    };
    class A3U_Occupants_Military_Medic : A3U_Occupants_Military_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_Medic;
        role = "CombatLifeSaver";
        GVAR(unitType) = QUOTE(Medic);
    };
    class A3U_Occupants_Military_Engineer : A3U_Occupants_Military_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_Engineer;
        role = "Sapper";
        GVAR(unitType) = QUOTE(Engineer);
    };
    class A3U_Occupants_Military_ExplosivesExpert : A3U_Occupants_Military_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_EExpert;
        role = "ExplosiveSpecialist";
        GVAR(unitType) = QUOTE(ExplosivesExpert);
    };
    class A3U_Occupants_Military_Grenadier : A3U_Occupants_Military_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_Grenadier;
        role = "Grenadier";
        GVAR(unitType) = QUOTE(Grenadier);
    };
    class A3U_Occupants_Military_LAT : A3U_Occupants_Military_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_LAT;
        role = "MissileSpecialist";
        GVAR(unitType) = QUOTE(LAT);
    };
    class A3U_Occupants_Military_AT : A3U_Occupants_Military_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_ATSpecialist;
        role = "ATSpecialist";
        GVAR(unitType) = QUOTE(AT);
    };
    class A3U_Occupants_Military_AA : A3U_Occupants_Military_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_AASpecialist;
        role = "AASpecialist";
        GVAR(unitType) = QUOTE(AA);
    };
    class A3U_Occupants_Military_MachineGunner : A3U_Occupants_Military_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_MachineGunner;
        role = "MachineGunner";
        GVAR(unitType) = QUOTE(MachineGunner);
    };
    class A3U_Occupants_Military_Marksman : A3U_Occupants_Military_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_Marksman;
        role = "Marksman";
        GVAR(unitType) = QUOTE(Marksman);
    };
    class A3U_Occupants_Military_Sniper : A3U_Occupants_Military_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_Sniper;
        role = "Sniper";
        GVAR(unitType) = QUOTE(Sniper);
    };
    class A3U_Occupants_Military_PatrolSniper : A3U_Occupants_Military_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_PSniper;
        role = "Sniper";
        GVAR(unitType) = QUOTE(PatrolSniper);
    };
    class A3U_Occupants_Military_PatrolSpotter : A3U_Occupants_Military_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_PSpotter;
        role = "Spotter";
        GVAR(unitType) = QUOTE(PatrolSpotter);
    };
    class A3U_Occupants_Elite_Rifleman : A3U_Occupants_Militia_Rifleman {
        editorSubcategory = "A3U_Elite";
        GVAR(unitPrefix) = QUOTE(elite);
        GVAR(unitType) = QUOTE(Rifleman);
    };
    class A3U_Occupants_Elite_SquadLeader : A3U_Occupants_Elite_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_SquadLeader;
        role = "SquadLeader";
        GVAR(unitType) = QUOTE(SquadLeader);
    };
    class A3U_Occupants_Elite_Radioman : A3U_Occupants_Elite_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_Radioman;
        role = "RadioOperator";
        GVAR(unitType) = QUOTE(Radioman);
    };
    class A3U_Occupants_Elite_Medic : A3U_Occupants_Elite_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_Medic;
        role = "CombatLifeSaver";
        GVAR(unitType) = QUOTE(Medic);
    };
    class A3U_Occupants_Elite_Engineer : A3U_Occupants_Elite_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_Engineer;
        role = "Sapper";
        GVAR(unitType) = QUOTE(Engineer);
    };
    class A3U_Occupants_Elite_ExplosivesExpert : A3U_Occupants_Elite_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_EExpert;
        role = "ExplosiveSpecialist";
        GVAR(unitType) = QUOTE(ExplosivesExpert);
    };
    class A3U_Occupants_Elite_Grenadier : A3U_Occupants_Elite_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_Grenadier;
        role = "Grenadier";
        GVAR(unitType) = QUOTE(Grenadier);
    };
    class A3U_Occupants_Elite_LAT : A3U_Occupants_Elite_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_LAT;
        role = "MissileSpecialist";
        GVAR(unitType) = QUOTE(LAT);
    };
    class A3U_Occupants_Elite_AT : A3U_Occupants_Elite_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_ATSpecialist;
        role = "ATSpecialist";
        GVAR(unitType) = QUOTE(AT);
    };
    class A3U_Occupants_Elite_AA : A3U_Occupants_Elite_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_AASpecialist;
        role = "AASpecialist";
        GVAR(unitType) = QUOTE(AA);
    };
    class A3U_Occupants_Elite_MachineGunner : A3U_Occupants_Elite_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_MachineGunner;
        role = "MachineGunner";
        GVAR(unitType) = QUOTE(MachineGunner);
    };
    class A3U_Occupants_Elite_Marksman : A3U_Occupants_Elite_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_Marksman;
        role = "Marksman";
        GVAR(unitType) = QUOTE(Marksman);
    };
    class A3U_Occupants_Elite_Sniper : A3U_Occupants_Elite_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_Sniper;
        role = "Sniper";
        GVAR(unitType) = QUOTE(Sniper);
    };
    class A3U_Occupants_Elite_PatrolSniper : A3U_Occupants_Elite_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_PSniper;
        role = "Sniper";
        GVAR(unitType) = QUOTE(PatrolSniper);
    };
    class A3U_Occupants_Elite_PatrolSpotter : A3U_Occupants_Elite_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_PSpotter;
        role = "Spotter";
        GVAR(unitType) = QUOTE(PatrolSpotter);
    };
    class A3U_Occupants_SpecialForces_Rifleman : A3U_Occupants_Militia_Rifleman {
        editorSubcategory = "A3U_SpecialForces";
        GVAR(unitPrefix) = QUOTE(SF);
        GVAR(unitType) = QUOTE(Rifleman);
    };
    class A3U_Occupants_SpecialForces_SquadLeader : A3U_Occupants_SpecialForces_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_SquadLeader;
        role = "SquadLeader";
        GVAR(unitType) = QUOTE(SquadLeader);
    };
    class A3U_Occupants_SpecialForces_Radioman : A3U_Occupants_SpecialForces_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_Radioman;
        role = "RadioOperator";
        GVAR(unitType) = QUOTE(Radioman);
    };
    class A3U_Occupants_SpecialForces_Medic : A3U_Occupants_SpecialForces_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_Medic;
        role = "CombatLifeSaver";
        GVAR(unitType) = QUOTE(Medic);
    };
    class A3U_Occupants_SpecialForces_Engineer : A3U_Occupants_SpecialForces_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_Engineer;
        role = "Sapper";
        GVAR(unitType) = QUOTE(Engineer);
    };
    class A3U_Occupants_SpecialForces_ExplosivesExpert : A3U_Occupants_SpecialForces_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_EExpert;
        role = "ExplosiveSpecialist";
        GVAR(unitType) = QUOTE(ExplosivesExpert);
    };
    class A3U_Occupants_SpecialForces_Grenadier : A3U_Occupants_SpecialForces_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_Grenadier;
        role = "Grenadier";
        GVAR(unitType) = QUOTE(Grenadier);
    };
    class A3U_Occupants_SpecialForces_LAT : A3U_Occupants_SpecialForces_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_LAT;
        role = "MissileSpecialist";
        GVAR(unitType) = QUOTE(LAT);
    };
    class A3U_Occupants_SpecialForces_AT : A3U_Occupants_SpecialForces_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_ATSpecialist;
        role = "ATSpecialist";
        GVAR(unitType) = QUOTE(AT);
    };
    class A3U_Occupants_SpecialForces_AA : A3U_Occupants_SpecialForces_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_AASpecialist;
        role = "AASpecialist";
        GVAR(unitType) = QUOTE(AA);
    };
    class A3U_Occupants_SpecialForces_MachineGunner : A3U_Occupants_SpecialForces_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_MachineGunner;
        role = "MachineGunner";
        GVAR(unitType) = QUOTE(MachineGunner);
    };
    class A3U_Occupants_SpecialForces_Marksman : A3U_Occupants_SpecialForces_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_Marksman;
        role = "Marksman";
        GVAR(unitType) = QUOTE(Marksman);
    };
    class A3U_Occupants_SpecialForces_Sniper : A3U_Occupants_SpecialForces_Rifleman {
        displayName = $STR_A3AU_Zeus_UnitType_Sniper;
        role = "Sniper";
        GVAR(unitType) = QUOTE(Sniper);
    };
    class A3U_Occupants_Police_Standard : A3U_Occupants_Militia_Rifleman {
        editorSubcategory = "A3U_Police";
        GVAR(unitPrefix) = QUOTE(police);
        GVAR(unitType) = QUOTE(Standard);
    };
    class A3U_Occupants_Police_SquadLeader : A3U_Occupants_Police_Standard {
        displayName = $STR_A3AU_Zeus_UnitType_SquadLeader;
        role = "SquadLeader";
        GVAR(unitType) = QUOTE(SquadLeader);
    };
    class A3U_Occupants_Other_Crew : A3U_Occupants_Militia_Rifleman {
        editorSubcategory = "A3U_Other";
        displayName = $STR_A3AU_Zeus_UnitType_Crew;
        role = "Crew";
        GVAR(unitPrefix) = QUOTE(other);
        GVAR(unitType) = QUOTE(Crew);
    };
    class A3U_Occupants_Other_Pilot : A3U_Occupants_Other_Crew {
        displayName = $STR_A3AU_Zeus_UnitType_Pilot;
        role = "Pilot";
        GVAR(unitType) = QUOTE(Pilot);
    };
    class A3U_Occupants_Other_Official : A3U_Occupants_Other_Crew {
        displayName = $STR_A3AU_Zeus_UnitType_Official;
        role = "Officer";
        GVAR(unitType) = QUOTE(Official);
    };
    class A3U_Occupants_Other_Traitor : A3U_Occupants_Other_Crew {
        displayName = $STR_A3AU_Zeus_UnitType_Traitor;
        role = "Rifleman";
        GVAR(unitType) = QUOTE(Traitor);
    };
    class A3U_Occupants_Other_Unarmed : A3U_Occupants_Other_Crew {
        displayName = $STR_A3AU_Zeus_UnitType_Unarmed;
        role = "Unarmed";
        GVAR(unitType) = QUOTE(Unarmed);
    };
