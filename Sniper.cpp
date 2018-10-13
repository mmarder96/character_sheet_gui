//
//  Sniper.cpp
//  CS 120 B
//
//  Created by Max Marder on 3/3/17.
//

#include "Sniper.h"
#include "Ammo.h"
#include <iostream>
#include <string>
using namespace std;

Sniper::Sniper() {
	//Declare default Accuracy modifiers
	closeAccMod = sniperCloseAccMod;
	medAccMod = sniperMedAccMod;
	longAccMod = sniperLongAccMod;
	//Declare default Damage value
	baseDmg = 40;
	//Declare default Damage modifers
	closeDmgMod = sniperCloseDmgMod;
	medDmgMod = sniperMedDmgMod;
	longDmgMod = sniperLongDmgMod;
}

Sniper::Sniper(int inBaseDmg)
{
	//Declare default Accuracy modifiers
	closeAccMod = sniperCloseAccMod;
	medAccMod = sniperMedAccMod;
	longAccMod = sniperLongAccMod;
	//Declare default Damage value
	baseDmg = inBaseDmg;
	//Declare default Damage modifers
	closeDmgMod = sniperCloseDmgMod;
	medDmgMod = sniperMedDmgMod;
	longDmgMod = sniperLongDmgMod;
}

Sniper::~Sniper() {
}

//Display Sniper Stats
void Sniper::displayStats() {
	cout << "The Sniper's base damage is: " << baseDmg << endl;
	cout << "The Sniper's close range accuracy modifer is: " << closeAccMod << " ACC" << endl;
	cout << "The Sniper's mid range accuracy modifer is: " << medAccMod << " ACC" << endl;
	cout << "The Sniper's close range accuracy modifer is: " << longAccMod << " ACC" << endl;
	cout << "The Sniper's close range damage modifer is: " << closeDmgMod << " DMG" << endl;
	cout << "The Sniper's mid range damage modifer is: " << medDmgMod << " DMG" << endl;
	cout << "The Sniper's long range damage modifer is: " << longDmgMod << " DMG" << endl;
}

string Sniper::name() {
	return "Sniper";
}