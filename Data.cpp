#include "Data.h"

namespace Data
{
	std::map<std::string, int> weapons[3] =
	{
		// Light
		{
			// Impact
			{ R"rx(^(spin(fusor)?|light(spin)?(fusor)?)$)rx", CONST_WEAPON_ID_SPINFUSOR_LIGHT },
			{ R"rx(^(dueling(spin)?(fusor)?)$)rx", CONST_WEAPON_ID_SPINFUSOR_LIGHT_MKD },
			{ R"rx(^(stealth(spin)?(fusor)?)$)rx", CONST_WEAPON_ID_STEALTHLIGHTSPINFUSOR },
			{ R"rx(^(bolt|boltlauncher)$)rx", CONST_WEAPON_ID_LAUNCHER_BOLT },
			{ R"rx(^(twin|twinfusor|lighttwinfusor)$)rx", CONST_WEAPON_ID_LIGHTTWINFUSOR },
			{ R"rx(^(blinks?|blinks?fusor)$)rx", CONST_WEAPON_ID_SPINFUSOR_LIGHT_100X },
			// Timed
			{ R"rx(^((light)?(gl|grenadelauncher)|lgl)$)rx", CONST_WEAPON_ID_LIGHTGRENADELAUNCHER },
			{ R"rx(^(jackal)$)rx", CONST_WEAPON_ID_REMOTE_ARX_BUSTER },
			// Speciality
			{ R"rx(^(bxt|bxt1|bxt1rifle)$)rx", CONST_WEAPON_ID_RIFLE_SNIPER },
			{ R"rx(^((bxt1a|bxt-1a|bxt1-a|bxt-1a)(rifle)?)$)rx", CONST_WEAPON_ID_RIFLE_SNIPER_MKD },
			{ R"rx(^(phase|phaserifle)$)rx", CONST_WEAPON_ID_RIFLE_PHASE },
			{ R"rx(^(sap(20)?(rifle)?)$)rx", CONST_WEAPON_ID_SAP20 },
			// Bullet
			{ R"rx(^(falcon)$)rx", CONST_WEAPON_ID_PISTOL_FALCON },
			{ R"rx(^(lightassaultrifle|lar|ar|assaultrifle|rifle)$)rx", CONST_WEAPON_ID_RIFLE_ASSAULT_LIGHT },
			{ R"rx(^(sparrow)$)rx", CONST_WEAPON_ID_PISTOL_SPARROW },
			{ R"rx(^(throwingknives|knives)$)rx", CONST_WEAPON_ID_THROWINGKNIVES },
			{ R"rx(^(rhino(smg)?)$)rx", CONST_WEAPON_ID_SMG_RHINO },
			{ R"rx(^(arcticrhino(smg)?)$)rx", CONST_WEAPON_ID_SMG_RHINO_MKD },
			{ R"rx(^(sn7(silenced)?(pistol)?)$)rx", CONST_WEAPON_ID_PISTOL_SN7 },
			{ R"rx(^(arcticsn7(silenced)?(pistol)?)$)rx", CONST_WEAPON_ID_PISTOL_SN7_MKD },
			// Short Range
			{ R"rx(^(shotgun)$)rx", CONST_WEAPON_ID_SHOTGUN },
			{ R"rx(^(holdout(shotgun)?)$)rx", CONST_WEAPON_ID_SHOTGUN_MKD },
			{ R"rx(^((accurized|accurised|sniper)(shotgun)?)$)rx", CONST_WEAPON_ID_ACCURIZEDSHOTGUN },
			{ R"rx(^(shocklance)$)rx", CONST_WEAPON_ID_PISTOL_H1 },
			// Belt
			{ R"rx(^(nitrons?|impactnitrons?|impacts?)$)rx", CONST_WEAPON_ID_GRENADE_NITRON },
			{ R"rx(^(compactnitrons?|compacts?)$)rx", CONST_WEAPON_ID_GRENADE_NITRON_MKD },
			{ R"rx(^(explosivenitrons?|explosives?)$)rx", CONST_WEAPON_ID_GRENADE_ST },
			{ R"rx(^(T5s?(grenades)?)$)rx", CONST_WEAPON_ID_GRENADE_T5 },
			{ R"rx(^(stickygrenades?|sticky|stickies)$)rx", CONST_WEAPON_ID_GRENADE_STICKY },
			{ R"rx(^(stickygrenades?xl|stickyxl|stickiesxl)$)rx", CONST_WEAPON_ID_GRENADE_STICKY_MKD },
			{ R"rx(^(claymores?|claymoremines?)$)rx", CONST_WEAPON_ID_MINE_CLAYMORE },
			{ R"rx(^(prismmines?|mines?)$)rx", CONST_WEAPON_ID_MINE_PRISM },
			{ R"rx(^(chaffs?(grenades?)?)$)rx", CONST_WEAPON_ID_GRENADE_NINJASMOKE },
		},

		// Medium
		{
			// Impact
			{ R"rx(^(spinfusor|spin)$)rx", CONST_WEAPON_ID_SPINFUSOR },
			{ R"rx(^(thumper)$)rx", CONST_WEAPON_ID_THUMPER },
			{ R"rx(^(thumperd)$)rx", CONST_WEAPON_ID_THUMPER_D },
			{ R"rx(^(thumperdx)$)rx", CONST_WEAPON_ID_THUMPERD_MKD },
			{ R"rx(^(twinfusor)$)rx", CONST_WEAPON_ID_TWINFUSOR },
			{ R"rx(^(blinks?|blinks?fusor)$)rx", CONST_WEAPON_ID_SPINFUSOR_100X },
			{ R"rx(^(honorfusor|honourfusor|honor)$)rx", CONST_WEAPON_ID_HONORFUSOR },
			// Timed
			{ R"rx(^(arxbuster|arx)$)rx", CONST_WEAPON_ID_ARX_BUSTER },
			{ R"rx(^(dustdevil)$)rx", CONST_WEAPON_ID_ARX_BUSTER_MKD },
			{ R"rx(^(grenadelauncher|nadelauncher|launcher|gl)$)rx", CONST_WEAPON_ID_LAUNCHER_GRENADE },
			// Speciality
			{ R"rx(^(improvedrepairtool|repairtool|repair)$)rx", CONST_WEAPON_ID_REPAIR_TOOL_SD },
			{ R"rx(^(longrangerepairtool)$)rx", CONST_WEAPON_ID_REPAIR_TOOL_SD_MKD },
			{ R"rx(^(elf(projector)?)$)rx", CONST_WEAPON_ID_ELFPROJECTOR },
			// Bullet
			{ R"rx(^(assaultrifle|rifle|ar)$)rx", CONST_WEAPON_ID_RIFLE_ASSAULT },
			{ R"rx(^(gast('s)?(rifle)?)$)rx", CONST_WEAPON_ID_RIFLE_ASSAULT_MKD },
			{ R"rx(^(nj4smg|nj4)$)rx", CONST_WEAPON_ID_SMG_NJ4 },
			{ R"rx(^(desertnj4|desertnj4smg)$)rx", CONST_WEAPON_ID_SMG_NJ4_MKD },
			{ R"rx(^(nj5(-?b)?(smg)?)$)rx", CONST_WEAPON_ID_NJ5SMG },
			{ R"rx(^(tcn4(smg)?)$)rx", CONST_WEAPON_ID_SMG_TCN4 },
			{ R"rx(^(tcn4rockwind(smg)?)$)rx", CONST_WEAPON_ID_SMG_TCN4_MKD },
			{ R"rx(^(tc24)$)rx", CONST_WEAPON_ID_TC24 },
			{ R"rx(^(plasmagun|plasma)$)rx", CONST_WEAPON_ID_PLASMA_GUN },
			{ R"rx(^(nova|blaster|novablaster)$)rx", CONST_WEAPON_ID_PISTOL_NOVA_COLT },
			{ R"rx(^(eaglepistol|eagle|pistol)$)rx", CONST_WEAPON_ID_PISTOL_EAGLE },
			// Short range
			{ R"rx(^(sawed-?offshotgun|shotgun|sawed-?off)$)rx", CONST_WEAPON_ID_SHOTGUN_SAWED_OFF },
			{ R"rx(^(flak(cannon)?)$)rx", CONST_WEAPON_ID_TC24 },
			// Belt
			{ R"rx(^(emps?|empgrenades?)$)rx", CONST_WEAPON_ID_GRENADE_EMP },
			{ R"rx(^(emps?xls?|emps?xlgrenades?)$)rx", CONST_WEAPON_ID_GRENADE_EMP_MKD },
			{ R"rx(^(blackouts?|blackoutgrenades?)$)rx", CONST_WEAPON_ID_GRENADE_WHITEOUT },
			{ R"rx(^(clustergrenades?|clusters?)$)rx", CONST_WEAPON_ID_MIRV_GRENADE },
			{ R"rx(^(anti-?personnelgrenades?|aps?|apgrenades?)$)rx", CONST_WEAPON_ID_GRENADE_AP },
			{ R"rx(^(fraggrenades?(xl)?|frags?(xl)?|grenades?(xl)?)$)rx", CONST_WEAPON_ID_GRENADE_XL },
			{ R"rx(^(proxmitys?(grenades?)?|proxies|proxys?)$)rx", CONST_WEAPON_ID_PROXIMITY_GRENADE },
			{ R"rx(^(short-?fusefraggrenades?|short-?fuses?)$)rx", CONST_WEAPON_ID_GRENADE_XL_MKD },
		},

		// Heavy
		{
			// Impact
			{ R"rx(^(spinfusormkd)$)rx", CONST_WEAPON_ID_SPINFUSOR_D },
			{ R"rx(^(spinfusormk-?x)$)rx", CONST_WEAPON_ID_SPINFUSOR_D_MKD },
			{ R"rx(^(heavy(spin)?(fusor)?|spin(fusor)?|fusor)$)rx", CONST_WEAPON_ID_SPINFUSOR_HEAVY },
			{ R"rx(^(devastator(spinfusor)?)$)rx", CONST_WEAPON_ID_SPINFUSOR_HEAVY_MKD },
			{ R"rx(^(heavyboltlauncher|boltlauncher|bolt)$)rx", CONST_WEAPON_ID_LAUNCHER_BOLT_HEAVY },
			{ R"rx(^((heavy)?blinks?(fusor)?)$)rx", CONST_WEAPON_ID_SPINFUSOR_HEAVY_MKD },
			{ R"rx(^(heavytwinfusor|twinfusor|twin)$)rx", CONST_WEAPON_ID_HEAVYTWINFUSOR },
			// Timed
			{ R"rx(^((fusion)?mortardeluxe)$)rx", CONST_WEAPON_ID_LAUNCHER_MORTAR_MKD },
			{ R"rx(^(fusionmortar|mortar)$)rx", CONST_WEAPON_ID_LAUNCHER_MORTAR },
			{ R"rx(^(mirvlauncher|mirv)$)rx", CONST_WEAPON_ID_LAUNCHER_MIRV },
			// Speciality
			{ R"rx(^(saberlauncher|saber)$)rx", CONST_WEAPON_ID_LAUNCHER_SABER },
			{ R"rx(^(titanlauncher|titan)$)rx", CONST_WEAPON_ID_LAUNCHER_SABER_MKD },
			{ R"rx(^(gladiator)$)rx", CONST_WEAPON_ID_SPIKELAUNCHER },
			// Bullet
			{ R"rx(^(chaingun)$)rx", CONST_WEAPON_ID_CHAINGUN },
			{ R"rx(^(chaincannon)$)rx", CONST_WEAPON_ID_CHAINGUN_MKD },
			{ R"rx(^(x1|lmg|x1lmg)$)rx", CONST_WEAPON_ID_RIFLE_ASSAULT_X1 },
			{ R"rx(^(plasmacannon|plasma)$)rx", CONST_WEAPON_ID_PLASMA_CANNON },
			{ R"rx(^(novacolt|colt|nova)$)rx", CONST_WEAPON_ID_PISTOL_NOVA_SLUG },
			{ R"rx(^(mx|novablastermx|novamx|blaster(mx)?)$)rx", CONST_WEAPON_ID_PISTOL_NOVA_COLT_MKD },
			// Short Range
			{ R"rx(^(automaticshotgun|autoshotgun|shotgun)$)rx", CONST_WEAPON_ID_SHOTGUN_AUTO },
			{ R"rx(^((the)?hammer)$)rx", CONST_WEAPON_ID_SHOTGUN_AUTO_MKD },
			{ R"rx(^(efg)$)rx", CONST_WEAPON_ID_ELFFLAK },
			// Belt
			{ R"rx(^(fraggrenades?|frags?)$)rx", CONST_WEAPON_ID_GRENADE },
			{ R"rx(^(fractals?|fractalgrenades?)$)rx", CONST_WEAPON_ID_GRENADE_SPIKE },
			{ R"rx(^(extendedfractals?(grenades)?)$)rx", CONST_WEAPON_ID_GRENADE_SPIKE_MKD },
			{ R"rx(^(lightsticky(grenades?)?|lightstickies)$)rx", CONST_WEAPON_ID_GRENADE_STICKY_LIGHT },
			{ R"rx(^(mines?)$)rx", CONST_WEAPON_ID_MINE },
			{ R"rx(^(spinfusordisks?|spinfusordiscs?|spins?|disks?|discs?|spindisks?|spindiscs?)$)rx", CONST_WEAPON_ID_SPINFUSOR_TOSS },
		},
	};

	std::map<std::string, int> packs[3] = {
		{
			{ R"rx(^(thrust(pack)?)$)rx", CONST_ITEM_PACK_BLINK },
			{ R"rx(^((light)?energy(pack)?)$)rx", CONST_ITEM_PACK_RECHARGE_PATHFINDER },
			{ R"rx(^(stealth(pack)?)$)rx", CONST_ITEM_PACK_STEALTH },
			{ R"rx(^((light)?utility(pack)?)$)rx", CONST_ITEM_PACK_RECHARGE_SENTINEL }
		}, 
		{
			{ R"rx(^((light)?turret)$)rx", CONST_WEAPON_ID_TURRET_LIGHT },
			{ R"rx(^(dropstation)$)rx", CONST_WEAPON_ID_DROPJAMMER },
			{ R"rx(^(shield(pack)?)$)rx", CONST_ITEM_PACK_SHIELD },
			{ R"rx(^(util(ity)?(pack)?)$)rx", CONST_ITEM_PACK_UTILITY_SOLDIER },
			{ R"rx(^(jammer(pack)?)$)rx", CONST_ITEM_PACK_JAMMER },
			{ R"rx(^(exr(turret)?)$)rx", CONST_WEAPON_ID_TURRET_EXR }

		}, 
		{
			{ R"rx(^(forcefield)$)rx", CONST_WEAPON_ID_FORCEFIELD },
			{ R"rx(^((heavy)?energy(pack)?)$)rx", CONST_ITEM_PACK_ENERGY_BRUTE },
			{ R"rx(^((heavy)?shield(pack)?)$)rx", CONST_ITEM_PACK_HEAVYSHIELD },
			{ R"rx(^((heavy)?utility(pack)?)$)rx", CONST_ITEM_PACK_SURVIVAL }
		}
	};

	std::map<std::string, int> skins[3] = {
		{
			{ R"rx(^(pth|pathfinder|light|lht)$)rx", CONST_ITEM_SKIN_PATHFINDER },
			{ R"rx(^(inf|infiltrator)$)rx", CONST_ITEM_SKIN_INFILTRATOR },
			{ R"rx(^(sen|sentinel)$)rx", CONST_ITEM_SKIN_SENTINEL },
			{ R"rx(^(freerunner)$)rx", CONST_ITEM_SKIN_PATHFINDER_MERC },
			{ R"rx(^(mercenary)$)rx", CONST_ITEM_SKIN_INFILTRATOR_MERC },
			{ R"rx(^(assassin)$)rx", CONST_ITEM_SKIN_INFILTRATOR_ASSASSIN },
			{ R"rx(^(specter|spectre)$)rx", CONST_ITEM_SKIN_SENTINEL_MERC }
		},
		{
			{ R"rx(^(sld|soldier|med(ium)?)$)rx", CONST_ITEM_SKIN_SOLDIER },
			{ R"rx(^(tcn|technician)$)rx", CONST_ITEM_SKIN_TECHNICIAN },
			{ R"rx(^(rdr|raider)$)rx", CONST_ITEM_SKIN_RAIDER },
			{ R"rx(^(mercenary)$)rx", CONST_ITEM_SKIN_RAIDER_MERC },
			{ R"rx(^(griever)$)rx", CONST_ITEM_SKIN_RAIDER_GRIEVER },
			{ R"rx(^(specialist)$)rx", CONST_ITEM_SKIN_TECHNICIAN_MERC },
			{ R"rx(^(synthrall)$)rx", CONST_ITEM_SKIN_SOLDIER_MERC }
		},
		{
			{ R"rx(^(jug|juggernaut|heavy|hvy)$)rx", CONST_ITEM_SKIN_JUGGERNAUT },
			{ R"rx(^(dmb|doombringer)$)rx", CONST_ITEM_SKIN_DOOMBRINGER },
			{ R"rx(^(brt|brute)$)rx", CONST_ITEM_SKIN_BRUTE },
			{ R"rx(^(crusher)$)rx", CONST_ITEM_SKIN_BRUTE_MERC },
			{ R"rx(^(executioner)$)rx", CONST_ITEM_SKIN_DOOMBRINGER_MERC },
			{ R"rx(^((the)?forlorn)$)rx", CONST_ITEM_SKIN_JUGGERNAUT_MERC }
		}
	};

	std::map<std::string, int> voices = {
		{ R"rx(^(light|lht)$)rx", CONST_ITEM_VOICE_LIGHT },
		{ R"rx(^(med(ium)?)$)rx", CONST_ITEM_VOICE_MEDIUM },
		{ R"rx(^(heavy|hvy)$)rx", CONST_ITEM_VOICE_HEAVY },
		{ R"rx(^(battleworn)$)rx", CONST_ITEM_VOICE_DARK },
		{ R"rx(^(femmefatale)$)rx", CONST_ITEM_VOICE_FEM1 },
		{ R"rx(^(ms\.?wilderzone)$)rx", CONST_ITEM_VOICE_FEM2 },
		{ R"rx(^(diskerdundee|aus(tralian)?)$)rx", CONST_ITEM_VOICE_AUS },
		{ R"rx(^(tb|totalbiscuit)$)rx", CONST_ITEM_VOICE_TOTALBISCUIT },
		{ R"rx(^(stowaway)$)rx", CONST_ITEM_VOICE_STOWAWAY },
		{ R"rx(^(t2(fem(ale)?)?heroine)$)rx", CONST_ITEM_VOICE_T2FEM01 },
		{ R"rx(^(t2(fem(ale)?)?pro(fessional)?)$)rx", CONST_ITEM_VOICE_T2FEM02 },
		{ R"rx(^(t2(fem(ale)?)?cadet)$)rx", CONST_ITEM_VOICE_T2FEM03 },
		{ R"rx(^(t2(fem(ale)?)?veteran)$)rx", CONST_ITEM_VOICE_T2FEM04 },
		{ R"rx(^(t2(fem(ale)?)?amazon)$)rx", CONST_ITEM_VOICE_T2FEM05 },
		{ R"rx(^(t2(male)?hero)$)rx", CONST_ITEM_VOICE_T2MALE01 },
		{ R"rx(^(t2(male)?iceman)$)rx", CONST_ITEM_VOICE_T2MALE02 },
		{ R"rx(^(t2(male)?rogue)$)rx", CONST_ITEM_VOICE_T2MALE03 },
		{ R"rx(^(t2(male)?hardcase)$)rx", CONST_ITEM_VOICE_T2MALE04 },
		{ R"rx(^(t2(male)?psycho)$)rx", CONST_ITEM_VOICE_T2MALE05 },
		{ R"rx(^(t2(bioderm)?warrior)$)rx", CONST_ITEM_VOICE_T2BDERM01 },
		{ R"rx(^(t2(bioderm)?monster)$)rx", CONST_ITEM_VOICE_T2BDERM02 },
		{ R"rx(^(t2(bioderm)?predator)$)rx", CONST_ITEM_VOICE_T2BDERM03 }
	};

	std::map<int, std::string> weapon_id_to_name = {
		{ CONST_WEAPON_ID_SPINFUSOR_LIGHT, "LightSpinfusor" },
		{ CONST_WEAPON_ID_LAUNCHER_BOLT, "BoltLauncher" },
		{ CONST_WEAPON_ID_SPINFUSOR_LIGHT_MKD, "LightSpinfusor_MKD" },
		{ CONST_WEAPON_ID_LIGHTTWINFUSOR, "LightTwinfusor" },
		{ CONST_WEAPON_ID_SPINFUSOR_LIGHT_100X, "LightSpinfusor_100X" },
		{ CONST_WEAPON_ID_SHOTGUN, "Shotgun" },
		{ CONST_WEAPON_ID_RIFLE_ASSAULT_LIGHT, "LightAssaultRifle" },
		{ CONST_WEAPON_ID_SHOTGUN_MKD, "Shotgun_MKD" },
		{ CONST_WEAPON_ID_RIFLE_SNIPER, "SniperRifle" },
		{ CONST_WEAPON_ID_RIFLE_PHASE, "PhaseRifle" },
		{ CONST_WEAPON_ID_RIFLE_SNIPER_MKD, "SniperRifle_MKD" },
		{ CONST_WEAPON_ID_SAP20, "SAP20" },
		{ CONST_WEAPON_ID_PISTOL_NOVA_COLT, "NovaColt" },
		{ CONST_WEAPON_ID_PISTOL_FALCON, "Falcon" },
		{ CONST_WEAPON_ID_PISTOL_NOVA_COLT_MKD, "NovaColt_MKD" },
		{ CONST_WEAPON_ID_ACCURIZEDSHOTGUN, "AccurizedShotgun" },
		{ CONST_WEAPON_ID_SMG_RHINO, "RhinoSMG" },
		{ CONST_WEAPON_ID_STEALTHLIGHTSPINFUSOR, "StealthLightSpinfusor" },
		{ CONST_WEAPON_ID_REMOTE_ARX_BUSTER, "RemoteArxBuster" },
		{ CONST_WEAPON_ID_SMG_RHINO_MKD, "RhinoSMG_MKD" },
		{ CONST_WEAPON_ID_PISTOL_SN7, "SN7" },
		{ CONST_WEAPON_ID_LIGHTGRENADELAUNCHER, "LightGrenadeLauncher" },
		{ CONST_WEAPON_ID_THROWINGKNIVES, "ThrowingKnives" },
		{ CONST_WEAPON_ID_PISTOL_SN7_MKD, "SN7_MKD" },
		{ CONST_WEAPON_ID_RIFLE_ASSAULT, "AssaultRifle" },
		{ CONST_WEAPON_ID_SPINFUSOR, "Spinfusor" },
		{ CONST_WEAPON_ID_RIFLE_ASSAULT_MKD, "AssaultRifle_MKD" },
		{ CONST_WEAPON_ID_TWINFUSOR, "Twinfusor" },
		{ CONST_WEAPON_ID_THUMPER_D, "ThumperD" },
		{ CONST_WEAPON_ID_PISTOL_EAGLE, "Eagle" },
		{ CONST_WEAPON_ID_THUMPERD_MKD, "ThumperD_MKD" },
		{ CONST_WEAPON_ID_SPINFUSOR_100X, "Spinfusor_100X" },
		{ CONST_WEAPON_ID_ARX_BUSTER, "ArxBuster" },
		{ CONST_WEAPON_ID_LAUNCHER_GRENADE, "GrenadeLauncher" },
		{ CONST_WEAPON_ID_PLASMA_GUN, "PlasmaGun" },
		{ CONST_WEAPON_ID_ARX_BUSTER_MKD, "ArxBuster_MKD" },
		{ CONST_WEAPON_ID_SMG_NJ4, "NJ4SMG" },
		{ CONST_WEAPON_ID_NJ5SMG, "NJ5SMG" },
		{ CONST_WEAPON_ID_SMG_NJ4_MKD, "NJ4SMG_MKD" },
		{ CONST_WEAPON_ID_SMG_TCN4, "TCN4SMG" },
		{ CONST_WEAPON_ID_THUMPER, "Thumper" },
		{ CONST_WEAPON_ID_SMG_TCN4_MKD, "TCN4SMG_MKD" },
		{ CONST_WEAPON_ID_TC24, "TC24" },
		{ CONST_WEAPON_ID_REPAIR_TOOL_SD, "RepairToolSD" },
		{ CONST_WEAPON_ID_SHOTGUN_SAWED_OFF, "SawedOffShotgun" },
		{ CONST_WEAPON_ID_PISTOL_SPARROW, "Sparrow" },
		{ CONST_WEAPON_ID_REPAIR_TOOL_SD_MKD, "RepairToolSD_MKD" },
		{ CONST_WEAPON_ID_LAUNCHER_MORTAR, "MortarLauncher" },
		{ CONST_WEAPON_ID_LAUNCHER_MIRV, "MIRVLauncher" },
		{ CONST_WEAPON_ID_LAUNCHER_MORTAR_MKD, "MortarLauncher_MKD" },
		{ CONST_WEAPON_ID_SPINFUSOR_D, "SpinfusorD" },
		{ CONST_WEAPON_ID_RIFLE_ASSAULT_X1, "X1Rifle" },
		{ CONST_WEAPON_ID_SPINFUSOR_D_MKD, "SpinfusorD_MKD" },
		{ CONST_WEAPON_ID_HEAVYTWINFUSOR, "HeavyTwinfusor" },
		{ CONST_WEAPON_ID_CHAINGUN, "ChainGun" },
		{ CONST_WEAPON_ID_LAUNCHER_BOLT_HEAVY, "HeavyBoltLauncher" },
		{ CONST_WEAPON_ID_CHAINGUN_MKD, "ChainGun_MKD" },
		{ CONST_WEAPON_ID_LAUNCHER_SABER, "SaberLauncher" },
		{ CONST_WEAPON_ID_LAUNCHER_SABER_MKD, "SaberLauncher_MKD" },
		{ CONST_WEAPON_ID_SPINFUSOR_HEAVY, "HeavySpinfusor" },
		{ CONST_WEAPON_ID_SPIKELAUNCHER, "SpikeLauncher" },
		{ CONST_WEAPON_ID_SPINFUSOR_HEAVY_MKD, "HeavySpinfusor_MKD" },
		{ CONST_WEAPON_ID_SHOTGUN_AUTO, "AutoShotgun" },
		{ CONST_WEAPON_ID_PLASMA_CANNON, "PlasmaCannon" },
		{ CONST_WEAPON_ID_PISTOL_NOVA_SLUG, "NovaSlug" },
		{ CONST_WEAPON_ID_SHOTGUN_AUTO_MKD, "AutoShotgun_MKD" },
		{ CONST_WEAPON_ID_ELFPROJECTOR, "ElfProjector" },
		{ CONST_WEAPON_ID_ELFFLAK, "ElfFlak" },
		{ CONST_WEAPON_ID_PILOT_GRAVCYCLE, "GravCyclePilot" },
		{ CONST_WEAPON_ID_PILOT_SHRIKE, "ShrikePilot" },
		{ CONST_WEAPON_ID_PILOT_BEOWULF, "BeowulfPilot" },
		{ CONST_WEAPON_ID_GUNNER_BEOWULF, "BeowulfGunner" }
	};

	std::map<int, std::string> weapon_id_to_proj_name = {
		// Light
		{ CONST_WEAPON_ID_SPINFUSOR_LIGHT, "LightSpinfusor" },
		{ CONST_WEAPON_ID_LAUNCHER_BOLT, "BoltLauncher" },
		{ CONST_WEAPON_ID_SPINFUSOR_LIGHT_MKD, "LightSpinfusor_MKD" },
		{ CONST_WEAPON_ID_LIGHTTWINFUSOR, "LightTwinfusor" },
		{ CONST_WEAPON_ID_SPINFUSOR_LIGHT_100X, "LightSpinfusor_100X" },
		{ CONST_WEAPON_ID_SHOTGUN, "" },
		{ CONST_WEAPON_ID_RIFLE_ASSAULT_LIGHT, "LightAssaultRifle" },
		{ CONST_WEAPON_ID_SHOTGUN_MKD, "" },
		{ CONST_WEAPON_ID_RIFLE_SNIPER, "" },
		{ CONST_WEAPON_ID_RIFLE_PHASE, "" },
		{ CONST_WEAPON_ID_RIFLE_SNIPER_MKD, "" },
		{ CONST_WEAPON_ID_SAP20, "" },
		{ CONST_WEAPON_ID_PISTOL_NOVA_COLT, "NovaColt" },
		{ CONST_WEAPON_ID_PISTOL_FALCON, "Falcon" },
		{ CONST_WEAPON_ID_PISTOL_NOVA_COLT_MKD, "NovaColt_MKD" },
		{ CONST_WEAPON_ID_ACCURIZEDSHOTGUN, "" },
		{ CONST_WEAPON_ID_SMG_RHINO, "RhinoSMG" },
		{ CONST_WEAPON_ID_STEALTHLIGHTSPINFUSOR, "StealthSpinfusor" },
		{ CONST_WEAPON_ID_REMOTE_ARX_BUSTER, "RemoteArxBuster" },
		{ CONST_WEAPON_ID_SMG_RHINO_MKD, "RhinoSMG_MKD" },
		{ CONST_WEAPON_ID_PISTOL_SN7, "SN7" },
		{ CONST_WEAPON_ID_THROWINGKNIVES, "ThrowingKnives" },
		{ CONST_WEAPON_ID_PISTOL_SN7_MKD, "SN7_MKD" },
		{ CONST_WEAPON_ID_GRENADE_NITRON, "ConcussionGrenade" },
		{ CONST_WEAPON_ID_GRENADE_NITRON_MKD, "ConcussionGrenade_MKD" },
		{ CONST_WEAPON_ID_GRENADE_ST, "STGrenade" },
		{ CONST_WEAPON_ID_GRENADE_T5 , "GrenadeT5" },
		{ CONST_WEAPON_ID_GRENADE_STICKY, "StickyGrenade" },
		{ CONST_WEAPON_ID_GRENADE_STICKY_MKD, "StickyGrenade_MKD" },
		{ CONST_WEAPON_ID_MINE_CLAYMORE, "Claymore" },
		{ CONST_WEAPON_ID_MINE_PRISM, "PrismMine" },
		{ CONST_WEAPON_ID_GRENADE_NINJASMOKE, "NinjaSmoke" },

		// Medium
		{ CONST_WEAPON_ID_RIFLE_ASSAULT, "AssaultRifle" },
		{ CONST_WEAPON_ID_SPINFUSOR, "Spinfusor" },
		{ CONST_WEAPON_ID_RIFLE_ASSAULT_MKD, "AssaultRifle_MKD" },
		{ CONST_WEAPON_ID_TWINFUSOR, "Twinfusor" },
		{ CONST_WEAPON_ID_THUMPER_D, "ThumperD" },
		{ CONST_WEAPON_ID_PISTOL_EAGLE, "Eagle" },
		{ CONST_WEAPON_ID_THUMPERD_MKD, "ThumperD_MKD" },
		{ CONST_WEAPON_ID_SPINFUSOR_100X, "Spinfusor_100X" },
		{ CONST_WEAPON_ID_ARX_BUSTER, "ArxBuster" },
		{ CONST_WEAPON_ID_LAUNCHER_GRENADE, "GrenadeLauncher" },
		{ CONST_WEAPON_ID_PLASMA_GUN, "PlasmaGun" },
		{ CONST_WEAPON_ID_ARX_BUSTER_MKD, "ArxBuster_MKD" },
		{ CONST_WEAPON_ID_SMG_NJ4, "NJ4SMG" },
		{ CONST_WEAPON_ID_NJ5SMG, "NJ5SMG" },
		{ CONST_WEAPON_ID_SMG_NJ4_MKD, "NJ4SMG_MKD" },
		{ CONST_WEAPON_ID_SMG_TCN4, "TCN4SMG" },
		{ CONST_WEAPON_ID_THUMPER, "Thumper" },
		{ CONST_WEAPON_ID_SMG_TCN4_MKD, "TCN4SMG_MKD" },
		{ CONST_WEAPON_ID_TC24, "TC24" },
		{ CONST_WEAPON_ID_REPAIR_TOOL_SD, "" },
		{ CONST_WEAPON_ID_SHOTGUN_SAWED_OFF, "SawedOffShotgun" },
		{ CONST_WEAPON_ID_PISTOL_SPARROW, "" },
		{ CONST_WEAPON_ID_REPAIR_TOOL_SD_MKD, "" },
		{ CONST_WEAPON_ID_GRENADE_EMP, "EMPGrenade" },
		{ CONST_WEAPON_ID_GRENADE_EMP_MKD, "EMPGrenade_MKD" },
		{ CONST_WEAPON_ID_GRENADE_WHITEOUT, "WhiteOut" },
		{ CONST_WEAPON_ID_MIRV_GRENADE, "MIRVGrenade" },
		{ CONST_WEAPON_ID_GRENADE_AP, "APGrenade" },
		{ CONST_WEAPON_ID_GRENADE_XL, "GrenadeXL" },
		{ CONST_WEAPON_ID_PROXIMITY_GRENADE, "ProximityGrenade" },
		{ CONST_WEAPON_ID_GRENADE_XL_MKD, "GrenadeXL_MKD" },

		// Heavy
		{ CONST_WEAPON_ID_LAUNCHER_MORTAR, "MortarLauncher" },
		{ CONST_WEAPON_ID_LAUNCHER_MIRV, "MIRVLauncher" },
		{ CONST_WEAPON_ID_LAUNCHER_MORTAR_MKD, "MortarLauncher_MKD" },
		{ CONST_WEAPON_ID_SPINFUSOR_D, "SpinfusorD" },
		{ CONST_WEAPON_ID_RIFLE_ASSAULT_X1, "X1Rifle" },
		{ CONST_WEAPON_ID_SPINFUSOR_D_MKD, "SpinfusorD_MKD" },
		{ CONST_WEAPON_ID_HEAVYTWINFUSOR, "HeavyTwinfusor" },
		{ CONST_WEAPON_ID_CHAINGUN, "Chaingun" },
		{ CONST_WEAPON_ID_LAUNCHER_BOLT_HEAVY, "HeavyBoltLauncher" },
		{ CONST_WEAPON_ID_CHAINGUN_MKD, "Chaingun_MKD" },
		{ CONST_WEAPON_ID_LAUNCHER_SABER, "TrackingMissile" },
		{ CONST_WEAPON_ID_LAUNCHER_SABER_MKD, "TrackingMissile_MKD" },
		{ CONST_WEAPON_ID_SPINFUSOR_HEAVY, "HeavySpinfusor" },
		{ CONST_WEAPON_ID_SPIKELAUNCHER, "SpikeLauncher" },
		{ CONST_WEAPON_ID_SPINFUSOR_HEAVY_MKD, "HeavySpinfusor_MKD" },
		{ CONST_WEAPON_ID_SHOTGUN_AUTO, "" },
		{ CONST_WEAPON_ID_PLASMA_CANNON, "" },
		{ CONST_WEAPON_ID_PISTOL_NOVA_SLUG, "" },
		{ CONST_WEAPON_ID_SHOTGUN_AUTO_MKD, "" },
		{ CONST_WEAPON_ID_ELFPROJECTOR, "" },
		{ CONST_WEAPON_ID_ELFFLAK, "ElfFlak" },
		{ CONST_WEAPON_ID_GRENADE,  "Grenade" },
		{ CONST_WEAPON_ID_GRENADE_SPIKE, "SpikeGrenade" },
		{ CONST_WEAPON_ID_GRENADE_SPIKE_MKD, "SpikeGrenade_MKD" },
		{ CONST_WEAPON_ID_GRENADE_STICKY_LIGHT, "LightStickyGrenade" },
		{ CONST_WEAPON_ID_MINE, "Mine" },
		{ CONST_WEAPON_ID_SPINFUSOR_TOSS, "DiskToss" },

		// Vehicle
		{ CONST_WEAPON_ID_PILOT_GRAVCYCLE, "GravCyclePilot" },
		{ CONST_WEAPON_ID_PILOT_SHRIKE, "ShrikePilot" },
		{ CONST_WEAPON_ID_PILOT_BEOWULF, "BeowulfPilot" },
		{ CONST_WEAPON_ID_GUNNER_BEOWULF, "BeowulfGunner" },
	};

	std::map<int, UClass*> weapon_id_to_weapon_class = {
		// Light
		{ CONST_WEAPON_ID_SPINFUSOR_LIGHT, ATrDevice_LightSpinfusor::StaticClass() },
		{ CONST_WEAPON_ID_LAUNCHER_BOLT, ATrDevice_BoltLauncher::StaticClass() },
		{ CONST_WEAPON_ID_SPINFUSOR_LIGHT_MKD, ATrDevice_LightSpinfusor_MKD::StaticClass() },
		{ CONST_WEAPON_ID_LIGHTTWINFUSOR, ATrDevice_LightTwinfusor::StaticClass() },
		{ CONST_WEAPON_ID_SPINFUSOR_LIGHT_100X, ATrDevice_LightSpinfusor_100X::StaticClass() },
		{ CONST_WEAPON_ID_SHOTGUN, ATrDevice_Shotgun::StaticClass() },
		{ CONST_WEAPON_ID_RIFLE_ASSAULT_LIGHT, ATrDevice_LightAssaultRifle::StaticClass() },
		{ CONST_WEAPON_ID_SHOTGUN_MKD, ATrDevice_Shotgun_MKD::StaticClass() },
		{ CONST_WEAPON_ID_RIFLE_SNIPER, ATrDevice_SniperRifle::StaticClass() },
		{ CONST_WEAPON_ID_RIFLE_PHASE, ATrDevice_PhaseRifle::StaticClass() },
		{ CONST_WEAPON_ID_RIFLE_SNIPER_MKD, ATrDevice_SniperRifle_MKD::StaticClass() },
		{ CONST_WEAPON_ID_SAP20, ATrDevice_SAP20::StaticClass() },
		{ CONST_WEAPON_ID_PISTOL_NOVA_COLT, ATrDevice_NovaColt::StaticClass() },
		{ CONST_WEAPON_ID_PISTOL_FALCON, ATrDevice_Falcon::StaticClass() },
		{ CONST_WEAPON_ID_PISTOL_NOVA_COLT_MKD, ATrDevice_NovaColt_MKD::StaticClass() },
		{ CONST_WEAPON_ID_ACCURIZEDSHOTGUN, ATrDevice_AccurizedShotgun::StaticClass() },
		{ CONST_WEAPON_ID_SMG_RHINO, ATrDevice_RhinoSMG::StaticClass() },
		{ CONST_WEAPON_ID_STEALTHLIGHTSPINFUSOR, ATrDevice_StealthLightSpinfusor::StaticClass() },
		{ CONST_WEAPON_ID_REMOTE_ARX_BUSTER, ATrDevice_RemoteArxBuster::StaticClass() },
		{ CONST_WEAPON_ID_SMG_RHINO_MKD, ATrDevice_RhinoSMG_MKD::StaticClass() },
		{ CONST_WEAPON_ID_PISTOL_SN7, ATrDevice_SN7::StaticClass() },
		{ CONST_WEAPON_ID_LIGHTGRENADELAUNCHER, ATrDevice_GrenadeLauncher_Light::StaticClass() },
		{ CONST_WEAPON_ID_THROWINGKNIVES, ATrDevice_ThrowingKnives::StaticClass() },
		{ CONST_WEAPON_ID_PISTOL_SN7_MKD, ATrDevice_SN7_MKD::StaticClass() },
		{ CONST_WEAPON_ID_GRENADE_NITRON, ATrDevice_ConcussionGrenade::StaticClass() },
		{ CONST_WEAPON_ID_GRENADE_NITRON_MKD, ATrDevice_ConcussionGrenade_MKD::StaticClass() },
		{ CONST_WEAPON_ID_GRENADE_ST, ATrDevice_STGrenade::StaticClass() },
		{ CONST_WEAPON_ID_GRENADE_T5 , ATrDevice_GrenadeT5::StaticClass() },
		{ CONST_WEAPON_ID_GRENADE_STICKY, ATrDevice_StickyGrenade::StaticClass() },
		{ CONST_WEAPON_ID_GRENADE_STICKY_MKD, ATrDevice_StickyGrenade_MKD::StaticClass() },
		{ CONST_WEAPON_ID_MINE_CLAYMORE, ATrDevice_Claymore::StaticClass() },
		{ CONST_WEAPON_ID_MINE_PRISM, ATrDevice_PrismMineDeployable::StaticClass() },
		{ CONST_WEAPON_ID_GRENADE_NINJASMOKE, ATrDevice_NinjaSmoke::StaticClass() },

		// Medium
		{ CONST_WEAPON_ID_RIFLE_ASSAULT, ATrDevice_AssaultRifle::StaticClass() },
		{ CONST_WEAPON_ID_SPINFUSOR, ATrDevice_Spinfusor::StaticClass() },
		{ CONST_WEAPON_ID_RIFLE_ASSAULT_MKD, ATrDevice_AssaultRifle_MKD::StaticClass() },
		{ CONST_WEAPON_ID_TWINFUSOR, ATrDevice_Twinfusor::StaticClass() },
		{ CONST_WEAPON_ID_THUMPER_D, ATrDevice_ThumperD::StaticClass() },
		{ CONST_WEAPON_ID_PISTOL_EAGLE, ATrDevice_Eagle::StaticClass() },
		{ CONST_WEAPON_ID_THUMPERD_MKD, ATrDevice_ThumperD_MKD::StaticClass() },
		{ CONST_WEAPON_ID_SPINFUSOR_100X, ATrDevice_Spinfusor_100X::StaticClass() },
		{ CONST_WEAPON_ID_ARX_BUSTER, ATrDevice_ArxBuster::StaticClass() },
		{ CONST_WEAPON_ID_LAUNCHER_GRENADE, ATrDevice_GrenadeLauncher::StaticClass() },
		{ CONST_WEAPON_ID_PLASMA_GUN, ATrDevice_PlasmaGun::StaticClass() },
		{ CONST_WEAPON_ID_ARX_BUSTER_MKD, ATrDevice_ArxBuster_MKD::StaticClass() },
		{ CONST_WEAPON_ID_SMG_NJ4, ATrDevice_NJ4SMG::StaticClass() },
		{ CONST_WEAPON_ID_NJ5SMG, ATrDevice_NJ5SMG::StaticClass() },
		{ CONST_WEAPON_ID_SMG_NJ4_MKD, ATrDevice_NJ4SMG_MKD::StaticClass() },
		{ CONST_WEAPON_ID_SMG_TCN4, ATrDevice_TCN4SMG::StaticClass() },
		{ CONST_WEAPON_ID_THUMPER, ATrDevice_Thumper::StaticClass() },
		{ CONST_WEAPON_ID_SMG_TCN4_MKD, ATrDevice_TCN4SMG_MKD::StaticClass() },
		{ CONST_WEAPON_ID_TC24, ATrDevice_TC24::StaticClass() },
		{ CONST_WEAPON_ID_REPAIR_TOOL_SD, ATrDevice_RepairToolSD::StaticClass() },
		{ CONST_WEAPON_ID_SHOTGUN_SAWED_OFF, ATrDevice_SawedOffShotgun::StaticClass() },
		{ CONST_WEAPON_ID_PISTOL_SPARROW, ATrDevice_Sparrow::StaticClass() },
		{ CONST_WEAPON_ID_REPAIR_TOOL_SD_MKD, ATrDevice_RepairToolSD_MKD::StaticClass() },
		{ CONST_WEAPON_ID_GRENADE_EMP, ATrDevice_EMPGrenade::StaticClass() },
		{ CONST_WEAPON_ID_GRENADE_EMP_MKD, ATrDevice_EMPGrenade_MKD::StaticClass() },
		{ CONST_WEAPON_ID_GRENADE_WHITEOUT, ATrDevice_WhiteOut::StaticClass() },
		{ CONST_WEAPON_ID_MIRV_GRENADE, ATrDevice_MIRVGrenade::StaticClass() },
		{ CONST_WEAPON_ID_GRENADE_AP, ATrDevice_APGrenade::StaticClass() },
		{ CONST_WEAPON_ID_GRENADE_XL, ATrDevice_GrenadeXL::StaticClass() },
		{ CONST_WEAPON_ID_PROXIMITY_GRENADE, ATrDevice_ProximityGrenade::StaticClass() },
		{ CONST_WEAPON_ID_GRENADE_XL_MKD, ATrDevice_GrenadeXL_MKD::StaticClass() },

		// Heavy
		{ CONST_WEAPON_ID_LAUNCHER_MORTAR, ATrDevice_MortarLauncher::StaticClass() },
		{ CONST_WEAPON_ID_LAUNCHER_MIRV, ATrDevice_MIRVLauncher::StaticClass() },
		{ CONST_WEAPON_ID_LAUNCHER_MORTAR_MKD, ATrDevice_MortarLauncher_MKD::StaticClass() },
		{ CONST_WEAPON_ID_SPINFUSOR_D, ATrDevice_SpinfusorD::StaticClass() },
		{ CONST_WEAPON_ID_RIFLE_ASSAULT_X1, ATrDevice_X1Rifle::StaticClass() },
		{ CONST_WEAPON_ID_SPINFUSOR_D_MKD, ATrDevice_SpinfusorD_MKD::StaticClass() },
		{ CONST_WEAPON_ID_HEAVYTWINFUSOR, ATrDevice_HeavyTwinfusor::StaticClass() },
		{ CONST_WEAPON_ID_CHAINGUN, ATrDevice_ChainGun::StaticClass() },
		{ CONST_WEAPON_ID_LAUNCHER_BOLT_HEAVY, ATrDevice_HeavyBoltLauncher::StaticClass() },
		{ CONST_WEAPON_ID_CHAINGUN_MKD, ATrDevice_ChainGun_MKD::StaticClass() },
		{ CONST_WEAPON_ID_LAUNCHER_SABER, ATrDevice_SaberLauncher::StaticClass() },
		{ CONST_WEAPON_ID_LAUNCHER_SABER_MKD, ATrDevice_SaberLauncher_MKD::StaticClass() },
		{ CONST_WEAPON_ID_SPINFUSOR_HEAVY, ATrDevice_HeavySpinfusor::StaticClass() },
		{ CONST_WEAPON_ID_SPIKELAUNCHER, ATrDevice_SpikeLauncher::StaticClass() },
		{ CONST_WEAPON_ID_SPINFUSOR_HEAVY_MKD, ATrDevice_HeavySpinfusor_MKD::StaticClass() },
		{ CONST_WEAPON_ID_SHOTGUN_AUTO, ATrDevice_AutoShotgun::StaticClass() },
		{ CONST_WEAPON_ID_PLASMA_CANNON, ATrDevice_PlasmaCannon::StaticClass() },
		{ CONST_WEAPON_ID_PISTOL_NOVA_SLUG, ATrDevice_NovaSlug::StaticClass() },
		{ CONST_WEAPON_ID_SHOTGUN_AUTO_MKD, ATrDevice_AutoShotgun::StaticClass() },
		{ CONST_WEAPON_ID_ELFPROJECTOR, ATrDevice_ElfProjector::StaticClass() },
		{ CONST_WEAPON_ID_ELFFLAK, ATrDevice_ElfFlak::StaticClass() },
		{ CONST_WEAPON_ID_PILOT_GRAVCYCLE, ATrVehicleWeapon_GravCyclePilot::StaticClass() },
		{ CONST_WEAPON_ID_PILOT_SHRIKE, ATrVehicleWeapon_ShrikePilot::StaticClass() },
		{ CONST_WEAPON_ID_PILOT_BEOWULF, ATrVehicleWeapon_BeowulfPilot::StaticClass() },
		{ CONST_WEAPON_ID_GUNNER_BEOWULF, ATrVehicleWeapon_BeowulfGunner::StaticClass() },
		{ CONST_WEAPON_ID_GRENADE,  ATrDevice_Grenade::StaticClass() },
		{ CONST_WEAPON_ID_GRENADE_SPIKE, ATrDevice_SpikeGrenade::StaticClass() },
		{ CONST_WEAPON_ID_GRENADE_SPIKE_MKD, ATrDevice_SpikeGrenade_MKD::StaticClass() },
		{ CONST_WEAPON_ID_GRENADE_STICKY_LIGHT, ATrDevice_LightStickyGrenade::StaticClass() },
		{ CONST_WEAPON_ID_MINE, ATrDevice_Mine::StaticClass() },
		{ CONST_WEAPON_ID_SPINFUSOR_TOSS, ATrDevice_DiskToss::StaticClass() },
	};

	std::map<std::string, int> vehicle_weapons =
	{
		{ R"rx(^(grav(cycle|bike)?)$)rx", CONST_WEAPON_ID_PILOT_GRAVCYCLE },
		{ R"rx(^(shrike(pilot)?)$)rx", CONST_WEAPON_ID_PILOT_SHRIKE },
		{ R"rx(^(tank|beowulf(cann?on|pilot)?)$)rx", CONST_WEAPON_ID_PILOT_BEOWULF },
		{ R"rx(^((tank|beowulf)(gunner|chaingun|chain|gun))$)rx", CONST_WEAPON_ID_GUNNER_BEOWULF },
		{ R"rx(^(havoc)$)rx", CONST_WEAPON_ID_PILOT_HAVOC },
		{ R"rx(^(herc(cann?on|pilot))$)rx", CONST_WEAPON_ID_PILOT_HERC },
		{ R"rx(^(herc(gunner|chaingun|chain|gun))$)rx", CONST_WEAPON_ID_GUNNER_HERC },
	};

	std::map<int, UClass*> vehicle_weapon_id_to_class = {
		{CONST_WEAPON_ID_PILOT_GRAVCYCLE, ATrVehicleWeapon_GravCyclePilot::StaticClass()},
		{CONST_WEAPON_ID_PILOT_SHRIKE, ATrVehicleWeapon_ShrikePilot::StaticClass()},
		{CONST_WEAPON_ID_PILOT_BEOWULF, ATrVehicleWeapon_BeowulfPilot::StaticClass()},
		{CONST_WEAPON_ID_GUNNER_BEOWULF, ATrVehicleWeapon_BeowulfGunner::StaticClass()},
		{CONST_WEAPON_ID_PILOT_HAVOC, ATrVehicleWeapon_HavocPilot::StaticClass()},
		{CONST_WEAPON_ID_PILOT_HERC, ATrVehicleWeapon_HERCPilot::StaticClass()},
		{CONST_WEAPON_ID_GUNNER_HERC, ATrVehicleWeapon_HERCGunner::StaticClass()},
	};

	std::map<int, std::string> vehicle_weapon_id_to_name = {
		{CONST_WEAPON_ID_PILOT_GRAVCYCLE, "GravCyclePilot"},
		{CONST_WEAPON_ID_PILOT_SHRIKE, "ShrikePilot"},
		{CONST_WEAPON_ID_PILOT_BEOWULF, "BeowulfPilot"},
		{CONST_WEAPON_ID_GUNNER_BEOWULF, "BeowulfGunner"},
		{CONST_WEAPON_ID_PILOT_HAVOC, "HavocPilot"},
		{CONST_WEAPON_ID_PILOT_HERC, "HERCPilot"},
		{CONST_WEAPON_ID_GUNNER_HERC, "HERCGunner"},
	};

	std::map<std::string, int> vehicles = {
		{ R"rx(^(grav(cycle|bike)?)$)rx", 1 },
		{ R"rx(^(tank|beowulf)$)rx", 2 },
		{ R"rx(^(shrike)$)rx", 3 },
		{ R"rx(^(havoc)$)rx", 4 },
		{ R"rx(^(herc)$)rx", 5 },
	};

	std::map<int, std::string> vehicle_id_to_name = {
		{1, "GravCycle"},
		{2, "Beowulf"},
		{3, "Shrike"},
		{4, "Havoc"},
		{5, "HERC"},
	};

	std::map<int, UClass*> vehicle_id_to_class = {
		{1, ATrVehicle_GravCycle::StaticClass()},
		{2, ATrVehicle_Beowulf::StaticClass()},
		{3, ATrVehicle_Shrike::StaticClass()},
		{4, ATrVehicle_Havoc::StaticClass()},
		{5, ATrVehicle_HERC::StaticClass()},
	};

	std::map<std::string, int> classes =
	{
		{ R"rx(^(light|lht)$)rx", 1 },
		{ R"rx(^(medium|med)$)rx", 2 },
		{ R"rx(^(heavy|hvy)$)rx", 3 }
	};

	std::map<std::string, int> crosshairs =
	{
		{ R"rx(^(spin(fusor)?)$)rx", CONST_THR_SPINFUSOR },
		{ R"rx(^(smg)$)rx", CONST_THR_SMG },
		{ R"rx(^(rifle)$)rx", CONST_THR_RIFLE },
		{ R"rx(^(locked_?on)$)rx", CONST_THR_LOCKED_ON },
		{ R"rx(^(crossbow)$)rx", CONST_THR_CROSSBOW },
		{ R"rx(^(flamethrower)$)rx", CONST_THR_FLAME_THROWER },
		{ R"rx(^(chaingun)$)rx", CONST_THR_CHAIN_GUN },
		{ R"rx(^(bolt(launcher)?|thumper|missile)$)rx", CONST_THR_MISSILE },
		{ R"rx(^(nanite)$)rx", CONST_THR_NANITE },
		{ R"rx(^(shotgun)$)rx", CONST_THR_SHOTGUN },
		{ R"rx(^(unknown)$)rx", CONST_THR_UNKNOWN },
		{ R"rx(^(laser)$)rx", CONST_THR_LASER },
		{ R"rx(^(ch_?v13)$)rx", CONST_THR_CH_V13 },
		{ R"rx(^(scope)$)rx", CONST_THR_SCOPE },
		{ R"rx(^(standard|(nova)?(colt|blaster)?)$)rx", CONST_THR_STANDARD },
		{ R"rx(^(grenadelauncher|mortar)$)rx", CONST_THR_GRENADE_LAUNCHER },
		{ R"rx(^(melee)$)rx", CONST_THR_MELEE },
		{ R"rx(^(shrike)$)rx", CONST_THR_SHRIKE },
		{ R"rx(^(spectator)$)rx", CONST_THR_FREE_SPECTATOR },
		{ R"rx(^(chain|dot|assaultrifle|ar|red_?dot)$)rx", CONST_THR_RED_DOT },
		{ R"rx(^(bxt1?)$)rx", CONST_THR_BXT1 },
		{ R"rx(^(phase(rifle)?)$)rx", CONST_THR_PHASERIFLE },
		{ R"rx(^(sap(20)?)$)rx", CONST_THR_SAP20 },
		{ R"rx(^(plasma(gun)?)$)rx", CONST_THR_PLASMAGUN }
	};

	int classes_id[3] = {
		CONST_CLASS_TYPE_LIGHT,
		CONST_CLASS_TYPE_MEDIUM,
		CONST_CLASS_TYPE_HEAVY
	};

	std::map<int, std::string> class_id_to_name = {
		{CONST_CLASS_TYPE_LIGHT, "Light_Pathfinder"},
		{CONST_CLASS_TYPE_MEDIUM, "Medium_Soldier"},
		{CONST_CLASS_TYPE_HEAVY, "Heavy_Juggernaught"},
	};

	std::map<int, UClass*> class_id_to_class = {
		{CONST_CLASS_TYPE_LIGHT, UTrFamilyInfo_Light_Pathfinder::StaticClass()},
		{CONST_CLASS_TYPE_MEDIUM, UTrFamilyInfo_Medium_Soldier::StaticClass()},
		{CONST_CLASS_TYPE_HEAVY, UTrFamilyInfo_Heavy_Juggernaught::StaticClass()},
	};

	std::map<int, int> class_id_to_nb =
	{
		{ CONST_CLASS_TYPE_LIGHT, 0 },
		{ CONST_CLASS_TYPE_MEDIUM, 1 },
		{ CONST_CLASS_TYPE_HEAVY, 2 }
	};

	std::string class_type_name[] =
	{
		"Light",
		"Medium",
		"Heavy"
	};

	std::string equip_type_name[] =
	{
		"Impact",
		"Timed",
		"Specialty",
		"Automatic",
		"Short Range",
		"Sidearm",
		"Belt",
		"Pack"
	};

	std::map<std::string, int> map_id = {
		{ R"rx(^arena[-_]?a.*$)rx",                     CONST_MAP_ID_ARENA_AIRARENA },
		{ R"rx(^arena[-_]?(f|to).*$)rx",                CONST_MAP_ID_ARENA_FRAYTOWN },
		{ R"rx(^arena[-_]?(h|lan).*$)rx",               CONST_MAP_ID_ARENA_HINTERLANDS },
		{ R"rx(^arena[-_]?(lav|lar).*$)rx",             CONST_MAP_ID_ARENA_LAVAARENA },
		{ R"rx(^arena[-_]?(u|cr).*$)rx",                CONST_MAP_ID_ARENA_UNDERCROFT },
		{ R"rx(^arena[-_]?(wi|wa|in).*$)rx",            CONST_MAP_ID_ARENA_WALLEDIN },
		{ R"rx(^arena[-_]?(wo|wh|ou).*$)rx",            CONST_MAP_ID_ARENA_WHITEOUT },

		{ R"rx(^blitz[-_]?(a|no).*$)rx",                CONST_MAP_ID_BLITZ_ARXNOVENA },
		{ R"rx(^blitz[-_]?(b[eo]|om).*$)rx",            CONST_MAP_ID_BLITZ_BELLAOMEGA },
		{ R"rx(^blitz[-_]?(b[ls]|sh).*$)rx",            CONST_MAP_ID_BLITZ_BLUESHIFT },
		{ R"rx(^blitz[-_]?(ccr?|ca|cru|c?re).*$)rx",    CONST_MAP_ID_BLITZ_CANYONCRUSADEREVIVAL },
		{ R"rx(^blitz[-_]?(cf|x|cro|fi).*$)rx",         CONST_MAP_ID_BLITZ_CROSSFIRE },
		{ R"rx(^blitz[-_]?d.*$)rx",                     CONST_MAP_ID_BLITZ_DRYDOCK },
		{ R"rx(^blitz[-_]?h.*$)rx",                     CONST_MAP_ID_BLITZ_HELLFIRE },
		{ R"rx(^blitz[-_]?(k|ba).*$)rx",                CONST_MAP_ID_BLITZ_KATABATIC },

		{ R"rx(^cah[-_]?(c[^o]|re).*$)rx",              CONST_MAP_ID_CAH_CANYONCRUSADEREVIVAL },
		{ R"rx(^cah[-_]?(d[^a]|ni).*$)rx",              CONST_MAP_ID_CAH_DRYDOCKNIGHT },
		{ R"rx(^cah[-_]?(k|ba).*$)rx",                  CONST_MAP_ID_CAH_KATABATIC },
		{ R"rx(^cah[-_]?(3|o|sk).*$)rx",                CONST_MAP_ID_CAH_OUTSKIRTS3P },
		{ R"rx(^cah[-_]?(r[^eu]|da).*$)rx",             CONST_MAP_ID_CAH_RAINDANCE },
		{ R"rx(^cah[-_]?(s[^k]|co).*$)rx",              CONST_MAP_ID_CAH_SULFURCOVE },
		{ R"rx(^cah[-_]?(t|ru).*$)rx",                  CONST_MAP_ID_CAH_TARTARUS },

		{ R"rx(^ctf[-_]?(a|no).*$)rx",                  CONST_MAP_ID_CTF_ARXNOVENA },
		{ R"rx(^ctf[-_]?(be|bo|bella|b?omega)+$)rx",    CONST_MAP_ID_CTF_BELLAOMEGA },
		{ R"rx(^ctf[-_]?(be|bo|bella|b?omega)+n.*$)rx", CONST_MAP_ID_CTF_BELLAOMEGANS },
		{ R"rx(^ctf[-_]?(bl|bs|shi).*$)rx",             CONST_MAP_ID_CTF_BLUESHIFT },
		{ R"rx(^ctf[-_]?(ccr?|ca|cru|re).*$)rx",        CONST_MAP_ID_CTF_CANYONCRUSADEREVIVAL },
		{ R"rx(^ctf[-_]?(cf|x|cro|fi).*$)rx",           CONST_MAP_ID_CTF_CROSSFIRE },
		{ R"rx(^ctf[-_]?(dx|dc|dang).*$)rx",            CONST_MAP_ID_CTF_DANGEROUSCROSSING },
		{ R"rx(^ctf[-_]?(dd|dr|do).*$)rx",              CONST_MAP_ID_CTF_DRYDOCK },
		{ R"rx(^ctf[-_]?h.*$)rx",                       CONST_MAP_ID_CTF_HELLFIRE },
		{ R"rx(^ctf[-_]?(i|co|to).*$)rx",               CONST_MAP_ID_CTF_ICECOASTER },
		{ R"rx(^ctf[-_]?(k|ba).*$)rx",                  CONST_MAP_ID_CTF_KATABATIC },
		{ R"rx(^ctf[-_]?(pd|perd).*$)rx",               CONST_MAP_ID_CTF_PERDITION },
		{ R"rx(^ctf[-_]?(pf|perm|fr).*$)rx",            CONST_MAP_ID_CTF_PERMAFROST },
		{ R"rx(^ctf[-_]?(r[^eu]|danc).*$)rx",           CONST_MAP_ID_CTF_RAINDANCE },
		{ R"rx(^ctf[-_]?(sh[^i]|st[^a]).*$)rx",         CONST_MAP_ID_CTF_STONEHENGE },
		{ R"rx(^ctf[-_]?(ss|su|sta).*$)rx",             CONST_MAP_ID_CTF_SUNSTAR },
		{ R"rx(^ctf[-_]?(ta|tt|rus).*$)rx",             CONST_MAP_ID_CTF_TARTARUS },
		{ R"rx(^ctf[-_]?(tem|tr|rui).*$)rx",            CONST_MAP_ID_CTF_TEMPLERUINS },
		{ R"rx(^ctf[-_]?(ter|tm|mi|nu).*$)rx",          CONST_MAP_ID_CTF_TERMINUS },

		{ R"rx(^rabbit[-_]?(cr|x|c?fi).*$)rx",          CONST_MAP_ID_RABBIT_CROSSFIRE },
		{ R"rx(^rabbit[-_]?(i|fe).*$)rx",               CONST_MAP_ID_RABBIT_INFERNO },
		{ R"rx(^rabbit[-_]?(k|n|ba).*$)rx",             CONST_MAP_ID_RABBIT_NIGHTABATIC },
		{ R"rx(^rabbit[-_]?(o|sk).*$)rx",               CONST_MAP_ID_RABBIT_OUTSKIRTS },
		{ R"rx(^rabbit[-_]?(q|sa).*$)rx",               CONST_MAP_ID_RABBIT_QUICKSAND },
		{ R"rx(^rabbit[-_]?(sc|su|co).*$)rx",           CONST_MAP_ID_RABBIT_SULFURCOVE },

		{ R"rx(^tdm[-_]?(cr|x|c?fi).*$)rx",             CONST_MAP_ID_TDM_CROSSFIRE },
		{ R"rx(^tdm[-_]?d.*$)rx",                       CONST_MAP_ID_TDM_DRYDOCKNIGHT },
		{ R"rx(^tdm[-_]?(i|fe).*$)rx",                  CONST_MAP_ID_TDM_INFERNO },
		{ R"rx(^tdm[-_]?(m|as).*$)rx",                  CONST_MAP_ID_TDM_MIASMA },
		{ R"rx(^tdm[-_]?(n|k|ba).*$)rx",                CONST_MAP_ID_TDM_NIGHTABATIC },
		{ R"rx(^tdm[-_]?(o|sk).*$)rx",                  CONST_MAP_ID_TDM_OUTSKIRTS },
		{ R"rx(^tdm[-_]?(q|sa).*$)rx",                  CONST_MAP_ID_TDM_QUICKSAND },
		{ R"rx(^tdm[-_]?(sc|su|co).*$)rx",              CONST_MAP_ID_TDM_SULFURCOVE },
	};

	std::map<int, std::string> map_id_to_name = {
		{ CONST_MAP_ID_CTF_KATABATIC,              "[CTF] Katabatic" },
		{ CONST_MAP_ID_CTF_ARXNOVENA,              "[CTF] Arx Novena" },
		{ CONST_MAP_ID_CTF_DRYDOCK,                "[CTF] Drydock" },
		{ CONST_MAP_ID_RABBIT_OUTSKIRTS,           "[Rabbit] Outskirts" },
		{ CONST_MAP_ID_RABBIT_QUICKSAND,           "[Rabbit] Quicksand" },
		{ CONST_MAP_ID_CTF_CROSSFIRE,              "[CTF] Crossfire" },
		{ CONST_MAP_ID_RABBIT_CROSSFIRE,           "[Rabbit] Crossfire" },
		{ CONST_MAP_ID_TDM_DRYDOCKNIGHT,           "[TDM] Drydock Night" },
		{ CONST_MAP_ID_TDM_CROSSFIRE,              "[TDM] Crossfire" },
		{ CONST_MAP_ID_TDM_QUICKSAND,              "[TDM] Quicksand" },
		{ CONST_MAP_ID_TDM_NIGHTABATIC,            "[TDM] Nightabatic" },
		{ CONST_MAP_ID_TDM_INFERNO,                "[TDM] Inferno" },
		{ CONST_MAP_ID_TDM_SULFURCOVE,             "[TDM] Sulfur Cove" },
		{ CONST_MAP_ID_TDM_OUTSKIRTS,              "[TDM] Outskirts" },
		{ CONST_MAP_ID_RABBIT_INFERNO,             "[Rabbit] Inferno" },
		{ CONST_MAP_ID_CTF_TEMPLERUINS,            "[CTF] Temple Ruins" },
		{ CONST_MAP_ID_RABBIT_NIGHTABATIC,         "[Rabbit] Nightabatic" },
		{ CONST_MAP_ID_ARENA_AIRARENA,             "[Arena] Air Arena" },
		{ CONST_MAP_ID_RABBIT_SULFURCOVE,          "[Rabbit] Sulfur Cove" },
		{ CONST_MAP_ID_ARENA_WALLEDIN,             "[Arena] Walled In" },
		{ CONST_MAP_ID_ARENA_LAVAARENA,            "[Arena] Lava Arena" },
		{ CONST_MAP_ID_CTF_TARTARUS,               "[CTF] Tartarus" },
		{ CONST_MAP_ID_CTF_CANYONCRUSADEREVIVAL,   "[CTF] Canyon Crusade Revival" },
		{ CONST_MAP_ID_CTF_RAINDANCE,              "[CTF] Raindance" },
		{ CONST_MAP_ID_CAH_KATABATIC,              "[CaH] Katabatic" },
		{ CONST_MAP_ID_CTF_STONEHENGE,             "[CTF] Stonehenge" },
		{ CONST_MAP_ID_CTF_SUNSTAR,                "[CTF] Sunstar" },
		{ CONST_MAP_ID_CAH_OUTSKIRTS3P,            "[CaH] Outskirts 3P" },
		{ CONST_MAP_ID_CAH_RAINDANCE,              "[CaH] Raindance" },
		{ CONST_MAP_ID_CAH_DRYDOCKNIGHT,           "[CaH] Drydock Night" },
		{ CONST_MAP_ID_ARENA_HINTERLANDS,          "[Arena] Hinterlands" },
		{ CONST_MAP_ID_CTF_PERMAFROST,             "[CTF] Permafrost" },
		{ CONST_MAP_ID_CAH_SULFURCOVE,             "[CaH] Sulfur Cove" },
		{ CONST_MAP_ID_TDM_MIASMA,                 "[TDM] Miasma" },
		{ CONST_MAP_ID_CAH_TARTARUS,               "[CaH] Tartarus" },
		{ CONST_MAP_ID_CTF_DANGEROUSCROSSING,      "[CTF] Dangerous Crossing" },
		{ CONST_MAP_ID_BLITZ_CROSSFIRE,            "[Blitz] Crossfire" },
		{ CONST_MAP_ID_CTF_BLUESHIFT,              "[CTF] Blueshift" },
		{ CONST_MAP_ID_ARENA_WHITEOUT,             "[Arena] Whiteout" },
		{ CONST_MAP_ID_ARENA_FRAYTOWN,             "[Arena] Fraytown" },
		{ CONST_MAP_ID_ARENA_UNDERCROFT,           "[Arena] Undercroft" },
		{ CONST_MAP_ID_CAH_CANYONCRUSADEREVIVAL,   "[CaH] Canyon Crusade Revival" },
		{ CONST_MAP_ID_BLITZ_CANYONCRUSADEREVIVAL, "[Blitz] Canyon Crusade Revival" },
		{ CONST_MAP_ID_BLITZ_BELLAOMEGA,           "[Blitz] Bella Omega" },
		{ CONST_MAP_ID_CTF_BELLAOMEGANS,           "[CTF] Bella Omega NS" },
		{ CONST_MAP_ID_BLITZ_BLUESHIFT,            "[Blitz] Blueshift" },
		{ CONST_MAP_ID_CTF_TERMINUS,               "[CTF] Terminus" },
		{ CONST_MAP_ID_CTF_ICECOASTER,             "[CTF] Icecoaster" },
		{ CONST_MAP_ID_CTF_PERDITION,              "[CTF] Perdition" },
		{ CONST_MAP_ID_CTF_HELLFIRE,               "[CTF] Hellfire" },
		{ CONST_MAP_ID_BLITZ_HELLFIRE,             "[Blitz] Hellfire" },
		{ CONST_MAP_ID_CTF_BELLAOMEGA,             "[CTF] Bella Omega" },
		{ CONST_MAP_ID_BLITZ_ARXNOVENA,            "[Blitz] Arx Novena" },
		{ CONST_MAP_ID_BLITZ_KATABATIC,            "[Blitz] Katabatic" },
		{ CONST_MAP_ID_BLITZ_DRYDOCK,              "[Blitz] Drydock" },
	};

	std::map<int, std::string> map_id_to_filename = {
		{ CONST_MAP_ID_CTF_KATABATIC,			   "TrCTF-Katabatic" },
		{ CONST_MAP_ID_CTF_ARXNOVENA,              "TrCTF-ArxNovena" },
		{ CONST_MAP_ID_CTF_DRYDOCK,                "TrCTF-Drydock" },
		{ CONST_MAP_ID_RABBIT_OUTSKIRTS,           "TrRabbit-ArxNovena" },
		{ CONST_MAP_ID_RABBIT_QUICKSAND,           "TrRabbit-BellaOmega" },
		{ CONST_MAP_ID_CTF_CROSSFIRE,              "TrCTF-Crossfire" },
		{ CONST_MAP_ID_RABBIT_CROSSFIRE,           "TrRabbit-Crossfire" },
		{ CONST_MAP_ID_TDM_DRYDOCKNIGHT,           "TrTeamRabbit-Drydock" },
		{ CONST_MAP_ID_TDM_CROSSFIRE,              "TrTeamRabbit-Crossfire" },
		{ CONST_MAP_ID_TDM_QUICKSAND,              "TrTeamRabbit-BellaOmega" },
		{ CONST_MAP_ID_TDM_NIGHTABATIC,            "TrTeamRabbit-NightKatabatic" },
		{ CONST_MAP_ID_TDM_INFERNO,                "TrTeamRabbit-Harabec" },
		{ CONST_MAP_ID_TDM_SULFURCOVE,             "TrTeamRabbit-CrossfireSmall" },
		{ CONST_MAP_ID_TDM_OUTSKIRTS,              "TrTeamRabbit-ArxNovena" },
		{ CONST_MAP_ID_RABBIT_INFERNO,             "TrRabbit-Harabec" },
		{ CONST_MAP_ID_CTF_TEMPLERUINS,            "TrCTF-RuinsOfHarabec" },
		{ CONST_MAP_ID_RABBIT_NIGHTABATIC,         "TrRabbit-NightKatabatic" },
		{ CONST_MAP_ID_ARENA_AIRARENA,             "TrArena-Airarena" },
		{ CONST_MAP_ID_RABBIT_SULFURCOVE,          "TrRabbit-CrossfireSmall" },
		{ CONST_MAP_ID_ARENA_WALLEDIN,             "TrArena-Walledin" },
		{ CONST_MAP_ID_ARENA_LAVAARENA,            "TrArena-Lavarena" },
		{ CONST_MAP_ID_CTF_TARTARUS,               "TrCTF-Tartarus" },
		{ CONST_MAP_ID_CTF_CANYONCRUSADEREVIVAL,   "TrCTF-CanyonCrusadeRev" },
		{ CONST_MAP_ID_CTF_RAINDANCE,              "TrCTF-Raindance" },
		{ CONST_MAP_ID_CAH_KATABATIC,              "TrCaH-Katabatic" },
		{ CONST_MAP_ID_CTF_STONEHENGE,             "TrCTF-Stonehenge2" },
		{ CONST_MAP_ID_CTF_SUNSTAR,                "TrCTF-Sunstar" },
		{ CONST_MAP_ID_CAH_OUTSKIRTS3P,            "TrCaH-ArxOutskirts_3p" },
		{ CONST_MAP_ID_CAH_RAINDANCE,              "TrCaH-Raindance" },
		{ CONST_MAP_ID_CAH_DRYDOCKNIGHT,           "TrCaH-Drydock" },
		{ CONST_MAP_ID_ARENA_HINTERLANDS,          "TrArena-Hinterland" },
		{ CONST_MAP_ID_CTF_PERMAFROST,             "TrCTF-Permafrost" },
		{ CONST_MAP_ID_CAH_SULFURCOVE,             "TrCaH-FrossfireSmall" },
		{ CONST_MAP_ID_TDM_MIASMA,                 "TrTeamRabbit-Tartarus" },
		{ CONST_MAP_ID_CAH_TARTARUS,               "TrCaH-Tartarus" },
		{ CONST_MAP_ID_CTF_DANGEROUSCROSSING,      "TrCTF-DangerousCrossing" },
		{ CONST_MAP_ID_BLITZ_CROSSFIRE,            "TrCTFBlitz-Crossfire" },
		{ CONST_MAP_ID_CTF_BLUESHIFT,              "TrCTF-Blueshift" },
		{ CONST_MAP_ID_ARENA_WHITEOUT,             "TrArena-Whiteout" },
		{ CONST_MAP_ID_ARENA_FRAYTOWN,             "TrArena-Fraytown" },
		{ CONST_MAP_ID_ARENA_UNDERCROFT,           "TrArena-Undercroft" },
		{ CONST_MAP_ID_CAH_CANYONCRUSADEREVIVAL,   "TrCaH-CanyonCrusadeRev" },
		{ CONST_MAP_ID_BLITZ_CANYONCRUSADEREVIVAL, "TrCTFBlitz-CanyonCrusadeRev" },
		{ CONST_MAP_ID_BLITZ_BELLAOMEGA,           "TrCTFBlitz-BellaOmega" },
		{ CONST_MAP_ID_CTF_BELLAOMEGANS,           "TrCTF-BellaOmegaNS" },
		{ CONST_MAP_ID_BLITZ_BLUESHIFT,            "TrCTFBlitz-Blueshift" },
		{ CONST_MAP_ID_CTF_TERMINUS,               "TrCTF-Terminus" },
		{ CONST_MAP_ID_BLITZ_TERMINUS,             "TrCTFBlitz-Terminus" },
		{ CONST_MAP_ID_CTF_ICECOASTER,             "TrCTF-IceCoaster" },
		{ CONST_MAP_ID_BLITZ_ICECOASTER,           "TrCTFBlitz-IceCoaster" },
		{ CONST_MAP_ID_CTF_PERDITION,              "TrCTF-Perdition" },
		{ CONST_MAP_ID_TDM_PERDITION,              "TrTeamRabbit-Perdition" },
		{ CONST_MAP_ID_CTF_HELLFIRE,               "TrCTF-Hellfire" },
		{ CONST_MAP_ID_BLITZ_HELLFIRE,             "TrCTFBlitz-Hellfire" },
		{ CONST_MAP_ID_CTF_BELLAOMEGA,             "TrCTF-BellaOmega" },
		{ CONST_MAP_ID_BLITZ_ARXNOVENA,            "TrCTFBlitz-ArxNovena" },
		{ CONST_MAP_ID_BLITZ_KATABATIC,            "TrCTFBlitz-Katabatic" },
		{ CONST_MAP_ID_BLITZ_DRYDOCK,              "TrCTFBlitz-Drydock" },
	};

}

namespace Data {
	int getItemId(const std::string& className, const std::string &itemName) {
		if (Utils::cleanString(className) == "vehicle")
			return Utils::searchMapId(vehicle_weapons, itemName, "", false);

		int classId = Utils::searchMapId(classes, className, "", false) - 1;
		if (classId == -1) return 0;

		// Try to find this as a weapon
		int res = Utils::searchMapId(weapons[classId], itemName, "", false);
		if (res) return res;

		// Try to find this as a pack
		res = Utils::searchMapId(packs[classId], itemName, "", false);
		if (res) return res;

		// Try to find this as a skin
		res = Utils::searchMapId(skins[classId], itemName, "", false);
		if (res) return res;

		// Try to find this as a voice
		res = Utils::searchMapId(voices, itemName, "", false);
		if (res) return res;

		Logger::warn("Searched for ID of item %s on class %s and failed to find it", itemName.c_str(), className.c_str());

		return 0;
	}
}

