//
//  Gun.h
//  CS 120 B
//
//  Created by Max Marder on 2/9/17.
//

#ifndef Gun_h
#define Gun_h
#include "Ammo.h"
//#include "GameLogic.h"
#include "GameConstants.h"
#include <string>
#include <iostream>
#include <memory>
using namespace std;

// default constructor
/**
* Requires: nothing
* Modifies: accuracy and damage
* Effects: sets default values for
*          damage and accuracy
*/
class Gun {
public:
	Gun();
	virtual string name() = 0;
	Gun(int inBaseDmg);
	Gun(int inBaseDmg, int cDmgIn, int mDmgIn, int lDmgIn);
	Gun(int inBaseDmg, int cDmgIn, int mDmgIn, int lDmgIn, int cAccIn, int mAccIn, int lAccIn);
	~Gun(); // destructor

	// One RME for all getters
	/**
	* Requires: nothing
	* Modifies: accurracy and damage
	* Effects: get and set values for
	*          accurracy and damage
	*/
	int getCloseAccMod() const;
	int getMedAccMod() const;
	int getLongAccMod() const;
	int getBaseDmg() const;
	int getCloseDmgMod() const;
	int getMedDmgMod() const;
	int getLongDmgMod() const;

	//Accuracy Modifier Setters
	void setCloseAccMod(int cAccIn);
	void setMedAccMod(int mAccIn);
	void setLongAccMod(int lAccIn);
	void setAccMod(int cAccIn, int mAccIn, int lAccIn);

	//Base Damage Setter
	void setBaseDmg(int bDmgIn);

	//Damage Modifier Setters
	void setCloseDmgMod(int cDmgIn);
	void setMedDmgMod(int mDmgIn);
	void setLongDmgMod(int lDmgIn);
	void setDmgMod(int cDmgIn, int mDmgIn, int lDmgIn);

	//Display Gun Stats to console
	virtual void displayStats() = 0;

	/**
	* Requires: range
	* Modifies: nothing
	* Effects: returns range identifier
	*/
	string identifyRng(int range);

	/**
	* Requires: range, roll
	* Modifies: nothing
	* Effects: returns Accuracy Roll
	*/
	int calculateAcc(int range, int roll);

	/**
	* Requires: range, roll
	* Modifies: nothing
	* Effects: returns Damage
	*/
	int calculateDmg(int range);

protected:
	// Accuracy fields
	int closeAccMod;
	int medAccMod;
	int longAccMod;
	//Damage fields
	int baseDmg;
	int closeDmgMod;
	int medDmgMod;
	int longDmgMod;
	//Range fields
	int closeRngMax;
	int medRngMax;
	int longRngMax;
};

#endif /* Gun_h */