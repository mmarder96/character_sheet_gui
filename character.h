#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H


#include <fstream>

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "structs.h"
#include "Gun.h"
#include <limits>
#include <memory>
#include "GameAlgorithms.h"

using namespace std;

class Character {
public:
	Character();
	Character(string name);

	void addBioEntry(string entry);
	void addTraitEntry(string entry);
	void addEffectsEntry(string entry);
	void addItemEntry(string item);
	void addGunEntry(shared_ptr<Gun> g);
	void print();

	string getName();
	string getRace();
	string getAlignment();

	string getHP();
	string getSpeed();
	
	string getStr();
	string getPer();
	string getEnd();
	string getCha();
	string getInt();
	string getAgi();
	string getLuc();
	
	string getHead();
	string getChest();
	string getRArm();
	string getRLeg();
	string getLArm();
	string getLLeg();

	string getBio();
	string getTraits();
	string getEffects();

	string getItemNames();
	string getGunNames();

	//save stuff
	/*
	Requires:Line num you want to read from players.txt
	Modifies:nothing
	Effects:Returns line as a string
	*/
	string getLine(int xLine);

	/*
	Requires:Name of a player
	Modifies:nothing
	Effects:Returns line num where player stats are located in players.txt or 0
	*/
	static int findPlayer(string name);

	/*
	Requires:Name of character
	Modifies:players.txt to have up to date player data (like saving a character)
	Effects:nothing
	*/
	void save();

	void load(string s);

//private:
	void initSpecial();
	void initLimbs();

	int getTotalWeight();

	CharacterSheet characterStats;

};

#endif