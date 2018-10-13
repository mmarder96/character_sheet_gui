//
//  SMG.h
//  CS 120 B
//
//  Created by Max Marder on 3/3/17.
//

#ifndef SMG_h
#define SMG_h
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
class SMG : public Gun {
public:
	SMG();
	string name() override;
	SMG(int inBaseDmg);
	~SMG(); // destructor

	//Display SMG Stats to console
	void displayStats() override;

protected:
	Ammo ammo;
};

#endif /* SMG_h */