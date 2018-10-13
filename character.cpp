#include "character.h"

using namespace std;

Character::Character()
{
	characterStats.hp = 100;
	characterStats.speed = 30;
	characterStats.inspiration = 1;
	characterStats.caps = 1500;
	characterStats.name = "bob";
	characterStats.race = "human";
	characterStats.alignment = "chaotic good";
	initSpecial();
	initLimbs();
}

Character::Character(string name)
{
	characterStats.hp = 100;
	characterStats.speed = 30;
	characterStats.inspiration = 1;
	characterStats.caps = 1500;
	characterStats.name = name;
	characterStats.race = "human";
	characterStats.alignment = "chaotic good";
	initSpecial();
	initLimbs();
}

void Character::addBioEntry(string entry)
{
	characterStats.bio.push_back(entry);
}

void Character::addTraitEntry(string entry)
{
	characterStats.traits.push_back(entry);
}

void Character::addEffectsEntry(string entry)
{
	characterStats.effects.push_back(entry);
}

void Character::addItemEntry(string item)
{
	characterStats.inventory.push_back(item);
}

void Character::addGunEntry(shared_ptr<Gun> g)
{
	characterStats.playerGuns.addGun(g);
}




void Character::print()
{
	cout << "Information" << endl << endl;
	cout << "Name: " << characterStats.name << endl;
	cout << "Alignment: " << characterStats.alignment << endl;
	cout << "Race: " << characterStats.race << endl;
	cout << "HP: " << characterStats.hp << endl;
	cout << "Speed: " << characterStats.speed << "ft" << endl;
	cout << "Inspiration: " << characterStats.inspiration << endl;
	cout << "Caps: " << characterStats.caps << endl << endl;
	cout << "S.P.E.C.I.A.L" << endl << endl;
	for (std::map<string, int>::iterator it = characterStats.special.begin(); it != characterStats.special.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	cout << "Crit Damage: " << characterStats.critDmg << endl;
	cout << "Rad Threshold: " << characterStats.radThresh << endl;

	cout << endl << "Limbs" << endl << endl;
	for (std::map<string, int>::iterator it = characterStats.limbs.begin(); it != characterStats.limbs.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	cout << endl << "Biography" << endl;
	for (int i = 0; i < characterStats.bio.size(); ++i) {
		cout << "+ " << characterStats.bio[i] << endl;
	}

	cout << endl << "Traits" << endl;
	for (int i = 0; i < characterStats.traits.size(); ++i) {
		cout << "+ " << characterStats.traits[i] << endl;
	}

	cout << endl << "Effects" << endl;
	for (int i = 0; i < characterStats.effects.size(); ++i) {
		cout << "+ " << characterStats.effects[i] << endl;
	}

	cout << endl << "Arsenal" << endl;
	characterStats.playerGuns.displayArsenal();

	cout << endl << "Inventory" << endl;
	for (int i = 0; i < characterStats.inventory.size(); ++i) {
		cout << "+ " << characterStats.inventory[i] << endl;
	}

	/*
	for (int i = 0; i < characterStats.inventory.size(); ++i) {
		cout << "+ " << characterStats.inventory[i].name << endl;
		cout << "  Description: " << characterStats.inventory[i].description << endl;
		cout << "  Weight: " << characterStats.inventory[i].weight << endl;
		cout << "  Count: " << characterStats.inventory[i].number << endl;
		cout << "  Total Weight: " << characterStats.inventory[i].number * characterStats.inventory[i].weight << endl;
	}
	cout << "Total Inventory Weight: " << getTotalWeight() << endl;
	*/
	

}

void Character::initSpecial()
{
	characterStats.special.insert(make_pair("strength", 0));
	characterStats.special.insert(make_pair("perception", 0));
	characterStats.special.insert(make_pair("endurance", 0));
	characterStats.special.insert(make_pair("charisma", 0));
	characterStats.special.insert(make_pair("inteligence", 0));
	characterStats.special.insert(make_pair("agility", 0));
	characterStats.special.insert(make_pair("luck", 0));
}

void Character::initLimbs()
{
	characterStats.limbs.insert(make_pair("chest", 5));
	characterStats.limbs.insert(make_pair("head", 5));
	characterStats.limbs.insert(make_pair("larm", 5));
	characterStats.limbs.insert(make_pair("rarm", 5));
	characterStats.limbs.insert(make_pair("lleg", 5));
	characterStats.limbs.insert(make_pair("rleg", 5));
}

///int Character::getTotalWeight()
//{
//	int totalWeight = 0;
//	for (int i = 0; i < characterStats.inventory.size(); ++i) {
//		totalWeight += characterStats.inventory[i].weight * characterStats.inventory[i].number;
//	}
//	return totalWeight;
//}


string Character::getLine(int xLine) {


	string line;
	//opens and read through file to return specific line
	ifstream fIn;
	fIn.open("players.txt");
	for (int lineno = 1; getline(fIn, line); lineno++) {
		if (lineno == xLine)
			return line;
	}
	//fIn.close;
}

int Character::findPlayer(string name) {

	string line;
	//open and reads through file and returns line player data is on for getPlayer function
	ifstream fIn;
	fIn.open("players.txt");
	for (int lineno = 1; getline(fIn, line); lineno++) {
		if (line == name)
			return lineno;
	}
	return 0;
	//fIn.close;
}

void Character::save() {

	cout << "character saved"; 

	string name = characterStats.name;

	int player = findPlayer(name);


	ofstream fApp;
	fApp.open("players.txt", ios_base::app);


	//if player doesnt exist yet just adds it on end of file
	if (player == 0) {

		fApp << "\n" << characterStats.name;
		
		fApp << "\n" << characterStats.name + "Hp";
		fApp << "\n" << characterStats.hp;
		
		fApp << "\n" << characterStats.name + "Inspiration";
		fApp << "\n" << characterStats.inspiration;
		
		fApp << "\n" << characterStats.name + "Caps";
		fApp << "\n" << characterStats.caps;
		
		fApp << "\n" << characterStats.name + "Race";
		fApp << "\n" << characterStats.race;

		fApp << "\n" << characterStats.name + "Alignment";
		fApp << "\n" << characterStats.alignment;
		

		fApp << "\n" << characterStats.name + "Special";
		for (std::map<string, int>::iterator it = characterStats.special.begin(); it != characterStats.special.end(); ++it) {
			fApp << "\n" << characterStats.name + it->first;
			fApp << "\n" << it->second;
		}
		
		fApp << "\n" << characterStats.name + "Limbs";
		for (std::map<string, int>::iterator it = characterStats.limbs.begin(); it != characterStats.limbs.end(); ++it) {
			fApp << "\n" << characterStats.name + it->first;
			fApp << "\n" << it->second;
		}

		fApp << "\n" << characterStats.name + "Bio";
		for (int i = 0; i < characterStats.bio.size(); ++i) {
			fApp << "\n" << characterStats.bio[i];
		}
		fApp << "\n" << characterStats.name + "BioEnd";

		fApp << "\n" << characterStats.name + "Traits";
		for (int i = 0; i < characterStats.traits.size(); ++i) {
			fApp << "\n" << characterStats.traits[i];
		}
		fApp << "\n" << characterStats.name + "TraitsEnd";

		fApp << "\n" << characterStats.name + "Effects";
		for (int i = 0; i < characterStats.effects.size(); ++i) {
			fApp << "\n" << characterStats.effects[i];
		}
		fApp << "\n" << characterStats.name + "EffectsEnd";


		fApp << "\n" << characterStats.name + "Inventory";
		/*for (int i = 0; i < characterStats.inventory.size(); ++i) {
			fApp << "\n" << characterStats.inventory[i].name;
			fApp << "\n" << characterStats.inventory[i].description;
			fApp << "\n" << characterStats.inventory[i].number;
			fApp << "\n" << characterStats.inventory[i].weight;
		}*/
		fApp << "\n" << characterStats.name + "InventoryEnd";

		fApp << "\n" << characterStats.name + "Arsenal";
		for (int i = 0; i < characterStats.playerGuns.size(); ++i) {
			fApp << "\n" << characterStats.playerGuns.getGunIndex(i)->name();
		
		}
		fApp << "\n" << characterStats.name + "ArsenalEnd";

		fApp << "\n" << characterStats.name + "End";

		
		
	}

	//if player does exits reads players.txt into vector switchs appropriate data then writes it back out
	else if (player != 0) {

		vector <string> playerData;


		string line;

		ifstream fIn;
		fIn.open("players.txt");
		int y = 0;
		while (getline(fIn, line)) {

			playerData.push_back(line);
			y++;

		}
		//saving an existing player

		int PS = findPlayer(name);
		int PE = findPlayer(name + "End");
		playerData.erase(playerData.begin() + PS-1, playerData.begin() + PE);

		playerData.push_back(characterStats.name);

		playerData.push_back(characterStats.name + "Hp");
		playerData.push_back(to_string(characterStats.hp));

		playerData.push_back(characterStats.name + "Inspiration");
		playerData.push_back(to_string(characterStats.inspiration));

		playerData.push_back(characterStats.name + "Caps");
		playerData.push_back(to_string(characterStats.caps));

		playerData.push_back(characterStats.name + "Race");
		playerData.push_back(characterStats.race);

		playerData.push_back(characterStats.name + "Alignment");
		playerData.push_back(characterStats.alignment);


		playerData.push_back(characterStats.name + "Special");
		for (std::map<string, int>::iterator it = characterStats.special.begin(); it != characterStats.special.end(); ++it) {
			playerData.push_back(characterStats.name + it->first);
			playerData.push_back(to_string(it->second));
		}

		playerData.push_back(characterStats.name + "Limbs");
		for (std::map<string, int>::iterator it = characterStats.limbs.begin(); it != characterStats.limbs.end(); ++it) {
			playerData.push_back(characterStats.name + it->first);
			playerData.push_back(to_string(it->second));
		}

		playerData.push_back(characterStats.name + "Bio");
		for (int i = 0; i < characterStats.bio.size(); ++i) {
			playerData.push_back(characterStats.bio[i]);
		}
		playerData.push_back(characterStats.name + "BioEnd");

		playerData.push_back(characterStats.name + "Traits");
		for (int i = 0; i < characterStats.traits.size(); ++i) {
			playerData.push_back(characterStats.traits[i]);
		}
		playerData.push_back(characterStats.name + "TraitsEnd");

		playerData.push_back(characterStats.name + "Effects");
		for (int i = 0; i < characterStats.effects.size(); ++i) {
			playerData.push_back(characterStats.effects[i]);
		}
		playerData.push_back(characterStats.name + "EffectsEnd");

		playerData.push_back(characterStats.name + "Inventory");
		for (int i = 0; i < characterStats.inventory.size(); ++i) {
			playerData.push_back(characterStats.inventory[i]);
		}

		/*for (int i = 0; i < characterStats.inventory.size(); ++i) {
			playerData.push_back(characterStats.inventory[i].name);
			playerData.push_back(characterStats.inventory[i].description);
			playerData.push_back(to_string(characterStats.inventory[i].number));
			playerData.push_back(to_string(characterStats.inventory[i].weight));
		}*/
		playerData.push_back(characterStats.name + "InventoryEnd");

		
		playerData.push_back(characterStats.name + "Arsenal");
		for (int i = 0; i < characterStats.playerGuns.size(); ++i) {
			playerData.push_back(characterStats.playerGuns.getGunIndex(i)->name());

		}
		playerData.push_back(characterStats.name + "ArsenalEnd");

		playerData.push_back(characterStats.name + "End");


		
		/*
		playerData[findPlayer(name + "Hp")] = to_string(testing.hp);
		playerData[findPlayer(name + "Inspiration")] = to_string(testing.inspiration);
		playerData[findPlayer(name + "Caps")] = to_string(testing.caps);
		playerData[findPlayer(name + "Race")] = testing.race;
		playerData[findPlayer(name + "Alignment")] = testing.alignment;


		for (std::map<string, int>::iterator it = testing.special.begin(); it != testing.special.end(); ++it) {
			playerData[findPlayer(testing.name + it->first)] = to_string(it->second);
		}

		for (std::map<string, int>::iterator it = testing.limbs.begin(); it != testing.limbs.end(); ++it) {
			playerData[findPlayer(testing.name + it->first)] = to_string(it->second);
		}

		int BS = findPlayer(testing.name + "Bio");
		int BE = findPlayer(testing.name + "BioEnd");
		playerData.erase(playerData.begin() + BS + 1, playerData.begin() + BE);
		for (int i = 0; i < testing.bio.size() - 1; ++i) {
			playerData.insert(playerData.begin() + BE - 1 , testing.bio[i]);
		}

		
		int TS = findPlayer(testing.name + "Traits");
		int TE = findPlayer(testing.name + "TraitsEnd");
		playerData.erase(playerData.begin() + TS + 1, playerData.begin() + TE);
		for (int i = 0; i < testing.traits.size() - 1; ++i) {
			playerData.insert(playerData.begin() + TE - 1, testing.traits[i]);
		}
		
		
		int ES = findPlayer(testing.name + "Effects");
		int EE = findPlayer(testing.name + "EffectsEnd");
		playerData.erase(playerData.begin() + ES + 1, playerData.begin() + EE);
		for (int i = 0; i < testing.effects.size() - 1; ++i) {
			playerData.insert(playerData.begin() + EE - 1, testing.effects[i]);
		}
		*/
		//add savign vectors for exsitign players

		ofstream fOut;
		fOut.open("players.txt");

		for (int x = 0; x < playerData.size(); x++) {
			fOut << playerData[x] << endl;
		}

	}
}

void Character::load(string s) {


	//cout << "Character Name: ";
	string nLoad;
	//getline(cin, nLoad);

	nLoad = s;

	int p = findPlayer(nLoad);

	if (p != 0) {

		string name = nLoad;

		characterStats.name = nLoad;
		characterStats.hp = stoi(getLine(findPlayer(name + "Hp") + 1));
		characterStats.inspiration = stoi(getLine(findPlayer(name + "Inspiration") + 1));
		characterStats.caps = stoi(getLine(findPlayer(name + "Caps") + 1));
		characterStats.race = getLine(findPlayer(name + "Race") + 1);
		characterStats.alignment = getLine(findPlayer(name + "Alignment") + 1);

		for (std::map<string, int>::iterator it = characterStats.special.begin(); it != characterStats.special.end(); ++it) {
			characterStats.special[it->first] = stoi(getLine(findPlayer(characterStats.name + it->first) + 1));
		}

		for (std::map<string, int>::iterator it = characterStats.limbs.begin(); it != characterStats.limbs.end(); ++it) {
			characterStats.limbs[it->first] = stoi(getLine(findPlayer(characterStats.name + it->first) + 1));
		}

		int BS = findPlayer(characterStats.name + "Bio");
		int BE = findPlayer(characterStats.name + "BioEnd");
		for (int i = 0; i < BE - BS - 1; ++i) {
			characterStats.bio.push_back(getLine(BS + 1 + i));
		}

		int TS = findPlayer(characterStats.name + "Traits");
		int TE = findPlayer(characterStats.name + "TraitsEnd");
		for (int i = 0; i < TE - TS - 1; ++i) {
			characterStats.traits.push_back(getLine(TS + 1 + i));
		}
		int ES = findPlayer(characterStats.name + "Effects");
		int EE = findPlayer(characterStats.name + "EffectsEnd");
		for (int i = 0; i < EE - ES - 1; ++i) {
			characterStats.effects.push_back(getLine(ES + 1 + i));
		}

		int IS = findPlayer(characterStats.name + "Inventory");
		int IE = findPlayer(characterStats.name + "InventoryEnd");
		for (int i = 0; i < IE - IS - 1; i += 4) {
			string name = getLine(IS + i + 1);
			string description = getLine(IS + i + 2);
			int w = stoi(getLine(IS + i + 3));
			int q = stoi(getLine(IS + i + 4));

			Item myItem = { name , description, w, q };
			addItemEntry(name);
		}


		int AS = findPlayer(characterStats.name + "Arsenal");
		int AE = findPlayer(characterStats.name + "ArsenalEnd");
		for (int i = 0; i < AE - AS - 1; i++) {

			if (getLine(AS + i + 1) == "AR") {
				shared_ptr<AR> AR(new AR());
				characterStats.playerGuns.addGun(AR);
			}

			if (getLine(AS + i + 1) == "BR") {
				shared_ptr<BR> BR(new BR());
				characterStats.playerGuns.addGun(BR);
			}

			if (getLine(AS + i + 1) == "Pistol") {
				shared_ptr<Pistol> Pistol(new Pistol());
				characterStats.playerGuns.addGun(Pistol);
			}

			if (getLine(AS + i + 1) == "Heavy") {
				shared_ptr<Heavy> Heavy(new Heavy());
				characterStats.playerGuns.addGun(Heavy);
			}

			if (getLine(AS + i + 1) == "LMG") {
				shared_ptr<LMG> LMG(new LMG());
				characterStats.playerGuns.addGun(LMG);
			}

			if (getLine(AS + i + 1) == "Shotgun") {
				shared_ptr<Shotgun> Shotgun(new Shotgun());
				characterStats.playerGuns.addGun(Shotgun);
			}

			if (getLine(AS + i + 1) == "SMG") {
				shared_ptr<SMG> SMG(new SMG());
				characterStats.playerGuns.addGun(SMG);
			}

			if (getLine(AS + i + 1) == "Sniper") {
				shared_ptr<Sniper> Sniper(new Sniper());
				characterStats.playerGuns.addGun(Sniper);
			}
		}



		cout << "Character " << nLoad << " loaded" << endl;
	}

	else if (p == 0) {

		cout << "Created new character " << nLoad << endl;

		cin.clear();

		cout << "What is your character's race: ";

		getline(cin, characterStats.race);

		cin.clear();
		cout << "What is your chracter's alignment: ";

		getline(cin, characterStats.alignment);

		cin.clear();
		cout << "How many caps does your character have: ";

		characterStats.caps = getUserInt();

		cin.clear();
		cout << "How many inspiration points does your character have: ";

		characterStats.inspiration = getUserInt();

		cout << "S.P.E.C.I.A.L." << endl;
		cout << "Pelase enter each of your starting special stats" << endl;

		cout << "Strength: ";
		characterStats.special["strength"] = getUserInt();

		cout << "Perception: ";
		characterStats.special["perception"] = getUserInt();

		cout << "Endurance: ";
		characterStats.special["endurance"] = getUserInt();

		cout << "Charisma: ";
		characterStats.special["charisma"] = getUserInt();

		cout << "Inteligence: ";
		characterStats.special["inteligence"] = getUserInt();

		cout << "Agility: ";
		characterStats.special["agility"] = getUserInt();

		cout << "Luck: ";
		characterStats.special["luck"] = getUserInt();

		characterStats.name = nLoad;
	}
}
	

string Character::getName() {
		return characterStats.name;
	}

string Character::getSpeed() {
	return to_string(characterStats.speed);
}

string Character::getRace() {
	return characterStats.race;
}

string Character::getAlignment() {
	return characterStats.alignment;
}

string Character::getHP() {
	return to_string(characterStats.hp);
}

string Character::getStr() {
	return to_string(characterStats.special["strength"]);
}

string Character::getPer() {
	return to_string(characterStats.special["perception"]);
}

string Character::getEnd() {
	return to_string(characterStats.special["endurance"]);
}

string Character::getCha() {
	return to_string(characterStats.special["charisma"]);
}

string Character::getInt() {
	return to_string(characterStats.special["inteligence"]);
}

string Character::getAgi() {
	return to_string(characterStats.special["agility"]);
}

string Character::getLuc() {
	return to_string(characterStats.special["luck"]);
}

string Character::getHead() {
	return to_string(characterStats.limbs["head"]);
}

string Character::getChest(){
	return to_string(characterStats.limbs["chest"]);
}

string Character::getRArm() {
	return to_string(characterStats.limbs["rarm"]);
}

string Character::getLArm() {
	return to_string(characterStats.limbs["larm"]);
}

string Character::getRLeg() {
	return to_string(characterStats.limbs["rleg"]);
}

string Character::getLLeg() {
	return to_string(characterStats.limbs["lleg"]);
}

string Character::getBio() {
	
	string final = "";

	for (int i = 0; i < characterStats.bio.size(); i++) {

		final += characterStats.bio[i] + " * ";

	}

	return final;
}

string Character::getTraits() {

	string final = "";

	for (int i = 0; i < characterStats.traits.size(); i++) {

		final += characterStats.traits[i] + " * ";

	}

	return final;
}

string Character::getEffects() {

	string final = "";

	for (int i = 0; i < characterStats.effects.size(); i++) {

		final += characterStats.effects[i] + " * ";

	}

	return final;
}

string Character::getItemNames() {

	string final = "";

	for (int i = 0; i < characterStats.inventory.size(); i++) {

		final += characterStats.inventory[i] + " * ";

	}

	return final;
}

string Character::getGunNames() {

	return characterStats.playerGuns.name();

}