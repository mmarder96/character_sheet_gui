//
//  Pistol.h
//  CS 120 B
//
//  Created by Max Marder on 3/3/17.
//

#ifndef Pistol_h
#define Pistol_h
#include "Gun.h"
#include <iostream>
#include <string>
using namespace std;

// default constructor
/**
* Requires: nothing
* Modifies: accuracy and damage
* Effects: sets default values for
*			damage and accuracy
*/
class Pistol : public Gun {
public:
	Pistol();
	string name() override;
	Pistol(int inBaseDmg);
	~Pistol(); // destructor
			   //Display Pistol Stats to console
	void displayStats() override;

protected:
	Ammo ammo;
};

#endif /* Pistol_h */