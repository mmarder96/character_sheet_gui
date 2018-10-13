#include "Button.h"
#include "character.h"


Button::Button(function<void()> f, screen s, string l) {

	NPfunc = f;
	label = l;
	state = s;
	paramState = 0;

}

Button::Button(function<void(string s)> f, screen s, string l) {

	Sfunc = f;
	label = l;
	state = s;
	paramState = 1;
	
}

Button::Button(function<void()> f, screen s, screen ls , string l) {

	NPfunc = f;
	label = l;
	state = s;
	linkedState = ls;
	paramState = 0;

}

Button::Button(function<void(string s)> f, screen s, screen ls, string l) {

	Sfunc = f;
	label = l;
	state = s;
	linkedState = ls;
	paramState = 1;

}

void Button::setParameters(string s) {
	paraS = s;

}

int Button::getX() {
	return x;
}

int Button::getY() {
	return y;
}

int Button::getEndX() {
	return x + width;
}

int Button::getEndY() {
	return y + height;
}

void Button::setXY(int X, int Y) {
	x = X;
	y = Y;
}

void Button::setWidth(int w) {
	width = w;
}

void Button::setHeight(int h) {
	height = h;
}

void Button::setCenter(int CX, int CY) {
	x = CX - width / 2;
	y = CY - height / 2;
}

bool Button::getNPfunc() {
	if (paramState = 0)
		return false;

	else true;
}

bool Button::getSfunc() {
	if (paramState = 1)
		return false;

	else true;
}

void Button::runNPMethod() {

	if (NPfunc != NULL) {
		NPfunc();
	}

}

void Button::runSMethod() {

	if (Sfunc != NULL) {
		Sfunc(paraS);
	}

}

screen Button::returnLinkedScreen() {
	
		return linkedState;

}

bool Button::CheckValid(int MX, int MY, screen s) {

	if (s == state) {
		if (x < MX && MX < x + width) {
			if (y < MY && MY < y + height) {
				return true;
			}
		}

	}
	return false;
}
