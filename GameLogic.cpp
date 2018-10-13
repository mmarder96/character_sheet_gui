#include "GameLogic.h"


GameLogic::GameLogic() {
}

GameLogic::~GameLogic(){
}

int GameLogic::CalcD20Mod(int stat) {
	if (stat < 1) {
		return -4 - (1 - stat);
	}
	else if (stat == 1) {
		return -4;
	}
	else if (stat == 2 || stat == 3) {
		return -3;
	}
	else if (stat == 4 || stat == 5 || stat == 6) {
		return -2;
	}
	else if (stat == 7 || stat == 8 || stat == 9) {
		return -1;
	}
	else if (stat == 10) {
		return 0;
	}
	else if (stat == 11 || stat == 12 || stat == 13) {
		return 1;
	}
	else if (stat == 14 || stat == 15 || stat == 16) {
		return 2;
	}
	else if (stat == 17 || stat == 18 || stat == 19) {
		return 3;
	}
	else if (stat == 20 || stat == 21) {
		return 4;
	}
	else if (stat == 22 || stat == 23) {
		return 5;
	}
	else if (stat == 24 || stat == 25 || stat == 26) {
		return 6;
	}
	else if (stat == 27 || stat == 28 || stat == 29) {
		return 7;
	}
	else if (stat == 30 || stat == 31) {
		return 8;
	}
	else if (stat == 32 || stat == 33) {
		return 9;
	}
	else if (stat == 34 || stat == 35 || stat == 36) {
		return 10;
	}
	else if (stat == 37 || stat == 38 || stat == 39) {
		return 11;
	}
	else if (stat == 40) {
		return 12;
	}
	else {
		return 0;
	}
}

void GameLogic::CalcHp(Character & myChar){
	myChar.characterStats.hp = defaultHp + (myChar.characterStats.special["endurance"] * 5);
}

void GameLogic::CalcSpd(Character & myChar){
	myChar.characterStats.speed = defaultSpd + ((CalcD20Mod(myChar.characterStats.special["agility"]) / 2) * 5);
}

void GameLogic::CalcHeadLhp(Character & myChar){
	myChar.characterStats.limbs["head"] = defaultHeadLhp + (CalcD20Mod(myChar.characterStats.special["endurance"]) / 2);
}

void GameLogic::CalcChestLhp(Character & myChar){
	myChar.characterStats.limbs["chest"] = defaultChestLhp + (CalcD20Mod(myChar.characterStats.special["endurance"]) / 2);
}

void GameLogic::CalcRightArmLhp(Character & myChar){
	myChar.characterStats.limbs["rarm"] = defaultArmLhp + (CalcD20Mod(myChar.characterStats.special["endurance"]) / 2);
}

void GameLogic::CalcLeftArmLhp(Character & myChar){
	myChar.characterStats.limbs["larm"] = defaultArmLhp + (CalcD20Mod(myChar.characterStats.special["endurance"]) / 2);
}

void GameLogic::CalcRightLegLhp(Character & myChar){
	myChar.characterStats.limbs["rleg"] = defaultLegLhp + (CalcD20Mod(myChar.characterStats.special["endurance"]) / 2);
}

void GameLogic::CalcLefttLegLhp(Character & myChar){
	myChar.characterStats.limbs["lleg"] = defaultLegLhp + (CalcD20Mod(myChar.characterStats.special["endurance"]) / 2);
}

void GameLogic::CalcCritDmg(Character & myChar){
	myChar.characterStats.critDmg = defaultCritDmg + (CalcD20Mod(myChar.characterStats.special["luck"]) * 5);
}

void GameLogic::CalcRadThresh(Character & myChar){
	myChar.characterStats.radThresh = defaultRadThresh + CalcD20Mod(myChar.characterStats.special["endurance"]);
}

void GameLogic::UpdateCharacterStats(Character & myChar){
	myChar.characterStats.hp = defaultHp + (myChar.characterStats.special["endurance"] * 5);
	myChar.characterStats.speed = defaultSpd + ((CalcD20Mod(myChar.characterStats.special["agility"]) / 2) * 5);
	myChar.characterStats.limbs["head"] = defaultHeadLhp + (CalcD20Mod(myChar.characterStats.special["endurance"]) / 2);
	myChar.characterStats.limbs["chest"] = defaultChestLhp + (CalcD20Mod(myChar.characterStats.special["endurance"]) / 2);
	myChar.characterStats.limbs["rarm"] = defaultArmLhp + (CalcD20Mod(myChar.characterStats.special["endurance"]) / 2);
	myChar.characterStats.limbs["larm"] = defaultArmLhp + (CalcD20Mod(myChar.characterStats.special["endurance"]) / 2);
	myChar.characterStats.limbs["rleg"] = defaultLegLhp + (CalcD20Mod(myChar.characterStats.special["endurance"]) / 2);
	myChar.characterStats.limbs["lleg"] = defaultLegLhp + (CalcD20Mod(myChar.characterStats.special["endurance"]) / 2);
	myChar.characterStats.critDmg = defaultCritDmg + (CalcD20Mod(myChar.characterStats.special["luck"]) * 5);
	myChar.characterStats.radThresh = defaultRadThresh + CalcD20Mod(myChar.characterStats.special["endurance"]);
}