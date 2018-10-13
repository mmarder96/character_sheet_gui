//
//  AR.h
//  CS 120 B
//
//  Created by Max Marder on 3/3/17.
//

#ifndef AR_h
#define AR_h
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
class AR : public Gun {
public:
	AR();
	string name() override;
	AR(int inBaseDmg);
	~AR(); // destructor

		   //Display AR Stats to console
	void displayStats();

protected:
	Ammo ammo;
};

#endif /* AR_h */