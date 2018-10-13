//
//  BR.cpp
//  CS 120 B
//
//  Created by Max Marder on 3/3/17.
//

#include "BR.h"
#include "Ammo.h"
#include <iostream>
#include <string>
using namespace std;

BR::BR() {
	//Declare default Accuracy modifiers
	closeAccMod = brCloseAccMod;
	medAccMod = brMedAccMod;
	longAccMod = brLongAccMod;
	//Declare default Damage value
	baseDmg = 35;
	//Declare default Damage modifers
	closeDmgMod = brCloseDmgMod;
	medDmgMod = brMedDmgMod;
	longDmgMod = brLongDmgMod;
}

BR::BR(int inBaseDmg)
{
	//Declare default Accuracy modifiers
	closeAccMod = brCloseAccMod;
	medAccMod = brMedAccMod;
	longAccMod = brLongAccMod;
	//Declare default Damage value
	baseDmg = inBaseDmg;
	//Declare default Damage modifers
	closeDmgMod = brCloseDmgMod;
	medDmgMod = brMedDmgMod;
	longDmgMod = brLongDmgMod;
}

BR::~BR() {
}

//Display BR Stats
void BR::displayStats() {
	cout << "The BR's base damage is: " << baseDmg << endl;
	cout << "The BR's close range accuracy modifer is: " << closeAccMod << " ACC" << endl;
	cout << "The BR's mid range accuracy modifer is: " << medAccMod << " ACC" << endl;
	cout << "The BR's long range accuracy modifer is: " << longAccMod << " ACC" << endl;
	cout << "The BR's close range damage modifer is: " << closeDmgMod << " DMG" << endl;
	cout << "The BR's mid range damage modifer is: " << medDmgMod << " DMG" << endl;
	cout << "The BR's long range damage modifer is: " << longDmgMod << " DMG" << endl;
}

string BR::name() {
	return "BR";
}