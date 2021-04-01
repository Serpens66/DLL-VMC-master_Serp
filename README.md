# DLL-VMC-master_Serp
 Civilization 5 DLL mod, based on whowards DLL v94:  http://www.picknmixmods.com/mods/CivV/DLL/Various%20Mod%20Components.html

I added various fixes, especially for multiplayer and also added few new features, partly my own work, partly from Community Patch (https://github.com/LoneGazebo/Community-Patch-DLL), partly from Artifical Unintelligence (https://github.com/DelnarErsike/Civ5-Artificial-Unintelligence-DLL) and partly from noquitters mod (https://github.com/gskleres/nqmod-vs2008 )

Navigate to the folder CvGameCoreDLL_Expansion2 and open CustomMods.h folder for an overview what I added. Search for "serp" and see my comments. And if you want to see code changes, you can simply search all files within CvGameCoreDLL_Expansion2 folder for the relevant define, for example "MOD_POSITIVE_STRAT_COMBAT" to see how I impleneted a combat bonus in DLL, if you have an high unused amount of strategic ressources (if enabled with a xml entry).

How to compile your own DLL:
https://forums.civfanatics.com/threads/building-a-dll-based-mod-in-2019.645887/
