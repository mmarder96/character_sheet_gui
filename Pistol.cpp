//
//  Pistol.cpp
//  CS 120 B
//
//  Created by Max Marder on 3/3/17.
//

#include "Pistol.h"
#include "Ammo.h"
#include <iostream>
#include <string>
using namespace std;

Pistol::Pistol() {
	//Declare default Accuracy modifiers
	closeAccMod = pistolCloseDmgMod;
	medAccMod = pistolMedAccMod;
	longAccMod = pistolLongAccMod;
	//Declare default Damage value
	baseDmg = 20;
	//Declare default Damage modifers
	closeDmgMod = pistolCloseDmgMod;
	medDmgMod = pistolMedDmgMod;
	longDmgMod = pistolLongDmgMod;
}

Pistol::Pistol(int inBaseDmg)
{
	//Declare default Accuracy modifiers
	closeAccMod = pistolCloseDmgMod;
	medAccMod = pistolMedAccMod;
	longAccMod = pistolLongAccMod;
	//Declare default Damage value
	baseDmg = inBaseDmg;
	//Declare default Damage modifers
	closeDmgMod = pistolCloseDmgMod;
	medDmgMod = pistolMedDmgMod;
	longDmgMod = pistolLongDmgMod;
}

Pistol::~Pistol() {
}

//Display Pistol Stats
void Pistol::displayStats() {
	cout << "The Pistol's base damage is: " << baseDmg << endl;
	cout << "The Pistol's close range accuracy modifer is: " << closeAccMod << " ACC" << endl;
	cout << "The Pistol's mid range accuracy modifer is: " << medAccMod << " ACC" << endl;
	cout << "The Pistol's long range accuracy modifer is: " << longAccMod << " ACC" << endl;
	cout << "The Pistol's close range damage modifer is: " << closeDmgMod << " DMG" << endl;
	cout << "The Pistol's mid range damage modifer is: " << medDmgMod << " DMG" << endl;
	cout << "The Pistol's long range damage modifer is: " << longDmgMod << " DMG" << endl;
}

string Pistol::name() {
	return "Pistol";
}