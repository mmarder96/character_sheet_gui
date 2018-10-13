#ifndef Button_h
#define Button_h

enum screen { mainMenu, characterMenu, addCharacterMenu, addTraitMenu, addBioMenu, addGunMenu, addItemMenu, addEffectMenu};

#include <string>
#include <iostream>
#include <functional>

using namespace std;

class Button {

public:

	Button::Button(function<void()> f, screen s, string label);
	Button::Button(function<void(string s)> f, screen s, string label);

	Button::Button(function<void()> f, screen s,screen ls, string label);
	Button::Button(function<void(string s)> f, screen s,screen ls, string label);

	int Button::getX();
	int Button::getEndX();
	int Button::getY();
	int Button::getEndY();

	void Button::setXY(int X, int Y);
	void Button::setWidth(int w);
	void Button::setHeight(int h);
	void Button::setCenter(int CX, int CY);

	bool Button::getNPfunc();
	bool Button::getSfunc();
	
	void Button::setParameters(string s);
	screen Button::returnLinkedScreen();


	void Button::runNPMethod();
	void Button::runSMethod();

	bool Button::CheckValid(int MX, int MY, screen s);

private:


	screen state;
	screen linkedState;

	int paramState;

	function<void()> NPfunc;
	function<void(string s)> Sfunc;

	string paraS;
	int paraI;

	enum page;


	int x = 0;
	int y = 0;
	int height = 10;
	int width = 10;
	string label = "Default";


};

#endif Button_h