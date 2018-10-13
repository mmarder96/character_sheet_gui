//
//  Shotgun.h
//  CS 120 B
//
//  Created by Max Marder on 3/3/17.
//

#ifndef Shotgun_h
#define Shotgun_h
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
class Shotgun : public Gun {
public:
	Shotgun();
	string name() override;
	Shotgun(int inBaseDmg);
	~Shotgun(); // destructor

				//Display Shotgun Stats to console
	void displayStats();

protected:
	Ammo ammo;
};

#endif /* Shotgun_h */