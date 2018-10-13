
//GLUT and Shapes
#include "graphics.hpp"
#include "rectangle.h"
#include "ellipse.h"
//Button Stuff
#include "Button.h"
//Character Stuff
#include "structs.h"
#include "GameLogic.h"
#include "character.h"
//General Stuff
#include <string>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
//Using Standard Namespace
using namespace std;

//Forward Declaration of renderBitmapString
//void renderBitmapString(double x, double y, char *str, double xmax, void *font);

//-------------------------------------------------------------------------------------
// INITIALIZATION ---------------------------------------------------------------------
//-------------------------------------------------------------------------------------

// VARIABLES --------------------------------------------------------------------------

//enum screen {menu, character, addItem, addGun, textBox};

screen currentScreen;
GLdouble width, height;
int wd;

int mouseX, mouseY;

string input;

GameLogic gl;

// CHARACTER MENU SHAPES ---------------------------------------------------------------

// Back Panel for Character Screen
geometry::Rectangle characterPanel;

// Panel for Buttons
geometry::Rectangle buttonPanel;
	// Create/Load Button Box
	geometry::Rectangle loadButtonBox;
	// Save Button Box
	geometry::Rectangle saveButtonBox;
	// Add Bio Button Box
	geometry::Rectangle bioButtonBox;
	// Add Trait Button Box
	geometry::Rectangle traitButtonBox;
	// Add Effect Button Box
	geometry::Rectangle effectButtonBox;
	// Add Gun Button Box
	geometry::Rectangle gunButtonBox;
	// Add Item Button Box
	geometry::Rectangle itemButtonBox;

// Name Panel
geometry::Rectangle namePanel;
	// Name Panel
	geometry::Rectangle nameBox;

// Race, Alignment, Traits, and Bio Panel
geometry::Rectangle artbPanel;
	// Alignment Box
	geometry::Rectangle alignBox;
	// Race Box
	geometry::Rectangle raceBox;
	// Traits Box
	geometry::Rectangle traitsBox;
	// Bio Box
	geometry::Rectangle bioBox;

// SPECIAL Panel
geometry::Rectangle specialPanel;
	// SPECIAL Boxes
	geometry::Rectangle strBox;
	geometry::Rectangle perBox;
	geometry::Rectangle endBox;
	geometry::Rectangle chaBox;
	geometry::Rectangle intBox;
	geometry::Rectangle aglBox;
	geometry::Rectangle luckBox;

// Health and Speed Panel
geometry::Rectangle hsPanel;
	// Health
	geometry::Rectangle hpBox;
	// Speed
	geometry::Rectangle spdBox;

// Crit and Rad Panel
geometry::Rectangle crPanel;
	// Crit
	geometry::Rectangle critBox;
	// Rad
	geometry::Rectangle radBox;

// Limbs Panel
geometry::Rectangle limbPanel;
	// Limb Boxes
	geometry::Rectangle larmBox;
	geometry::Rectangle headBox;
	geometry::Rectangle rarmBox;
	geometry::Rectangle llegBox;
	geometry::Rectangle chestBox;
	geometry::Rectangle rlegBox;

// Arsenal Panel
geometry::Rectangle arsenalPanel;
	// Arsenal Box
	geometry::Rectangle arsenalBox;

// Inventory Panel
geometry::Rectangle invPanel;
	// Caps Box
	geometry::Rectangle capsBox;
	// Inventory Box
	geometry::Rectangle invBox;

// Effects Panel
geometry::Rectangle effectsPanel;
	// Effects Box
	geometry::Rectangle effectsBox;

// TEXT-BOX MENU SHAPES ---------------------------------------------------------------

// Text-Box Back Panel
geometry::Rectangle textPanel;
	// Text-Box Info Box
	geometry::Rectangle infoBox;
	// Text-Box Input Box
	geometry::Rectangle inputBox;

//-------------------------------------------------------------------------------------
// TEXT-BOX STUFF ---------------------------------------------------------------------
//-------------------------------------------------------------------------------------

void renderBitmapString(double x, double y, char *str, double xmax, void *font = GLUT_BITMAP_9_BY_15) {
	double curx, cury;
	curx = x;
	cury = y;
	glRasterPos2d(x, y);
	glColor3f(0, 0, 0);
	for (char* it = str; *it; ++it) {
		if (curx > xmax) {
			curx = x;
			cury += 15;
			glRasterPos2d(curx, cury);
		}
		glutBitmapCharacter(font, *it);
		curx += 9;
	}
}

void updateString() {
	renderBitmapString(100, 100, &input[0u], 200);
}

// --------------------------------------------------------------------------------
// BUTTON COLOR STUFF --------------------------------------------------------------
// --------------------------------------------------------------------------------

/*
void updateColor(RectangleCoord &r, int x, int y) {
	// if the mouse overlaps with rectangle r, set r to be indigo
	if (r.isOverlapping(x, y)) {
		r.setFill(97 / 255.0, 0, 158 / 255.0);
	}
	else {
		// not overlapping, so return to original color
		r.setFill((127 / 255.0), 1, 0);
	}
}
*/

// --------------------------------------------------------------------------------
// BUTTON STUFF -------------------------------------------------------------------
// --------------------------------------------------------------------------------

Character playerCharacter;

void gunz(string type) {

	if (type == "pistol") {
		shared_ptr<Gun> myGun(new Pistol());
		playerCharacter.addGunEntry(myGun);
		cout << "Pistol added to character arsenal" << endl;
	}
	else if (type == "smg") {
		shared_ptr<Gun> myGun(new SMG());
		playerCharacter.addGunEntry(myGun);
		cout << "Submachine gun added to character arsenal" << endl;
	}
	else if (type == "shotgun") {
		shared_ptr<Gun> myGun(new Shotgun());
		playerCharacter.addGunEntry(myGun);
		cout << "Shotgun added to character arsenal" << endl;
	}
	else if (type == "ar") {
		shared_ptr<Gun> myGun(new AR());
		playerCharacter.addGunEntry(myGun);
		cout << "Assault rifle added to character arsenal" << endl;
	}
	else if (type == "br") {
		shared_ptr<Gun> myGun(new BR());
		playerCharacter.addGunEntry(myGun);
		cout << "Battle rifle added to character arsenal" << endl;
	}
	else if (type == "sniper") {
		shared_ptr<Gun> myGun(new Sniper());
		playerCharacter.addGunEntry(myGun);
		cout << "Sniper rifle added to character arsenal" << endl;
	}
	else if (type == "heavy") {
		shared_ptr<Gun> myGun(new Heavy());
		playerCharacter.addGunEntry(myGun);
		cout << "Heavy weapon added to character arsenal" << endl;
	}
}

void itemz(string s) {
	/*vector<string> array;
	std::size_t pos = 0, found;
	while ((found = s.find_first_of(' ', pos)) != string::npos) {
		array.push_back(s.substr(pos, found - pos));
		pos = found + 1;
	}
	array.push_back(s.substr(pos));

	Item myItem = { array[0], array[1],stoi(array[2]), stoi(array[3]) };*/
	playerCharacter.addItemEntry(s);
}

void loadChar(string s) {
	playerCharacter.load(s);
	gl.UpdateCharacterStats(playerCharacter);
}

void saveChar() {
	playerCharacter.save();
}

void printChar() {
	playerCharacter.print();
}

void addTrait(string s) {
	playerCharacter.addTraitEntry(s);
}
void addEffects(string s) {
	playerCharacter.addEffectsEntry(s);
}

void addBio(string s) {
	playerCharacter.addBioEntry(s);
}

int flag;
int itemFlag = 0;

vector<Button> buttons;

//Button printStats(printChar, character, character, "Print Stats");
Button loadButton(loadChar, characterMenu, addCharacterMenu, "Load Character");
Button saveButton(saveChar, characterMenu, characterMenu, "Sacve Character");
Button bioButton(addBio, characterMenu, addBioMenu, "Add Bio");
Button traitButton(addTrait, characterMenu, addTraitMenu, "Add Trait");
Button effectButton(addEffects, characterMenu, addEffectMenu, "Add Effect");
Button gunButton(gunz, characterMenu, addGunMenu, "Add Gun");
Button itemButton(itemz, characterMenu, addItemMenu, "Add Item");


// DRAWING PANE -----------------------------------------------------------------------

void init() {
	// set height and width of drawing pane
	height = 900;
	width = 900;

	// set default screen
	currentScreen = mainMenu;

	// initialize mouse coordinates
	mouseX = mouseY = -1;

	// Set input to an empty String
	input = "";

	//------------------------------------------------------------------------------------
	// CHARACTER MENU SHAPES -------------------------------------------------------------
	//------------------------------------------------------------------------------------

	// Main Panel and Buttons ---------------------------------------------------------
	
	// Character Menu Back Panel 
	characterPanel.setFill(0, 1, 1);
	characterPanel.setHeight(height * 0.95);
	characterPanel.setWidth(width * 0.95);
	characterPanel.setCenter(width/2, height/2);

	// Button Panel
	buttonPanel.setFill(1, 1, 1);
	buttonPanel.setHeight(characterPanel.getHeight() * 0.07);
	buttonPanel.setWidth(characterPanel.getWidth() * 0.95);
	buttonPanel.setCenter(characterPanel.getCenter().getX(), characterPanel.getCenter().getY() - ((characterPanel.getHeight()/2) * 0.85));
		// Create/Load Button Box
		loadButtonBox.setFill(0, 1, 1);
		loadButtonBox.setHeight(buttonPanel.getHeight() * 0.75);
		loadButtonBox.setWidth(buttonPanel.getWidth() * 0.10);
		loadButtonBox.setCenter(buttonPanel.getCenter().getX() - ((buttonPanel.getWidth() / 2) * 0.84), buttonPanel.getCenter().getY() - ((buttonPanel.getHeight() / 2) * 0.00));
		// Save Button Box
		saveButtonBox.setFill(0, 1, 1);
		saveButtonBox.setHeight(buttonPanel.getHeight() * 0.75);
		saveButtonBox.setWidth(buttonPanel.getWidth() * 0.10);
		saveButtonBox.setCenter(buttonPanel.getCenter().getX() - ((buttonPanel.getWidth() / 2) * 0.56), buttonPanel.getCenter().getY() - ((buttonPanel.getHeight() / 2) * 0.00));
		// Add Bio Button Box
		bioButtonBox.setFill(0, 1, 1);
		bioButtonBox.setHeight(buttonPanel.getHeight() * 0.75);
		bioButtonBox.setWidth(buttonPanel.getWidth() * 0.10);
		bioButtonBox.setCenter(buttonPanel.getCenter().getX() - ((buttonPanel.getWidth() / 2) * 0.28), buttonPanel.getCenter().getY() - ((buttonPanel.getHeight() / 2) * 0.00));
		// Add Trait Button Box
		traitButtonBox.setFill(0, 1, 1);
		traitButtonBox.setHeight(buttonPanel.getHeight() * 0.75);
		traitButtonBox.setWidth(buttonPanel.getWidth() * 0.10);
		traitButtonBox.setCenter(buttonPanel.getCenter().getX() + ((buttonPanel.getWidth() / 2) * 0.00), buttonPanel.getCenter().getY() - ((buttonPanel.getHeight() / 2) * 0.00));
		// Add Gun Button Box
		gunButtonBox.setFill(0, 1, 1);
		gunButtonBox.setHeight(buttonPanel.getHeight() * 0.75);
		gunButtonBox.setWidth(buttonPanel.getWidth() * 0.10);
		gunButtonBox.setCenter(buttonPanel.getCenter().getX() + ((buttonPanel.getWidth() / 2) * 0.28), buttonPanel.getCenter().getY() - ((buttonPanel.getHeight() / 2) * 0.00));
		// Add Item Button Box
		itemButtonBox.setFill(0, 1, 1);
		itemButtonBox.setHeight(buttonPanel.getHeight() * 0.75);
		itemButtonBox.setWidth(buttonPanel.getWidth() * 0.10);
		itemButtonBox.setCenter(buttonPanel.getCenter().getX() + ((buttonPanel.getWidth() / 2) * 0.56), buttonPanel.getCenter().getY() - ((buttonPanel.getHeight() / 2) * 0.00));
		// Add Effect Button Box
		effectButtonBox.setFill(0, 1, 1);
		effectButtonBox.setHeight(buttonPanel.getHeight() * 0.75);
		effectButtonBox.setWidth(buttonPanel.getWidth() * 0.10);
		effectButtonBox.setCenter(buttonPanel.getCenter().getX() + ((buttonPanel.getWidth() / 2) * 0.84), buttonPanel.getCenter().getY() - ((buttonPanel.getHeight() / 2) * 0.00));

	// Character Info ------------------------------------------------------------------

	// Name Panel
	namePanel.setFill(1, 1, 1);
	namePanel.setHeight(characterPanel.getHeight() * 0.10);
	namePanel.setWidth((characterPanel.getWidth() * 0.86) / 2);
	namePanel.setCenter(characterPanel.getCenter().getX() - ((characterPanel.getWidth() / 2) * 0.52), characterPanel.getCenter().getY() - ((characterPanel.getHeight() / 2) * 0.63));
		//Name Box
		nameBox.setFill(0, 1, 1);
		nameBox.setHeight(namePanel.getHeight() * 0.65);
		nameBox.setWidth(namePanel.getWidth()  * 0.90);
		nameBox.setCenter(namePanel.getCenter().getX() - ((namePanel.getWidth() / 2) * 0.00), namePanel.getCenter().getY() - ((namePanel.getHeight() / 2) * 0.00));

	// Alignment, Race, Traits, and Bio Panel
	artbPanel.setFill(1, 1, 1);
	artbPanel.setHeight(characterPanel.getHeight() * 0.70);
	artbPanel.setWidth(characterPanel.getWidth() * 0.20);
	artbPanel.setCenter(characterPanel.getCenter().getX() - ((characterPanel.getWidth() / 2) * 0.75), characterPanel.getCenter().getY() + ((characterPanel.getHeight() / 2) * 0.20));
		// Alignment Box
		alignBox.setFill(0, 1, 1);
		alignBox.setHeight(artbPanel.getHeight() * 0.05);
		alignBox.setWidth(artbPanel.getWidth() * 0.85);
		alignBox.setCenter(artbPanel.getCenter().getX(), artbPanel.getCenter().getY() - ((characterPanel.getHeight() / 2) * 0.62));
		// Race Box
		raceBox.setFill(0, 1, 1);
		raceBox.setHeight(artbPanel.getHeight() * 0.05);
		raceBox.setWidth(artbPanel.getWidth() * 0.85);
		raceBox.setCenter(artbPanel.getCenter().getX(), artbPanel.getCenter().getY() - ((characterPanel.getHeight() / 2) * 0.50));
		// Traits Box
		traitsBox.setFill(0, 1, 1);
		traitsBox.setHeight(artbPanel.getHeight() * 0.25);
		traitsBox.setWidth(artbPanel.getWidth() * 0.85);
		traitsBox.setCenter(artbPanel.getCenter().getX(), artbPanel.getCenter().getY() - ((characterPanel.getHeight() / 2) * 0.24));
		// Bio Box
		bioBox.setFill(0, 1, 1);
		bioBox.setHeight(artbPanel.getHeight() * 0.47);
		bioBox.setWidth(artbPanel.getWidth() * 0.85);
		bioBox.setCenter(artbPanel.getCenter().getX(), artbPanel.getCenter().getY() + ((characterPanel.getHeight() / 2) * 0.32));

	// Primary Stats ------------------------------------------------------------------

	// SPECIAL Panel
	specialPanel.setFill(1, 1, 1);
	specialPanel.setHeight(characterPanel.getHeight() * 0.70);
	specialPanel.setWidth(characterPanel.getWidth() * 0.20);
	specialPanel.setCenter(characterPanel.getCenter().getX() - ((characterPanel.getWidth() / 2) * 0.30), characterPanel.getCenter().getY() + ((characterPanel.getHeight() / 2) * 0.20));
		// STR Box
		strBox.setFill(0, 1, 1);
		strBox.setHeight(specialPanel.getHeight() * 0.10);
		strBox.setWidth(specialPanel.getWidth()  * 0.85);
		strBox.setCenter(specialPanel.getCenter().getX(), specialPanel.getCenter().getY() - ((specialPanel.getHeight() / 2) * 0.84));
		// PER Box
		perBox.setFill(0, 1, 1);
		perBox.setHeight(specialPanel.getHeight() * 0.10);
		perBox.setWidth(specialPanel.getWidth()  * 0.85);
		perBox.setCenter(specialPanel.getCenter().getX(), specialPanel.getCenter().getY() - ((specialPanel.getHeight() / 2) * 0.56));
		// END Box
		endBox.setFill(0, 1, 1);
		endBox.setHeight(specialPanel.getHeight() * 0.10);
		endBox.setWidth(specialPanel.getWidth()  * 0.85);
		endBox.setCenter(specialPanel.getCenter().getX(), specialPanel.getCenter().getY() - ((specialPanel.getHeight() / 2) * 0.28));
		// CHA Box
		chaBox.setFill(0, 1, 1);
		chaBox.setHeight(specialPanel.getHeight() * 0.10);
		chaBox.setWidth(specialPanel.getWidth()  * 0.85);
		chaBox.setCenter(specialPanel.getCenter().getX(), specialPanel.getCenter().getY() + ((specialPanel.getHeight() / 2) * 0.00));
		// INT Box
		intBox.setFill(0, 1, 1);
		intBox.setHeight(specialPanel.getHeight() * 0.10);
		intBox.setWidth(specialPanel.getWidth()  * 0.85);
		intBox.setCenter(specialPanel.getCenter().getX(), specialPanel.getCenter().getY() + ((specialPanel.getHeight() / 2) * 0.28));
		// AGL Box
		aglBox.setFill(0, 1, 1);
		aglBox.setHeight(specialPanel.getHeight() * 0.10);
		aglBox.setWidth(specialPanel.getWidth()  * 0.85);
		aglBox.setCenter(specialPanel.getCenter().getX(), specialPanel.getCenter().getY() + ((specialPanel.getHeight() / 2) * 0.56));
		// LUCK Box
		luckBox.setFill(0, 1, 1);
		luckBox.setHeight(specialPanel.getHeight() * 0.10);
		luckBox.setWidth(specialPanel.getWidth()  * 0.85);
		luckBox.setCenter(specialPanel.getCenter().getX(), specialPanel.getCenter().getY() + ((specialPanel.getHeight() / 2) * 0.84));

	// Secondary Stats -----------------------------------------------------------------

	// HP and SPD Panel
	hsPanel.setFill(1, 1, 1);
	hsPanel.setHeight(characterPanel.getHeight() * 0.10);
	hsPanel.setWidth((characterPanel.getWidth() * 0.95) / 2);
	hsPanel.setCenter(characterPanel.getCenter().getX() + ((characterPanel.getWidth() / 2) * 0.47) , characterPanel.getCenter().getY() - ((characterPanel.getHeight() / 2) * 0.63));
		// HP
		hpBox.setFill(0, 1, 1);
		hpBox.setHeight(hsPanel.getHeight() * 0.65);
		hpBox.setWidth(hsPanel.getWidth()  * 0.40);
		hpBox.setCenter(hsPanel.getCenter().getX() - ((hsPanel.getWidth() / 2) * 0.50) , hsPanel.getCenter().getY() - ((hsPanel.getHeight() / 2) * 0.00));
		// SPD
		spdBox.setFill(0, 1, 1);
		spdBox.setHeight(hsPanel.getHeight() * 0.65);
		spdBox.setWidth(hsPanel.getWidth()  * 0.40);
		spdBox.setCenter(hsPanel.getCenter().getX() + ((hsPanel.getWidth() / 2) * 0.50), hsPanel.getCenter().getY() - ((hsPanel.getHeight() / 2) * 0.00));

	// Limb Panel
	limbPanel.setFill(1, 1, 1);
	limbPanel.setHeight(characterPanel.getHeight() * 0.15);
	limbPanel.setWidth((characterPanel.getWidth() * 0.95) / 2);
	limbPanel.setCenter(characterPanel.getCenter().getX() + ((characterPanel.getWidth() / 2) * 0.47), characterPanel.getCenter().getY() - ((characterPanel.getHeight() / 2) * 0.35));
		// Left Arm Box
		larmBox.setFill(0, 1, 1);
		larmBox.setHeight(limbPanel.getHeight() * 0.35);
		larmBox.setWidth(limbPanel.getWidth()  * 0.27);
		larmBox.setCenter(limbPanel.getCenter().getX() - ((limbPanel.getWidth() / 2) * 0.63), limbPanel.getCenter().getY() - ((limbPanel.getHeight() / 2) * 0.45));
		// Head Box
		headBox.setFill(0, 1, 1);
		headBox.setHeight(limbPanel.getHeight() * 0.35);
		headBox.setWidth(limbPanel.getWidth()  * 0.27);
		headBox.setCenter(limbPanel.getCenter().getX() - ((limbPanel.getWidth() / 2) * 0.00), limbPanel.getCenter().getY() - ((limbPanel.getHeight() / 2) * 0.45));
		// Right Arm Box
		rarmBox.setFill(0, 1, 1);
		rarmBox.setHeight(limbPanel.getHeight() * 0.35);
		rarmBox.setWidth(limbPanel.getWidth()  * 0.27);
		rarmBox.setCenter(limbPanel.getCenter().getX() + ((limbPanel.getWidth() / 2) * 0.63), limbPanel.getCenter().getY() - ((limbPanel.getHeight() / 2) * 0.45));
		// Left Leg Box
		llegBox.setFill(0, 1, 1);
		llegBox.setHeight(limbPanel.getHeight() * 0.35);
		llegBox.setWidth(limbPanel.getWidth()  * 0.27);
		llegBox.setCenter(limbPanel.getCenter().getX() - ((limbPanel.getWidth() / 2) * 0.63), limbPanel.getCenter().getY() + ((limbPanel.getHeight() / 2) * 0.45));
		// Chest Box
		chestBox.setFill(0, 1, 1);
		chestBox.setHeight(limbPanel.getHeight() * 0.35);
		chestBox.setWidth(limbPanel.getWidth()  * 0.27);
		chestBox.setCenter(limbPanel.getCenter().getX() - ((limbPanel.getWidth() / 2) * 0.00), limbPanel.getCenter().getY() + ((limbPanel.getHeight() / 2) * 0.45));
		// Right Leg Box
		rlegBox.setFill(0, 1, 1);
		rlegBox.setHeight(limbPanel.getHeight() * 0.35);
		rlegBox.setWidth(limbPanel.getWidth()  * 0.27);
		rlegBox.setCenter(limbPanel.getCenter().getX() + ((limbPanel.getWidth() / 2) * 0.63), limbPanel.getCenter().getY() + ((limbPanel.getHeight() / 2) * 0.45));

	// Items and Inventory ------------------------------------------------------------
	
	// Arsenal Panel
	arsenalPanel.setFill(1, 1, 1);
	arsenalPanel.setHeight(characterPanel.getHeight() * 0.17);
	arsenalPanel.setWidth((characterPanel.getWidth() * 0.95) / 2);
	arsenalPanel.setCenter(characterPanel.getCenter().getX() + ((characterPanel.getWidth() / 2) * 0.47), characterPanel.getCenter().getY() + ((characterPanel.getHeight() / 2) * 0.02));
		// Arsenal Box
		arsenalBox.setFill(0, 1, 1);
		arsenalBox.setHeight(arsenalPanel.getHeight() * 0.75);
		arsenalBox.setWidth(arsenalPanel.getWidth()  * 0.95);
		arsenalBox.setCenter(arsenalPanel.getCenter().getX() - ((arsenalPanel.getWidth() / 2) * 0.00), arsenalPanel.getCenter().getY() - ((arsenalPanel.getHeight() / 2) * 0.00));

	// Inventory Panel
	invPanel.setFill(1, 1, 1);
	invPanel.setHeight(characterPanel.getHeight() * 0.15);
	invPanel.setWidth((characterPanel.getWidth() * 0.95) / 2);
	invPanel.setCenter(characterPanel.getCenter().getX() + ((characterPanel.getWidth() / 2) * 0.47), characterPanel.getCenter().getY() + ((characterPanel.getHeight() / 2) * 0.40));
		// Inventory Box
		invBox.setFill(0, 1, 1);
		invBox.setHeight(invPanel.getHeight() * 0.75);
		invBox.setWidth(invPanel.getWidth()  * 0.95);
		invBox.setCenter(invPanel.getCenter().getX() - ((invPanel.getWidth() / 2) * 0.00), invPanel.getCenter().getY() - ((invPanel.getHeight() / 2) * 0.00));

	// Effects Panel
	effectsPanel.setFill(1, 1, 1);
	effectsPanel.setHeight(characterPanel.getHeight() * 0.15);
	effectsPanel.setWidth((characterPanel.getWidth() * 0.95) / 2);
	effectsPanel.setCenter(characterPanel.getCenter().getX() + ((characterPanel.getWidth() / 2) * 0.47), characterPanel.getCenter().getY() + ((characterPanel.getHeight() / 2) * 0.75));
		// Effects Box
		effectsBox.setFill(0, 1, 1);
		effectsBox.setHeight(effectsPanel.getHeight() * 0.75);
		effectsBox.setWidth(effectsPanel.getWidth()  * 0.95);
		effectsBox.setCenter(effectsPanel.getCenter().getX() - ((effectsPanel.getWidth() / 2) * 0.00), effectsPanel.getCenter().getY() - ((effectsPanel.getHeight() / 2) * 0.00));

	// Buttons -------------------------------------------------------------------------
	
	//printStats.setXY(785, 0);

	// New/Load Character Button
	loadButton.setWidth(loadButtonBox.getWidth());
	loadButton.setHeight(loadButtonBox.getHeight());
	loadButton.setCenter(loadButtonBox.getCenter().getX(), loadButtonBox.getCenter().getY());


	// Save Character Button
	saveButton.setWidth(saveButtonBox.getWidth());
	saveButton.setHeight(saveButtonBox.getHeight());
	saveButton.setCenter(saveButtonBox.getCenter().getX(), saveButtonBox.getCenter().getY());

	// Add Bio Button
	bioButton.setWidth(bioButtonBox.getWidth());
	bioButton.setHeight(bioButtonBox.getHeight());
	bioButton.setCenter(bioButtonBox.getCenter().getX(), bioButtonBox.getCenter().getY());
	
	// Add Trait Button
	traitButton.setWidth(traitButtonBox.getWidth());
	traitButton.setHeight(traitButtonBox.getHeight());
	traitButton.setCenter(traitButtonBox.getCenter().getX(), traitButtonBox.getCenter().getY());

	// Add Gun Button
	gunButton.setWidth(gunButtonBox.getWidth());
	gunButton.setHeight(gunButtonBox.getHeight());
	gunButton.setCenter(gunButtonBox.getCenter().getX(), gunButtonBox.getCenter().getY());

	// Add Item Button
	itemButton.setWidth(itemButtonBox.getWidth());
	itemButton.setHeight(itemButtonBox.getHeight());
	itemButton.setCenter(itemButtonBox.getCenter().getX(), itemButtonBox.getCenter().getY());

	// Add Effect Button
	effectButton.setWidth(effectButtonBox.getWidth());
	effectButton.setHeight(effectButtonBox.getHeight());
	effectButton.setCenter(effectButtonBox.getCenter().getX(), effectButtonBox.getCenter().getY());


	//buttons.push_back(printStats);
	buttons.push_back(loadButton);
	buttons.push_back(saveButton);

	buttons.push_back(bioButton);
	buttons.push_back(traitButton);
	buttons.push_back(effectButton);

	buttons.push_back(gunButton);
	buttons.push_back(itemButton);

	//------------------------------------------------------------------------------------
	// TEXT-BOX SHAPES -------------------------------------------------------------------
	//------------------------------------------------------------------------------------

	// Text-Box Back Panel 
	textPanel.setFill(0, 1, 1);
	textPanel.setHeight(height * 0.95);
	textPanel.setWidth(width * 0.95);
	textPanel.setCenter(width / 2, height / 2);
		//Info Box
		infoBox.setFill(1, 1, 1);
		infoBox.setHeight(textPanel.getHeight() * 0.25);
		infoBox.setWidth(textPanel.getWidth()  * 0.90);
		infoBox.setCenter(textPanel.getCenter().getX() - ((textPanel.getWidth() / 2) * 0.00), textPanel.getCenter().getY() - ((textPanel.getHeight() / 2) * 0.60));
		//Input Box
		inputBox.setFill(1, 1, 1);
		inputBox.setHeight(textPanel.getHeight() * 0.55);
		inputBox.setWidth(textPanel.getWidth()  * 0.90);
		inputBox.setCenter(textPanel.getCenter().getX() - ((textPanel.getWidth() / 2) * 0.00), textPanel.getCenter().getY() + ((textPanel.getHeight() / 2) * 0.30));
}

//-------------------------------------------------------------------------------------
// SCREEN STATES-----------------------------------------------------------------------
//-------------------------------------------------------------------------------------

// WELCOME MESSAGE --------------------------------------------------------------------

void displayMenu() {
	//Display Welcome Message
	string welcome = "Welcome to the Quest: Combat Character Manager!";
	// set color to lime green
	glColor3f(50 / 255.0, 205 / 255.0, 50 / 255.0);
	glRasterPos2i(width/5, height/3);
	for (int i = 0; i < welcome.length(); ++i) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, welcome[i]);
	}

	// Display Click Message
	string click = "Click Anywhere To Begin!";
	// set color to lime green
	glColor3f(250 / 255.0, 205 / 255.0, 250 / 255.0);
	glRasterPos2i(width / 3, height / 2.5);
	for (int i = 0; i < click.length(); ++i) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, click[i]);
	}
}

// MAIN CHARACTER MENU -----------------------------------------------------------------

void displayCharacterMenu() {

	// Draw Shapes for Menu Design -----------------------------------------------------

	// Draw Character Panel
	characterPanel.draw();
	
	// Draw Button Panel
	buttonPanel.draw();
		// Draw Create/Load Button Box
		loadButtonBox.onHoverColor(0, 1, 0);
		loadButtonBox.setIsInShape(mouseX, mouseY);
		loadButtonBox.draw();
		// Draw Save Button Box
		saveButtonBox.onHoverColor(0, 1, 0);
		saveButtonBox.setIsInShape(mouseX, mouseY);
		saveButtonBox.draw();
		// Draw Add Bio Button Box
		bioButtonBox.onHoverColor(0, 1, 0);
		bioButtonBox.setIsInShape(mouseX, mouseY);
		bioButtonBox.draw();
		// Draw Add Trait Button Box
		traitButtonBox.onHoverColor(0, 1, 0);
		traitButtonBox.setIsInShape(mouseX, mouseY);
		traitButtonBox.draw();
		// Draw Add Effect Button Box
		effectButtonBox.onHoverColor(0, 1, 0);
		effectButtonBox.setIsInShape(mouseX, mouseY);
		effectButtonBox.draw();
		// Draw Add Gun Button Box
		gunButtonBox.onHoverColor(0, 1, 0);
		gunButtonBox.setIsInShape(mouseX, mouseY);
		gunButtonBox.draw();
		// Draw Add Item Button Box
		itemButtonBox.onHoverColor(0, 1, 0);
		itemButtonBox.setIsInShape(mouseX, mouseY);
		itemButtonBox.draw();

	// Character Name Panel
	namePanel.draw();
		// Draw Name Box
		nameBox.draw();

	// Draw Alignment, Race, Traits, and Bio Panel
	artbPanel.draw();
		// Draw Alignment Box
		alignBox.draw();
		// Draw Race Box
		raceBox.draw();
		// Draw Traits Box
		traitsBox.draw();
		// Draw Bio Box 
		bioBox.draw();

	// Draw SPECIAL Panel
	specialPanel.draw();
		// Draw Strength Box
		strBox.draw();
		// Draw Perception Box
		perBox.draw();
		// Draw Endurance Box
		endBox.draw();
		// Draw Charisma
		chaBox.draw();
		// Draw Intelligence Box
		intBox.draw();
		// Draw Agility Box
		aglBox.draw();
		// Draw Luck Box
		luckBox.draw();

	// Draw Health and Speed Panel
	hsPanel.draw();
		// Draw HP Box
		hpBox.draw();
		//Draw SPD Box
		spdBox.draw();

	// Draw Limb Panel
	limbPanel.draw();
		//Draw Left Arm Box
		larmBox.draw();
		//Draw Head Box
		headBox.draw();
		//Draw Right Arm Box
		rarmBox.draw();
		//Draw Left Leg Box
		llegBox.draw();
		//Draw Chest Box
		chestBox.draw();
		//Draw Right Leg Box
		rlegBox.draw();

	// Draw Arsenal Panel
	arsenalPanel.draw();
		// Draw Arsenal Box
		arsenalBox.draw();

	// Draw Inventory Panel
	invPanel.draw();
		// Draw Inventory Box
		invBox.draw();

	// Draw Effects Panel
	effectsPanel.draw();
		// Draw Effects Box
		effectsBox.draw();

	// Draw Labels for Character Sheet ------------------------------------------------
	
	// Set Label Color Black
	renderBitmapString(0, 0, " ", 200);
	
	// Draw Button Panel Label
	renderBitmapString(buttonPanel.getCenter().getX() - (buttonPanel.getWidth() / 2), 
		buttonPanel.getCenter().getY() - (buttonPanel.getHeight() / 2), 
		"Button Panel", width, GLUT_BITMAP_9_BY_15);

	// Draw Create/Load Button Box Label
	renderBitmapString(loadButtonBox.getCenter().getX() - ((loadButtonBox.getWidth() / 2) * 0.85),
		loadButtonBox.getCenter().getY(),
		"New/Load", width, GLUT_BITMAP_8_BY_13);
	// Draw Save Button Box Label
	renderBitmapString(saveButtonBox.getCenter().getX() - ((saveButtonBox.getWidth() / 2) * 0.50),
		saveButtonBox.getCenter().getY(),
		"Save", width, GLUT_BITMAP_8_BY_13);
	// Draw Add Bio Button Box Label
	renderBitmapString(bioButtonBox.getCenter().getX() - ((bioButtonBox.getWidth() / 2) * 0.85),
		bioButtonBox.getCenter().getY(),
		"Add Bio", width, GLUT_BITMAP_8_BY_13);
	// Draw Add Trait Button Box Label
	renderBitmapString(traitButtonBox.getCenter().getX() - ((traitButtonBox.getWidth() / 2) * 1.00),
		traitButtonBox.getCenter().getY(),
		"Add Trait", width, GLUT_BITMAP_8_BY_13);
	// Draw Add Gun Button Box Label
	renderBitmapString(gunButtonBox.getCenter().getX() - ((gunButtonBox.getWidth() / 2) * 0.85),
		gunButtonBox.getCenter().getY(),
		"Add Gun", width, GLUT_BITMAP_8_BY_13);
	// Draw Add Item Button Box Label
	renderBitmapString(itemButtonBox.getCenter().getX() - ((itemButtonBox.getWidth() / 2) * 0.90),
		itemButtonBox.getCenter().getY(),
		"Add Item", width, GLUT_BITMAP_8_BY_13);
	// Draw Add Effect Button Box Label
	renderBitmapString(effectButtonBox.getCenter().getX() - ((effectButtonBox.getWidth() / 2) * 1.05),
		effectButtonBox.getCenter().getY(),
		"Add Effect", width, GLUT_BITMAP_8_BY_13);
	
	// Character Name Panel Label
	renderBitmapString(namePanel.getCenter().getX() - (namePanel.getWidth() / 2),
		namePanel.getCenter().getY() - (namePanel.getHeight() / 2),
		"Character Name", width, GLUT_BITMAP_9_BY_15);

	// Draw Alignment Box Label
	renderBitmapString(alignBox.getCenter().getX() - (alignBox.getWidth() / 2),
		alignBox.getCenter().getY() - (alignBox.getHeight() / 2),
		"Alignment", width, GLUT_BITMAP_9_BY_15);
	// Draw Race Box Label
	renderBitmapString(raceBox.getCenter().getX() - (raceBox.getWidth() / 2),
		raceBox.getCenter().getY() - (raceBox.getHeight() / 2),
		"Race", width, GLUT_BITMAP_9_BY_15);
	// Draw Traits Box Label
	renderBitmapString(traitsBox.getCenter().getX() - (traitsBox.getWidth() / 2),
		traitsBox.getCenter().getY() - (traitsBox.getHeight() / 2),
		"Traits", width, GLUT_BITMAP_9_BY_15);
	// Draw Bio Box Label
	renderBitmapString(bioBox.getCenter().getX() - (bioBox.getWidth() / 2),
		bioBox.getCenter().getY() - (bioBox.getHeight() / 2),
		"Bio", width, GLUT_BITMAP_9_BY_15);
	
	// Draw Strength Box Label
	renderBitmapString(strBox.getCenter().getX() - (strBox.getWidth() / 2),
		strBox.getCenter().getY() - (strBox.getHeight() / 2),
		"STR", width, GLUT_BITMAP_9_BY_15);	
	// Draw Perception Box Label
	renderBitmapString(perBox.getCenter().getX() - (perBox.getWidth() / 2),
		perBox.getCenter().getY() - (perBox.getHeight() / 2),
		"PER", width, GLUT_BITMAP_9_BY_15);	
	// Draw Endurance Box Label
	renderBitmapString(endBox.getCenter().getX() - (endBox.getWidth() / 2),
		endBox.getCenter().getY() - (endBox.getHeight() / 2),
		"END", width, GLUT_BITMAP_9_BY_15);	
	// Draw Charisma Label
	renderBitmapString(chaBox.getCenter().getX() - (chaBox.getWidth() / 2),
		chaBox.getCenter().getY() - (chaBox.getHeight() / 2),
		"CHA", width, GLUT_BITMAP_9_BY_15);
	// Draw Intelligence Box Label
	renderBitmapString(intBox.getCenter().getX() - (intBox.getWidth() / 2),
		intBox.getCenter().getY() - (intBox.getHeight() / 2),
		"INT", width, GLUT_BITMAP_9_BY_15);	
	// Draw Agility Box Label
	renderBitmapString(aglBox.getCenter().getX() - (aglBox.getWidth() / 2),
		aglBox.getCenter().getY() - (aglBox.getHeight() / 2),
		"AGL", width, GLUT_BITMAP_9_BY_15);	
	// Draw Luck Box Label
	renderBitmapString(luckBox.getCenter().getX() - (luckBox.getWidth() / 2),
		luckBox.getCenter().getY() - (luckBox.getHeight() / 2),
		"LUCK", width, GLUT_BITMAP_9_BY_15);

	// Draw HP Box  Label
	renderBitmapString(hpBox.getCenter().getX() - (hpBox.getWidth() / 2),
		hpBox.getCenter().getY() - (hpBox.getHeight() / 2),
		"HP", width, GLUT_BITMAP_9_BY_15);
	//Draw SPD Box Label
	renderBitmapString(spdBox.getCenter().getX() - (spdBox.getWidth() / 2),
		spdBox.getCenter().getY() - (spdBox.getHeight() / 2),
		"SPD", width, GLUT_BITMAP_9_BY_15);

	//Draw Left Arm Box Label
	renderBitmapString(larmBox.getCenter().getX() - (larmBox.getWidth() / 2),
		larmBox.getCenter().getY() - (larmBox.getHeight() / 2),
		"Left Arm", width, GLUT_BITMAP_9_BY_15);
	//Draw Head Box Label
	renderBitmapString(headBox.getCenter().getX() - (headBox.getWidth() / 2),
		headBox.getCenter().getY() - (headBox.getHeight() / 2),
		"Head", width, GLUT_BITMAP_9_BY_15);
	//Draw Right Arm Box
	renderBitmapString(rarmBox.getCenter().getX() - (rarmBox.getWidth() / 2),
		rarmBox.getCenter().getY() - (rarmBox.getHeight() / 2),
		"Right Arm", width, GLUT_BITMAP_9_BY_15);
	//Draw Left Leg Box Label
	renderBitmapString(llegBox.getCenter().getX() - (llegBox.getWidth() / 2),
		llegBox.getCenter().getY() - (llegBox.getHeight() / 2),
		"Left Leg", width, GLUT_BITMAP_9_BY_15);
	//Draw Chest Box Label
	renderBitmapString(chestBox.getCenter().getX() - (chestBox.getWidth() / 2),
		chestBox.getCenter().getY() - (chestBox.getHeight() / 2),
		"Chest", width, GLUT_BITMAP_9_BY_15);
	//Draw Right Leg Box Label
	renderBitmapString(rlegBox.getCenter().getX() - (rlegBox.getWidth() / 2),
		rlegBox.getCenter().getY() - (rlegBox.getHeight() / 2),
		"Right Leg", width, GLUT_BITMAP_9_BY_15);
	// Draw Arsenal Panel Label
	renderBitmapString(arsenalPanel.getCenter().getX() - (arsenalPanel.getWidth() / 2),
		arsenalPanel.getCenter().getY() - (arsenalPanel.getHeight() / 2),
		"Arsenal", width, GLUT_BITMAP_9_BY_15);
	// Draw Inventory Panel Label
	renderBitmapString(invPanel.getCenter().getX() - (invPanel.getWidth() / 2),
		invPanel.getCenter().getY() - (invPanel.getHeight() / 2),
		"Inventory", width, GLUT_BITMAP_9_BY_15);
	// Draw Effects Panel Label
	renderBitmapString(effectsPanel.getCenter().getX() - (effectsPanel.getWidth() / 2),
		effectsPanel.getCenter().getY() - (effectsPanel.getHeight() / 2),
		"Effects", width, GLUT_BITMAP_9_BY_15);

	// Draw Character Info -------------------------------------------------------------------------

	// Character Name

	renderBitmapString(nameBox.getCenter().getX() - ((nameBox.getWidth() / 2) * 0.90),
		nameBox.getCenter().getY() + ((nameBox.getHeight() / 2) * 0.15),
		&playerCharacter.getName()[0u], nameBox.getCenter().getX() + (nameBox.getWidth() / 2), GLUT_BITMAP_9_BY_15);

	// Alignment
	renderBitmapString(alignBox.getCenter().getX() - ((alignBox.getWidth() / 2) * 0.90),
		alignBox.getCenter().getY() + ((alignBox.getHeight() / 2) * 0.15),
		&playerCharacter.getAlignment()[0u], alignBox.getCenter().getX() + (alignBox.getWidth() / 2), GLUT_BITMAP_8_BY_13);
	// Race
	renderBitmapString(raceBox.getCenter().getX() - ((raceBox.getWidth() / 2) * 0.90),
		raceBox.getCenter().getY() + ((raceBox.getHeight() / 2) * 0.15),
		&playerCharacter.getRace()[0u], raceBox.getCenter().getX() + (raceBox.getWidth() / 2), GLUT_BITMAP_8_BY_13);
	// Traits
	renderBitmapString(traitsBox.getCenter().getX() - ((traitsBox.getWidth() / 2) * 0.95),
		traitsBox.getCenter().getY() - ((traitsBox.getHeight() / 2) * 0.80),
		&playerCharacter.getTraits()[0u], traitsBox.getCenter().getX() + (traitsBox.getWidth() / 2), GLUT_BITMAP_8_BY_13);
	// Bio
	renderBitmapString(bioBox.getCenter().getX() - ((bioBox.getWidth() / 2) * 0.95),
		bioBox.getCenter().getY() - ((bioBox.getHeight() / 2) * 0.85),
		&playerCharacter.getBio()[0u], bioBox.getCenter().getX() + (bioBox.getWidth() / 2), GLUT_BITMAP_8_BY_13);

	// Strength
	renderBitmapString(strBox.getCenter().getX() - ((strBox.getWidth() / 2) * 0.05),
		strBox.getCenter().getY() + ((strBox.getHeight() / 2) * 0.05),
		&playerCharacter.getStr()[0u], strBox.getCenter().getX() + (strBox.getWidth() / 2), GLUT_BITMAP_9_BY_15);
	// Perception
	renderBitmapString(perBox.getCenter().getX() - ((perBox.getWidth() / 2) * 0.05),
		perBox.getCenter().getY() + ((perBox.getHeight() / 2) * 0.05),
		&playerCharacter.getPer()[0u], perBox.getCenter().getX() + (perBox.getWidth() / 2), GLUT_BITMAP_9_BY_15);
	// Endurance
	renderBitmapString(strBox.getCenter().getX() - ((endBox.getWidth() / 2) * 0.05),
		endBox.getCenter().getY() + ((endBox.getHeight() / 2) * 0.05),
		&playerCharacter.getEnd()[0u], endBox.getCenter().getX() + (endBox.getWidth() / 2), GLUT_BITMAP_9_BY_15);
	// Charisma
	renderBitmapString(chaBox.getCenter().getX() - ((chaBox.getWidth() / 2) * 0.05),
		chaBox.getCenter().getY() + ((chaBox.getHeight() / 2) * 0.05),
		&playerCharacter.getCha()[0u], chaBox.getCenter().getX() + (chaBox.getWidth() / 2), GLUT_BITMAP_9_BY_15);
	// Intelligence
	renderBitmapString(intBox.getCenter().getX() - ((intBox.getWidth() / 2) * 0.05),
		intBox.getCenter().getY() + ((intBox.getHeight() / 2) * 0.05),
		&playerCharacter.getInt()[0u], intBox.getCenter().getX() + (intBox.getWidth() / 2), GLUT_BITMAP_9_BY_15);
	// Agility
	renderBitmapString(aglBox.getCenter().getX() - ((aglBox.getWidth() / 2) * 0.05),
		aglBox.getCenter().getY() + ((aglBox.getHeight() / 2) * 0.05),
		&playerCharacter.getAgi()[0u], aglBox.getCenter().getX() + aglBox.getWidth(), GLUT_BITMAP_9_BY_15);
	// Luck
	renderBitmapString(luckBox.getCenter().getX() - ((luckBox.getWidth() / 2) * 0.05),
		luckBox.getCenter().getY() + ((luckBox.getHeight() / 2) * 0.05),
		&playerCharacter.getLuc()[0u], luckBox.getCenter().getX() + (luckBox.getWidth() / 2), GLUT_BITMAP_9_BY_15);

	// HP
	renderBitmapString(hpBox.getCenter().getX() - ((hpBox.getWidth() / 2) * 0.15),
		hpBox.getCenter().getY() + ((hpBox.getHeight() / 2) * 0.05),
		&playerCharacter.getHP()[0u], hpBox.getCenter().getX() + (hpBox.getWidth() / 2), GLUT_BITMAP_9_BY_15);
	// SPD
	renderBitmapString(spdBox.getCenter().getX() - ((spdBox.getWidth() / 2) * 0.05),
		spdBox.getCenter().getY() + ((spdBox.getHeight() / 2) * 0.05),
		&playerCharacter.getSpeed()[0u], spdBox.getCenter().getX() + (spdBox.getWidth() /2 ), GLUT_BITMAP_9_BY_15);

	// Left Arm LHP
	renderBitmapString(larmBox.getCenter().getX() - ((larmBox.getWidth() / 2) * 0.05),
		larmBox.getCenter().getY() + ((larmBox.getHeight() / 2) * 0.05),
		&playerCharacter.getLArm()[0u], larmBox.getCenter().getX() + (larmBox.getWidth() / 2), GLUT_BITMAP_9_BY_15);
	// Head LHP
	renderBitmapString(headBox.getCenter().getX() - ((headBox.getWidth() / 2) * 0.05),
		headBox.getCenter().getY() + ((headBox.getHeight() / 2) * 0.05),
		&playerCharacter.getHead()[0u], headBox.getCenter().getX() + (headBox.getWidth() / 2), GLUT_BITMAP_9_BY_15);
	// Right Arm LHP
	renderBitmapString(rarmBox.getCenter().getX() - ((rarmBox.getWidth() / 2) * 0.05),
		rarmBox.getCenter().getY() + ((rarmBox.getHeight() / 2) * 0.05),
		&playerCharacter.getRArm()[0u], rarmBox.getCenter().getX() + (rarmBox.getWidth() / 2), GLUT_BITMAP_9_BY_15);
	// Left Leg LHP
	renderBitmapString(llegBox.getCenter().getX() - ((llegBox.getWidth() / 2) * 0.05),
		llegBox.getCenter().getY() + ((llegBox.getHeight() / 2) * 0.05),
		&playerCharacter.getLLeg()[0u], llegBox.getCenter().getX() + (llegBox.getWidth() / 2), GLUT_BITMAP_9_BY_15);
	// Chest LHP
	renderBitmapString(chestBox.getCenter().getX() - ((chestBox.getWidth() / 2) * 0.05),
		chestBox.getCenter().getY() + ((chestBox.getHeight() / 2) * 0.05),
		&playerCharacter.getChest()[0u], chestBox.getCenter().getX() + (chestBox.getWidth() / 2), GLUT_BITMAP_9_BY_15);
	// Right Leg LHP
	renderBitmapString(rlegBox.getCenter().getX() - ((rlegBox.getWidth() / 2) * 0.05),
		rlegBox.getCenter().getY() + ((rlegBox.getHeight() / 2) * 0.05),
		&playerCharacter.getRLeg()[0u], rlegBox.getCenter().getX() + (rlegBox.getWidth() / 2), GLUT_BITMAP_9_BY_15);

	// Arsenal
	renderBitmapString(arsenalBox.getCenter().getX() - ((arsenalBox.getWidth() / 2) * 0.95),
		arsenalBox.getCenter().getY() - ((arsenalBox.getHeight() / 2) * 0.80),
		&playerCharacter.getGunNames()[0u], arsenalBox.getCenter().getX() + (arsenalBox.getWidth() / 2), GLUT_BITMAP_8_BY_13);
	// Inventory
	renderBitmapString(invBox.getCenter().getX() - ((invBox.getWidth() / 2) * 0.95),
		invBox.getCenter().getY() - ((invBox.getHeight() / 2) * 0.80),
		&playerCharacter.getItemNames()[0u], invBox.getCenter().getX() + (invBox.getWidth() / 2), GLUT_BITMAP_8_BY_13);
	// Effects
	renderBitmapString(effectsBox.getCenter().getX() - ((effectsBox.getWidth() / 2) * 0.95),
		effectsBox.getCenter().getY() - ((effectsBox.getHeight() / 2) * 0.80),
		&playerCharacter.getEffects()[0u], effectsBox.getCenter().getX() + (effectsBox.getWidth() / 2), GLUT_BITMAP_8_BY_13);
}

// NEW/LOAD CHARACTER MENU ------------------------------------------------------------

void displayAddCharacterMenu() {

	// Draw Shapes

	// Draw Text-Box Back Panel
	textPanel.draw();
	// Draw Information Box
	infoBox.draw();
	// Draw Input Box
	inputBox.draw();

	//Draw Labels

	// Set Label Color Black
	renderBitmapString(0, 0, " ", 200);

	// Draw Information Box Label
	renderBitmapString(infoBox.getCenter().getX() - (infoBox.getWidth() / 2),
		infoBox.getCenter().getY() - ((infoBox.getHeight() / 2) * 1.05),
		"Information", width, GLUT_BITMAP_9_BY_15);
	// Draw Information in Info Box
	renderBitmapString(infoBox.getCenter().getX() - ((infoBox.getWidth() / 2) * 0.95),
		infoBox.getCenter().getY() - ((infoBox.getHeight() / 2) * 0.80),
		"Enter your desired character name then follow instructions on console.",
		infoBox.getCenter().getX() + ((infoBox.getWidth() / 2) * 0.90),
		GLUT_BITMAP_9_BY_15);

	// Draw Input Box Label
	renderBitmapString(inputBox.getCenter().getX() - (inputBox.getWidth() / 2),
		inputBox.getCenter().getY() - ((inputBox.getHeight() / 2) * 1.05),
		"Input", width, GLUT_BITMAP_9_BY_15);

	// Allow User Input in Input Box
	renderBitmapString(inputBox.getCenter().getX() - ((inputBox.getWidth() / 2) * 0.95),
		inputBox.getCenter().getY() - ((inputBox.getHeight() / 2) * 0.90),
		&input[0u],
		inputBox.getCenter().getX() + ((inputBox.getWidth() / 2) * 0.90));

}

// ADD TRAIT MENU ---------------------------------------------------------------------

void displayAddTraitMenu() {

	// Draw Shapes

	// Draw Text-Box Back Panel
	textPanel.draw();
	// Draw Information Box
	infoBox.draw();
	// Draw Input Box
	inputBox.draw();

	//Draw Labels

	// Set Label Color Black
	renderBitmapString(0, 0, " ", 200);

	// Draw Information Box Label
	renderBitmapString(infoBox.getCenter().getX() - (infoBox.getWidth() / 2),
		infoBox.getCenter().getY() - ((infoBox.getHeight() / 2) * 1.05),
		"Information", 
		infoBox.getCenter().getX() + ((infoBox.getWidth() / 2) * 0.90), 
		GLUT_BITMAP_9_BY_15);
	// Draw Information Box Label
	renderBitmapString(infoBox.getCenter().getX() - ((infoBox.getWidth() / 2) * 0.95),
		infoBox.getCenter().getY() - ((infoBox.getHeight() / 2) * 0.80),
		"Enter the desired trait for your character, then hit enter.", 
		infoBox.getCenter().getX() + ((infoBox.getWidth() / 2) * 0.90),
		GLUT_BITMAP_9_BY_15);

	// Draw Input Box Label
	renderBitmapString(inputBox.getCenter().getX() - (inputBox.getWidth() / 2),
		inputBox.getCenter().getY() - ((inputBox.getHeight() / 2) * 1.05),
		"Input", 
		infoBox.getCenter().getX() + ((infoBox.getWidth() / 2) * 0.90), 
		GLUT_BITMAP_9_BY_15);

	// Allow User Input in Input Box
	renderBitmapString(inputBox.getCenter().getX() - ((inputBox.getWidth() / 2) * 0.95),
		inputBox.getCenter().getY() - ((inputBox.getHeight() / 2) * 0.90),
		&input[0u],
		inputBox.getCenter().getX() + ((inputBox.getWidth() / 2) * 0.90));

}

// ADD BIO MENU -----------------------------------------------------------------------

void displayAddBioMenu() {

	// Draw Shapes

	// Draw Text-Box Back Panel
	textPanel.draw();
	// Draw Information Box
	infoBox.draw();
	// Draw Input Box
	inputBox.draw();

	//Draw Labels

	// Set Label Color Black
	renderBitmapString(0, 0, " ", 200);

	// Draw Information Box Label
	renderBitmapString(infoBox.getCenter().getX() - (infoBox.getWidth() / 2),
		infoBox.getCenter().getY() - ((infoBox.getHeight() / 2) * 1.05),
		"Information", 
		infoBox.getCenter().getX() + ((infoBox.getWidth() / 2) * 0.90), 
		GLUT_BITMAP_9_BY_15);
	// Draw Input Box Label
	renderBitmapString(infoBox.getCenter().getX() - ((infoBox.getWidth() / 2) * 0.95),
		infoBox.getCenter().getY() - ((infoBox.getHeight() / 2) * 0.80),
		"Enter the desired bio for your character, then hit enter.", 
		infoBox.getCenter().getX() + ((infoBox.getWidth() / 2) * 0.90), 
		GLUT_BITMAP_9_BY_15);

	// Draw Input Box Label
	renderBitmapString(inputBox.getCenter().getX() - (inputBox.getWidth() / 2),
		inputBox.getCenter().getY() - ((inputBox.getHeight() / 2) * 1.05),
		"Input", 
		infoBox.getCenter().getX() + ((infoBox.getWidth() / 2) * 0.90), 
		GLUT_BITMAP_9_BY_15);

	// Allow User Input in Input Box
	renderBitmapString(inputBox.getCenter().getX() - ((inputBox.getWidth() / 2) * 0.95),
		inputBox.getCenter().getY() - ((inputBox.getHeight() / 2) * 0.90),
		&input[0u],
		inputBox.getCenter().getX() + ((inputBox.getWidth() / 2) * 0.90));

}

// ADD GUN MENU -----------------------------------------------------------------------

void displayAddGunMenu() {
	// Draw Shapes

	// Draw Text-Box Back Panel
	textPanel.draw();
	// Draw Information Box
	infoBox.draw();
	// Draw Input Box
	inputBox.draw();

	//Draw Labels

	// Set Label Color Black
	renderBitmapString(0, 0, " ", 200);

	// Draw Information Box Label
	renderBitmapString(infoBox.getCenter().getX() - (infoBox.getWidth() / 2),
		infoBox.getCenter().getY() - ((infoBox.getHeight() / 2) * 1.05),
		"Information", 
		infoBox.getCenter().getX() + ((infoBox.getWidth() / 2) * 0.90), 
		GLUT_BITMAP_9_BY_15);
	// Draw Input Box Label
	renderBitmapString(infoBox.getCenter().getX() - ((infoBox.getWidth() / 2) * 0.95),
		infoBox.getCenter().getY() - ((infoBox.getHeight() / 2) * 0.80),
		"Add a Pistol, SMG, Shotgun, Assault Rfile, Battle Rifle, Light Machinegun, Sniper Rifle, or Heavy Weapon by entering one of the following keycodes and then hitting enter. [pistol, smg, ar, br, sniper, lmg, heavy]", 
		infoBox.getCenter().getX() + ((infoBox.getWidth() / 2) * 0.90),
		GLUT_BITMAP_9_BY_15);

	// Draw Input Box Label
	renderBitmapString(inputBox.getCenter().getX() - (inputBox.getWidth() / 2),
		inputBox.getCenter().getY() - ((inputBox.getHeight() / 2) * 1.05),
		"Input", 
		infoBox.getCenter().getX() + ((infoBox.getWidth() / 2) * 0.90),
		GLUT_BITMAP_9_BY_15);

	// Allow User Input in Input Box
	renderBitmapString(inputBox.getCenter().getX() - ((inputBox.getWidth() / 2) * 0.95),
		inputBox.getCenter().getY() - ((inputBox.getHeight() / 2) * 0.90),
		&input[0u],
		inputBox.getCenter().getX() + ((inputBox.getWidth() / 2) * 0.90));

}

// ADD ITEM MENU ----------------------------------------------------------------------

void displayAddItemMenu() {
	// Draw Shapes

	// Draw Text-Box Back Panel
	textPanel.draw();
	// Draw Information Box
	infoBox.draw();
	// Draw Input Box
	inputBox.draw();

	//Draw Labels

	// Set Label Color Black
	renderBitmapString(0, 0, " ", 200);

	// Draw Information Box Label
	renderBitmapString(infoBox.getCenter().getX() - (infoBox.getWidth() / 2),
		infoBox.getCenter().getY() - ((infoBox.getHeight() / 2) * 1.05),
		"Information", width, GLUT_BITMAP_9_BY_15);
	// Draw Input Box Label
	renderBitmapString(infoBox.getCenter().getX() - ((infoBox.getWidth() / 2) * 0.95),
		infoBox.getCenter().getY() - ((infoBox.getHeight() / 2) * 0.80),
		"Add an item to your character's inventory by entering the following paramaters seperated by commas.",
		infoBox.getCenter().getX() + ((infoBox.getWidth() / 2) * 0.90),
		GLUT_BITMAP_9_BY_15);


	// Draw Input Box Label
	renderBitmapString(inputBox.getCenter().getX() - (inputBox.getWidth() / 2),
		inputBox.getCenter().getY() - ((inputBox.getHeight() / 2) * 1.05),
		"Input", width, GLUT_BITMAP_9_BY_15);

	// Allow User Input in Input Box
	renderBitmapString(inputBox.getCenter().getX() - ((inputBox.getWidth() / 2) * 0.95),
		inputBox.getCenter().getY() - ((inputBox.getHeight() / 2) * 0.95),
		&input[0u],
		inputBox.getCenter().getX() + ((inputBox.getWidth() / 2) * 0.95));

}

// ADD EFFECT MENU --------------------------------------------------------------------

void displayAddEffectMenu() {
	// Draw Shapes

	// Draw Text-Box Back Panel
	textPanel.draw();
	// Draw Information Box
	infoBox.draw();
	// Draw Input Box
	inputBox.draw();

	//Draw Labels

	// Set Label Color Black
	renderBitmapString(0, 0, " ", 200);

	// Draw Information Box Label
	renderBitmapString(infoBox.getCenter().getX() - (infoBox.getWidth() / 2),
		infoBox.getCenter().getY() - ((infoBox.getHeight() / 2) * 1.05),
		"Information", width, GLUT_BITMAP_9_BY_15);
	// Draw Input Box Label
	renderBitmapString(infoBox.getCenter().getX() - ((infoBox.getWidth() / 2) * 0.95),
		infoBox.getCenter().getY() - ((infoBox.getHeight() / 2) * 0.80),
		"Add the desired effect to your character's effect log and then hit enter.",
		infoBox.getCenter().getX() + ((infoBox.getWidth() / 2) * 0.90),
		GLUT_BITMAP_9_BY_15);

	// Draw Input Box Label
	renderBitmapString(inputBox.getCenter().getX() - (inputBox.getWidth() / 2),
		inputBox.getCenter().getY() - ((inputBox.getHeight() / 2) * 1.05),
		"Input", width, GLUT_BITMAP_9_BY_15);

	// Allow User Input in Input Box
	renderBitmapString(inputBox.getCenter().getX() - ((inputBox.getWidth() / 2) * 0.95),
		inputBox.getCenter().getY() - ((inputBox.getHeight() / 2) * 0.95),
		&input[0u],
		inputBox.getCenter().getX() + ((inputBox.getWidth() / 2) * 0.95));
}

//-------------------------------------------------------------------------------------
// INIT GL ----------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

/* Initialize OpenGL Graphics */
void initGL() {
	// Set "clearing" or background color
	glClearColor(0.0f, 0.0f, 0.9f, 1.0f); // Blue and opaque
	glColor3f(0, 0, 1);
}

//-------------------------------------------------------------------------------------
// DISPLAY ----------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
	// tell OpenGL to use the whole window for drawing
	glViewport(0, 0, width, height);

	// do an orthographic parallel projection with the coordinate
	// system set to first quadrant, limited by screen/window size
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

	glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


	// START DRAW THINGS -----------------------------------------------------------

	// Switch between different pages based on state of screen
	switch (currentScreen) {
	case mainMenu:
		displayMenu();
		break;
	case characterMenu:
		displayCharacterMenu();
		break;
	case addCharacterMenu:
		displayAddCharacterMenu();
		break;
	case addTraitMenu:
		displayAddTraitMenu();
		break;
	case addBioMenu:
		displayAddBioMenu();
		break;
	case addGunMenu:
		displayAddGunMenu();
		break;
	case addItemMenu:
		displayAddItemMenu();
		break;
	case addEffectMenu:
		displayAddEffectMenu();
		break;
	}
	
	// END DRAW THINGS ------------------------------------------------------------

	glFlush();  // Render now
}

// --------------------------------------------------------------------------------
// KEYBOARD AND MOUSE--------------------------------------------------------------
// --------------------------------------------------------------------------------

// KEYBOARD -----------------------------------------------------------------------

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y)
{

	// General Keys

	// escape to quit
	if (key == 27) {
		glutDestroyWindow(wd);
		exit(0);
	}

	// Character Menu Keys

	// hit c to create/load
	else if (key == 99 && currentScreen == characterMenu) {
		currentScreen = addCharacterMenu;
	}

	// hit s to save
	else if (key == 115 && currentScreen == characterMenu) {
		playerCharacter.save();
	}

	// hit g to add gun
	else if (key == 103 && currentScreen == characterMenu) {
		currentScreen = addGunMenu;
	}


	// Text-Box Keys
	
	
	// backspace
	else if (key == 8) {
		if (input.size() != 0) {
			input.pop_back();
		}
	}
	// enter
	else if (key == 13) {
		if (currentScreen == addCharacterMenu) {
			buttons[flag].setParameters(input);
			buttons[flag].runSMethod();

			input = "";
			currentScreen = characterMenu;
		}

		if (currentScreen == addTraitMenu) {
			buttons[flag].setParameters(input);
			buttons[flag].runSMethod();

			input = "";
			currentScreen = characterMenu;
		}

		if (currentScreen == addBioMenu) {
			buttons[flag].setParameters(input);
			buttons[flag].runSMethod();

			input = "";
			currentScreen = characterMenu;
		}

		if (currentScreen == addGunMenu) {
			buttons[flag].setParameters(input);
			buttons[flag].runSMethod();

			input = "";
			currentScreen = characterMenu;
		}

		if (currentScreen == addItemMenu) {
			buttons[flag].setParameters(input);
			buttons[flag].runSMethod();
	

			input = "";
			currentScreen = characterMenu;
		}

		if (currentScreen == addEffectMenu) {
			buttons[flag].setParameters(input);
			buttons[flag].runSMethod();
			

			input = "";
			currentScreen = characterMenu;
		}
	}
	else if (currentScreen != characterMenu) {
		input += key;
	}

	glutPostRedisplay();

	return;
}

void kbdS(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_DOWN:
		break;
	case GLUT_KEY_LEFT:
		break;
	case GLUT_KEY_RIGHT:
		break;
	case GLUT_KEY_UP:
		break;
	}
	glutPostRedisplay();

	return;
}

// MOUSE -----------------------------------------------------------------------

void cursor(int x, int y) {
	//r.setTopLeft(x, y);

	mouseX = x;
	mouseY = y;

	//updateColor(r, x, y);

	glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

		for (int i = 0; i < buttons.size(); i++) {
			if (buttons[i].CheckValid(mouseX, mouseY, currentScreen)) {

				if (!buttons[i].getNPfunc()) {
					buttons[i].runNPMethod();
				}

				if (!buttons[i].getSfunc()) {
					currentScreen = buttons[i].returnLinkedScreen();
					flag = i;
				}
				//currentScreen = buttons[i].returnLinkedScreen();
				//buttons[i].runMethod();
			}
		}

	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && currentScreen == mainMenu) {
		currentScreen = characterMenu;
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {

	}

	glutPostRedisplay();
}

// --------------------------------------------------------------------------------
// ANIMATION ----------------------------------------------------------------
// --------------------------------------------------------------------------------
void timer(int extra) {

	glutPostRedisplay();
	glutTimerFunc(30, timer, 0);
}

// --------------------------------------------------------------------------------
// MAIN ---------------------------------------------------------------------------
// --------------------------------------------------------------------------------

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {

	init();

	glutInit(&argc, argv);          // Initialize GLUT

	glutInitDisplayMode(GLUT_RGBA);

	glutInitWindowSize((int)width, (int)height);
	glutInitWindowPosition(200, 100); // Position the window's initial top-left corner
									  /* create the window and store the handle to it */
	wd = glutCreateWindow("Quest: Combat Character Manager" /* title */);

	// Register callback handler for window re-paint event
	glutDisplayFunc(display);

	// Our own OpenGL initialization
	initGL();

	// register keyboard press event processing function
	// works for numbers, letters, spacebar, etc.
	glutKeyboardFunc(kbd);

	// register special event: function keys, arrows, etc.
	glutSpecialFunc(kbdS);

	// handles mouse movement
	glutPassiveMotionFunc(cursor);

	// handles mouse click
	glutMouseFunc(mouse);

	// handles timer
	glutTimerFunc(0, timer, 0);

	// Enter the event-processing loop
	glutMainLoop();
	return 0;
}