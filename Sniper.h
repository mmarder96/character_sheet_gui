//
//  Sniper.h
//  CS 120 B
//
//  Created by Max Marder on 3/3/17.
//

#ifndef Sniper_h
#define Sniper_h
#include "Gun.h"
#include <iostream>
#include <string>
using namespace std;

// default constructor
/**
* Requires: nothing
* Modifies: accuracy and damage
* Effects: sets default values for
*          damage and accuracy
*/
class Sniper : public Gun {
public:
	Sniper();
	string name() override;
	Sniper(int inBaseDmg);
	~Sniper(); // destructor

	//Display Sniper Stats to console
	void displayStats();

protected:
	Ammo ammo;
};

#endif /* Sniper_h */#pragma once
