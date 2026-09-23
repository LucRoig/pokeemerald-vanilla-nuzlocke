InsideOfTruck_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, InsideOfTruck_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, InsideOfTruck_OnResume
	.byte 0

InsideOfTruck_OnLoad:
	setmetatile 4, 1, METATILE_InsideOfTruck_ExitLight_Top, FALSE
	setmetatile 4, 2, METATILE_InsideOfTruck_ExitLight_Mid, FALSE
	setmetatile 4, 3, METATILE_InsideOfTruck_ExitLight_Bottom, FALSE
	end

InsideOfTruck_OnResume:
	setstepcallback STEP_CB_TRUCK
	end

InsideOfTruck_EventScript_SetIntroFlags::
	lockall
	setflag FLAG_HIDE_MAP_NAME_POPUP
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, InsideOfTruck_EventScript_SetIntroFlagsMale
	goto_if_eq VAR_RESULT, FEMALE, InsideOfTruck_EventScript_SetIntroFlagsFemale
	end

InsideOfTruck_EventScript_SetIntroFlagsMale::
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 1
	setdynamicwarp MAP_LITTLEROOT_TOWN, 3, 10
	releaseall
	end

InsideOfTruck_EventScript_SetIntroFlagsFemale::
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 1
	setdynamicwarp MAP_LITTLEROOT_TOWN, 12, 10
	releaseall
	end

InsideOfTruck_EventScript_MovingBox::

	// TESTING
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CASTFORM
	givemon SPECIES_CASTFORM, 50, ITEM_MYSTIC_WATER
	call Common_EventScript_GetGiftMonPartySlot
	
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET
	setflag FLAG_BADGE05_GET
	setflag FLAG_BADGE06_GET
	setflag FLAG_BADGE07_GET
	setflag FLAG_BADGE08_GET

	giveitem ITEM_HM_CUT
	giveitem ITEM_HM_FLY
	setflag FLAG_SYS_FLY
	giveitem ITEM_HM_SURF
	giveitem ITEM_HM_STRENGTH
	giveitem ITEM_HM_FLASH
	giveitem ITEM_HM_ROCK_SMASH
	giveitem ITEM_HM_WATERFALL
	giveitem ITEM_HM_DIVE

	setflag FLAG_VISITED_LITTLEROOT_TOWN 
	setflag FLAG_VISITED_OLDALE_TOWN     
	setflag FLAG_VISITED_DEWFORD_TOWN    
	setflag FLAG_VISITED_LAVARIDGE_TOWN  
	setflag FLAG_VISITED_FALLARBOR_TOWN  
	setflag FLAG_VISITED_VERDANTURF_TOWN 
	setflag FLAG_VISITED_PACIFIDLOG_TOWN 
	setflag FLAG_VISITED_PETALBURG_CITY  
	setflag FLAG_VISITED_SLATEPORT_CITY  
	setflag FLAG_VISITED_MAUVILLE_CITY   
	setflag FLAG_VISITED_RUSTBORO_CITY   
	setflag FLAG_VISITED_FORTREE_CITY    
	setflag FLAG_VISITED_LILYCOVE_CITY   
	setflag FLAG_VISITED_MOSSDEEP_CITY   
	setflag FLAG_VISITED_SOOTOPOLIS_CITY 
	setflag FLAG_VISITED_EVER_GRANDE_CITY

	
	msgbox InsideOfTruck_Text_BoxPrintedWithMonLogo, MSGBOX_SIGN

	end

InsideOfTruck_Text_BoxPrintedWithMonLogo:
	.string "The box is printed with a POKéMON logo.\p"
	.string "It's a POKéMON brand moving and\n"
	.string "delivery service.$"

