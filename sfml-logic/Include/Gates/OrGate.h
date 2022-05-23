#pragma once


#include "LogicElement.h"

class OrGate : public LogicElement
{
public:

	//FUNcs
	OrGate(sf::RenderWindow* w, LogicElement* ePtr);
	~OrGate();
	void setSprite();// Handle the correct sprite and scale it
	void simulate(); //Determine the next state of OUTPUT PIN
};



