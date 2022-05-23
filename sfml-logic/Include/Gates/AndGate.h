#pragma once

#include "LogicElement.h"

class AndGate: public LogicElement
{
public:

	//FUNcs
	AndGate(sf::RenderWindow* w, LogicElement* ePtr);
	~AndGate();
	void setSprite();  // Handle the correct sprite and scale it
	void simulate() override; //  Determine the next state of the output pin 
};

