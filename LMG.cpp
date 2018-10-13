//
//  LMG.cpp
//  CS 120 B
//
//  Created by Max Marder on 3/3/17.
//

#include "LMG.h"
#include "Ammo.h"
#include <iostream>
#include <string>
using namespace std;

LMG::LMG() {
	//Declare default Accuracy modifiers
	closeAccMod = lmgCloseAccMod;
	medAccMod = lmgMedAccMod;
	longAccMod = lmgLongAccMod;
	//Declare default Damage value
	baseDmg = 20;
	//Declare default Damage modifers
	closeDmgMod = lmgCloseDmgMod;
	medDmgMod = lmgMedDmgMod;
	longDmgMod = lmgLongDmgMod;
}

LMG::LMG(int inBaseDmg)
{
	//Declare default Accuracy modifiers
	closeAccMod = lmgCloseAccMod;
	medAccMod = lmgMedAccMod;
	longAccMod = lmgLongAccMod;
	//Declare default Damage value
	baseDmg = inBaseDmg;
	//Declare default Damage modifers
	closeDmgMod = lmgCloseDmgMod;
	medDmgMod = lmgMedDmgMod;
	longDmgMod = lmgLongDmgMod;
}

LMG::~LMG() {
}

//Display LMG Stats
void LMG::displayStats() {
	cout << "The LMG's base damage is: " << baseDmg << endl;
	cout << "The LMG's close range accuracy modifer is: " << closeAccMod << " ACC" << endl;
	cout << "The LMG's mid range accuracy modifer is: " << medAccMod << " ACC" << endl;
	cout << "The LMG's long range accuracy modifer is: " << longAccMod << " ACC" << endl;
	cout << "The LMG's close range damage modifer is: " << closeDmgMod << " DMG" << endl;
	cout << "The LMG's mid range damage modifer is: " << medDmgMod << " DMG" << endl;
	cout << "The LMG's long range damage modifer is: " << longDmgMod << " DMG" << endl;
}

string LMG::name() {
	return "LMG";
}