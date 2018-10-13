//
//  Arsenal.h
//  CS 120 A
//
//  Created by Max Marder on 2/9/17.
//


#ifndef Arsenal_h
#define Arsenal_h
#include <string>
#include <vector>
#include <memory>
#include "Gun.h"
#include "Pistol.h"
#include "SMG.h"
#include "Shotgun.h"
#include "AR.h"
#include "BR.h"
#include "LMG.h"
#include "Sniper.h"
#include "Heavy.h"
using namespace std;

// default constructor
/**
* Requires: nothing
* Modifies: vector of Guns
* Effects: create arsenal of Guns
*/
class Arsenal {
public:
	Arsenal();
	~Arsenal(); // destructor
	string name();
	int size();
	void displayArsenal();
	void addGun(shared_ptr<Gun> g); // add gun g to arsenal vector
	void deleteArsenalIndex(int i); //delete gun at index i in arsenal vector
	shared_ptr<Gun> getGunIndex(int i); //get Gun at index i
	void fireArsenal(); //fire all guns in arsenal vector

private:
	vector<shared_ptr<Gun>> arsenalVector; //vector that holds an assortment of guns
};
#endif /* Arsenal_h */


