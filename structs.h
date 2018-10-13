#pragma once
#ifndef STRUCTS_H
#define STRUCTS_H

#include <string>
#include <map>
#include <vector>
#include "Arsenal.h"

using namespace std;

struct Item {
	string name;
	string description;
	int weight;
	int number;
};

struct CharacterSheet {
	int hp;
	int speed;
	int critDmg;
	int radThresh;
	int caps;
	int inspiration;

	string name;
	string race;
	string alignment;

	map <string, int> special;
	map <string, int> limbs;

	vector<string> bio;
	vector<string> traits;
	vector<string> effects;

	vector<string> inventory;
	Arsenal playerGuns;
};

#endif