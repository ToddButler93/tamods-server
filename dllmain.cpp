// dllmain.cpp : Defines the entry point for the DLL application.
#include "dllmain.h"

static void fixPingDependencies() {
	std::vector<UClass*> toFix = {
		ATrDevice_NovaSlug::StaticClass(),

		// Not working?
		ATrDevice_Shotgun::StaticClass(),
		ATrDevice_Shotgun_MKD::StaticClass(),
		ATrDevice_AccurizedShotgun::StaticClass(),
		ATrDevice_SawedOffShotgun::StaticClass(),
		ATrDevice_AutoShotgun::StaticClass(),
		ATrDevice_AutoShotgun_MKD::StaticClass(),

		ATrDevice_LightTwinfusor::StaticClass(),
		ATrDevice_Twinfusor::StaticClass(),
		ATrDevice_HeavyTwinfusor::StaticClass(),
		ATrDevice_SniperRifle::StaticClass(),
		ATrDevice_SniperRifle_MKD::StaticClass(),
		ATrDevice_PhaseRifle::StaticClass(),
		ATrDevice_SAP20::StaticClass(),
		ATrDevice_GrenadeLauncher::StaticClass(),
		ATrDevice_GrenadeLauncher_Light::StaticClass(),
		ATrDevice_ArxBuster::StaticClass(),
		ATrDevice_ArxBuster_MKD::StaticClass(),
		ATrDevice_RemoteArxBuster::StaticClass(),
		ATrDevice_PlasmaGun::StaticClass(),
		ATrDevice_PlasmaCannon::StaticClass(),
	};

	for (auto& cls : toFix) {
		ATrDevice* default = (ATrDevice*)cls->Default;
		default->m_bForceReplicateAmmoOnFire = true;
	}
}

static void testing_PrintOutGObjectIndices() {
	for (int i = 0; i < UObject::GObjObjects()->Count; ++i)
	{
		UObject* Object = UObject::GObjObjects()->Data[i];
		Logger::debug("%d \t\t | %s", i, Object->GetFullName());
	}
}

void WorldInfo_SeamlessTravel(AWorldInfo* that, AWorldInfo_execSeamlessTravel_Parms* params) {
	Logger::debug("SEAMLESS TRAVEL!");
	that->SeamlessTravel(params->URL, params->bAbsolute, params->MapPackageGuid);
}

void GameInfo_ProcessClientTravel(AGameInfo* that, AGameInfo_execProcessClientTravel_Parms* params, APlayerController** result) {
	Logger::debug("ProcessClientTravel: bSeamless = %d, bAbsolute = %d", params->bSeamless, params->bAbsolute);
	FString url;
	*result = that->ProcessClientTravel(params->NextMapGuid, params->bSeamless, params->bAbsolute, &url);
}

void GameInfo_ProcessServerTravel(AGameInfo* that, AGameInfo_execProcessServerTravel_Parms* params) {
	Logger::debug("GameInfo ProcessServerTravel!");
	that->ProcessServerTravel(params->URL, params->bAbsolute);
}


// Desired hooks should be added here
static void addHooks() {
	// Disabled due to bugs
	//fixPingDependencies();

	//Hooks::addUScript(&WorldInfo_SeamlessTravel, "Function Engine.WorldInfo.SeamlessTravel");
	//Hooks::addUScript(&GameInfo_ProcessClientTravel, "Function Engine.GameInfo.ProcessClientTravel");
	//Hooks::addUScript(&GameInfo_ProcessServerTravel, "Function Engine.GameInfo.ProcessServerTravel");

	Hooks::addUScript(&TrDevice_SniperRifle_ModifyInstantHitDamage, "Function TribesGame.TrDevice_SniperRifle.ModifyInstantHitDamage");
	Hooks::add(&TrDevice_SniperRifle_Tick, "Function TribesGame.TrDevice_SniperRifle.Tick");
	Hooks::addUScript(&ATrPlayerController_ResetZoomDuration, "Function TribesGame.TrPlayerController.ResetZoomDuration");

	Hooks::addUScript(&TrDevice_CalcHUDAimChargePercent, "Function TribesGame.TrDevice.CalcHUDAimChargePercent");
	Hooks::addUScript(&TrDevice_LaserTargeter_OnStartConstantFire, "Function TribesGame.TrDevice_LaserTargeter.OnStartConstantFire");
	Hooks::addUScript(&TrDevice_LaserTargeter_OnEndConstantFire, "Function TribesGame.TrDevice_LaserTargeter.OnEndConstantFire");
	Hooks::addUScript(&TrDevice_LaserTargeter_UpdateTarget, "Function TribesGame.TrDevice_LaserTargeter.UpdateTarget");
	//Hooks::addUScript(&TrDevice_LaserTargeter_GetLaserStartAndEnd, "Function TribesGame.TrDevice_LaserTargeter.GetLaserStartAndEnd");
	//Hooks::addUScript(&TrDevice_LaserTargeter_SpawnLaserEffect, "Function TribesGame.TrDevice_LaserTargeter.SpawnLaserEffect");
	Hooks::addUScript(&TrDevice_LaserTargeter_UpdateLaserEffect, "Function TribesGame.TrDevice_LaserTargeter.UpdateLaserEffect");

	//Hooks::addUScript(&TrDevice_PlayWeaponEquip, "Function TribesGame.TrDevice.PlayWeaponEquip");
	//Hooks::addUScript(&TrDevice_UpdateWeaponMICs, "Function TribesGame.TrDevice.UpdateWeaponMICs");

	// Server Settings
	Hooks::addUScript(&TrServerSettingsInfo_LoadServerSettings, "Function TribesGame.TrServerSettingsInfo.LoadServerSettings");
	Hooks::addUScript(&TrPlayerController_GetRespawnDelayTotalTime, "Function TribesGame.TrPlayerController.GetRespawnDelayTotalTime");

	// Loadouts
	Hooks::addUScript(&TrPlayerReplicationInfo_GetCharacterEquip, "Function TribesGame.TrPlayerReplicationInfo.GetCharacterEquip");
	Hooks::addUScript(&TrPlayerReplicationInfo_ResolveDefaultEquip, "Function TribesGame.TrPlayerReplicationInfo.ResolveDefaultEquip");
	Hooks::addUScript(&TrPlayerReplicationInfo_GetCurrentVoiceClass, "Function TribesGame.TrPlayerReplicationInfo.GetCurrentVoiceClass");
	//Hooks::addUScript(&TrDevice_GetReloadTime, "Function TribesGame.TrDevice.GetReloadTime");

	// TAServer Game Info
	Hooks::add(&TrGameReplicationInfo_PostBeginPlay, "Function TribesGame.TrGameReplicationInfo.PostBeginPlay");
	Hooks::add(&TrGameReplicationInfo_Tick, "Function TribesGame.TrGameReplicationInfo.Tick");
	Hooks::addUScript(&TrGame_SendShowSummary, "Function TribesGame.TrGame.SendShowSummary");
	Hooks::add(&UTGame_MatchInProgress_BeginState, "Function UTGame.MatchInProgress.BeginState");
	Hooks::addUScript(&TrGame_RequestTeam, "Function TribesGame.TrGame.RequestTeam");
	Hooks::addUScript(&UTGame_EndGame, "Function UTGame.UTGame.EndGame");
	Hooks::addUScript(&PlayerController_ServerUpdatePing, "Function Engine.PlayerController.ServerUpdatePing");

	// Part of fix for colt ping dependency
	Hooks::addUScript(&TrDevice_FireAmmunition, "Function TribesGame.TrDevice.FireAmmunition");
	Hooks::addUScript(&TrDevice_NovaSlug_FireAmmunition, "Function TribesGame.TrDevice_NovaSlug.FireAmmunition");

	Hooks::addUScript(&UTGame_ProcessServerTravel, "Function UTGame.UTGame.ProcessServerTravel");

	Hooks::addUScript(&TrPawn_TakeDamage, "Function TribesGame.TrPawn.TakeDamage");
	Hooks::addUScript(&TrPawn_RememberLastDamager, "Function TribesGame.TrPawn.RememberLastDamager");
	Hooks::add(&TrPawn_RechargeHealthPool, "Function TribesGame.TrPawn.RechargeHealthPool");
	Hooks::addUScript(&TrPawn_GetLastDamager, "Function TribesGame.TrPawn.GetLastDamager");
	Hooks::addUScript(&TrPawn_ProcessKillAssists, "Function TribesGame.TrPawn.ProcessKillAssists");

	Hooks::addUScript(&TrPawn_RefreshInventory, "Function TribesGame.TrPawn.RefreshInventory");

	//Hooks::addUScript(&ATrDevice_RemoteArxBuster_ActivateRemoteRounds, "Function TribesGame.TrDevice_RemoteArxBuster.ActivateRemoteRounds");

	// Honorfusor hitreg issues
	ATrProj_Honorfusor* honorfusorDefault = (ATrProj_Honorfusor*)UObject::FindObject<UObject>("TrProj_Honorfusor TribesGame.Default__TrProj_Honorfusor");
	Logger::debug("CLASSNAME = %s", honorfusorDefault->Class->GetName());
	//Logger::debug("m_bIsBullet = %d", honorfusorDefault->m_bIsBullet);
	//Logger::debug("DamageRadius = %f", honorfusorDefault->DamageRadius);
	//Logger::debug("CheckRadius = %f", honorfusorDefault->CheckRadius);
	//honorfusorDefault->m_bIsBullet = true;
	//honorfusorDefault->DamageRadius = 100;
	//Hooks::addUScript(&TrProj_Honorfusor_ProjectileHurtRadius, "Function TribesGame.TrProj_Honorfusor.ProjectileHurtRadius");

	//Hooks::addUScript(&TrPlayerController_GetBlinkPackAccel, "Function TribesGame.TrPlayerController.GetBlinkPackAccel");
	//Hooks::addUScript(&TrDevice_Blink_OnBlink, "Function TribesGame.TrDevice_Blink.OnBlink");

}

void onDLLProcessAttach() {
	
#ifdef RELEASE
	Logger::setLevel(Logger::LOG_ERROR);
#else
	Logger::setLevel(Logger::LOG_DEBUG);
#endif

	Logger::info("Initialising...");

	g_config.load();
	Logger::info("Configuration loaded");

	//testing_PrintOutGObjectIndices();

	addHooks();

	Hooks::init(false);

	//g_config.serverSettings.ApplyAsDefaults();

	if (g_config.connectToTAServer) {
		Logger::info("Connecting to TAServer...");
		if (g_TAServerClient.connect("127.0.0.1", 9002)) {
			Logger::info("[Connected]");
		} else {
			Logger::error("Failed to connect to TAServer launcher.");
		}
	}
	else {
		Logger::info("Not attempting connection");
	}
}

void onDLLProcessDetach() {
	if (g_TAServerClient.isConnected()) {
		if (!g_TAServerClient.disconnect()) {
			Logger::error("Failed to disconnect from TAServer launcher.");
		}
	}
	Logger::debug("DLL Process Detach");
	Hooks::cleanup();
	Logger::cleanup();
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hModule);
		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)onDLLProcessAttach, NULL, 0, NULL);
		break;
    case DLL_PROCESS_DETACH:
		onDLLProcessDetach();
        break;
    }
    return TRUE;
}

