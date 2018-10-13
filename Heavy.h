//
//  Heavy.h
//  CS 120 B
//
//  Created by Max Marder on 3/3/17.
//

#ifndef Heavy_h
#define Heavy_h
#include "Gun.h"
#include "Ammo.h"
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
class Heavy : public Gun {
public:
	Heavy();
	string name() override;
	Heavy(int inBaseDmg);
	~Heavy(); // destructor

			  //Display Heavy Stats to console
	void displayStats();
	//get bullet count in magazine
	int getAmmoCount();
	//get ammo type of weapon
	ammoType getAmmoType();

protected:
	Ammo ammo;
};
#endif /* Heavy_h */
