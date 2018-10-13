//
//  BR.h
//  CS 120 B
//
//  Created by Max Marder on 3/3/17.
//

#ifndef BR_h
#define BR_h
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
class BR : public Gun {
public:
	BR();
	string name() override;
	BR(int inBaseDmg);
	~BR(); // destructor

	//Display BR Stats to console
	void displayStats();

protected:
	Ammo ammo;
};

#endif /* BR_h */