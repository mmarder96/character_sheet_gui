//
//  Shotgun.cpp
//  CS 120 B
//
//  Created by Max Marder on 3/3/17.
//

#include "Shotgun.h"
#include "Ammo.h"
#include <iostream>
#include <string>
using namespace std;

Shotgun::Shotgun() {
	//Declare default Accuracy modifiers
	closeAccMod = shotgunCloseAccMod;
	medAccMod = shotgunMedAccMod;
	longAccMod = shotgunLongAccMod;
	//Declare default Damage value
	baseDmg = 30;
	//Declare default Damage modifers
	closeDmgMod = shotgunCloseDmgMod;
	medDmgMod = shotgunMedDmgMod;
	longDmgMod = shotgunLongDmgMod;
}

Shotgun::Shotgun(int inBaseDmg) {
	//Declare default Accuracy modifiers
	closeAccMod = shotgunCloseAccMod;
	medAccMod = shotgunMedAccMod;
	longAccMod = shotgunLongAccMod;
	//Declare default Damage value
	baseDmg = inBaseDmg;
	//Declare default Damage modifers
	closeDmgMod = shotgunCloseDmgMod;
	medDmgMod = shotgunMedDmgMod;
	longDmgMod = shotgunLongDmgMod;
}

Shotgun::~Shotgun() {
}

//Display Shotgun Stats
void Shotgun::displayStats() {
	cout << "The Shotgun's base damage is: " << baseDmg << endl;
	cout << "The Shotgun's close range accuracy modifer is: " << closeAccMod << " ACC" << endl;
	cout << "The Shotgun's mid range accuracy modifer is: " << medAccMod << " ACC" << endl;
	cout << "The Shotgun's long range accuracy modifer is: " << longAccMod << " ACC" << endl;
	cout << "The Shotgun's close range damage modifer is: " << closeDmgMod << " DMG" << endl;
	cout << "The Shotgun's mid range damage modifer is: " << medDmgMod << " DMG" << endl;
	cout << "The Shotgun's long range damage modifer is: " << longDmgMod << " DMG" << endl;
}

string Shotgun::name() {
	return "Shotgun";
}