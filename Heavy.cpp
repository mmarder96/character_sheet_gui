//
//  Heavy.cpp
//  CS 120 B
//
//  Created by Max Marder on 3/3/17.
//

#include "Heavy.h"
#include "Ammo.h"
#include <iostream>
#include <string>
using namespace std;

Heavy::Heavy() {
	//Declare default Accuracy modifiers
	closeAccMod = heavyCloseAccMod;
	medAccMod = heavyMedAccMod;
	longAccMod = heavyLongAccMod;
	//Declare default Damage value
	baseDmg = 45;
	//Declare default Damage modifers
	closeDmgMod = heavyCloseDmgMod;
	medDmgMod = heavyMedDmgMod;
	longDmgMod = heavyLongDmgMod;
}

Heavy::Heavy(int inBaseDmg)
{
	//Declare default Accuracy modifiers
	closeAccMod = heavyCloseAccMod;
	medAccMod = heavyMedAccMod;
	longAccMod = heavyLongAccMod;
	//Declare default Damage value
	baseDmg = 45;
	//Declare default Damage modifers
	closeDmgMod = heavyCloseDmgMod;
	medDmgMod = heavyMedDmgMod;
	longDmgMod = heavyLongDmgMod;
}

Heavy::~Heavy() {
}

//Display Heavy Stats
void Heavy::displayStats() {
	cout << "The Heavy's base damage is: " << baseDmg << endl;
	cout << "The Heavy's close range accuracy modifer is: " << closeAccMod << " ACC" << endl;
	cout << "The Heavy's mid range accuracy modifer is: " << medAccMod << " ACC" << endl;
	cout << "The Heavy's long range accuracy modifer is: " << longAccMod << " ACC" << endl;
	cout << "The Heavy's close range damage modifer is: " << closeDmgMod << " DMG" << endl;
	cout << "The Heavy's mid range damage modifer is: " << medDmgMod << " DMG" << endl;
	cout << "The Heavy's long range damage modifer is: " << longDmgMod << " DMG" << endl;
}

int Heavy::getAmmoCount()
{
	int outCount = ammo.getAmmoCount();
	return outCount;
}

ammoType Heavy::getAmmoType()
{
	ammoType outType = ammo.getAmmoType();
	return outType;
}

string Heavy::name() {
	return "Heavy";
}