//
//  GameConstants.h
//  CS 120 B
//
//  Created by Max Marder on 2/9/17.
//

#ifndef GameConstants_h
#define GameConstants_h
using namespace std;

//Character Stats

//Health Points
const int defaultHp = 100;

//Speed
const int defaultSpd = 30;

//Limbs
const int defaultHeadLhp = 3;

const int defaultChestLhp = 5;

const int defaultArmLhp = 4;

const int defaultLegLhp = 4;

//Critical DMG
const int defaultCritDmg = 40;

//Radiation
const int defaultRadThresh = 10;

//Guns

//Pistol
//Accuracy fields
const int pistolCloseAccMod = 3;
const int pistolMedAccMod = 1;
const int pistolLongAccMod = 0;
//Damage fields
const int pistolCloseDmgMod = 0;
const int pistolMedDmgMod = 0;
const int pistolLongDmgMod = -5;

//Submachine Gun 
//Accuracy fields
const int smgCloseAccMod = 3;
const int smgMedAccMod = 0;
const int smgLongAccMod = -1;
//Damage fields
const int smgCloseDmgMod = 10;
const int smgMedDmgMod = 0;
const int smgLongDmgMod = -5;

//Shotgun
//Accuracy fields
const int shotgunCloseAccMod = 4;
const int shotgunMedAccMod = -2;
const int shotgunLongAccMod = -4;
//Damage fields
const int shotgunCloseDmgMod = 20;
const int shotgunMedDmgMod = 0;
const int shotgunLongDmgMod = -20;

//Assault Rifle
//Accuracy fields
const int arCloseAccMod = 0;
const int arMedAccMod = 2;
const int arLongAccMod = 2;
//Damage fields
const int arCloseDmgMod = 5;
const int arMedDmgMod = 0;
const int arLongDmgMod = 0;

//Battle Rifle
//Accuracy fields
const int brCloseAccMod = -1;
const int brMedAccMod = 2;
const int brLongAccMod = 2;
//Damage fields
const int brCloseDmgMod = 5;
const int brMedDmgMod = 0;
const int brLongDmgMod = 0;

//Light Machinegun
//Accuracy fields
const int lmgCloseAccMod = -1;
const int lmgMedAccMod = 1;
const int lmgLongAccMod = 1;
//Damage fields
const int lmgCloseDmgMod = 5;
const int lmgMedDmgMod = 0;
const int lmgLongDmgMod = 0;

//Sniper Rifle
//Accuracy fields
const int sniperCloseAccMod = -4;
const int sniperMedAccMod = -2;
const int sniperLongAccMod = 4;
//Damage fields
const int sniperCloseDmgMod = 5;
const int sniperMedDmgMod = 0;
const int sniperLongDmgMod = 0;

//Heavy Weapon
//Accuracy fields
const int heavyCloseAccMod = -3;
const int heavyMedAccMod = -1;
const int heavyLongAccMod = 3;
//Damage fields
const int heavyCloseDmgMod = 0;
const int heavyMedDmgMod = 0;
const int heavyLongDmgMod = 0;

//Range Border fields
const int closeRngMax = 20;
const int medRngMax = 80;
const int longRngMax = 160;


#endif /* GameConstants_h */

