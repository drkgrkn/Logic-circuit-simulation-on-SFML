#pragma once

#include "LogicElement.h"

class DFlipFlop : public LogicElement
{
public:

	//FUNcs
	DFlipFlop(sf::RenderWindow* w, LogicElement* ePtr);
	~DFlipFlop();
	void setSprite();
};