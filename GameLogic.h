//
//  GameLogic.h
//  CS 120 B
//
//  Created by Max Marder on 2/9/17.
//

#ifndef GameLogic_h
#define GameLogic_h

#include <string>
#include <iostream>
#include "Arsenal.h"
#include "Ammo.h"
#include "character.h"
#include <memory>


using namespace std;

// default constructor
/**
* Requires: nothing
* Modifies: accuracy and damage
* Effects: sets default values for
*          damage and accuracy
*/
class GameLogic {
public:
	GameLogic();
	~GameLogic(); // destructor


//S.P.E.C.I.A.L. D20 Calculation
	int CalcD20Mod(int stat);

//Methods for Secondary Derived Stat Calculation
	
	//Health Points
	void CalcHp(Character &myChar);

	//Speed
	void CalcSpd(Character &myChar);

	//Limb Health
	void CalcHeadLhp(Character &myChar);

	void CalcChestLhp(Character &myChar);

	void CalcRightArmLhp(Character &myChar);

	void CalcLeftArmLhp(Character &myChar);

	void CalcRightLegLhp(Character &myChar);

	void CalcLefttLegLhp(Character &myChar);

	//Critical Strike Damage
	void CalcCritDmg(Character &myChar);

	//Radiation Threshold
	void CalcRadThresh(Character &myChar);
	
//Update Character's Derived Stats
	void UpdateCharacterStats(Character &myChar);

	
	
};

#endif /* GameLogic_h */
