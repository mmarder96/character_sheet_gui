//
//  Arsenal.cpp
//  CS 120 B
//
//  Created by Max Marder on 2/9/17.
//
#include "Arsenal.h"
#include "Gun.h"
#include "Pistol.h"
#include "SMG.h"
#include "Shotgun.h"
#include "AR.h"
#include "BR.h"
#include "LMG.h"
#include "Sniper.h"
#include "Heavy.h"
#include <memory>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

Arsenal::Arsenal() {
}

Arsenal::~Arsenal() {
}

void Arsenal::displayArsenal() {
	for (int i = 0; i < arsenalVector.size(); i++) {
		cout << "Gun: " << i << endl;
		arsenalVector[i]->displayStats();
	}
}

void Arsenal::addGun(shared_ptr<Gun> g) {
	arsenalVector.push_back(g);
}

void Arsenal::deleteArsenalIndex(int i) {
	arsenalVector.erase(arsenalVector.begin() + i);
}

shared_ptr<Gun> Arsenal::getGunIndex(int i) {
	return arsenalVector[i];
}

void Arsenal::fireArsenal() {
	srand(time(NULL));
	//randomly generate range distance
	int range;
	range = rand() % 135 + 1;
	//initialize roll integer
	int roll;
	//randomly generate roll
	roll = rand() % 10 + 1;
	int hit = 5; //set roll needed to hit
	cout << "Range: " << range << "ft" << endl;
	//Display range type
	Pistol g1;
	cout << "Range Type: " << g1.identifyRng(range) << endl << endl;
	//Display unmodified ACC roll
	cout << "Unmodified Accuracy Roll: " << roll << endl << endl;
	//Iterate over all Guns in vector and determine whether the gun has hit or not
	for (int i = 0; i < arsenalVector.size(); i++) {
		int accRoll = arsenalVector[i]->calculateAcc(range, roll);
		cout << "Gun: " << i << endl;
		cout << "Accuracy Roll: " << accRoll << endl;
		//Display damage if hit
		if (accRoll >= hit) {
			cout << "Damage Dealt: ";
			cout << arsenalVector[i]->calculateDmg(range) << endl << endl;
		}
		//Display MISS if miss
		else {
			cout << "MISS" << endl << endl;
		}
	}
}

int Arsenal::size() {
	return arsenalVector.size();
}

string Arsenal::name() {

	string Final;

	for (int i = 0; i < arsenalVector.size(); i++) {

		Gun *type = arsenalVector[i].get();

		Final += type -> name() + " * ";

	}

	return Final;
}