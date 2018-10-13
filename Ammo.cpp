
//
//  Gun.cpp
//  CS 120 B
//
//  Created by Max Marder on 2/9/17.
//

#include "Gun.h"
#include "Ammo.h"
#include <iostream>
#include <string>
using namespace std;

Ammo::Ammo() {
	type = default;
	ammoCount = 5;
}

Ammo::Ammo(ammoType a) {
	type = a;
	ammoCount = 5;
}

Ammo::Ammo(int inCount) {
	type = heavy;
	ammoCount = inCount;
}

Ammo::Ammo(ammoType a, int inCount) {
	type = a;
	ammoCount = inCount;
}

Ammo::~Ammo() {
}

void Ammo::setAmmoCount(int inCount) {
	ammoCount = inCount;
}

void Ammo::setAmmoType(ammoType inType) {
	type = inType;
}

int Ammo::getAmmoCount()
{
	return ammoCount;
}

ammoType Ammo::getAmmoType()
{
	return type;
}
