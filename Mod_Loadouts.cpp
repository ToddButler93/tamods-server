#include "Mods.h"
#include "LoadoutTypes.h"

void TrDevice_GetReloadTime(ATrDevice* that, ATrDevice_execGetReloadTime_Parms* params, float* result, Hooks::CallInfo* callInfo) {
	Logger::debug("[GetReloadTime] Caller function: %s::%s", callInfo->callerObject->Name.GetName(), callInfo->caller->Name.GetName());
	float r = that->GetReloadTime(params->PRI, params->equipPoint);
	Logger::debug("[GetReloadTime] Reload time for %s = %f", that->Name.GetName(), r);
	*result = r;	
}

static bool isWeaponEquipPoint(int eqp) {
	return eqp == EQP_Primary || eqp == EQP_Secondary || eqp == EQP_Tertiary || eqp == EQP_Quaternary || eqp == EQP_Belt;
}


static void applyHardcodedLoadout(ATrPlayerReplicationInfo* that, int classId, int slot) {
	auto& it = Data::class_id_to_nb.find(classId);
	if (it == Data::class_id_to_nb.end()) return;
	unsigned classNum = it->second;
	for (int i = 0; i < EQP_MAX; ++i) {
		std::string item = g_config.hardcodedLoadouts.get(classNum, slot, i);
		if (item != "") {
			int itemId = 0;
			if (isWeaponEquipPoint(i)) {
				itemId = Utils::searchMapId(Data::weapons[classNum], item, "", false);
			}
			else if (i == EQP_Pack) {
				itemId = Utils::searchMapId(Data::packs[classNum], item, "", false);
			}
			else if (i == EQP_Skin) {
				itemId = Utils::searchMapId(Data::skins[classNum], item, "", false);
			}
			else if (i == EQP_Voice) {
				itemId = Utils::searchMapId(Data::voices, item, "", false);
			}
			if (itemId != 0) {
				that->r_EquipLevels[i].EquipId = itemId;
			}
		}
	}
}

static void applyTAServerLoadout(ATrPlayerReplicationInfo* that, int classId, int slot) {
	if (g_TAServerClient.isConnected()) {
		std::map<int, int> taserverRetrievedMap;
		if (!g_TAServerClient.retrieveLoadout(that->UniqueId, classId, slot, taserverRetrievedMap)) {
			Logger::warn("Failed to retrieve loadout on class %d, slot %d for UniqueID %d from TAServer.", classId, slot, that->UniqueId);
		}
		for (auto& eqpItem : taserverRetrievedMap) {
			if (eqpItem.second != 0) {
				// TODO: Should do extra validation against server settings here...
				that->r_EquipLevels[eqpItem.first].EquipId = eqpItem.second;
			}
		}
	}
}

void TrPlayerReplicationInfo_GetCharacterEquip(ATrPlayerReplicationInfo* that, ATrPlayerReplicationInfo_execGetCharacterEquip_Parms* params, void* result, Hooks::CallInfo* callInfo) {
	// Apply any server hardcoded loadout configuration
	applyHardcodedLoadout(that, params->ClassId, params->Loadout);
	// If in a mode to retrieve loadout info from a server, do so
	switch (g_config.serverMode) {
	case ServerMode::TASERVER:
		applyTAServerLoadout(that, params->ClassId, params->Loadout);
		break;
	case ServerMode::API:
		// TBA
		break;
	}
}

void TAServer::Client::handler_Launcher2GameLoadoutMessage(const json& msgBody) {
	// Parse the message
	Launcher2GameLoadoutMessage msg;
	if (!msg.fromJson(msgBody)) {
		// Failed to parse
		Logger::error("Failed to parse loadout response: %s", msgBody.dump().c_str());
	}

	// Put it in the map
	std::lock_guard<std::mutex> lock(receivedLoadoutsMutex);
	receivedLoadouts[netIdToLong(msg.uniquePlayerId)] = msg;
}

// static variables for lua enum
static int eqpNone = EQP_NONE;
static int eqpMelee = EQP_Melee;
static int eqpPrimary = EQP_Primary;
static int eqpSecondary = EQP_Secondary;
static int eqpTertiary = EQP_Tertiary;
static int eqpQuarternary = EQP_Quaternary;
static int eqpPack = EQP_Pack;
static int eqpBelt = EQP_Belt;
static int eqpDeployable = EQP_Deployable;
static int eqpLaserTarget = EQP_LaserTarget;
static int eqpArmor = EQP_Armor;
static int eqpPerkA = EQP_PerkA;
static int eqpPerkB = EQP_PerkB;
static int eqpSkin = EQP_Skin;
static int eqpVoice = EQP_Voice;

 template <unsigned classNum>
 static std::string getEquip(int slot, int equip) {
	 return g_config.hardcodedLoadouts.getTemplated<classNum>(slot, equip);
}

 template <unsigned classNum>
 static void setEquip(int slot, int equip, std::string item) {
	 g_config.hardcodedLoadouts.setTemplated<classNum>(slot, equip, item);
}

namespace LuaAPI {
	void addLoadoutsLuaAPI(luabridge::Namespace ns) {
		ns
			.beginNamespace("Loadouts")
				.beginNamespace("EquipPoints")
					.addVariable("None", &eqpNone, false)
					.addVariable("Melee", &eqpMelee, false)
					.addVariable("Primary", &eqpPrimary, false)
					.addVariable("Secondary", &eqpSecondary, false)
					.addVariable("Tertiary", &eqpTertiary, false)
					.addVariable("Quarternary", &eqpQuarternary, false)
					.addVariable("Pack", &eqpPack, false)
					.addVariable("Belt", &eqpBelt, false)
					.addVariable("Deployable", &eqpDeployable, false)
					.addVariable("LaserTarget", &eqpLaserTarget, false)
					.addVariable("Armor", &eqpArmor, false)
					.addVariable("PerkA", &eqpPerkA, false)
					.addVariable("PerkB", &eqpPerkB, false)
					.addVariable("Skin", &eqpSkin, false)
					.addVariable("Voice", &eqpVoice, false)
				.endNamespace()

				.beginNamespace("Hardcoded")
					.beginNamespace("Light")
						.addFunction("get", &getEquip<0>)
						.addFunction("set", &setEquip<0>)
					.endNamespace()
					.beginNamespace("Medium")
						.addFunction("get", &getEquip<1>)
						.addFunction("set", &setEquip<1>)
					.endNamespace()
					.beginNamespace("Heavy")
						.addFunction("get", &getEquip<2>)
						.addFunction("set", &setEquip<2>)
					.endNamespace()
				.endNamespace()
			.endNamespace()
			;
	}
}
