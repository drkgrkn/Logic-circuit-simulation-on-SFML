#pragma once

#include "LogicElement.h"

class Logic1 : public LogicElement
{
public:

	//FUNcs
	Logic1(sf::RenderWindow* w, LogicElement* ePtr);
	~Logic1();
	void setSprite(); // Handle the correct sprite and scale it
	void simulate();  // Initialize the output pin (constant HIGH)	
	void preSimulate() override; // (not used for logic1 )
};
