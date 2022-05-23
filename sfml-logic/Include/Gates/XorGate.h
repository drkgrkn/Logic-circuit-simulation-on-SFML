#pragma once

#include "LogicElement.h"

class XorGate : public LogicElement
{
public:

	//FUNcs
	XorGate(sf::RenderWindow* w, LogicElement* ePtr);
	~XorGate();
	void setSprite(); // Handle the correct sprite and scale it
	void simulate(); //Determine the next state of OUTPUT PIN
};
