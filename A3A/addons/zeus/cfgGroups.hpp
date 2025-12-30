class CfgGroups {
	class INDEP {
		class A3U_Rebels {
			name = $STR_A3AU_Zeus_Faction_Rebels;
			class Infantry {
				name = $STR_A3AU_Zeus_GroupType_Infantry;
				
				class A3U_Rebels_Infantry_Squad {
					name = $STR_A3AU_Zeus_GroupType_Infantry_Squad;
					faction = "A3U_Rebels";
					side = 2;
					class Unit0 {
						side = 2;
						vehicle = "A3U_Rebels_SquadLeader";
						rank = "SERGEANT";
						position[] = {0,0,0};
					};
					class Unit1 : Unit0 {
						vehicle = "A3U_Rebels_Rifleman";
						rank = "CORPORAL";
						position[] = {2,-2,0};
					};
					class Unit2 : Unit1 {
						position[] = {4,-4,0};
					};
					class Unit3 : Unit0 {
						vehicle = "A3U_Rebels_MachineGunner";
						rank = "PRIVATE";
						position[] = {6,-6,0};
					};
					class Unit4 : Unit0 {
						vehicle = "A3U_Rebels_Grenadier";
						rank = "PRIVATE";
						position[] = {8,-8,0};
					};
					class Unit5 : Unit1 {
						position[] = {-2,-2,0};
					};
					class Unit6 : Unit2 {
						position[] = {-4,-4,0};
					};
					class Unit7 : Unit3 {
						position[] = {-6,-6,0};
					};
					class Unit8 : Unit4 {
						position[] = {-8,-8,0};
					};
				};
				class A3U_Rebels_Infantry_Team {
					name = $STR_A3AU_Zeus_GroupType_Infantry_Team;
					faction = "A3U_Rebels";
					side = 2;
					class Unit0 {
						side = 2;
						vehicle = "A3U_Rebels_Rifleman";
						rank = "CORPORAL";
						position[] = {0,0,0};
					};
					class Unit1 : Unit0 {
						vehicle = "A3U_Rebels_Rifleman";
						rank = "PRIVATE";
						position[] = {2,-2,0};
					};
					class Unit2 : Unit1 {
						vehicle = "A3U_Rebels_MachineGunner";
						rank = "PRIVATE";
						position[] = {-2,-2,0};
					};
					class Unit3 : Unit1 {
						vehicle = "A3U_Rebels_Grenadier";
						rank = "PRIVATE";
						position[] = {0,-4,0};
					};
				};
				class A3U_Rebels_Infantry_MachineGun_Team {
					name = $STR_A3AU_Zeus_GroupType_Infantry_MGTeam;
					faction = "A3U_Rebels";
					side = 2;
					class Unit0 {
						side = 2;
						vehicle = "A3U_Rebels_Rifleman";
						rank = "CORPORAL";
						position[] = {0,0,0};
					};
					class Unit1 : Unit0 {
						vehicle = "A3U_Rebels_MachineGunner";
						rank = "PRIVATE";
						position[] = {2,-2,0};
					};
					class Unit2 : Unit1 {
						vehicle = "A3U_Rebels_Rifleman";
						rank = "PRIVATE";
						position[] = {-2,-2,0};
					};
				};
				class A3U_Rebels_Infantry_AT_Team : A3U_Rebels_Infantry_MachineGun_Team {
					name = $STR_A3AU_Zeus_GroupType_Infantry_ATTeam;
					class Unit0 : Unit0 {};
					class Unit1 : Unit1 {
						vehicle = "A3U_Rebels_AT";
					};
					class Unit2 : Unit2 {};
				};
				class A3U_Rebels_Infantry_AA_Team : A3U_Rebels_Infantry_MachineGun_Team {
					name = $STR_A3AU_Zeus_GroupType_Infantry_AATeam;
					class Unit0 : Unit0 {};
					class Unit1 : Unit1 {
						vehicle = "A3U_Rebels_AA";
					};
					class Unit2 : Unit2 {};
				};
				class A3U_Rebels_Infantry_Sniper_Team {
					name = $STR_A3AU_Zeus_GroupType_Infantry_SniperTeam;
					faction = "A3U_Rebels";
					side = 2;
					class Unit0 {
						side = 2;
						vehicle = "A3U_Rebels_Marksman";
						rank = "SERGEANT";
						position[] = {0,0,0};
					};
					class Unit1 : Unit0 {
						vehicle = "A3U_Rebels_Sniper";
						rank = "CORPORAL";
						position[] = {2,-2,0};
					};
				};
			};
			class Weapons {
				name = $STR_A3AU_Zeus_GroupType_Weapons;

				class A3U_Rebels_Weapons_MG_Team {
					name = $STR_A3AU_Zeus_GroupType_Weapons_MGTeam;
					faction = "A3U_Rebels";
					side = 2;
					class Unit0 {
						side = 2;
						vehicle = "A3U_Rebels_Vehicle_StaticMG";
						rank = "PRIVATE";
						position[] = {0,0,0};
					};
					class Unit1 {
						side = 2;
						vehicle = "A3U_Rebels_SquadLeader";
						rank = "SERGEANT";
						position[] = {0,-2,0};
					};
					class Unit2 : Unit1 {
						vehicle = "A3U_Rebels_Rifleman";
						rank = "Corporal";
						position[] = {-2,-4,0};
					};
					class Unit3 : Unit2 {
						rank = "PRIVATE";
						position[] = {2,-4,0};
					};
				};
				class A3U_Rebels_Weapons_AT_Team : A3U_Rebels_Weapons_MG_Team {
					name = $STR_A3AU_Zeus_GroupType_Weapons_ATTeam;
					class Unit0 : Unit0 {
						vehicle = "A3U_Rebels_Vehicle_StaticAT";
					};
					class Unit1 : Unit1 {};
					class Unit2 : Unit2 {};
					class Unit3 : Unit3 {};
				};
				class A3U_Rebels_Weapons_AA_Team : A3U_Rebels_Weapons_MG_Team {
					name = $STR_A3AU_Zeus_GroupType_Weapons_AATeam;
					class Unit0 : Unit0 {
						vehicle = "A3U_Rebels_Vehicle_StaticAA";
					};
					class Unit1 : Unit1 {};
					class Unit2 : Unit2 {};
					class Unit3 : Unit3 {};
				};
				class A3U_Rebels_Weapons_Mortar_Team : A3U_Rebels_Weapons_MG_Team {
					name = $STR_A3AU_Zeus_GroupType_Weapons_MortarTeam;
					class Unit0 : Unit0 {
						vehicle = "A3U_Rebels_Vehicle_Mortar";
					};
					class Unit1 : Unit1 {};
					class Unit2 : Unit2 {};
					class Unit3 : Unit3 {};
				};				
			};
			class Vehicles {
				name = $STR_A3AU_Zeus_GroupType_Vehicles;

				class A3U_Rebels_Vehicles_AT {
					name = $STR_A3AU_Zeus_GroupType_Vehicles_AT;
					faction = "A3U_Rebels";
					side = 2;
					class Unit0 {
						side = 2;
						vehicle = "A3U_Rebels_Vehicle_AT";
						rank = "PRIVATE";
						position[] = {0,0,0};
					};
					class Unit1 {
						side = 2;
						vehicle = "A3U_Rebels_staticCrew";
						rank = "CORPORAL";
						position[] = {0,-12,0};
					};
					class Unit2 : Unit1 {
						rank = "PRIVATE";
						position[] = {2,-12,0};
					};
				};
				class A3U_Rebels_Vehicles_AA : A3U_Rebels_Vehicles_AT {
					name = $STR_A3AU_Zeus_GroupType_Vehicles_AA;
					class Unit0 : Unit0 {
						vehicle = "A3U_Rebels_Vehicle_AA";
					};
					class Unit1 : Unit1 {};
					class Unit2 : Unit2 {};
				};
			};
		};
	};
};