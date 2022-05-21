#pragma once


#include "LogicElement.h"

class OrGate : public LogicElement
{
public:

	//FUNcs
	OrGate(sf::RenderWindow* w, LogicElement* ePtr);
	~OrGate();
	void setSprite();
	void simulate();
};



