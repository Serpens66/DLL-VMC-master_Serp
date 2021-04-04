// CustomMods.h
#pragma once

#ifndef CUSTOM_MODS_H
#define CUSTOM_MODS_H

// Custom #defines used by all DLLs
#include "..\CvGameCoreDLLUtil\include\CustomModsGlobal.h"

/****************************************************************************
 ****************************************************************************
 *****                                                                  *****
 *****                           IMPORTANT!!!                           *****
 *****                                                                  *****
 *****                        Modders take note!                        *****
 *****                                                                  *****
 *****  See the comment in CvDllVersion.h regarding the DLL GUID value  *****
 *****                                                                  *****
 *****                                                                  *****
 *****          This DLL is based on the 1.0.3.276 source code          *****
 *****                                                                  *****
 ****************************************************************************
 ****************************************************************************/

/****************************************************************************
 ****************************************************************************
 *****                                                                  *****
 *****   FOR THE LOVE OF GOD - GET YOUR OWN INTERNAL GUID FOR THE DLL   *****
 *****                                                                  *****
 *****                   AND STOP USING MINE!!!!!                       *****
 *****                                                                  *****
 ****************************************************************************
 ****************************************************************************/
#define MOD_DLL_GUID {0xcf7d28a8, 0x1684, 0x4420, { 0xaf, 0x45, 0x11, 0x7, 0xc, 0xb, 0x8c, 0x4a }} // {CF7D28A8-1684-4420-AF45-11070C0B8C4A}
#define MOD_DLL_NAME "Pick'N'Mix BNW DLL"
#define MOD_DLL_VERSION_NUMBER ((uint) 94)
#define MOD_DLL_VERSION_STATUS ""			// a (alpha), b (beta) or blank (released)
#define MOD_DLL_CUSTOM_BUILD_NAME ""

/** Serp info for myself:
 ** version 10.11
 ** disabled: MOD_AI_MP_DIPLOMACY, MOD_AUI_MILITARY_FIX_BARBARIAN_THREAT, MOD_CVM_AUTOSAVE_FIX
 ** should not enable in xml: MOD_AI_SMART_V3 (long turn duration after a while)
 ** 
 ** 
 ** 
 ** 
 ** search for "serp" to find notes about my changes/additions.
 ** 
 ** 
 ** changelog from 10. to 10.1:
 ** - added GAMEEVENT_PreSaveEvent
 ** 
 ** 10.11 added CustomLog into CustomMods::eventHook and LuaSupport::CallHook to find out if that is causing freezes with GAMEEVENT_PreSaveEvent... (seems to be the lock, bool bResult = pkScriptSystem->CallHook(szName, args, value); in LuaSupport::CallHook is never finished)
 ** 10.12: MOD_BETTER_BARBCAMP_SPAWNCODE zugefuegt und chillbarb mach nun auch 2/3*maxcamps und es gibt mindestzahl an camps je nach kartengroesse 1-6, falls es validspots gibt.
 **        sowie MOD_DEBUG_GAMEHOOKS zugefuegt, was per XML an/aus geschaltet werden kann 
 ** 10.13: fixed the bug that workers did not continue to build after they removed a feature (eg forest) (was in CvUnitMission.cpp) and doubled to min amount of barb camps
 ** 10.14: in CvReligionClasses.cpp fixed inability to found religion when 2 or more players had the same pantheon. and adjusted a bit with comment in lGetAvailablePantheonBeliefs in CvLuaGame.cpp. and added note that you also need to adjust popup.lua for these kind of mods to work.
 **        with MOD_AUI_GAME_AUTOPAUSE_ON_ACTIVE_DISCONNECT_IF_NOT_SEQUENTIAL I set in CvGame.cpp the pause value to -1, to unpause the game after loading a mp game.
 ** 
 ** 10.15: Added GAMEEVENT_GoodyHutReceivedBonus also for shoshone goody picker.
 ** added MOD_IMPROVE_BELIEF_CODE_TO_CHECK_IF_PLOT_RELEVANT , saves alot of ressources, since AI does not need to check every single plot for every belief when founding religion.
 ** added MOD_MORE_IMPROVEMENT_PLACESTYLES which makes EVENTS_PLOT for me unnecessary , which saves a ton of ressources!
 ** added MOD_LEVEL_PROMOTIONS ,so we can disable EVENTS_UNIT_UPGRADES
 ** changed MOD_EVENTS_CITY_BOMBARD to only update the value once per turn per city, instead of thousand times per turn.
 ** added minor_bugfix to allow more than one free policy per era, if set in database.
 ** 
 **/

// Comment out this line to include all the achievements code (which don't work in modded games, so we don't need the code!)
// #define NO_ACHIEVEMENTS

// Uncomment this line to include the achievements hack code
// #define ACHIEVEMENT_HACKS
#if defined(ACHIEVEMENT_HACKS)
#undef NO_ACHIEVEMENTS
#else

// Comment out this line to include all the tutorials code
#define NO_TUTORIALS

// Comment out this line to switch off all custom mod logging
#define CUSTOMLOGDEBUG "CustomMods.log"
// Define to include the file name and line number in the log
#define CUSTOMLOGFILEINFO
// Define to include the function name in the log
#define CUSTOMLOGFUNCINFO

// Comment out this line to switch off all unified yield logging
// #define UNIFIEDLOGDEBUG "UnifiedYields.log"

// Comment out this line to remove minidumps - see http://forums.civfanatics.com/showthread.php?t=498919
// If minidumps are enabled, do NOT set GenerateDebugInfo=No (Props -> Config Props -> Linker -> Debugging)
#define MOD_DEBUG_MINIDUMP


// Comment these lines out to remove the associated code from the DLL,
// Alternatively, set the associated entries in the CustomModOptions table to disable(0) or enable(1) at load-time

// Enables the Player Logs API - AFFECTS SAVE GAME DATA FORMAT (v68)
#define MOD_API_PLAYER_LOGS                         gCustomMods.isAPI_PLAYER_LOGS()
// Enables the Espionage API - AFFECTS SAVE GAME DATA FORMAT
#define MOD_API_ESPIONAGE                           gCustomMods.isAPI_ESPIONAGE()
// Enables the Trade Routes API - AFFECTS SAVE GAME DATA FORMAT (v23)
#define MOD_API_TRADEROUTES                         gCustomMods.isAPI_TRADEROUTES()
// Enables the Religion API
#define MOD_API_RELIGION                            gCustomMods.isAPI_RELIGION()
// Enables the Plot Based Damage API (replaces fixed damage from mountains)
#define MOD_API_PLOT_BASED_DAMAGE                   gCustomMods.isAPI_PLOT_BASED_DAMAGE()
// Enables the Plot Yield tables (v35)
#define MOD_API_PLOT_YIELDS                         gCustomMods.isAPI_PLOT_YIELDS()
// Enables the Achievements table (v45)
#define MOD_API_ACHIEVEMENTS                        gCustomMods.isAPI_ACHIEVEMENTS()
// Enables the Unit Stats API (v73)
#define MOD_API_UNIT_STATS                          (true)
// Enables the Extensions API
#define MOD_API_EXTENSIONS                          gCustomMods.isAPI_EXTENSIONS()
// Enables the LUA Extensions API
#define MOD_API_LUA_EXTENSIONS                      gCustomMods.isAPI_LUA_EXTENSIONS()
// Enables the Unified Yields extensions - thanks to bane_, JFD and Ulixes for extensive testing (v54)
#define MOD_API_UNIFIED_YIELDS                      (true)
// Enables the Unified Yields (YIELD_TOURISM) extensions (v56)
#define MOD_API_UNIFIED_YIELDS_TOURISM              (true)
// Enables the Unified Yields (YIELD_GOLDEN_AGE_POINTS) extensions (v57)
#define MOD_API_UNIFIED_YIELDS_GOLDEN_AGE           (true)

// Push various hard-coded values controlling the game out into XML - see DB/CONFIG/GameInXml.sql for specific values -->
// Serp: added the hardcoded value for min turns to spawn first barbarian units out of camps, default 10: BARBARIAN_NO_SPAWN_BEFORE_TURN
#define MOD_CONFIG_GAME_IN_XML                      gCustomMods.isCONFIG_GAME_IN_XML()
// Push various hard-coded values controlling the AI out into XML - see DB/CONFIG/AiInXml.sql for specific values
#define MOD_CONFIG_AI_IN_XML                        gCustomMods.isCONFIG_AI_IN_XML()

// If A declares war on B that preempts a co-op war, A is locked into the war for the same number of turns as if they had agreed to the co-op war (v86) 
#define MOD_GLOBAL_EARLY_COOP_WAR_LOCK				gCustomMods.isGLOBAL_EARLY_COOP_WAR_LOCK()
// Changes the stacking limits based on what the tile is (city, fort, plain, etc) - AFFECTS SAVE GAME DATA FORMAT
#define MOD_GLOBAL_STACKING_RULES                   gCustomMods.isGLOBAL_STACKING_RULES()
// This is the "No More Civilian Traffic Jams (NMCTJs) Mod" by Pazyryk - see http://forums.civfanatics.com/showthread.php?t=519754 (v45)
#define MOD_GLOBAL_BREAK_CIVILIAN_1UPT              gCustomMods.isGLOBAL_BREAK_CIVILIAN_1UPT()
#if defined(MOD_GLOBAL_BREAK_CIVILIAN_1UPT)
#define MOD_GLOBAL_BREAK_CIVILIAN_RESTRICTIONS     (MOD_GLOBAL_BREAK_CIVILIAN_1UPT && gCustomMods.isGLOBAL_BREAK_CIVILIAN_RESTRICTIONS())
#endif
// Great Generals and Admirals gained from combat experience spawn in the war-zone and not in a distant city (Serp: may cause desync in MP?)
#define MOD_GLOBAL_LOCAL_GENERALS                   gCustomMods.isGLOBAL_LOCAL_GENERALS()
// Separates out the repair fleet and change port abilities of the Great Admiral (v61)
#define MOD_GLOBAL_SEPARATE_GREAT_ADMIRAL           gCustomMods.isGLOBAL_SEPARATE_GREAT_ADMIRAL()
// Permits units to have promotion trees different from their assigned CombatClass
#define MOD_GLOBAL_PROMOTION_CLASSES                gCustomMods.isGLOBAL_PROMOTION_CLASSES()
// Permits ships to enter coastal forts/citadels in friendly lands
#define MOD_GLOBAL_PASSABLE_FORTS                   gCustomMods.isGLOBAL_PASSABLE_FORTS()
// Permits ships to enter any forts/citadels (based on code supplied by 12monkeys)
#define MOD_GLOBAL_PASSABLE_FORTS_ANY               (MOD_GLOBAL_PASSABLE_FORTS && gCustomMods.isGLOBAL_PASSABLE_FORTS_ANY())
// Goody Huts can always give gold, stops the late-game issue where entering a goody hut can result in nothing being awarded (v22)
#define MOD_GLOBAL_ANYTIME_GOODY_GOLD               gCustomMods.isGLOBAL_ANYTIME_GOODY_GOLD()
// Give initial production boost for cities founded on forests, as if the forest had been chopped down by a worker
#define MOD_GLOBAL_CITY_FOREST_BONUS                gCustomMods.isGLOBAL_CITY_FOREST_BONUS()
// Give initial production boost for cities founded on jungle, as if the jungle had been chopped down by a worker (v72)
#define MOD_GLOBAL_CITY_JUNGLE_BONUS                gCustomMods.isGLOBAL_CITY_JUNGLE_BONUS()
// Permit cities to work tiles up to MAXIMUM_ACQUIRE_PLOT_DISTANCE - WARNING! Cities take 2.5 times as much memory/file space
#define MOD_GLOBAL_CITY_WORKING                     gCustomMods.isGLOBAL_CITY_WORKING()
// Permit cities to have automaton workers (v89)
#define MOD_GLOBAL_CITY_AUTOMATON_WORKERS           gCustomMods.isGLOBAL_CITY_AUTOMATON_WORKERS()
// Enables rebasing to and airlifting to/from improvements (v74)
#define MOD_GLOBAL_RELOCATION                       gCustomMods.isGLOBAL_RELOCATION()
// Mountain plots return their terrain as TERRAIN_MOUNTAIN and any land unit may enter a mountain that has a road/rail route
#define MOD_GLOBAL_ALPINE_PASSES                    gCustomMods.isGLOBAL_ALPINE_PASSES()
// Permits City States to gift ships
#define MOD_GLOBAL_CS_GIFT_SHIPS                    gCustomMods.isGLOBAL_CS_GIFT_SHIPS()
// Permits units to upgrade in allied militaristic City States
#define MOD_GLOBAL_CS_UPGRADES                      gCustomMods.isGLOBAL_CS_UPGRADES()
// City States will only raze captured cities if they are very unhappy
#define MOD_GLOBAL_CS_RAZE_RARELY                   gCustomMods.isGLOBAL_CS_RAZE_RARELY()
// City States can be liberated after they have been "bought" (Austria's or Venice's UA)
#define MOD_GLOBAL_CS_LIBERATE_AFTER_BUYOUT         gCustomMods.isGLOBAL_CS_LIBERATE_AFTER_BUYOUT()
// City States give different gifts depending on their type (cultural, religious, maritime, etc)
// serp: with teams, not only the teamleader will get food, double friendship and chance of a unit, but all teammembers will get everything (no double friendship).
// it is not trivial to get the actual meeting player, so everyone getting everything is more fair than always the teamleader.
#define MOD_GLOBAL_CS_GIFTS                         gCustomMods.isGLOBAL_CS_GIFTS()
// Units gifted from City States receive XP from their spawning city, not the CS capital (v84)
#define MOD_GLOBAL_CS_GIFTS_LOCAL_XP                gCustomMods.isGLOBAL_CS_GIFTS_LOCAL_XP()
// City States allied to a major behave as an overseas territory of that major (v39)
#define MOD_GLOBAL_CS_OVERSEAS_TERRITORY            gCustomMods.isGLOBAL_CS_OVERSEAS_TERRITORY()
// City States at war with each other but allied to the same major will declare peace (v39)
#define MOD_GLOBAL_CS_NO_ALLIED_SKIRMISHES          gCustomMods.isGLOBAL_CS_NO_ALLIED_SKIRMISHES()
// Mercantile City States acquired via a Merchant of Venice do not lose their unique resources (v22)
#define MOD_GLOBAL_VENICE_KEEPS_RESOURCES           gCustomMods.isGLOBAL_VENICE_KEEPS_RESOURCES()
// Mercantile City States acquired via Diplomatic Marriage do not lose their unique resources (v81)
#define MOD_GLOBAL_CS_MARRIAGE_KEEPS_RESOURCES      gCustomMods.isGLOBAL_CS_MARRIAGE_KEEPS_RESOURCES()
// Units attacking from designated improvements (forts, citadels, etc) will not follow-up if they kill the defender (v87)
#define MOD_GLOBAL_NO_FOLLOWUP                      gCustomMods.isGLOBAL_NO_FOLLOWUP()
// Units attacking from cities will not follow-up if they kill the defender
#define MOD_GLOBAL_NO_FOLLOWUP_FROM_CITIES          gCustomMods.isGLOBAL_NO_FOLLOWUP_FROM_CITIES()
// Units that can move after attacking can also capture civilian units (eg workers in empty barbarian camps) (v32)
#define MOD_GLOBAL_CAPTURE_AFTER_ATTACKING          gCustomMods.isGLOBAL_CAPTURE_AFTER_ATTACKING()
// Trade routes can't be plundered on ocean tiles - too much sea to hide in, too many directions to escape in (v39)
#define MOD_GLOBAL_NO_OCEAN_PLUNDERING              gCustomMods.isGLOBAL_NO_OCEAN_PLUNDERING()
// Remove assembled spaceship parts from conquered capitals
#define MOD_GLOBAL_NO_CONQUERED_SPACESHIPS          gCustomMods.isGLOBAL_NO_CONQUERED_SPACESHIPS()
// Modified blockade logic (v52)
// The standard logic says "if there is an enemy ship within two hexes of a port, it is blockaded"
// HOWEVER - this includes the situations where
//   a) an enemy ship on the other side of a two-wide strip of land can blockade a port (ie enemy-land-port-water blockades the port)
//   b) a port with two non-adjacent exits (ie on a one-wide strip of land) can be blockaded by a non-adjacent enemy (ie enemy-water-port-water blockades the port)
// What is needed is a check for every adjacent water plot to the port being blockaded, not a simple check of the port itself
#define MOD_GLOBAL_ADJACENT_BLOCKADES               gCustomMods.isGLOBAL_ADJACENT_BLOCKADES()
// Adjacent allied ships block blockades by enemy ships 2 or more tiles away
#define MOD_GLOBAL_ALLIES_BLOCK_BLOCKADES           gCustomMods.isGLOBAL_ALLIES_BLOCK_BLOCKADES()
// Embarked combat units only blockade adjacent tiles
#define MOD_GLOBAL_SHORT_EMBARKED_BLOCKADES         gCustomMods.isGLOBAL_SHORT_EMBARKED_BLOCKADES()
// Other player's settlers captured from Barbarians will sometimes remain as settlers
#define MOD_GLOBAL_GRATEFUL_SETTLERS                gCustomMods.isGLOBAL_GRATEFUL_SETTLERS()
// Units that can found a city take their religion with them (v34)
#define MOD_GLOBAL_RELIGIOUS_SETTLERS               gCustomMods.isGLOBAL_RELIGIOUS_SETTLERS()
// Route To will only build roads, or upgrade road to rail, for human players (v44)
#define MOD_GLOBAL_QUICK_ROUTES                     gCustomMods.isGLOBAL_QUICK_ROUTES()
// Subs under ice are immune to all attacks except from other subs
#define MOD_GLOBAL_SUBS_UNDER_ICE_IMMUNITY          gCustomMods.isGLOBAL_SUBS_UNDER_ICE_IMMUNITY()
// Paratroops can move/attack after the drop, if the drop is not at max range
#define MOD_GLOBAL_PARATROOPS_MOVEMENT              gCustomMods.isGLOBAL_PARATROOPS_MOVEMENT()
// Paratroops take AA damage from hostile units
#define MOD_GLOBAL_PARATROOPS_AA_DAMAGE             gCustomMods.isGLOBAL_PARATROOPS_AA_DAMAGE()
// Nukes will melt ice
#define MOD_GLOBAL_NUKES_MELT_ICE                   gCustomMods.isGLOBAL_NUKES_MELT_ICE() 
// Great Works can generate different yields than just culture (v25)
#define MOD_GLOBAL_GREATWORK_YIELDTYPES             gCustomMods.isGLOBAL_GREATWORK_YIELDTYPES() 
// Great Artists, Writers and Musicians that do NOT create Great Works can be "reborn" (v84)
#define MOD_GLOBAL_NO_LOST_GREATWORKS               gCustomMods.isGLOBAL_NO_LOST_GREATWORKS() 
// Units of this type will not be gifted by City States (v46)
#define MOD_GLOBAL_EXCLUDE_FROM_GIFTS               gCustomMods.isGLOBAL_EXCLUDE_FROM_GIFTS()
// Units of this type may move after being upgraded (v46)
#define MOD_GLOBAL_MOVE_AFTER_UPGRADE               gCustomMods.isGLOBAL_MOVE_AFTER_UPGRADE()
// Units of this type may never embark (v46)
#define MOD_GLOBAL_CANNOT_EMBARK                    gCustomMods.isGLOBAL_CANNOT_EMBARK()
// Separates the Engineer, Scientist and Merchant GP counters (v52)
#define MOD_GLOBAL_SEPARATE_GP_COUNTERS             gCustomMods.isGLOBAL_SEPARATE_GP_COUNTERS()
// Removes free GP (from buildings, policies, traits, etc) from the GP counters (v61)
#define MOD_GLOBAL_TRULY_FREE_GP                    gCustomMods.isGLOBAL_TRULY_FREE_GP()

// Displays the opinion weight in the tooltip when meeting a leader (v80)
#define MOD_DIPLOMACY_BY_NUMBERS                    gCustomMods.isDIPLOMACY_BY_NUMBERS()
// Tech bonuses from other teams require an embassy or spy in their capital and not from just having met them (v30)
#define MOD_DIPLOMACY_TECH_BONUSES                  gCustomMods.isDIPLOMACY_TECH_BONUSES()
// Human players will auto-denounce AI players before going to war with them (v39)
#define MOD_DIPLOMACY_AUTO_DENOUNCE                 gCustomMods.isDIPLOMACY_AUTO_DENOUNCE()
// Gags the AI for annoying, inter-turn, so called, diplomacy messages "You're army is weak", "You're so powerful", etc. (v67)
//   GameEvents.DiplomacyStfu.Add(function(iAI, iResponseType, iDiploMessage, iDiploUIState, iAction, iExtraData) return GameInfoTypes.STFU_DEFAULT; end)
#define MOD_DIPLOMACY_STFU                          gCustomMods.isDIPLOMACY_STFU()
// Don't display leader heads (behaves more like multi-player diplomacy) (v67)
#define MOD_DIPLOMACY_NO_LEADERHEADS                gCustomMods.isDIPLOMACY_NO_LEADERHEADS()

// Permits units to earn GG/GA points from killing barbarians (v83)
#define MOD_TRAITS_GG_FROM_BARBARIANS               gCustomMods.isTRAITS_GG_FROM_BARBARIANS()
// Permits land units to cross ice - AFFECTS SAVE GAME DATA FORMAT
#define MOD_TRAITS_CROSSES_ICE                      gCustomMods.isTRAITS_CROSSES_ICE()
// Permits cities to work more rings - AFFECTS SAVE GAME DATA FORMAT
#define MOD_TRAITS_CITY_WORKING                     gCustomMods.isTRAITS_CITY_WORKING()
// Permit cities to have automaton workers - AFFECTS SAVE GAME DATA FORMAT (v90)
#define MOD_TRAITS_CITY_AUTOMATON_WORKERS           gCustomMods.isTRAITS_CITY_AUTOMATON_WORKERS()
// Enables traits to be enabled/obsoleted via beliefs and policies (v77)
#define MOD_TRAITS_OTHER_PREREQS                    gCustomMods.isTRAITS_OTHER_PREREQS()
// Enables any belief to be selected, even if already taken (v46) Serp: (in IsInSomeReligion in CvReligionClasses) if AnyBelif-Player chose one, others wont be able to select it too. whowards code had a bug, he wanted to have others to choose it too, but when they picked it, the religion wasnt found with error. So we either had to fix this, or refuse others to get same belief like AnyBelif-Player
// It is important! that in ChooseReligionPopup.lua and ChoosePantheonPopup.lua the player id is given to all calls like GetAvailableBonusBeliefs. Otherwise the players theoretically can choose the same beliefs, but they will not show up in the list! (we could hardcode in DLL that these lua functions always use ActivePlayer if no player given, but who knows who is using these functions somewhere, so better only use activeplayer in those popup lua files, where it is save to use activeplayer)
#define MOD_TRAITS_ANY_BELIEF                       gCustomMods.isTRAITS_ANY_BELIEF()
// Enables additional trade route related traits (v52)
#define MOD_TRAITS_TRADE_ROUTE_BONUSES              gCustomMods.isTRAITS_TRADE_ROUTE_BONUSES()
// Enables additional unit supply from traits (v78)
#define MOD_TRAITS_EXTRA_SUPPLY                     gCustomMods.isTRAITS_EXTRA_SUPPLY()

// Permits cities to work more rings - AFFECTS SAVE GAME DATA FORMAT
#define MOD_POLICIES_CITY_WORKING                   gCustomMods.isPOLICIES_CITY_WORKING()
// Permit cities to have automaton workers - AFFECTS SAVE GAME DATA FORMAT (v90)
#define MOD_POLICIES_CITY_AUTOMATON_WORKERS         gCustomMods.isPOLICIES_CITY_AUTOMATON_WORKERS()

// Permits cities to work more rings - AFFECTS SAVE GAME DATA FORMAT
#define MOD_TECHS_CITY_WORKING                      gCustomMods.isTECHS_CITY_WORKING()
// Permit cities to have automaton workers - AFFECTS SAVE GAME DATA FORMAT (v89)
#define MOD_TECHS_CITY_AUTOMATON_WORKERS            gCustomMods.isTECHS_CITY_AUTOMATON_WORKERS()

// Permits variable great general and admiral aura ranges (v83)
#define MOD_PROMOTIONS_AURA_CHANGE                  gCustomMods.isPROMOTIONS_AURA_CHANGE()
// Permits units to earn GG/GA points from killing barbarians (v83)
#define MOD_PROMOTIONS_GG_FROM_BARBARIANS           gCustomMods.isPROMOTIONS_GG_FROM_BARBARIANS()
// Permits variable recon ranges by creating extra recon range promotions (like extra sight range)
#define MOD_PROMOTIONS_VARIABLE_RECON               gCustomMods.isPROMOTIONS_VARIABLE_RECON()
// Permits land units to cross mountains (like the Carthage trait)
#define MOD_PROMOTIONS_CROSS_MOUNTAINS              gCustomMods.isPROMOTIONS_CROSS_MOUNTAINS()
// Permits coastal units to cross oceans
#define MOD_PROMOTIONS_CROSS_OCEANS                 gCustomMods.isPROMOTIONS_CROSS_OCEANS()
// Permits land units to cross ice
#define MOD_PROMOTIONS_CROSS_ICE                    gCustomMods.isPROMOTIONS_CROSS_ICE()
// Adds a HalfMove feature to the UnitPromotions_Terrains and UnitPromotions_Features tables
#define MOD_PROMOTIONS_HALF_MOVE                    gCustomMods.isPROMOTIONS_HALF_MOVE()
// Permits Deep Water (Ocean) embarkation for hovering units - AFFECTS SAVE GAME DATA FORMAT
#define MOD_PROMOTIONS_DEEP_WATER_EMBARKATION       gCustomMods.isPROMOTIONS_DEEP_WATER_EMBARKATION()
// Permits naval units to transfer their moves to Great Admirals (like land units can to Great Generals) (v39)
#define MOD_PROMOTIONS_FLAGSHIP                     gCustomMods.isPROMOTIONS_FLAGSHIP()
// Permits units to be named based on a promotion they have (v46)
#define MOD_PROMOTIONS_UNIT_NAMING                  gCustomMods.isPROMOTIONS_UNIT_NAMING()
// Permits units to receive a combat bonus from being near an improvement (v46)
#define MOD_PROMOTIONS_IMPROVEMENT_BONUS            gCustomMods.isPROMOTIONS_IMPROVEMENT_BONUS()

// Permit the focus (gold/production/culture) of puppet cities to be set (but not what is being built or how specialists are allocated)
#define MOD_UI_CITY_PRODUCTION                      gCustomMods.isUI_CITY_PRODUCTION()
// Permit human players to choose they own city tiles due to cultural expansion
#define MOD_UI_CITY_EXPANSION                       gCustomMods.isUI_CITY_EXPANSION()

// National Wonders (NW) requiring a building in every city exclude those being razed (in addition to excluding puppets) (v63)
#define MOD_BUILDINGS_NW_EXCLUDE_RAZING             gCustomMods.isBUILDINGS_NW_EXCLUDE_RAZING()
// Purchase of buildings in cities allows for any current production
#define MOD_BUILDINGS_PRO_RATA_PURCHASE             gCustomMods.isBUILDINGS_PRO_RATA_PURCHASE()
// Permits cities to work more rings - AFFECTS SAVE GAME DATA FORMAT
#define MOD_BUILDINGS_CITY_WORKING                  gCustomMods.isBUILDINGS_CITY_WORKING()
// Permit cities to have automaton workers - AFFECTS SAVE GAME DATA FORMAT (v90)
#define MOD_BUILDINGS_CITY_AUTOMATON_WORKERS        gCustomMods.isBUILDINGS_CITY_AUTOMATON_WORKERS()

// Scales trade routes based on map size and game speed (v52)
#define MOD_TRADE_ROUTE_SCALING                     gCustomMods.isTRADE_ROUTE_SCALING()

// Permits wonder resource (ie Marble) trade routes to be established (v43)
#define MOD_TRADE_WONDER_RESOURCE_ROUTES            gCustomMods.isTRADE_WONDER_RESOURCE_ROUTES()

// Permits units to have no supply cost (v77)
#define MOD_UNITS_NO_SUPPLY                         gCustomMods.isUNITS_NO_SUPPLY()
// Permits units to have other than GameDefines.MAX_HIT_POINTS maximum hit points (v77)
#define MOD_UNITS_MAX_HP                            gCustomMods.isUNITS_MAX_HP()
// Enables the XP times 100 API (v77)
#define MOD_UNITS_XP_TIMES_100                      gCustomMods.isUNITS_XP_TIMES_100()
// Restricts worker suggestions to local tiles
#define MOD_UNITS_LOCAL_WORKERS                     gCustomMods.isUNITS_LOCAL_WORKERS()
// Hovering unit can only heal over land
#define MOD_UNITS_HOVERING_LAND_ONLY_HEAL           gCustomMods.isUNITS_HOVERING_LAND_ONLY_HEAL()
// Permits hovering units to attack coastal shipping
#define MOD_UNITS_HOVERING_COASTAL_ATTACKS          gCustomMods.isUNITS_HOVERING_COASTAL_ATTACKS()

// Removes religion preference
#define MOD_RELIGION_NO_PREFERRENCES                gCustomMods.isRELIGION_NO_PREFERRENCES()
// Randomises religion choice (if preferred religion unavailable)
#define MOD_RELIGION_RANDOMISE                      gCustomMods.isRELIGION_RANDOMISE()
// Adds ConversionModifier and GlobalConversionModifier (in the same vein as espionage modifiers) to buildings - AFFECTS SAVE GAME DATA FORMAT
#define MOD_RELIGION_CONVERSION_MODIFIERS           gCustomMods.isRELIGION_CONVERSION_MODIFIERS()
// Keeps overflow faith from spawning a Great Prophet if the base spawn chance is 100% (v21)
#define MOD_RELIGION_KEEP_PROPHET_OVERFLOW          gCustomMods.isRELIGION_KEEP_PROPHET_OVERFLOW()
// Inquisitors will keep religion out of allied City State cities if positioned adjacent (v60)
#define MOD_RELIGION_ALLIED_INQUISITORS             gCustomMods.isRELIGION_ALLIED_INQUISITORS()
// Send purchase notifications at every boundary and not just the first (v42)
#define MOD_RELIGION_RECURRING_PURCHASE_NOTIFIY     gCustomMods.isRELIGION_RECURRING_PURCHASE_NOTIFIY()
// Adds support for the Belief_PlotYieldChanges table (v35)
#if defined(MOD_API_PLOT_YIELDS)
#define MOD_RELIGION_PLOT_YIELDS                    (gCustomMods.isRELIGION_PLOT_YIELDS() && MOD_API_PLOT_YIELDS)
#endif
// Adds support for Great People being purchased by faith to be specified on a policy (usually a finisher) and not hard-coded (v53)
#define MOD_RELIGION_POLICY_BRANCH_FAITH_GP         gCustomMods.isRELIGION_POLICY_BRANCH_FAITH_GP()
// Adds support for "local" religions (ie ones that only have influence within the civ's own territory) (v48)
#define MOD_RELIGION_LOCAL_RELIGIONS                gCustomMods.isRELIGION_LOCAL_RELIGIONS()

// Enables production to be stockpiled (v28)
#define MOD_PROCESS_STOCKPILE                       gCustomMods.isPROCESS_STOCKPILE()

// Stops the AI from adding zero-value items (eg late game horses) into trade offers (v85)
#define MOD_AI_NO_ZERO_VALUE_TRADE_ITEMS            gCustomMods.isAI_NO_ZERO_VALUE_TRADE_ITEMS()

// Fixes the AI's inability to use combat units as secondary workers (v26)
#define MOD_AI_SECONDARY_WORKERS                    gCustomMods.isAI_SECONDARY_WORKERS()
// Fixes the AI's inability to use combat units for founding cities (v26)
#define MOD_AI_SECONDARY_SETTLERS                   gCustomMods.isAI_SECONDARY_SETTLERS()

// Fixes the AI's inability to pick free Great Prophets, Merchants of Venice, Great Musicians and Great Writers (v82)
#define MOD_AI_GREAT_PEOPLE_CHOICES                 gCustomMods.isAI_GREAT_PEOPLE_CHOICES()

// Enables JdH's MP Diplomacy code (v84)
// #define MOD_AI_MP_DIPLOMACY                         gCustomMods.isAI_MP_DIPLOMACY() // commeted out by serp: Confirmed: this define alone is causing trade bugs between human players in MP

// Features from the "Smart AI V3 mod" by Ninakoru - see http://forums.civfanatics.com/showthread.php?t=562319 (v85)
// serp: I think it is also responsible for high turn duration in lategame. there is some event that starts from one turn to another, that turn duration is *4 . without smart_ai loading the same savegame, the problem is gone. But no need to outcomment it here, it is enough to not enable this via xml. 
#define MOD_AI_SMART_V3                             gCustomMods.isAI_SMART_V3()

// Events sent when terraforming occurs (v33)
//   GameEvents.TerraformingMap.Add(function(iEvent, iLoad) end)
//   GameEvents.TerraformingPlot.Add(function(iEvent, iPlotX, iPlotY, iInfo, iNewValue, iOldValue, iNewExtra, iOldExtra) end)
#define MOD_EVENTS_TERRAFORMING                     gCustomMods.isEVENTS_TERRAFORMING()

// Events sent when plots change from worker actions (v44)
//   GameEvents.TileFeatureChanged.Add(function(iPlotX, iPlotY, iOwner, iOldFeature, iNewFeature) end)
//   GameEvents.TileImprovementChanged.Add(function(iPlotX, iPlotY, iOwner, iOldImprovement, iNewImprovement, bPillaged) end)
//   GameEvents.TileOwnershipChanged.Add(function(iPlotX, iPlotY, iOwner, iOldOwner) end) (v46)
//   GameEvents.TileRouteChanged.Add(function(iPlotX, iPlotY, iOwner, iOldRoute, iNewRoute, bPillaged) end)
#define MOD_EVENTS_TILE_IMPROVEMENTS                gCustomMods.isEVENTS_TILE_IMPROVEMENTS()

// Event sent when a plot is revealed (v58)
//   GameEvents.TileRevealed.Add(function(iPlotX, iPlotY, iteam, iFromTeam, bFirst) end)
#define MOD_EVENTS_TILE_REVEALED                    gCustomMods.isEVENTS_TILE_REVEALED()

// Event sent when a team circumnavigates the globe
//   GameEvents.CircumnavigatedGlobe.Add(function(iTeam) end)
#define MOD_EVENTS_CIRCUMNAVIGATION                 gCustomMods.isEVENTS_CIRCUMNAVIGATION()

// Event sent when the player enters a new era, see also NewEraPopup.lua and BUTTONPOPUP_NEW_ERA
//   GameEvents.TeamSetEra.Add(function(eTeam, eEra, bFirst) end)
#define MOD_EVENTS_NEW_ERA                          gCustomMods.isEVENTS_NEW_ERA()

// Event sent when the team discovers a new Natural Wonder
//   GameEvents.NaturalWonderDiscovered.Add(function(iTeam, iFeature, iX, iY, bFirst) end)
#define MOD_EVENTS_NW_DISCOVERY                     gCustomMods.isEVENTS_NW_DISCOVERY()

// Event sent during Game.DoFromUIDiploEvent, see also DiscussionDialog.lua
//   GameEvents.UiDiploEvent.Add(function(iEvent, iAIPlayer, iArg1, iArg2) end)
#define MOD_EVENTS_DIPLO_EVENTS                     gCustomMods.isEVENTS_DIPLO_EVENTS()

// Enhanced Diplomacy Modifiers events (v53)
//   GameEvents.GetDiploModifier.Add(function(iEvent, iFromPlayer, iToPlayer) return 0 end)
#define MOD_EVENTS_DIPLO_MODIFIERS                  gCustomMods.isEVENTS_DIPLO_MODIFIERS()

// Events sent on status change with City States
//   GameEvents.MinorFriendsChanged.Add(function(iMinor, iMajor, bIsFriend, iOldFriendship, iNewFriendship) end)
//   GameEvents.MinorAlliesChanged.Add(function(iMinor, iMajor, bIsAlly, iOldFriendship, iNewFriendship) end)
#define MOD_EVENTS_MINORS                           gCustomMods.isEVENTS_MINORS()

// Event sent upon a City State giving a gift (v73)
//   GameEvents.MinorGift.Add(function(iMinor, iMajor, iGift, iFriendshipBoost, 0, bFirstMajorCiv, false, szTxtKeySuffix) end)
#define MOD_EVENTS_MINORS_GIFTS                     gCustomMods.isEVENTS_MINORS_GIFTS()

// Events sent on interaction with City States (v68)
//   GameEvents.PlayerCanProtect.Add(function(iPlayer, iCS) return true end)
//   GameEvents.PlayerProtected.Add(function(iPlayer, iCS) end)
//   GameEvents.PlayerCanRevoke.Add(function(iPlayer, iCS) return true end)
//   GameEvents.PlayerRevoked.Add(function(iPlayer, iCS, bPledgeNowBroken) end)
//   GameEvents.PlayerCanBuyOut.Add(function(iPlayer, iCS) return true end)
//   GameEvents.PlayerBoughtOut.Add(function(iPlayer, iCS) end)
//   GameEvents.PlayerCanBullyGold.Add(function(iPlayer, iCS) return true end)
//   GameEvents.PlayerCanBullyUnit.Add(function(iPlayer, iCS) return true end)
//   GameEvents.PlayerBullied.Add(function(iPlayer, iCS, iGold, iUnitType, iPlotX, iPlotY) end)
//   GameEvents.PlayerCanGiftGold.Add(function(iPlayer, iCS) return true end)
//   GameEvents.PlayerCanGiftUnit.Add(function(iPlayer, iCS, iUnit) return true end)
//   GameEvents.PlayerCanGiftImprovement.Add(function(iPlayer, iCS) return true end)
//   GameEvents.PlayerGifted.Add(function(iPlayer, iCS, iGold, iUnitType, iPlotX, iPlotY) end)
//   GameEvents.PlayerCanTransitMinorCity.Add(function(iPlayer, iCS, iCity, iPlotX, iPlotY) return true end) (v74)
//   GameEvents.UnitCanTransitMinorCity.Add(function(iPlayer, iUnit, iCS, iCity, iPlotX, iPlotY) return true end) (v74)
#define MOD_EVENTS_MINORS_INTERACTION               gCustomMods.isEVENTS_MINORS_INTERACTION()

// Events sent by City State quests (v81)
//   GameEvents.QuestIsAvailable(iPlayer, iCS, iQuest, iData1, iData2) return false end)
//   GameEvents.QuestIsCompleted.Add(function(iPlayer, iCS, iQuest, bLastTurn) return false end)
//   GameEvents.QuestIsRevoked.Add(function(iPlayer, iCS, iQuest) return false end)
//   GameEvents.QuestIsExpired.Add(function(iPlayer, iCS, iQuest) return false end)
//   GameEvents.QuestStart.Add(function(iPlayer, iCS, iQuest, iStartTurn, iData1, iData2) end)
//   GameEvents.QuestGetData.Add(function(iPlayer, iCS, iQuest, bData1) return 0 end)
//   GameEvents.QuestSendNotification.Add(function(iPlayer, iCS, iQuest, iStartTurn, iEndTurn, iData1, iData2, bStarted, bFinished, sNames) end)
//   GameEvents.QuestContestValue.Add(function(iPlayer, iCS, iQuest) return 0 end)
#define MOD_EVENTS_QUESTS                           gCustomMods.isEVENTS_QUESTS()

// Events sent by Barbarians (v68)
//   GameEvents.BarbariansCanFoundCamp.Add(function(iPlotX, iPlotY) return true end)
//   GameEvents.BarbariansCampFounded.Add(function(iPlotX, iPlotY) end)
//   GameEvents.BarbariansCampCleared.Add(function(iPlotX, iPlotY, iPlayer) end)
//   GameEvents.BarbariansCampCanSpawnUnit.Add(function(iPlotX, iPlotY) return true end)
//   GameEvents.BarbariansCampGetSpawnUnit.Add(function(iPlotX, iPlotY, iPrefUnitType) return iPrefUnitType end)
//   GameEvents.BarbariansSpawnedUnit.Add(function(iPlotX, iPlotY, iUnitType) end)
#define MOD_EVENTS_BARBARIANS                       gCustomMods.isEVENTS_BARBARIANS()

// Event sent when a Goody Hut is entered (v33)
//   GameEvents.GoodyHutCanNotReceive.Add(function(iPlayer, iUnit, eGoody, bPick) return false end)
//   GameEvents.GoodyHutReceivedBonus.Add(function(iPlayer, iUnit, eGoody, iX, iY) end)
#define MOD_EVENTS_GOODY_CHOICE                     gCustomMods.isEVENTS_GOODY_CHOICE()

// Events sent if a Goody Hut is giving a tech
//   GameEvents.GoodyHutCanResearch.Add(function(iPlayer, eTech) return true end)
//   GameEvents.GoodyHutTechResearched.Add(function(iPlayer, eTech) end)
#define MOD_EVENTS_GOODY_TECH                       gCustomMods.isEVENTS_GOODY_TECH()

// Event sent to allow Lua to override the AI's choice of tech (v30)
//   GameEvents.AiOverrideChooseNextTech.Add(function(iPlayer, bFreeTech) return iChoosenTech end)
#define MOD_EVENTS_AI_OVERRIDE_TECH                 gCustomMods.isEVENTS_AI_OVERRIDE_TECH()

// Events sent by Great People actions
//   GameEvents.GreatPersonExpended.Add(function(iPlayer, iUnit, iUnitType, iX, iY) end)
#define MOD_EVENTS_GREAT_PEOPLE                     gCustomMods.isEVENTS_GREAT_PEOPLE()

// Events sent when a player is about to found a religion
//   GameEvents.PlayerCanFoundPantheon.Add(function(iPlayer) return true end)
//   GameEvents.PlayerCanFoundReligion.Add(function(iPlayer, iCity) return true end)
//   GameEvents.GetReligionToFound.Add(function(iPlayer, iPreferredReligion, bIsAlreadyFounded) return iPreferredReligion end)
//   GameEvents.PantheonFounded.Add(function(iPlayer, iCapitalCity, iReligion, iBelief1) end)
//   GameEvents.ReligionFounded.Add(function(iPlayer, iHolyCity, iReligion, iBelief1, iBelief2, iBelief3, iBelief4, iBelief5) end)
//   GameEvents.ReligionEnhanced.Add(function(iPlayer, iReligion, iBelief1, iBelief2) end)
//   GameEvents.ReligionReformed.Add(function(iPlayer, iReligion, iBelief1) end) (v65)
#define MOD_EVENTS_FOUND_RELIGION                   gCustomMods.isEVENTS_FOUND_RELIGION()

// Events sent when choosing beliefs
//   GameEvents.PlayerCanHaveBelief.Add(function(iPlayer, iBelief) return true end)
//   GameEvents.ReligionCanHaveBelief.Add(function(iPlayer, iReligion, iBelief) return true end)
#define MOD_EVENTS_ACQUIRE_BELIEFS                  gCustomMods.isEVENTS_ACQUIRE_BELIEFS()

// Events sent to see if religion missions are valid (v46)
//   GameEvents.PlayerCanSpreadReligion.Add(function(iPlayer, iUnit, iPlotX, iPlotY) return true end)
//   GameEvents.PlayerCanRemoveHeresy.Add(function(iPlayer, iUnit, iPlotX, iPlotY) return true end)
#define MOD_EVENTS_RELIGION                         gCustomMods.isEVENTS_RELIGION()

// Events sents on espionage outcomes (v63)
//   GameEvents.EspionageResult.Add(function(iPlayer, iSpy, iResult, iCityX, iCityY) end)
//   GameEvents.EspionageState.Add(function(iPlayer, iSpy, iState, iCityX, iCityY) end)
//   GameEvents.EspionageCanMoveSpyTo.Add(function(iPlayer, iCityOwner, iCity) return true)
//   GameEvents.EspionageCanStageCoup.Add(function(iPlayer, iCityOwner, iCity) return true)
#define MOD_EVENTS_ESPIONAGE                         gCustomMods.isEVENTS_ESPIONAGE()

// Event sent to ascertain if a unit can start a paradrop from this tile
//   GameEvents.CanParadropFrom.Add(function(iPlayer, iUnit, iPlotX, iPlotY) return false end)
//   GameEvents.CannotParadropFrom.Add(function(iPlayer, iUnit, iPlotX, iPlotY) return false end)
//   GameEvents.ParadropAt.Add(function(iPlayer, iUnit, iFromX, iFromY, iToX, iToY) end)
#define MOD_EVENTS_PARADROPS                        gCustomMods.isEVENTS_PARADROPS()

// Event sent to ascertain if a unit can perform a ranged attack on a tile (v90)
//   GameEvents.UnitCanRangeAttackAt.Add(function(iPlayer, iUnit, iPlotX, iPlotY, bNeedWar) return false end)
//   GameEvents.UnitRangeAttackAt.Add(function(iPlayer, iUnit, iPlotX, iPlotY) return 0; end)
#define MOD_EVENTS_UNIT_RANGEATTACK                 gCustomMods.isEVENTS_UNIT_RANGEATTACK()

// Event sent when a unit is created (v46)
//   GameEvents.UnitCreated.Add(function(iPlayer, iUnit, iUnitType, iPlotX, iPlotY) end)
#define MOD_EVENTS_UNIT_CREATED                     gCustomMods.isEVENTS_UNIT_CREATED()

// Event sent when a unit founds a city (v58)
//   GameEvents.UnitCityFounded.Add(function(iPlayer, iUnit, iUnitType, iPlotX, iPlotY) end)
#define MOD_EVENTS_UNIT_FOUNDED                     gCustomMods.isEVENTS_UNIT_FOUNDED()

// Event sent just before a unit is killed (via CvUnit::kill()) (v22)
//   GameEvents.UnitPrekill.Add(function(iPlayer, iUnit, iUnitType, iX, iY, bDelay, iByPlayer) end)
#define MOD_EVENTS_UNIT_PREKILL                     gCustomMods.isEVENTS_UNIT_PREKILL()

// Event sent as a unit is captured (v46)
//   GameEvents.UnitCaptured.Add(function(iByPlayer, iByUnit, iCapturedPlayer, iCapturedUnit, bWillBeKilled, iReason) end) (v69)
//   iReason - 0=Move, 1=Combat, 2=Trait (barb land), 3=Trait (barb naval), 4=Belief (barb)
//   GameEvents.UnitCaptureType.Add(function(iPlayer, iUnit, iUnitType, iByCiv) return iCaptureUnitType; end)
#define MOD_EVENTS_UNIT_CAPTURE                     gCustomMods.isEVENTS_UNIT_CAPTURE()

// Events sent as units perform actions (v86)
//   GameEvents.UnitCanPillage.Add(function(iPlayer, iUnit, iImprovement, iRoute) return true end)
//   GameEvents.UnitPillageGold.Add(function(iPlayer, iUnit, iImprovement, iGold) return iGold end)
//   GameEvents.UnitCanFollowupFrom.Add(function(iPlayer, iUnit, iImprovement, iFromX, iFromY, iToX, iToY) return true end) (v87)
#define MOD_EVENTS_UNIT_ACTIONS                     gCustomMods.isEVENTS_UNIT_ACTIONS()

// Events sent as units are promoted/upgraded
//   GameEvents.CanHavePromotion.Add(function(iPlayer, iUnit, iPromotionType) return true end)
//   GameEvents.UnitCanHavePromotion.Add(function(iPlayer, iUnit, iPromotionType) return true end)
//   GameEvents.UnitPromoted.Add(function(iPlayer, iUnit, iPromotionType) end)
//   GameEvents.CanHaveAnyUpgrade.Add(function(iPlayer, iUnit) return true end)
//   GameEvents.UnitCanHaveAnyUpgrade.Add(function(iPlayer, iUnit) return true end)
//   GameEvents.CanHaveUpgrade.Add(function(iPlayer, iUnit, iUnitClassType, iUnitType) return true end)
//   GameEvents.UnitCanHaveUpgrade.Add(function(iPlayer, iUnit, iUnitClassType, iUnitType) return true end)
//   GameEvents.UnitUpgraded.Add(function(iPlayer, iOldUnit, iNewUnit, bGoodyHut) end)
#define MOD_EVENTS_UNIT_UPGRADES                    gCustomMods.isEVENTS_UNIT_UPGRADES()

// Events sent as units are created (v51)
//   GameEvents.UnitCanHaveName.Add(function(iPlayer, iUnit, iName) return true end)
//   GameEvents.UnitCanHaveGreatWork.Add(function(iPlayer, iUnit, iGreatWork) return true end)
#define MOD_EVENTS_UNIT_DATA                        gCustomMods.isEVENTS_UNIT_DATA()

// Event sent to ascertain if a unit can move into a given plot - VERY, VERY CPU INTENSIVE!!!
//   GameEvents.CanMoveInto.Add(function(iPlayer, iUnit, iPlotX, iPlotY, bAttack, bDeclareWar) return true end)
#define MOD_EVENTS_CAN_MOVE_INTO                    gCustomMods.isEVENTS_CAN_MOVE_INTO()

// Event sent as ascertain if a trade route can be created (v68)
//   GameEvents.PlayerCanCreateTradeRoute.Add(function(iFromPlayer, iFromCity, iToPlayer, iToCity, iDomain, iConnectionType) return true end)
#define MOD_EVENTS_TRADE_ROUTES                     gCustomMods.isEVENTS_TRADE_ROUTES()

// Event sent as a trade route is plundered (v52)
//   GameEvents.PlayerPlunderedTradeRoute.Add(function(iPlayer, iUnit, iPlunderedGold, iFromPlayer, iFromCity, iToPlayer, iToCity, iRouteType, iRouteDomain) end)
#define MOD_EVENTS_TRADE_ROUTE_PLUNDERED            gCustomMods.isEVENTS_TRADE_ROUTE_PLUNDERED()

// Event sent when a nuke is fired
//   GameEvents.NuclearDetonation.Add(function(iPlayer, iX, iY, bWar, bBystanders) end)
#define MOD_EVENTS_NUCLEAR_DETONATION               gCustomMods.isEVENTS_NUCLEAR_DETONATION()

// Events sent about war and peace
//   GameEvents.PlayerCanDeclareWar.Add(function(iPlayer, iAgainstTeam) return true end)
//   GameEvents.IsAbleToDeclareWar.Add(function(iPlayer, iAgainstTeam) return true end) - deprecated, use PlayerCanDeclareWar
//   GameEvents.DeclareWar.Add(function(iPlayer, iAgainstTeam, bAggressor) end)
//   GameEvents.PlayerCanMakePeace.Add(function(iPlayer, iAgainstTeam) return true end)
//   GameEvents.IsAbleToMakePeace.Add(function(iPlayer, iAgainstTeam) return true end) - deprecated, use PlayerCanMakePeace
//   GameEvents.MakePeace.Add(function(iPlayer, iAgainstTeam, bPacifier) end)
#define MOD_EVENTS_WAR_AND_PEACE                    gCustomMods.isEVENTS_WAR_AND_PEACE()

// Events sent about resolutions (v51)
//   GameEvents.PlayerCanPropose.Add(function(iPlayer, iResolution, iChoice, bEnact) return true end)
//   GameEvents.ResolutionProposing.Add(function(iPlayer, iLeague) return false; end) (v88)
//   GameEvents.ResolutionVoting.Add(function(iPlayer, iLeague) return false; end) (v88)
//   GameEvents.ResolutionResult.Add(function(iResolution, iChoice, bEnact, bPassed) end)
#define MOD_EVENTS_RESOLUTIONS                      gCustomMods.isEVENTS_RESOLUTIONS()

// Events sent about ideologies and tenets (v51)
//   GameEvents.PlayerCanAdoptIdeology.Add(function(iPlayer, iIdeology) return true end)
//   GameEvents.PlayerCanAdoptTenet.Add(function(iPlayer, iTenet) return true end)
#define MOD_EVENTS_IDEOLOGIES                       gCustomMods.isEVENTS_IDEOLOGIES()

// Events sent by plots (v30)
//   GameEvents.PlayerCanBuild.Add(function(iPlayer, iUnit, iX, iY, iBuild) return true end)
//   GameEvents.PlotCanImprove.Add(function(iX, iY, iImprovement) return true end)
//   GameEvents.PlayerBuilding.Add(function(iPlayer, iUnit, iX, iY, iBuild, bStarting) end) (v46)
//   GameEvents.PlayerBuilt.Add(function(iPlayer, iUnit, iX, iY, iBuild) end) (v46)
#define MOD_EVENTS_PLOT                             gCustomMods.isEVENTS_PLOT()

// Event sent by ending turn (v94)
//   GameEvents.PlayerDoneTurn.Add(function(iPlayer) end)
#define MOD_EVENTS_PLAYER_TURN                      gCustomMods.isEVENTS_PLAYER_TURN()

// Event sent by golden ages (v52)
//   GameEvents.PlayerGoldenAge.Add(function(iPlayer, bStart, iTurns) end)
#define MOD_EVENTS_GOLDEN_AGE                       gCustomMods.isEVENTS_GOLDEN_AGE()

// Events sent after a city produces/buys something
//   GameEvents.CityTrained.Add(function(iPlayer, iCity, iUnit, bGold, bFaith) end)
//   GameEvents.CityConstructed.Add(function(iPlayer, iCity, iBuilding, bGold, bFaith) end)
//   GameEvents.CityCreated.Add(function(iPlayer, iCity, iProject, bGold, bFaith) end)
//   GameEvents.CityPrepared.Add(function(iPlayer, iCity, iSpecialist, bGold, bFaith) end) (v33)
//   GameEvents.CityBoughtPlot.Add(function(iPlayer, iCity, iPlotX, iPlotY, bGold, bCulture) end)
//   GameEvents.CitySoldBuilding.Add(function(iPlayer, iCity, iBuilding) end)
#define MOD_EVENTS_CITY                             gCustomMods.isEVENTS_CITY()

// Event sent after a civilization moves their capital (v73)
//   GameEvents.CapitalChanged.Add(function(iPlayer, iNewCapital, iOldCapital) end)
#define MOD_EVENTS_CITY_CAPITAL                     gCustomMods.isEVENTS_CITY_CAPITAL()

// Event sent to ascertain if a city can acquire a plot (v20)
//   GameEvents.CityCanAcquirePlot.Add(function(iPlayer, iCity, iPlotX, iPlotY) return true end)
#define MOD_EVENTS_CITY_BORDERS                     gCustomMods.isEVENTS_CITY_BORDERS()
	
// Event sent about city founding (v68)
//   GameEvents.PlayerCanFoundCity.Add(function(iPlayer, iPlotX, iPlotY) return true end)
//   GameEvents.PlayerCanFoundCityRegardless.Add(function(iPlayer, iPlotX, iPlotY) return false end)
#define MOD_EVENTS_CITY_FOUNDING                    gCustomMods.isEVENTS_CITY_FOUNDING()
	
// Event sent to ascertain if a player can liberate another player (v68)
//   GameEvents.PlayerCanLiberate.Add(function(iPlayer, iOtherPlayer) return true end)
//   GameEvents.PlayerLiberated.Add(function(iPlayer, iOtherPlayer, iCity) end)
#define MOD_EVENTS_LIBERATION                       gCustomMods.isEVENTS_LIBERATION()
	
// Event sent to ascertain if a player can over-ride the standard razing rules for the specified city and raze it anyway (v20)
//   GameEvents.PlayerCanRaze.Add(function(iPlayer, iCity) return false end)
#define MOD_EVENTS_CITY_RAZING                      gCustomMods.isEVENTS_CITY_RAZING()
	
// Event sent to ascertain if a city can perform airlifts (v68)
//   GameEvents.CityCanAirlift.Add(function(iPlayer, iCity) return false end)
#define MOD_EVENTS_CITY_AIRLIFT                     gCustomMods.isEVENTS_CITY_AIRLIFT()

// Events sent to ascertain the bombard range for a city, and if indirect fire is allowed (v32)
//   GameEvents.GetBombardRange.Add(function(iPlayer, iCity) return (-1 * GameDefines.CITY_ATTACK_RANGE) end)
// serp: made the game only call this event once per turn (beginning). on all the thousand other times, we use a chached value.
#define MOD_EVENTS_CITY_BOMBARD                     gCustomMods.isEVENTS_CITY_BOMBARD()

// Events sent to ascertain if one city is connected to another (v33)
//   GameEvents.CityConnections.Add(function(iPlayer, bDomestic) return false end)
//   GameEvents.CityConnected.Add(function(iPlayer, iCityX, iCityY, iToCityX, iToCityY, bDomestic) return false end)
#define MOD_EVENTS_CITY_CONNECTIONS                 gCustomMods.isEVENTS_CITY_CONNECTIONS()

// Events sent to ascertain if an area can have civ specific resources and to place those resources (v20)
//   GameEvents.AreaCanHaveAnyResource.Add(function(iPlayer, iArea) return true end)
//   GameEvents.PlaceResource.Add(function(iPlayer, iResource, iCount, iPlotX, iPlotY) end)
#define MOD_EVENTS_AREA_RESOURCES                   gCustomMods.isEVENTS_AREA_RESOURCES()

// Events sent to ascertain if a unit can airlift from/to a specific plot (v74)
//   GameEvents.CanAirliftFrom.Add(function(iPlayer, iUnit, iPlotX, iPlotY) return false end)
//   GameEvents.CanAirliftTo.Add(function(iPlayer, iUnit, iPlotX, iPlotY) return false end)
#define MOD_EVENTS_AIRLIFT                           gCustomMods.isEVENTS_AIRLIFT()

// Events sent to ascertain if a unit can rebase to a specific plot (either a city or a carrier)
//   GameEvents.CanLoadAt.Add(function(iPlayer, iUnit, iPlotX, iPlotY) return false end)
//   GameEvents.CanRebaseInCity.Add(function(iPlayer, iUnit, iPlotX, iPlotY) return false end)
//   GameEvents.CanRebaseTo.Add(function(iPlayer, iUnit, iPlotX, iPlotY, bIsCity) return false end)
//   GameEvents.RebaseTo.Add(function(iPlayer, iUnit, iPlotX, iPlotY) end)
#define MOD_EVENTS_REBASE                           gCustomMods.isEVENTS_REBASE()

// Event sent to see if a command is valid (v46)
//   GameEvents.CanDoCommand.Add(function(iPlayer, iUnit, iCommand, iData1, iData2, iPlotX, iPlotY, bTestVisible) return true end)
#define MOD_EVENTS_COMMAND                          gCustomMods.isEVENTS_COMMAND()

// Events sent for custom missions (v46)
//   CUSTOM_MISSION_NO_ACTION       = 0
//   CUSTOM_MISSION_ACTION          = 1
//   CUSTOM_MISSION_DONE            = 2
//   CUSTOM_MISSION_ACTION_AND_DONE = 3
//   GameEvents.CustomMissionPossible.Add(function(iPlayer, iUnit, iMission, iData1, iData2, iFlags=0, iTurn=-1, iPlotX, iPlotY, bTestVisible) return false end)
//   GameEvents.CustomMissionStart.Add(function(iPlayer, iUnit, iMission, iData1, iData2, iFlags, iTurn) return CUSTOM_MISSION_ACTION end)
//   GameEvents.CustomMissionSetActivity.Add(function(iPlayer, iUnit, iMission, iData1, iData2, iFlags, iTurn) return CUSTOM_MISSION_ACTION_AND_DONE end)
//   GameEvents.CustomMissionDoStep.Add(function(iPlayer, iUnit, iMission, iData1, iData2, iFlags, iTurn) return CUSTOM_MISSION_ACTION_AND_DONE end)
//   GameEvents.CustomMissionCompleted.Add(function(iPlayer, iUnit, iMission, iData1, iData2, iFlags, iTurn) return false end)
//   GameEvents.CustomMissionTargetPlot.Add(function(iPlayer, iUnit, iMission, iData1, iData2, iFlags, iTurn) return iPlotIndex end)
//   GameEvents.CustomMissionCameraTime.Add(function(iPlayer, iUnit, iMission, iData1, iData2, iFlags, iTurn) return iCameraTime end) -- iCameraTime is 0, 1, 5 or 10
//   GameEvents.CustomMissionTimerInc.Add(function(iPlayer, iUnit, iMission, iData1, iData2, iFlags, iTurn) return iTimerInc end)
#define MOD_EVENTS_CUSTOM_MISSIONS                  gCustomMods.isEVENTS_CUSTOM_MISSIONS()

// Events sent during combat (v68)
//   GameEvents.BattleStarted.Add(function(iType, iPlotX, iPlotY) end)
//   GameEvents.BattleJoined.Add(function(iPlayer, iUnitOrCity, iRole, bIsCity) end)
//   GameEvents.BattleFinished.Add(function() end)
#define MOD_EVENTS_BATTLES                          gCustomMods.isEVENTS_BATTLES()
//   GameEvents.BattleDamageDelta.Add(function(iRole, iBaseDamage) return 0 end)
#define MOD_EVENTS_BATTLES_DAMAGE                   (MOD_EVENTS_BATTLES && gCustomMods.isEVENTS_BATTLES_DAMAGE())

// Minor bug fixes (missing catch-all else clauses, etc) (v30 onwards)
// serp, commented out ~2 of them, eg in CvUnitMission.cpp to make workers continue to work after removing a feature
// serp added in CvTeam SetCurrentEra a bugfix whoward noted in v95
#define MOD_BUGFIX_MINOR 							(true)
// Minor bug fixes in the Lua API (v86 onwards)
#define MOD_BUGFIX_LUA_API 							(true)
// Adds validation to setting plot values (type, terrain, feature, resource, improvement and route) to stop CTDs in the graphics engine (v86)
#define MOD_BUGFIX_PLOT_VALIDATION					(true)
// Fixes some minor issues with the random number generator (v83)
#define MOD_BUGFIX_RANDOM							(true)
// Recodes direct access to (certain) member variables to use the associated getter/setter methods (v72 onwards)
#define MOD_BUGFIX_USE_GETTERS                      (true)
// Fixes the spy name crash (v53)
#define MOD_BUGFIX_SPY_NAMES                        (true)
// Fixes the bug when giving free religious units after the player has founded a religion not appearing in a religious city! (v78)
#define MOD_BUGFIX_FREE_RELIGIOUS_UNITS             (true)
// Fixes the issues with using dummy policies, thanks to LeeS for assistance with this (v77)
#define MOD_BUGFIX_DUMMY_POLICIES                   gCustomMods.isBUGFIX_DUMMY_POLICIES()
// Fixes the 'radaring' bug/exploit - see https://www.reddit.com/r/nqmod/comments/34reu9/how_to_remove_radaring/ (v74)
#define MOD_BUGFIX_RADARING                         gCustomMods.isBUGFIX_RADARING()
// Fixes the research NaN issue (v90)
#define MOD_BUGFIX_RESEARCH_NAN						(true)
// Fixes the research overflow bug/exploit (v52)
#define MOD_BUGFIX_RESEARCH_OVERFLOW                gCustomMods.isBUGFIX_RESEARCH_OVERFLOW()
// Fixes the bug where a city doesn't work its centre tile (v45)
#define MOD_BUGFIX_CITY_CENTRE_WORKING              (true)
// Fixes the bug of creating a capital from a puppet city, and leaving it that way (v73)
#define MOD_BUGFIX_NO_PUPPET_CAPITALS               (true)
// Adds missing policy events when adopting an ideology (v33)
#define MOD_BUGFIX_MISSING_POLICY_EVENTS			(true)
// Fixes trade routes sticking to coastal water when the player has the EmbarkAllWater trait (v33)
#define MOD_BUGFIX_TRADE_ROUTES_EMBARK_ALL_WATER	(true)
// Fixes the bug where Venice puppets it's own capital (v42)
#define MOD_BUGFIX_VENICE_PUPPETS_CAPITAL			(true)
// Fixes the bug in the Lua Plot:ChangeVisibilityCount() method where iChange is treated as a boolean and not a signed int (v23)
#define MOD_BUGFIX_LUA_CHANGE_VISIBILITY_COUNT      gCustomMods.isBUGFIX_LUA_CHANGE_VISIBILITY_COUNT()
// Fixes the bug that excludes spy pressure (Underground Sects) from the city banner tooltip display (v45)
#define MOD_BUGFIX_RELIGIOUS_SPY_PRESSURE           gCustomMods.isBUGFIX_RELIGIOUS_SPY_PRESSURE()
// Fixes the CanMoveAfterPurchase() bug where it is only tested for at one specific point in the code (v26)
#define MOD_BUGFIX_MOVE_AFTER_PURCHASE              gCustomMods.isBUGFIX_MOVE_AFTER_PURCHASE()
// Fixes the issues caused by using UNIT_XYZ instead of UNITCLASS_XYZ (v26)
#define MOD_BUGFIX_UNITCLASS_NOT_UNIT               gCustomMods.isBUGFIX_UNITCLASS_NOT_UNIT()
// Fixes the issues caused by using BUILDING_XYZ instead of BUILDINGCLASS_XYZ (v26)
#define MOD_BUGFIX_BUILDINGCLASS_NOT_BUILDING       gCustomMods.isBUGFIX_BUILDINGCLASS_NOT_BUILDING()
// Fixes the NumCitiesFreeFoodBuilding (policy finisher) bug where the civilization has a UB for the Aqueduct - AFFECTS SAVE GAME DATA FORMAT
#define MOD_BUGFIX_FREE_FOOD_BUILDING               gCustomMods.isBUGFIX_FREE_FOOD_BUILDING()
// Fixes the bug where the naval Civilization_FreeUnits start on land
#define MOD_BUGFIX_NAVAL_FREE_UNITS                 gCustomMods.isBUGFIX_NAVAL_FREE_UNITS()
// Fixes the bug where the naval units jump to the nearest city and not the nearest available non-lake water plot
#define MOD_BUGFIX_NAVAL_NEAREST_WATER              gCustomMods.isBUGFIX_NAVAL_NEAREST_WATER()
// Fixes the bug where stacked ranged units may attack out of cities but melee units may not
#define MOD_BUGFIX_CITY_STACKING                    gCustomMods.isBUGFIX_CITY_STACKING()
// Fixes the bug in goody hut messages that have parameters (v38)
#define MOD_BUGFIX_GOODY_HUT_MESSAGES               (true)
// Fixes the bug where Barb Camps ignore the ValidTerrains and ValidFeatures tables
#define MOD_BUGFIX_BARB_CAMP_TERRAINS               gCustomMods.isBUGFIX_BARB_CAMP_TERRAINS()
// Fixes the bug where Barb Camps won't spawn units if they are added via pPlot:SetImprovementType() (v21)
#define MOD_BUGFIX_BARB_CAMP_SPAWNING               gCustomMods.isBUGFIX_BARB_CAMP_SPAWNING()
// Fixes the bug where ranged combat (archers, catapults, ships and planes) against barbarians generates Great People XP (v43)
#define MOD_BUGFIX_BARB_GP_XP                       gCustomMods.isBUGFIX_BARB_GP_XP()
// Fixes the bug where you can't remove roads in no-mans-land originally built by a now dead player
#define MOD_BUGFIX_REMOVE_GHOST_ROUTES              gCustomMods.isBUGFIX_REMOVE_GHOST_ROUTES()
// Fixes healing units ignoring enemy units and sleeping units under direct fire remaining asleep - thanks to hulkster for highlighting the latter issue
#define MOD_BUGFIX_UNITS_AWAKE_IN_DANGER            gCustomMods.isBUGFIX_UNITS_AWAKE_IN_DANGER()
// Fixes workers stopping what they are doing at any hint of danger to only when they can see an enemy unit
#define MOD_BUGFIX_WORKERS_VISIBLE_DANGER           gCustomMods.isBUGFIX_WORKERS_VISIBLE_DANGER()
// Fixes the hard-coding of what builds remove which features (v45)
#define MOD_BUGFIX_FEATURE_REMOVAL                  gCustomMods.isBUGFIX_FEATURE_REMOVAL()
// Fixes the bug in calculating AA interception strength which takes terrain into account
#define MOD_BUGFIX_INTERCEPTOR_STRENGTH             gCustomMods.isBUGFIX_INTERCEPTOR_STRENGTH()
// Fixes the very dodgy maths in the calculation of a unit's power
#define MOD_BUGFIX_UNIT_POWER_CALC                  gCustomMods.isBUGFIX_UNIT_POWER_CALC()
// Fixes the Anti-Air non-domain bonuses issue, requires BUGFIX_UNIT_POWER_CALC to be enabled
#define MOD_BUGFIX_UNIT_POWER_BONUS_VS_DOMAIN_ONLY  gCustomMods.isBUGFIX_UNIT_POWER_BONUS_VS_DOMAIN_ONLY()
// Fixes the naval imbalance in a unit's power calculation, requires BUGFIX_UNIT_POWER_CALC to be enabled
#define MOD_BUGFIX_UNIT_POWER_NAVAL_CONSISTENCY     gCustomMods.isBUGFIX_UNIT_POWER_NAVAL_CONSISTENCY()
// Fixes the bug where units can upgrade even without any pre-req project being available (v22)
#define MOD_BUGFIX_UNIT_PREREQ_PROJECT              gCustomMods.isBUGFIX_UNIT_PREREQ_PROJECT()
// Fixes a bug where hovering units can be chosen as rebels! (v39)
#define MOD_BUGFIX_NO_HOVERING_REBELS               gCustomMods.isBUGFIX_NO_HOVERING_REBELS()
// Fixes a bug in the pathfinder code for hovering units at the seaside!
#define MOD_BUGFIX_HOVERING_PATHFINDER              gCustomMods.isBUGFIX_HOVERING_PATHFINDER()
// Fixes a bug in the pathfinder code for embarking
#define MOD_BUGFIX_EMBARKING_PATHFINDER             gCustomMods.isBUGFIX_EMBARKING_PATHFINDER()

////////////////////////
// Added by Serp, mostly copied from Community Patch:
// also added below MOD_OPT_DECL(..) and MOD_OPT_CACHE() code in custommods.cpp
// I replaced "GC.getGame().getActivePlayer() == GetID()" in CvPlayer.cpp in DoGoody with GET_PLAYER(pUnit->getOwner()).isHuman() to prevent desync, like it is done in CP.
// Workaround for the AI double turn when loading MP games with simultaneous/hybrid turns from CP (28.03.2020)
#define MOD_BUGFIX_AI_DOUBLE_TURN_MP_LOAD
// Adds Lua functions from from MOD_BALANCE_CORE from community patch (28.03.2020)
// currently: GetTotalValueToMe and GetTotalValueToMeNormal
#define MOD_LUA_AI_DEAL_FETCHINFO
// Enables the various tables related to production cost modifiers triggered by access to resources. from community patch (28.03.2020)
#define MOD_RESOURCES_PRODUCTION_COST_MODIFIERS		gCustomMods.isRESOURCES_PRODUCTION_COST_MODIFIERS()
// adds Obsolete Era to WonderProductionMod Notification (eg marble), written by myself
#define MOD_RESOURCES_WONDERMOD_TXT_OBSOLETE
// allow anyone to choose his panthon, even if an other player has already choosed it. from CP (28.03.2020)
// It is important! that in ChooseReligionPopup.lua and ChoosePantheonPopup.lua the player id is given to all calls like GetAvailableBonusBeliefs. Otherwise the players theoretically can choose the same beliefs, but they will not show up in the list! (we could hardcode in DLL that these lua functions always use ActivePlayer if no player given, but who knows who is using these functions somewhere, so better only use activeplayer in those popup lua files, where it is save to use activeplayer)
#define MOD_ANY_PANTHEON						gCustomMods.isANY_PANTHEON()
// Event sent on visibilty count changed of a plot
//   GameEvents.VisibilityCountChanged.Add(function(iTeam, iChange, iSeeInvisible, bInformExplorationTracking, bAlwaysSeeInvisible, iUnit, iPlotX, iPlotY, iPlayer) end)
#define MOD_EVENTS_VISCOUNT_CHANGED				gCustomMods.isEVENTS_VISCOUNT_CHANGED()
// Bugfix in CvReligionClasses.cpp, crash wenn founding a pantheon without capital (GET_PLAYER(ePlayer).getCapitalCity() ? GET_PLAYER(ePlayer).getCapitalCity()->GetID() : -1)
#define BUGFIX_PANTHEON_WO_CAPTIAL
// Features from NQ NoQuitters multiplayer mod:
// MP fix: barbarians wont spawn and move in same turn in simultanous multiplayer
// disabled, because instead we change all "DoSpawnBarbarianUnit" with true as third param, so all spawned barbs finish their movement after spawning
// #define BUGFIX_AUI_GAME_FIX_MULTIPLAYER_BARBARIANS_SPAWN_AFTER_MOVING
// if player disconnects in multiplayer with simultanous turns, the game will pause until reconnect, so no forced AI control.
#define MOD_AUI_GAME_AUTOPAUSE_ON_ACTIVE_DISCONNECT_IF_NOT_SEQUENTIAL
/// The function that gets the amount of different trading partners a player has will now use an array instead of a vector to avoid crash possibilities
#define MOD_AUI_TRADE_FIX_GET_NUM_DIFFERENT_TRADING_PARTNERS_USES_ARRAY
// puts the autosave in multiplayer to the beginning of turn, not the end. not sure if this will solve any problem, but lets try. serp: possibly causes disconnects in MP
// #define MOD_CVM_AUTOSAVE_FIX // causes problems! players get disconnected during next turn or it will endlessly load (not 100% sure that it is caused by this, but still not worth it)
/// Fixes a possible crash when exiting the game caused by too few items in a FStaticVector
#define MOD_AUI_TRADE_FIX_POSSIBLE_DEALLOCATION_CRASH
// We Love The King Day now scales based on game speed
#define MOD_NQ_WLTKD_SCALES_BY_GAME_SPEED
/// Fixes possible null pointer (==crash) dereferences in A*
#define BUGFIX_AUI_ASTAR_FIX_POSSIBLE_NULL_POINTERS
/// Fixes the fact that the game's Linear Congruential RNG is set to use constants that would require a modulus of 2^31 instead of ones that need 2^32 (couldn't introduce a modulus step because Civ5's engine really dislikes modifications to the RNG system)
#define MOD_AUI_RANDOM_FIX_CONSTANTS_SET_TO_MODULUS_2_POW_32
/// Minors will always "see" units of major civs in tiles (value) away from their city (since minors don't scout) when plotting danger values (stops excessive worker stealing)
#define MOD_AUI_DANGER_PLOTS_SHOULD_IGNORE_UNIT_MINORS_SEE_MAJORS (5)
/// Fixes bad code for visible barbarian units adding to "barbarian threat" value (affects CS)
// #define MOD_AUI_MILITARY_FIX_BARBARIAN_THREAT // serp: hm.. I dont think this is a fix, the original code makes more sense and with this AI is too passive against barbarians.
/// The AI will consider promises it made not to convert cities of a player when choosing a prophet conversion target
#define FIX_AUI_RELIGION_FIX_CHOOSE_PROPHET_CONVERSION_CITY_HONOR_NONCONVERT_PROMISE
/// Fixes Iroquois' UA so friendly forest tiles will now connect with road tiles!
#define FIX_AUI_UNIT_MOVEMENT_IROQUOIS_ROAD_TRANSITION_FIX
/// Fixes the code that checks for cramped status (it always triggered originally, now it only triggers if we really are cramped)
#define AUI_GS_CONQUEST_FIX_CRAMPED
/// Since Venice can purchase stuff at puppets, the function will no longer treat Venice's puppets as ordinary puppets
#define AUI_RELIGION_FIX_ARE_ALL_OUR_CITIES_HAVE_FAITH_BUILDING_VENICE_PUPPETS
/// Puppet cities and cities with automated production will no longer accidentally trigger the production notification
#define AUI_CITY_FIX_PUPPET_CHOOSE_PRODUCTION_NOTIFICATION
/// Makes UI combat prediction more representative of the actual combat that will take place when combat would tie
#define AUI_GAME_FIX_COMBAT_PREDICTION_ACCURATE_PREDICT_TIES
/// If a unit is dead, it cannot perform any mission (fixes cases where players could cause two missions to fire in multiplayer)
#define AUI_UNIT_MISSION_FIX_NO_MISSION_ON_DEATH
/// serp: added to "GAMEEVENT_BarbariansSpawnedUnit" iUnit, a unit ID to identify the new barbarian unit and CampX und CampY, to alwasy know the plot where the camp is
/// Added game option Chilled Barbarians from CP mod. needs the gameoption added in xml/sql, did it in custommodoptions.xml
/// this will also make newly spanwed camps spawn an extra unit, if the option is not enabled
/// if enabled, the max camps are only 2/3 and the unti spawn rate is halfed
#define GAMEOPTION_CHILL_BARBARIANS			"GAMEOPTION_CHILL_BARBARIANS"
/// Automated workers do not care about the build time or cost of scrubbing fallout
#define AUI_WORKER_FIX_FALLOUT
/// Resets the UnitLoop iterator before looping through units (would otherwise cause problems when both land and sea exploration was in the "enough" state)
#define AUI_ECONOMIC_FIX_DO_RECON_STATE_ITERATOR
/// UnitProcessed() function will now only execute if the unit has no moves remaining, allowing units with blitz to execute multiple moves each turn
#define AUI_TACTICAL_FIX_UNIT_PROCESSED_BLITZ
/// Fixes poor placement of ranged units with a range of 1 (eg. machine guns)
#define AUI_TACTICAL_FIX_CLOSE_ON_TARGET_MELEE_RANGE
/// AI smart v3 , I think it is also responsible for high turn duration in lategame. there is some event that starts from one turn to another, that turn duration is *4 . without smart_ai loading the same savegame, the problem is gone.
/// in MOD_AI_SMART_V3 in CvTactivalAI.cpp I commented out the "Don't pull melee units out of camps to attack." part, because for some reaon it made the opposite, many camps are emtpy because of this (according to tests)
// Positive Strategic Ressource combat multiplier, by Serp. Up to 50% combat bonus, if you have 4 times the required number in stock.
#define MOD_POSITIVE_STRAT_COMBAT						gCustomMods.isPOSITIVE_STRAT_COMBAT()
// Event sent prior to making a savegame, used this method: https://forums.civfanatics.com/threads/tablesaverloader-for-persisting-lua-table-data-through-game-save-load.442249/
//   GameEvents.PreSaveEvent.Add(function(bIsSaveGame,bIsAutosave,bIsQuickSave,bIsReplaySave) end)
#define MOD_EVENTS_PRE_SAVE_EVENT				gCustomMods.isEVENTS_PRE_SAVE_EVENT()
/// Better Barbarian-camp spawn code, own idea, but community patch already implemented it the same way, so code taken and adjusted from there. (and barbs wont move directly after spawning)
#define MOD_BETTER_BARBCAMP_SPAWNCODE
/// if enabled, do many customlogs during GAMEEVENTINVOKE_HOOK and so on, to find out cause of freeze caused by this/Lock
#define MOD_DEBUG_GAMEHOOKS				gCustomMods.isDEBUG_GAMEHOOKS()
// add fast checks for beliefs, if they at all change specific yields, without the need to iterate for every single belief over every single plot to check for it -.- this should speed up AI turns while they choose beliefs significantly (ScoreBelief).
#define MOD_IMPROVE_BELIEF_CODE_TO_CHECK_IF_PLOT_RELEVANT
// adds more improvement placement restrictions, like RequiresHills and RequiresAdjacentCity (we add this, so we can disable the EVENTS_PLOT from whoward, because they are really really heavily send)
#define MOD_MORE_IMPROVEMENT_PLACESTYLES
// incoorperates my mod Level Promotions into DLL and assign the promotion PROM_UNLOCK_LVL_2/3/4 at levelup.
#define MOD_LEVEL_PROMOTIONS				gCustomMods.isLEVEL_PROMOTIONS()

////////////////////////

#endif // ACHIEVEMENT_HACKS


//
// MOD_PROMOTIONS_XYZ changes manage/grant the promotions and may affect the game saving code
// MOD_PATHFINDER_XYZ changes only affect the path finding code so can be disabled if necessary
//

#if defined(MOD_PROMOTIONS_CROSS_MOUNTAINS)
#define MOD_PATHFINDER_CROSS_MOUNTAINS         MOD_PROMOTIONS_CROSS_MOUNTAINS
#endif
#if defined(MOD_PROMOTIONS_CROSS_OCEANS)
#define MOD_PATHFINDER_CROSS_OCEANS            MOD_PROMOTIONS_CROSS_OCEANS
#endif
#if defined(MOD_PROMOTIONS_CROSS_ICE)
#define MOD_PATHFINDER_CROSS_ICE               MOD_PROMOTIONS_CROSS_ICE
#endif
#if defined(MOD_PROMOTIONS_DEEP_WATER_EMBARKATION)
#define MOD_PATHFINDER_DEEP_WATER_EMBARKATION  MOD_PROMOTIONS_DEEP_WATER_EMBARKATION
#endif

// ONLY CHANGE THIS IF YOU TRULY KNOW WHAT YOU ARE DOING IN THE PATHFINDER CODE!!!
#if defined(MOD_PATHFINDER_CROSS_ICE) || defined(MOD_PATHFINDER_DEEP_WATER_EMBARKATION)
#define MOD_PATHFINDER_TERRAFIRMA
#endif


//
// NOTHING BELOW HERE SHOULD NEED CHANGING
//

// Terraforming event types
enum TerraformingEventTypes {
	NO_TERRAFORMINGEVENT = -1,
	TERRAFORMINGEVENT_LOAD,
	TERRAFORMINGEVENT_AREA,
	TERRAFORMINGEVENT_LANDMASS,
	TERRAFORMINGEVENT_CONTINENT,
	TERRAFORMINGEVENT_PLOT,
	TERRAFORMINGEVENT_TERRAIN,
	TERRAFORMINGEVENT_FEATURE,
	TERRAFORMINGEVENT_RIVER,
	TERRAFORMINGEVENT_CITY,
	NUM_TERRAFORMINGEVENT_TYPES
};


// Player diplomacy and military event loggers
#if defined(MOD_API_PLAYER_LOGS)
#define DIPLOMACYLOG(eForPlayer, sMessage, eFromPlayer, eDiploUIState, eDiploMessage)                  \
	if (MOD_API_PLAYER_LOGS) {                                                                          \
		GET_PLAYER(eForPlayer).AddDiplomacyEvent(sMessage, eFromPlayer, eDiploUIState, eDiploMessage); \
CUSTOMLOG("DiploLog: For=%i, From=%i, Dstate=%i, Dmsg=%i - %s", eForPlayer, eFromPlayer, eDiploUIState, eDiploMessage, sMessage);\
	}
#define MILITARYLOG(eForPlayer, sMessage, pPlot, eOtherPlayer)                  \
	if (MOD_API_PLAYER_LOGS) {                                                  \
		GET_PLAYER(eForPlayer).AddMilitaryEvent(sMessage, pPlot, eOtherPlayer); \
	}
#else
#define DIPLOMACYLOG(eForPlayer, sMessage, eOtherPlayer, eDiploUIState, eDiploMessage)  __noop
#define MILITARYLOG(eForPlayer, sMessage, pPlot, eOtherPlayer)                          __noop
#endif


// Battle event macros
enum BattleTypeTypes
{
	BATTLE_TYPE_MELEE,
	BATTLE_TYPE_RANGED,
	BATTLE_TYPE_AIR,
	BATTLE_TYPE_SWEEP,
	BATTLE_TYPE_PARADROP,
	BATTLE_TYPE_NUKE
};

#if defined(MOD_EVENTS_BATTLES)
#define BATTLE_STARTED(iType, pPlot)              if (MOD_EVENTS_BATTLES) { GAMEEVENTINVOKE_HOOK(GAMEEVENT_BattleStarted, iType, pPlot.getX(), pPlot.getY()); }
#define BATTLE_JOINED(pCombatant, iRole, bIsCity) if (MOD_EVENTS_BATTLES && pCombatant) { GAMEEVENTINVOKE_HOOK(GAMEEVENT_BattleJoined, (pCombatant)->getOwner(), (pCombatant)->GetID(), iRole, bIsCity); }
#define BATTLE_FINISHED()                         if (MOD_EVENTS_BATTLES) { GAMEEVENTINVOKE_HOOK(GAMEEVENT_BattleFinished); }
#else
#define BATTLE_STARTED(pPlot)            __noop
#define BATTLE_JOINED(pCombatant, iRole) __noop
#define BATTLE_FINISHED()                __noop
#endif


// Custom mod logger
#if defined(CUSTOMLOGDEBUG)
#if defined(CUSTOMLOGFILEINFO) && defined(CUSTOMLOGFUNCINFO)
#define CUSTOMLOG(sFmt, ...) {																					\
	CvString sMsg; CvString::format(sMsg, sFmt, __VA_ARGS__);													\
	CvString sLine; CvString::format(sLine, "%s[%i]: %s - %s", __FILE__, __LINE__, __FUNCTION__, sMsg.c_str());	\
	LOGFILEMGR.GetLog(CUSTOMLOGDEBUG, FILogFile::kDontTimeStamp)->Msg(sLine.c_str());							\
}
#endif
#if defined(CUSTOMLOGFILEINFO) && !defined(CUSTOMLOGFUNCINFO)
#define CUSTOMLOG(sFmt, ...) {																					\
	CvString sMsg; CvString::format(sMsg, sFmt, __VA_ARGS__);													\
	CvString sLine; CvString::format(sLine, "%s[%i] - %s", __FILE__, __LINE__, sMsg.c_str());					\
	LOGFILEMGR.GetLog(CUSTOMLOGDEBUG, FILogFile::kDontTimeStamp)->Msg(sLine.c_str());							\
}
#endif
#if !defined(CUSTOMLOGFILEINFO) && defined(CUSTOMLOGFUNCINFO)
#define CUSTOMLOG(sFmt, ...) {																					\
	CvString sMsg; CvString::format(sMsg, sFmt, __VA_ARGS__);													\
	CvString sLine; CvString::format(sLine, "%s - %s", __FUNCTION__, sMsg.c_str());								\
	LOGFILEMGR.GetLog(CUSTOMLOGDEBUG, FILogFile::kDontTimeStamp)->Msg(sLine.c_str());							\
}
#endif
#if !defined(CUSTOMLOGFILEINFO) && !defined(CUSTOMLOGFUNCINFO)
#define CUSTOMLOG(sFmt, ...) {																					\
	CvString sMsg; CvString::format(sMsg, sFmt, __VA_ARGS__);													\
	LOGFILEMGR.GetLog(CUSTOMLOGDEBUG, FILogFile::kDontTimeStamp)->Msg(sMsg.c_str());							\
}
#endif
#else
#define CUSTOMLOG(sFmt, ...) __noop
#endif

// Unified yields logger
#if defined(UNIFIEDLOGDEBUG)
#define UNIFIEDLOG(sFmt, ...) {																		\
	CvString sMsg; CvString::format(sMsg, sFmt, __VA_ARGS__);										\
	CvString sLine; CvString::format(sLine, "%s[%i] - %s", __FILE__, __LINE__, sMsg.c_str());	    \
	LOGFILEMGR.GetLog(UNIFIEDLOGDEBUG, FILogFile::kDontTimeStamp)->Msg(sLine.c_str());			    \
}
#else
#define UNIFIEDLOG(sFmt, ...) __noop
#endif


// Message wrappers
#define SHOW_PLAYER_MESSAGE(pPlayer, szMessage)       DLLUI->AddMessage(0, pPlayer->GetID(), false, GC.getEVENT_MESSAGE_TIME(), szMessage)
#define SHOW_CITY_MESSAGE(pCity, ePlayer, szMessage)  DLLUI->AddCityMessage(0, pCity->GetIDInfo(), ePlayer, false, GC.getEVENT_MESSAGE_TIME(), szMessage)
#define SHOW_UNIT_MESSAGE(pUnit, ePlayer, szMessage)  DLLUI->AddUnitMessage(0, pUnit->GetIDInfo(), ePlayer, false, GC.getEVENT_MESSAGE_TIME(), szMessage)
#define SHOW_PLOT_MESSAGE(pPlot, ePlayer, szMessage)  DLLUI->AddPlotMessage(0, pPlot->GetPlotIndex(), ePlayer, false, GC.getEVENT_MESSAGE_TIME(), szMessage)
#define SHOW_PLOT_POPUP(pPlot, ePlayer, szMessage, fDelay)  pPlot->showPopupText(ePlayer, szMessage)


// GlobalDefines wrappers
#define GD_INT_DECL(name)         int m_i##name
#define GD_INT_DEF(name)          inline int get##name() { return m_i##name; }
#define GD_INT_INIT(name, def)    m_i##name(def)
#define GD_INT_CACHE(name)        m_i##name = getDefineINT(#name); CUSTOMLOG("<Defines>: %s = %i", #name, m_i##name)
#define GD_INT_GET(name)          GC.get##name()

#define GD_FLOAT_DECL(name)       float m_f##name
#define GD_FLOAT_DEF(name)        inline float get##name() { return m_f##name; }
#define GD_FLOAT_INIT(name, def)  m_f##name(def)
#define GD_FLOAT_CACHE(name)      m_f##name = getDefineFLOAT(#name); CUSTOMLOG("<Defines>: %s = %f", #name, m_f##name)
#define GD_FLOAT_GET(name)        GC.get##name()


// LUA API wrappers
#define LUAAPIEXTN(method, type, ...) static int l##method(lua_State* L)
#define LUAAPIIMPL(object, method) int CvLua##object::l##method(lua_State* L) { return BasicLuaMethod(L, &Cv##object::##method); }
#define LUAAPIINLINE(method, hasMethod, type) inline bool method() const { return hasMethod(type); }


// Game Event wrappers
#include "Lua\CvLuaSupport.h"
#define GAMEEVENTINVOKE_HOOK    gCustomMods.eventHook
#define GAMEEVENTINVOKE_TESTANY gCustomMods.eventTestAny
#define GAMEEVENTINVOKE_TESTALL gCustomMods.eventTestAll
#define GAMEEVENTINVOKE_VALUE   gCustomMods.eventAccumulator

#define GAMEEVENTRETURN_NONE  -1
#define GAMEEVENTRETURN_FALSE  0
#define GAMEEVENTRETURN_TRUE   1
#define GAMEEVENTRETURN_HOOK   GAMEEVENTRETURN_TRUE
#define GAMEEVENTRETURN_VALUE  GAMEEVENTRETURN_TRUE

// Pairs of event names and (optional) parameter types
//    iii means three int params
//    ibi means an int, then a bool, then a final int
//    s means a string (char*) and is only allowed as the last parameter
#define GAMEEVENT_AiOverrideChooseNextTech		"AiOverrideChooseNextTech",		"ib"
#define GAMEEVENT_AreaCanHaveAnyResource		"AreaCanHaveAnyResource",		"ii"
#define GAMEEVENT_BarbariansCanFoundCamp		"BarbariansCanFoundCamp",		"ii"
#define GAMEEVENT_BarbariansCampFounded			"BarbariansCampFounded",		"ii"
#define GAMEEVENT_BarbariansCampCleared			"BarbariansCampCleared",		"iii"
#define GAMEEVENT_BarbariansCampCanSpawnUnit	"BarbariansCampCanSpawnUnit",	"ii"
#define GAMEEVENT_BarbariansCampGetSpawnUnit	"BarbariansCampGetSpawnUnit",	"iii"
#define GAMEEVENT_BarbariansSpawnedUnit			"BarbariansSpawnedUnit",		"iiiiii"
#define GAMEEVENT_BattleDamageDelta				"BattleDamageDelta",			"ii"
#define GAMEEVENT_BattleFinished				"BattleFinished",				""
#define GAMEEVENT_BattleJoined					"BattleJoined",					"iiib"
#define GAMEEVENT_BattleStarted					"BattleStarted",				"iii"
#define GAMEEVENT_CanAirliftFrom				"CanAirliftFrom",				"iiii"
#define GAMEEVENT_CanAirliftTo					"CanAirliftTo",					"iiii"
#define GAMEEVENT_CanDoCommand					"CanDoCommand",					"iiiiiiib"
#define GAMEEVENT_CanHaveAnyUpgrade				"CanHaveAnyUpgrade",			"ii"
#define GAMEEVENT_CanHavePromotion				"CanHavePromotion",				"iii"
#define GAMEEVENT_CanHaveUpgrade				"CanHaveUpgrade",				"iiii"
#define GAMEEVENT_CanLoadAt						"CanLoadAt",					"iiii"
#define GAMEEVENT_CanMoveInto					"CanMoveInto",					"iiiibb"
#define GAMEEVENT_CannotParadropFrom			"CannotParadropFrom",			"iiii"
#define GAMEEVENT_CanParadropFrom				"CanParadropFrom",				"iiii"
#define GAMEEVENT_CanRebaseInCity				"CanRebaseInCity",				"iiii"
#define GAMEEVENT_CanRebaseTo					"CanRebaseTo",					"iiiib"
#define GAMEEVENT_CapitalChanged				"CapitalChanged",				"iii"
#define GAMEEVENT_CircumnavigatedGlobe			"CircumnavigatedGlobe",			"i"
#define GAMEEVENT_CityBoughtPlot				"CityBoughtPlot",				"iiiibb"
#define GAMEEVENT_CityCanAcquirePlot			"CityCanAcquirePlot",			"iiii"
#define GAMEEVENT_CityCanAirlift				"CityCanAirlift",				"ii"
#define GAMEEVENT_CityConnected					"CityConnected",				"iiiiib"
#define GAMEEVENT_CityConnections				"CityConnections",				"ib"
#define GAMEEVENT_CityConstructed				"CityConstructed",				"iiibb"
#define GAMEEVENT_CityCreated					"CityCreated",					"iiibb"
#define GAMEEVENT_CityPrepared					"CityPrepared",					"iiibb"
#define GAMEEVENT_CitySoldBuilding				"CitySoldBuilding",				"iii"
#define GAMEEVENT_CityTrained					"CityTrained",					"iiibb"
#define GAMEEVENT_CustomMissionCompleted		"CustomMissionCompleted",		"iiiiiii"
#define GAMEEVENT_CustomMissionCameraTime		"CustomMissionCameraTime",		"iiiiiii"
#define GAMEEVENT_CustomMissionDoStep			"CustomMissionDoStep",			"iiiiiii"
#define GAMEEVENT_CustomMissionPossible			"CustomMissionPossible",		"iiiiiiiiib"
#define GAMEEVENT_CustomMissionStart			"CustomMissionStart",			"iiiiiii"
#define GAMEEVENT_CustomMissionSetActivity		"CustomMissionSetActivity",		"iiiiiii"
#define GAMEEVENT_CustomMissionTargetPlot		"CustomMissionTargetPlot",		"iiiiiii"
#define GAMEEVENT_CustomMissionTimerInc			"CustomMissionTimerInc",		"iiiiiii"
#define GAMEEVENT_DeclareWar					"DeclareWar",					"iib"
#define GAMEEVENT_DiplomacyStfu					"DiplomacyStfu",				"iiiiii"
#define GAMEEVENT_DiplomacyStfuLeaveLeader		"DiplomacyStfuLeaveLeader",		"i"
#define GAMEEVENT_EspionageCanMoveSpyTo			"EspionageCanMoveSpyTo",		"iii"
#define GAMEEVENT_EspionageCanStageCoup			"EspionageCanStageCoup",		"iii"
#define GAMEEVENT_EspionageResult				"EspionageResult",				"iiiii"
#define GAMEEVENT_EspionageState				"EspionageState",				"iiiii"
#define GAMEEVENT_GetDiploModifier				"GetDiploModifier",				"iii"
#define GAMEEVENT_GetBombardRange				"GetBombardRange",				"ii"
#define GAMEEVENT_GetReligionToFound			"GetReligionToFound",			"iib"
#define GAMEEVENT_GoodyHutCanNotReceive			"GoodyHutCanNotReceive",		"iiib"
#define GAMEEVENT_GoodyHutReceivedBonus			"GoodyHutReceivedBonus",		"iiiii"
#define GAMEEVENT_GoodyHutCanResearch			"GoodyHutCanResearch",			"ii"
#define GAMEEVENT_GoodyHutTechResearched		"GoodyHutTechResearched",		"ii"
#define GAMEEVENT_GreatPersonExpended			"GreatPersonExpended",			"iiiii"
#define GAMEEVENT_IsAbleToDeclareWar			"IsAbleToDeclareWar",			"ii"
#define GAMEEVENT_IsAbleToMakePeace				"IsAbleToMakePeace",			"ii"
#define GAMEEVENT_MakePeace						"MakePeace",					"iib"
#define GAMEEVENT_MinorAlliesChanged			"MinorAlliesChanged",			"iibii"
#define GAMEEVENT_MinorFriendsChanged			"MinorFriendsChanged",			"iibii"
#define GAMEEVENT_MinorGift						"MinorGift",					"iiiiibbs"
#define GAMEEVENT_NaturalWonderDiscovered		"NaturalWonderDiscovered",		"iiiibii"
#define GAMEEVENT_NuclearDetonation				"NuclearDetonation",			"iiibb"
#define GAMEEVENT_PantheonFounded				"PantheonFounded",				"iiii"
#define GAMEEVENT_ParadropAt					"ParadropAt",					"iiiiii"
#define GAMEEVENT_PlaceResource					"PlaceResource",				"iiiii"
#define GAMEEVENT_PlayerBoughtOut				"PlayerBoughtOut",				"ii"
#define GAMEEVENT_PlayerBuilding				"PlayerBuilding",				"iiiiib"
#define GAMEEVENT_PlayerBuilt					"PlayerBuilt",					"iiiii"
#define GAMEEVENT_PlayerBullied					"PlayerBullied",				"iiiiii"
#define GAMEEVENT_PlayerCanAdoptIdeology		"PlayerCanAdoptIdeology",		"ii"
#define GAMEEVENT_PlayerCanAdoptTenet			"PlayerCanAdoptTenet",			"ii"
#define GAMEEVENT_PlayerCanBuild				"PlayerCanBuild",				"iiiii"
#define GAMEEVENT_PlayerCanBullyGold			"PlayerCanBullyGold",			"ii"
#define GAMEEVENT_PlayerCanBullyUnit			"PlayerCanBullyUnit",			"ii"
#define GAMEEVENT_PlayerCanBuyOut				"PlayerCanBuyOut",				"ii"
#define GAMEEVENT_PlayerCanCreateTradeRoute		"PlayerCanCreateTradeRoute",	"iiiiii"
#define GAMEEVENT_PlayerCanDeclareWar			"PlayerCanDeclareWar",			"ii"
#define GAMEEVENT_PlayerCanFoundCity			"PlayerCanFoundCity",			"iii"
#define GAMEEVENT_PlayerCanFoundCityRegardless	"PlayerCanFoundCityRegardless",	"iii"
#define GAMEEVENT_PlayerCanFoundPantheon		"PlayerCanFoundPantheon",		"i"
#define GAMEEVENT_PlayerCanFoundReligion		"PlayerCanFoundReligion",		"ii"
#define GAMEEVENT_PlayerCanGiftGold				"PlayerCanGiftGold",			"ii"
#define GAMEEVENT_PlayerCanGiftImprovement		"PlayerCanGiftImprovement",		"ii"
#define GAMEEVENT_PlayerCanGiftUnit				"PlayerCanGiftUnit",			"iii"
#define GAMEEVENT_PlayerCanHaveBelief			"PlayerCanHaveBelief",			"ii"
#define GAMEEVENT_PlayerCanLiberate				"PlayerCanLiberate",			"ii"
#define GAMEEVENT_PlayerCanMakePeace			"PlayerCanMakePeace",			"ii"
#define GAMEEVENT_PlayerCanPropose				"PlayerCanPropose",				"iiib"
#define GAMEEVENT_PlayerCanProtect				"PlayerCanProtect",				"ii"
#define GAMEEVENT_PlayerCanRaze					"PlayerCanRaze",				"ii"
#define GAMEEVENT_PlayerCanRemoveHeresy			"PlayerCanRemoveHeresy",		"iiii"
#define GAMEEVENT_PlayerCanRevoke				"PlayerCanRevoke",				"ii"
#define GAMEEVENT_PlayerCanSpreadReligion		"PlayerCanSpreadReligion",		"iiii"
#define GAMEEVENT_PlayerCanTransitMinorCity		"PlayerCanTransitMinorCity",	"iiiii"
#define GAMEEVENT_PlayerDoneTurn				"PlayerDoneTurn",				"i"
#define GAMEEVENT_PlayerGifted					"PlayerGifted",					"iiiiii"
#define GAMEEVENT_PlayerGoldenAge				"PlayerGoldenAge",				"ibi"
#define GAMEEVENT_PlayerLiberated				"PlayerLiberated",				"iii"
#define GAMEEVENT_PlayerPlunderedTradeRoute		"PlayerPlunderedTradeRoute",	"iiiiiiiii"
#define GAMEEVENT_PlayerProtected				"PlayerProtected",				"ii"
#define GAMEEVENT_PlayerRevoked					"PlayerRevoked",				"iib"
#define GAMEEVENT_PlotCanImprove				"PlotCanImprove",				"iii"
#define GAMEEVENT_QuestContestValue				"QuestContestValue",			"iii"
#define GAMEEVENT_QuestGetData					"QuestGetData",					"iiib"
#define GAMEEVENT_QuestIsAvailable				"QuestIsAvailable",				"iiibii"
#define GAMEEVENT_QuestIsCompleted				"QuestIsCompleted",				"iiib"
#define GAMEEVENT_QuestIsExpired				"QuestIsExpired",				"iii"
#define GAMEEVENT_QuestIsRevoked				"QuestIsRevoked",				"iii"
#define GAMEEVENT_QuestSendNotification			"QuestSendNotification",		"iiiiiiibbs"
#define GAMEEVENT_QuestStart					"QuestStart",					"iiibiii"
#define GAMEEVENT_RebaseTo						"RebaseTo",						"iiii"
#define GAMEEVENT_ReligionCanHaveBelief			"ReligionCanHaveBelief",		"iii"
#define GAMEEVENT_ReligionEnhanced				"ReligionEnhanced",				"iiii"
#define GAMEEVENT_ReligionFounded				"ReligionFounded",				"iiiiiiii"
#define GAMEEVENT_ReligionReformed				"ReligionReformed",				"iiiiiii"
#define GAMEEVENT_ResolutionProposing			"ResolutionProposing",			"ii"
#define GAMEEVENT_ResolutionResult				"ResolutionResult",				"iibb"
#define GAMEEVENT_ResolutionVoting				"ResolutionVoting",				"ii"
#define GAMEEVENT_TeamSetEra					"TeamSetEra",					"iib"
#define GAMEEVENT_TerraformingMap				"TerraformingMap",				"ii"
#define GAMEEVENT_TerraformingPlot				"TerraformingPlot",				"iiiiiiii"
#define GAMEEVENT_TileFeatureChanged			"TileFeatureChanged",			"iiiii"
#define GAMEEVENT_TileImprovementChanged		"TileImprovementChanged",		"iiiiib"
#define GAMEEVENT_TileOwnershipChanged			"TileOwnershipChanged",			"iiii"
#define GAMEEVENT_TileRevealed					"TileRevealed",					"iiiibii"
#define GAMEEVENT_TileRouteChanged				"TileRouteChanged",				"iiiiib"
#define GAMEEVENT_UiDiploEvent					"UiDiploEvent",					"iiii"
#define GAMEEVENT_UnitCanFollowupFrom			"UnitCanFollowupFrom",			"iiiiiii"
#define GAMEEVENT_UnitCanHaveAnyUpgrade			"UnitCanHaveAnyUpgrade",		"ii"
#define GAMEEVENT_UnitCanHaveGreatWork			"UnitCanHaveGreatWork",			"iii"
#define GAMEEVENT_UnitCanHaveName				"UnitCanHaveName",				"iii"
#define GAMEEVENT_UnitCanHavePromotion			"UnitCanHavePromotion",			"iii"
#define GAMEEVENT_UnitCanHaveUpgrade			"UnitCanHaveUpgrade",			"iiii"
#define GAMEEVENT_UnitCanPillage				"UnitCanPillage",				"iiii"
#define GAMEEVENT_UnitCanRangeAttackAt			"UnitCanRangeAttackAt",			"iiiib"
#define GAMEEVENT_UnitCanTransitMinorCity		"UnitCanTransitMinorCity",		"iiiiii"
#define GAMEEVENT_UnitCaptured					"UnitCaptured",					"iiiibi"
#define GAMEEVENT_UnitCaptureType				"UnitCaptureType",				"iiii"
#define GAMEEVENT_UnitCityFounded				"UnitCityFounded",				"iiiii"
#define GAMEEVENT_UnitCreated					"UnitCreated",					"iiiii"
#define GAMEEVENT_UnitPillageGold				"UnitPillageGold",				"iiii"
#define GAMEEVENT_UnitPrekill					"UnitPrekill",					"iiiiibi"
#define GAMEEVENT_UnitPromoted					"UnitPromoted",					"iii"
#define GAMEEVENT_UnitRangeAttackAt				"UnitRangeAttackAt",			"iiii"
#define GAMEEVENT_UnitUpgraded					"UnitUpgraded",					"iiib"

// Added by Serp
#define GAMEEVENT_VisibilityCountChanged		"VisibilityCountChanged",		"iiibbiiii"
#define GAMEEVENT_PreSaveEvent					"PreSaveEvent",					""

// Serialization wrappers
#define MOD_SERIALIZE

#if defined(MOD_SERIALIZE)
#define MOD_SERIALIZE_INIT_READ(stream) uint uiDllSaveVersion; stream >> uiDllSaveVersion
#define MOD_SERIALIZE_READ(version, stream, member, def) if (uiDllSaveVersion >= version) { stream >> member; } else { member = def; }
#define MOD_SERIALIZE_READ_AUTO(version, stream, member, size, def)   \
	if (uiDllSaveVersion >= version) {                                \
		stream >> member;                                             \
	} else {                                                          \
		for (int iI = 0; iI < size; iI++) { member.setAt(iI, def); }  \
	}
#define MOD_SERIALIZE_READ_ARRAY(version, stream, member, type, size, def)	\
	if (uiDllSaveVersion >= version) {										\
		ArrayWrapper<type> wrapper(size, member); stream >> wrapper;		\
	} else {																\
		for (int iI = 0; iI < size; iI++) { (member)[iI] = def; }			\
	}
#define MOD_SERIALIZE_READ_HASH(version, stream, member, type, size, def)		\
	if (uiDllSaveVersion >= version) {											\
		CvInfosSerializationHelper::ReadHashedDataArray(stream, member, size);	\
	} else {																	\
		for (int iI = 0; iI < size; iI++) { (member)[iI] = def; }				\
	}
#define MOD_SERIALIZE_INIT_WRITE(stream) uint uiDllSaveVersion = MOD_DLL_VERSION_NUMBER; stream << uiDllSaveVersion
#define MOD_SERIALIZE_WRITE(stream, member) CvAssert(uiDllSaveVersion == MOD_DLL_VERSION_NUMBER); stream << member
#define MOD_SERIALIZE_WRITE_AUTO(stream, member) CvAssert(uiDllSaveVersion == MOD_DLL_VERSION_NUMBER); stream << member
#define MOD_SERIALIZE_WRITE_ARRAY(stream, member, type, size) CvAssert(uiDllSaveVersion == MOD_DLL_VERSION_NUMBER); stream << ArrayWrapper<type>(size, member)
#define MOD_SERIALIZE_WRITE_CONSTARRAY(stream, member, type, size) CvAssert(uiDllSaveVersion == MOD_DLL_VERSION_NUMBER); stream << ArrayWrapperConst<type>(size, member)
#define MOD_SERIALIZE_WRITE_HASH(stream, member, type, size, obj) CvAssert(uiDllSaveVersion == MOD_DLL_VERSION_NUMBER); CvInfosSerializationHelper::WriteHashedDataArray<obj, type>(stream, member, size)
#else
#define MOD_SERIALIZE_INIT_READ(stream) __noop
#define MOD_SERIALIZE_READ(version, stream, member, def) __noop
#define MOD_SERIALIZE_READ_AUTO(version, stream, member, size, def) __noop
#define MOD_SERIALIZE_READ_ARRAY(version, stream, member, type, size, def) __noop
#define MOD_SERIALIZE_READ_HASH(version, stream, member, type, size, def) __noop
#define MOD_SERIALIZE_INIT_WRITE(stream) __noop
#define MOD_SERIALIZE_WRITE(stream, member) __noop
#define MOD_SERIALIZE_WRITE_AUTO(stream, member) __noop
#define MOD_SERIALIZE_WRITE_ARRAY(stream, member, type, size) __noop
#define MOD_SERIALIZE_WRITE_ARRAYCONST(stream, member, type, size) __noop
#define MOD_SERIALIZE_WRITE_HASH(stream, member, type, size) __noop
#endif


// Custom database table name and columns
#define MOD_DB_TABLE "CustomModOptions"
#define MOD_DB_COL_NAME "Name"
#define MOD_DB_COL_VALUE "Value"
#define MOD_DB_COL_CLASS "Class"
#define MOD_DB_COL_DBUPDATES "DbUpdates"
#define MOD_DB_UPDATES "CustomModDbUpdates"


// CustomMod option wrappers
#define MOD_OPT_DECL(name)  protected: bool m_b##name; public: inline bool is##name() { return m_b##name; }
#define MOD_OPT_CACHE(name) m_b##name = (m_options[string(#name)] == 1);


// Class used to cache the database control settings and provide utility functions
class CustomMods {
public:
	CustomMods();

	int eventHook(const char* szName, const char* p, ...);
	int eventTestAll(const char* szName, const char* p, ...);
	int eventTestAny(const char* szName, const char* p, ...);
	int eventAccumulator(int& iValue, const char* szName, const char* p, ...);

	// CvLuaArgsHandle in the next four methos MUST be passed by reference (&args)
	int eventHook(const char* szName, CvLuaArgsHandle &args);
	int eventTestAll(const char* szName, CvLuaArgsHandle &args);
	int eventTestAny(const char* szName, CvLuaArgsHandle &args);
	int eventAccumulator(int& iValue, const char* szName, CvLuaArgsHandle &args);

	void prefetchCache();
	void preloadCache();
	void reloadCache();
	int getOption(const char* szName, int defValue = 0);
	int getOption(std::string sName, int defValue = 0);
	int getCivOption(const char* szCiv, const char* szName, int defValue = 0);

	MOD_OPT_DECL(GLOBAL_EARLY_COOP_WAR_LOCK);
	MOD_OPT_DECL(GLOBAL_STACKING_RULES);
	MOD_OPT_DECL(GLOBAL_BREAK_CIVILIAN_1UPT);
	MOD_OPT_DECL(GLOBAL_BREAK_CIVILIAN_RESTRICTIONS);
	MOD_OPT_DECL(GLOBAL_LOCAL_GENERALS);
	MOD_OPT_DECL(GLOBAL_SEPARATE_GREAT_ADMIRAL);
	MOD_OPT_DECL(GLOBAL_PROMOTION_CLASSES);
	MOD_OPT_DECL(GLOBAL_PASSABLE_FORTS);
	MOD_OPT_DECL(GLOBAL_PASSABLE_FORTS_ANY);
	MOD_OPT_DECL(GLOBAL_ANYTIME_GOODY_GOLD);
	MOD_OPT_DECL(GLOBAL_CITY_FOREST_BONUS);
	MOD_OPT_DECL(GLOBAL_CITY_JUNGLE_BONUS);
	MOD_OPT_DECL(GLOBAL_CITY_WORKING);
	MOD_OPT_DECL(GLOBAL_CITY_AUTOMATON_WORKERS);
	MOD_OPT_DECL(GLOBAL_RELOCATION);
	MOD_OPT_DECL(GLOBAL_ALPINE_PASSES);
	MOD_OPT_DECL(GLOBAL_CS_GIFT_SHIPS);
	MOD_OPT_DECL(GLOBAL_CS_UPGRADES);
	MOD_OPT_DECL(GLOBAL_CS_RAZE_RARELY);
	MOD_OPT_DECL(GLOBAL_CS_LIBERATE_AFTER_BUYOUT);
	MOD_OPT_DECL(GLOBAL_CS_GIFTS);
	MOD_OPT_DECL(GLOBAL_CS_GIFTS_LOCAL_XP);
	MOD_OPT_DECL(GLOBAL_CS_OVERSEAS_TERRITORY);
	MOD_OPT_DECL(GLOBAL_CS_NO_ALLIED_SKIRMISHES);
	MOD_OPT_DECL(GLOBAL_VENICE_KEEPS_RESOURCES);
	MOD_OPT_DECL(GLOBAL_CS_MARRIAGE_KEEPS_RESOURCES);
	MOD_OPT_DECL(GLOBAL_NO_FOLLOWUP);
	MOD_OPT_DECL(GLOBAL_NO_FOLLOWUP_FROM_CITIES);
	MOD_OPT_DECL(GLOBAL_CAPTURE_AFTER_ATTACKING);
	MOD_OPT_DECL(GLOBAL_NO_OCEAN_PLUNDERING);
	MOD_OPT_DECL(GLOBAL_NO_CONQUERED_SPACESHIPS);
	MOD_OPT_DECL(GLOBAL_ADJACENT_BLOCKADES);
	MOD_OPT_DECL(GLOBAL_ALLIES_BLOCK_BLOCKADES);
	MOD_OPT_DECL(GLOBAL_SHORT_EMBARKED_BLOCKADES);
	MOD_OPT_DECL(GLOBAL_GRATEFUL_SETTLERS);
	MOD_OPT_DECL(GLOBAL_RELIGIOUS_SETTLERS);
	MOD_OPT_DECL(GLOBAL_QUICK_ROUTES);
	MOD_OPT_DECL(GLOBAL_SUBS_UNDER_ICE_IMMUNITY);
	MOD_OPT_DECL(GLOBAL_PARATROOPS_MOVEMENT);
	MOD_OPT_DECL(GLOBAL_PARATROOPS_AA_DAMAGE);
	MOD_OPT_DECL(GLOBAL_NUKES_MELT_ICE); 
	MOD_OPT_DECL(GLOBAL_GREATWORK_YIELDTYPES); 
	MOD_OPT_DECL(GLOBAL_NO_LOST_GREATWORKS); 
	MOD_OPT_DECL(GLOBAL_EXCLUDE_FROM_GIFTS);
	MOD_OPT_DECL(GLOBAL_MOVE_AFTER_UPGRADE);
	MOD_OPT_DECL(GLOBAL_CANNOT_EMBARK);
	MOD_OPT_DECL(GLOBAL_SEPARATE_GP_COUNTERS);
	MOD_OPT_DECL(GLOBAL_TRULY_FREE_GP);
	
	MOD_OPT_DECL(DIPLOMACY_BY_NUMBERS);
	MOD_OPT_DECL(DIPLOMACY_TECH_BONUSES);
	MOD_OPT_DECL(DIPLOMACY_AUTO_DENOUNCE);
	MOD_OPT_DECL(DIPLOMACY_STFU);
	MOD_OPT_DECL(DIPLOMACY_NO_LEADERHEADS);
    
	MOD_OPT_DECL(TRAITS_GG_FROM_BARBARIANS);
	MOD_OPT_DECL(TRAITS_CROSSES_ICE);
	MOD_OPT_DECL(TRAITS_CITY_WORKING);
	MOD_OPT_DECL(TRAITS_CITY_AUTOMATON_WORKERS);
	MOD_OPT_DECL(TRAITS_OTHER_PREREQS);
	MOD_OPT_DECL(TRAITS_ANY_BELIEF);
	MOD_OPT_DECL(TRAITS_TRADE_ROUTE_BONUSES);
	MOD_OPT_DECL(TRAITS_EXTRA_SUPPLY);

	MOD_OPT_DECL(POLICIES_CITY_WORKING);
	MOD_OPT_DECL(POLICIES_CITY_AUTOMATON_WORKERS);

	MOD_OPT_DECL(TECHS_CITY_WORKING);
	MOD_OPT_DECL(TECHS_CITY_AUTOMATON_WORKERS);

	MOD_OPT_DECL(PROMOTIONS_AURA_CHANGE);
	MOD_OPT_DECL(PROMOTIONS_GG_FROM_BARBARIANS);
	MOD_OPT_DECL(PROMOTIONS_VARIABLE_RECON);
	MOD_OPT_DECL(PROMOTIONS_CROSS_MOUNTAINS);
	MOD_OPT_DECL(PROMOTIONS_CROSS_OCEANS);
	MOD_OPT_DECL(PROMOTIONS_CROSS_ICE);
	MOD_OPT_DECL(PROMOTIONS_HALF_MOVE);
	MOD_OPT_DECL(PROMOTIONS_DEEP_WATER_EMBARKATION);
	MOD_OPT_DECL(PROMOTIONS_FLAGSHIP);
	MOD_OPT_DECL(PROMOTIONS_UNIT_NAMING);
	MOD_OPT_DECL(PROMOTIONS_IMPROVEMENT_BONUS);

	MOD_OPT_DECL(UI_CITY_PRODUCTION);
	MOD_OPT_DECL(UI_CITY_EXPANSION);

	MOD_OPT_DECL(BUILDINGS_NW_EXCLUDE_RAZING);
	MOD_OPT_DECL(BUILDINGS_PRO_RATA_PURCHASE);
	MOD_OPT_DECL(BUILDINGS_CITY_WORKING);
	MOD_OPT_DECL(BUILDINGS_CITY_AUTOMATON_WORKERS);

	MOD_OPT_DECL(TRADE_ROUTE_SCALING);
	MOD_OPT_DECL(TRADE_WONDER_RESOURCE_ROUTES);

	MOD_OPT_DECL(UNITS_NO_SUPPLY);
	MOD_OPT_DECL(UNITS_MAX_HP);
	MOD_OPT_DECL(UNITS_XP_TIMES_100);
	MOD_OPT_DECL(UNITS_LOCAL_WORKERS);
	MOD_OPT_DECL(UNITS_HOVERING_LAND_ONLY_HEAL);
	MOD_OPT_DECL(UNITS_HOVERING_COASTAL_ATTACKS);

	MOD_OPT_DECL(RELIGION_NO_PREFERRENCES);
	MOD_OPT_DECL(RELIGION_RANDOMISE);
	MOD_OPT_DECL(RELIGION_CONVERSION_MODIFIERS);
	MOD_OPT_DECL(RELIGION_KEEP_PROPHET_OVERFLOW);
	MOD_OPT_DECL(RELIGION_ALLIED_INQUISITORS);
	MOD_OPT_DECL(RELIGION_RECURRING_PURCHASE_NOTIFIY);
	MOD_OPT_DECL(RELIGION_PLOT_YIELDS);
	MOD_OPT_DECL(RELIGION_POLICY_BRANCH_FAITH_GP);
	MOD_OPT_DECL(RELIGION_LOCAL_RELIGIONS);

	MOD_OPT_DECL(PROCESS_STOCKPILE);

	MOD_OPT_DECL(AI_NO_ZERO_VALUE_TRADE_ITEMS);
	MOD_OPT_DECL(AI_SECONDARY_WORKERS);
	MOD_OPT_DECL(AI_SECONDARY_SETTLERS);
	MOD_OPT_DECL(AI_GREAT_PEOPLE_CHOICES);
	MOD_OPT_DECL(AI_MP_DIPLOMACY);
	MOD_OPT_DECL(AI_SMART_V3);

	MOD_OPT_DECL(EVENTS_TERRAFORMING);
	MOD_OPT_DECL(EVENTS_TILE_IMPROVEMENTS);
	MOD_OPT_DECL(EVENTS_TILE_REVEALED);
	MOD_OPT_DECL(EVENTS_CIRCUMNAVIGATION);
	MOD_OPT_DECL(EVENTS_NEW_ERA);
	MOD_OPT_DECL(EVENTS_NW_DISCOVERY);
	MOD_OPT_DECL(EVENTS_DIPLO_EVENTS);
	MOD_OPT_DECL(EVENTS_DIPLO_MODIFIERS);
	MOD_OPT_DECL(EVENTS_MINORS);
	MOD_OPT_DECL(EVENTS_MINORS_GIFTS);
	MOD_OPT_DECL(EVENTS_MINORS_INTERACTION);
	MOD_OPT_DECL(EVENTS_QUESTS);
	MOD_OPT_DECL(EVENTS_BARBARIANS);
	MOD_OPT_DECL(EVENTS_GOODY_CHOICE);
	MOD_OPT_DECL(EVENTS_GOODY_TECH);
	MOD_OPT_DECL(EVENTS_AI_OVERRIDE_TECH);
	MOD_OPT_DECL(EVENTS_GREAT_PEOPLE);
	MOD_OPT_DECL(EVENTS_FOUND_RELIGION);
	MOD_OPT_DECL(EVENTS_ACQUIRE_BELIEFS);
	MOD_OPT_DECL(EVENTS_RELIGION);
	MOD_OPT_DECL(EVENTS_ESPIONAGE);
	MOD_OPT_DECL(EVENTS_PLOT);
	MOD_OPT_DECL(EVENTS_PLAYER_TURN);
	MOD_OPT_DECL(EVENTS_GOLDEN_AGE);
	MOD_OPT_DECL(EVENTS_CITY);
	MOD_OPT_DECL(EVENTS_CITY_CAPITAL);
	MOD_OPT_DECL(EVENTS_CITY_BORDERS);
	MOD_OPT_DECL(EVENTS_LIBERATION);
	MOD_OPT_DECL(EVENTS_CITY_FOUNDING);
	MOD_OPT_DECL(EVENTS_CITY_RAZING);
	MOD_OPT_DECL(EVENTS_CITY_AIRLIFT);
	MOD_OPT_DECL(EVENTS_CITY_BOMBARD);
	MOD_OPT_DECL(EVENTS_CITY_CONNECTIONS);
	MOD_OPT_DECL(EVENTS_AREA_RESOURCES);
	MOD_OPT_DECL(EVENTS_PARADROPS);
	MOD_OPT_DECL(EVENTS_UNIT_RANGEATTACK);
	MOD_OPT_DECL(EVENTS_UNIT_CREATED);
	MOD_OPT_DECL(EVENTS_UNIT_FOUNDED);
	MOD_OPT_DECL(EVENTS_UNIT_PREKILL);
	MOD_OPT_DECL(EVENTS_UNIT_CAPTURE);
	MOD_OPT_DECL(EVENTS_CAN_MOVE_INTO);
	MOD_OPT_DECL(EVENTS_UNIT_ACTIONS);
	MOD_OPT_DECL(EVENTS_UNIT_UPGRADES);
	MOD_OPT_DECL(EVENTS_UNIT_DATA);
	MOD_OPT_DECL(EVENTS_TRADE_ROUTES);
	MOD_OPT_DECL(EVENTS_TRADE_ROUTE_PLUNDERED);
	MOD_OPT_DECL(EVENTS_WAR_AND_PEACE);
	MOD_OPT_DECL(EVENTS_RESOLUTIONS);
	MOD_OPT_DECL(EVENTS_IDEOLOGIES);
	MOD_OPT_DECL(EVENTS_NUCLEAR_DETONATION);
	MOD_OPT_DECL(EVENTS_AIRLIFT);
	MOD_OPT_DECL(EVENTS_REBASE);
	MOD_OPT_DECL(EVENTS_COMMAND);
	MOD_OPT_DECL(EVENTS_CUSTOM_MISSIONS);
	MOD_OPT_DECL(EVENTS_BATTLES);
	MOD_OPT_DECL(EVENTS_BATTLES_DAMAGE);

	MOD_OPT_DECL(API_PLAYER_LOGS);
	MOD_OPT_DECL(API_ESPIONAGE);
	MOD_OPT_DECL(API_TRADEROUTES);
	MOD_OPT_DECL(API_RELIGION);
	MOD_OPT_DECL(API_PLOT_BASED_DAMAGE);
	MOD_OPT_DECL(API_PLOT_YIELDS);
	MOD_OPT_DECL(API_ACHIEVEMENTS);
	MOD_OPT_DECL(API_EXTENSIONS);
	MOD_OPT_DECL(API_LUA_EXTENSIONS);

	MOD_OPT_DECL(CONFIG_GAME_IN_XML);
	MOD_OPT_DECL(CONFIG_AI_IN_XML);

	MOD_OPT_DECL(BUGFIX_DUMMY_POLICIES);
	MOD_OPT_DECL(BUGFIX_RADARING);
	MOD_OPT_DECL(BUGFIX_RESEARCH_OVERFLOW);
	MOD_OPT_DECL(BUGFIX_LUA_CHANGE_VISIBILITY_COUNT);
	MOD_OPT_DECL(BUGFIX_RELIGIOUS_SPY_PRESSURE);
	MOD_OPT_DECL(BUGFIX_MOVE_AFTER_PURCHASE);
	MOD_OPT_DECL(BUGFIX_UNITCLASS_NOT_UNIT);
	MOD_OPT_DECL(BUGFIX_BUILDINGCLASS_NOT_BUILDING);
	MOD_OPT_DECL(BUGFIX_FREE_FOOD_BUILDING);
	MOD_OPT_DECL(BUGFIX_NAVAL_FREE_UNITS);
	MOD_OPT_DECL(BUGFIX_NAVAL_NEAREST_WATER);
	MOD_OPT_DECL(BUGFIX_CITY_STACKING);
	MOD_OPT_DECL(BUGFIX_BARB_CAMP_TERRAINS);
	MOD_OPT_DECL(BUGFIX_BARB_CAMP_SPAWNING);
	MOD_OPT_DECL(BUGFIX_BARB_GP_XP);
	MOD_OPT_DECL(BUGFIX_REMOVE_GHOST_ROUTES);
	MOD_OPT_DECL(BUGFIX_UNITS_AWAKE_IN_DANGER);
	MOD_OPT_DECL(BUGFIX_WORKERS_VISIBLE_DANGER);
	MOD_OPT_DECL(BUGFIX_FEATURE_REMOVAL);
	MOD_OPT_DECL(BUGFIX_INTERCEPTOR_STRENGTH);
	MOD_OPT_DECL(BUGFIX_UNIT_POWER_CALC);
	MOD_OPT_DECL(BUGFIX_UNIT_POWER_BONUS_VS_DOMAIN_ONLY);
	MOD_OPT_DECL(BUGFIX_UNIT_POWER_NAVAL_CONSISTENCY);
	MOD_OPT_DECL(BUGFIX_UNIT_PREREQ_PROJECT);
	MOD_OPT_DECL(BUGFIX_NO_HOVERING_REBELS);
	MOD_OPT_DECL(BUGFIX_HOVERING_PATHFINDER);
	MOD_OPT_DECL(BUGFIX_EMBARKING_PATHFINDER);
    
    // added by Serp from commuity patch dll or selfmade
    MOD_OPT_DECL(ANY_PANTHEON);
    MOD_OPT_DECL(RESOURCES_PRODUCTION_COST_MODIFIERS);
    MOD_OPT_DECL(EVENTS_VISCOUNT_CHANGED);
    MOD_OPT_DECL(POSITIVE_STRAT_COMBAT);
    MOD_OPT_DECL(EVENTS_PRE_SAVE_EVENT);
    MOD_OPT_DECL(DEBUG_GAMEHOOKS);
    MOD_OPT_DECL(LEVEL_PROMOTIONS);
    
    

protected:
	bool m_bInit;
	std::map<std::string, int> m_options;
};

extern CustomMods gCustomMods;
#endif