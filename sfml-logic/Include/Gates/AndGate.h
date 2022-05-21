#pragma once

#include "LogicElement.h"

class AndGate: public LogicElement
{
public:

	//FUNcs
	AndGate(sf::RenderWindow* w, LogicElement* ePtr);
	~AndGate();
	void setSprite();
	void simulate() override;
};

