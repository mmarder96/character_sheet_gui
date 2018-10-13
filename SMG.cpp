//
//  SMG.cpp
//  CS 120 B
//
//  Created by Max Marder on 3/3/17.
//

#include "SMG.h"
#include "Ammo.h"
#include <iostream>
#include <string>
using namespace std;

SMG::SMG() {
	//Declare default Accuracy modifiers
	closeAccMod = smgCloseAccMod;
	medAccMod = smgMedAccMod;
	longAccMod = smgLongAccMod;
	//Declare default Damage value
	baseDmg = 30;
	//Declare default Damage modifers
	closeDmgMod = smgCloseDmgMod;
	medDmgMod = smgMedDmgMod;
	longDmgMod = smgLongDmgMod;
}

SMG::SMG(int inBaseDmg)
{
	//Declare default Accuracy modifiers
	closeAccMod = smgCloseAccMod;
	medAccMod = smgMedAccMod;
	longAccMod = smgLongAccMod;
	//Declare default Damage value
	baseDmg = inBaseDmg;
	//Declare default Damage modifers
	closeDmgMod = smgCloseDmgMod;
	medDmgMod = smgMedDmgMod;
	longDmgMod = smgLongDmgMod;
}

SMG::~SMG() {
}

//Display SMG Stats
void SMG::displayStats() {
	cout << "The SMG's base damage is: " << baseDmg << endl;
	cout << "The SMG's close range accuracy modifer is: " << closeAccMod << " ACC" << endl;
	cout << "The SMG's mid range accuracy modifer is: " << medAccMod << " ACC" << endl;
	cout << "The SMG's long range accuracy modifer is: " << longAccMod << " ACC" << endl;
	cout << "The SMG's close range damage modifer is: " << closeDmgMod << " DMG" << endl;
	cout << "The SMG's mid range damage modifer is: " << medDmgMod << " DMG" << endl;
	cout << "The SMG's long range damage modifer is: " << longDmgMod << " DMG" << endl;
}

string SMG::name() {
	return "SMG";
}