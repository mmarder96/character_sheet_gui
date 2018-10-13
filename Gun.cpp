//
//  Gun.cpp
//  CS 120 B
//
//  Created by Max Marder on 2/9/17.
//

#include "Gun.h"
#include <iostream>
#include <string>
using namespace std;

Gun::Gun() {
	//Declare default Accuracy modifiers
	closeAccMod = 1;
	medAccMod = 0;
	longAccMod = -1;
	//Declare default Damage value
	baseDmg = 20;
	//Declare default Damage modifers
	closeDmgMod = 5;
	medDmgMod = 0;
	longDmgMod = -5;
}

Gun::Gun(int inBaseDmg){
	//Declare default Accuracy modifiers
	closeAccMod = 1;
	medAccMod = 0;
	longAccMod = -1;
	//Declare default Damage value
	baseDmg = inBaseDmg;
	//Declare default Damage modifers
	closeDmgMod = 5;
	medDmgMod = 0;
	longDmgMod = -5;
}

Gun::~Gun() {
}

//Accuracy Getters
int Gun::getCloseAccMod() const {
	return closeAccMod;
}
int Gun::getMedAccMod() const {
	return medAccMod;
}
int Gun::getLongAccMod() const {
	return longAccMod;
}
//Damage Getters
int Gun::getBaseDmg() const {
	return baseDmg;
}
int Gun::getCloseDmgMod() const {
	return closeDmgMod;
}
int Gun::getMedDmgMod() const {
	return medDmgMod;
}
int Gun::getLongDmgMod() const {
	return longDmgMod;
}

//Accuracy Setters
void Gun::setCloseAccMod(int cAccIn) {
	closeAccMod = cAccIn;
}
void Gun::setMedAccMod(int mAccIn) {
	medAccMod = mAccIn;
}
void Gun::setLongAccMod(int lAccIn) {
	longAccMod = lAccIn;
}
//Damage Setters
void Gun::setBaseDmg(int bDmgIn) {
	baseDmg = bDmgIn;
}
void Gun::setCloseDmgMod(int cDmgIn) {
	closeDmgMod = cDmgIn;
}
void Gun::setMedDmgMod(int mDmgIn) {
	medDmgMod = mDmgIn;
}
void Gun::setLongDmgMod(int lDmgIn) {
	longDmgMod = lDmgIn;
}

void Gun::setDmgMod(int cDmgIn, int mDmgIn, int lDmgIn) {
	closeDmgMod = cDmgIn;
	medDmgMod = mDmgIn;
	longDmgMod = lDmgIn;
}

void Gun::setAccMod(int cAccIn, int mAccIn, int lAccIn) {
	closeAccMod = cAccIn;
	medAccMod = mAccIn;
	longAccMod = lAccIn;
}

//Range Identifier
string Gun::identifyRng(int range) {
	if (0 <= range && range < closeRngMax) {
		string range = "Close Range";
		return range;
	}
	else if (closeRngMax <= range && range < medRngMax) {
		string range = "Mid Range";
		return range;
	}
	else if (medRngMax <= range && range < longRngMax) {
		string range = "Long Range";
		return range;
	}
	else {
		string invalid = "Invalid Range";
		return invalid;
	}
}


//Accuracy Calculator
int Gun::calculateAcc(int range, int roll) {
	if (0 <= range && range < closeRngMax) {
		int accRoll = roll + closeAccMod;
		return accRoll;
	}
	else if (closeRngMax <= range && range < medRngMax) {
		int accRoll = roll + medAccMod;
		return accRoll;
	}
	else if (medRngMax <= range && range < longRngMax) {
		int accRoll = roll + longAccMod;
		return accRoll;
	}
	else {
		return 0;
	}
}

//Damage Calculator
int Gun::calculateDmg(int range) {
	if (0 <= range && range < closeRngMax) {
		int damage = baseDmg + closeDmgMod;
		return damage;
	}
	else if (closeRngMax <= range && range < medRngMax) {
		int damage = baseDmg + medDmgMod;
		return damage;
	}
	else if (medRngMax <= range && range < longRngMax) {
		int damage = baseDmg + longDmgMod;
		return damage;
	}
	else {
		return 0;
	}
}

