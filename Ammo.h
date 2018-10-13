//
//  Ammo.h
//  CS 120 B
//
//  Created by Max Marder on 3/3/17.
//

#ifndef Ammo_h
#define Ammo_h
#include "Gun.h"
#include <iostream>
#include <string>
using namespace std;

//Ammo Types
enum ammoType { default, pistol, shotgun, rifle, heavy };

// default constructor
/**
* Requires: nothing
* Modifies: nothing
* Effects: sets default values for
*          ammo type and ammo count
*/
class Ammo {
public:
	Ammo();
	Ammo(ammoType a);
	Ammo(int inCount);
	Ammo(ammoType a, int inCount);
	~Ammo(); // destructor

			 /**
			 * Requires: nothing
			 * Modifies: Nothing
			 * Effects: get and set values for
			 *          ammoCount
			 */
	void setAmmoCount(int inCount);
	void setAmmoType(ammoType inType);
	int getAmmoCount();
	ammoType getAmmoType();

	//fields
protected:
	int ammoCount;
	ammoType type;
};

#endif /* AR_h */