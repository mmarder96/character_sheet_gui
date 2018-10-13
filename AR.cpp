//
//  AR.cpp
//  CS 120 B
//
//  Created by Max Marder on 3/3/17.
//

#include "GameLogic.h"
#include "AR.h"
#include <iostream>
#include <string>
#include "Ammo.h"
using namespace std;

AR::AR() {
	//Declare default Accuracy modifiers
	closeAccMod = arCloseAccMod;
	medAccMod = arMedAccMod;
	longAccMod = arLongAccMod;
	//Declare default Damage value
	baseDmg = 30;
	//Declare default Damage modifers
	closeDmgMod = arCloseDmgMod;
	medDmgMod = arMedDmgMod;
	longDmgMod = arLongDmgMod;
}

AR::AR(int inBaseDmg)
{
	//Declare default Accuracy modifiers
	closeAccMod = arCloseAccMod;
	medAccMod = arMedAccMod;
	longAccMod = arLongAccMod;
	//Declare default Damage value
	baseDmg = inBaseDmg;
	//Declare default Damage modifers
	closeDmgMod = arCloseDmgMod;
	medDmgMod = arMedDmgMod;
	longDmgMod = arLongDmgMod;
}

AR::~AR() {
}

//Display AR Stats
void AR::displayStats() {
	cout << "The AR's base damage is: " << baseDmg << endl;
	cout << "The AR's close range accuracy modifer is: " << closeAccMod << " ACC" << endl;
	cout << "The AR's mid range accuracy modifer is: " << medAccMod << " ACC" << endl;
	cout << "The AR's long range accuracy modifer is: " << longAccMod << " ACC" << endl;
	cout << "The AR's close range damage modifer is: " << closeDmgMod << " DMG" << endl;
	cout << "The AR's mid range damage modifer is: " << medDmgMod << " DMG" << endl;
	cout << "The AR's long range damage modifer is: " << longDmgMod << " DMG" << endl;
}

string AR::name() {
	return "AR";
}