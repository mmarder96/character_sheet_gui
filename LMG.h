//
//  LMG.h
//  CS 120 B
//
//  Created by Max Marder on 3/3/17.
//

#ifndef LMG_h
#define LMG_h
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
class LMG : public Gun {
public:
	LMG();
	string name() override;
	LMG(int inBaseDmg);
	~LMG(); // destructor

			//Display LMG Stats to console
	void displayStats();

protected:
	Ammo ammo;
};

#endif /* LMG_h */