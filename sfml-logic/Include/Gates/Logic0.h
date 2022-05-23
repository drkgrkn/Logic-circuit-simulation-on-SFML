#pragma once

#include "LogicElement.h"

class Logic0 : public LogicElement
{
public:

	//FUNcs
	Logic0(sf::RenderWindow* w, LogicElement* ePtr);
	~Logic0();
	void setSprite();  // Handle the correct sprite and scale it
	void simulate() override; //  Initialize the output pin (constant LOW)
	void preSimulate() override;  // (not used for logic 0)
};