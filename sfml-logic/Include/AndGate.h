#pragma once

#include "LogicElement.h"

class AndGate: public LogicElement
{
public:

	//FUNcs
	AndGate(sf::RenderWindow* w, Entity* ePtr);
	~AndGate();
	void setSprite();
};

