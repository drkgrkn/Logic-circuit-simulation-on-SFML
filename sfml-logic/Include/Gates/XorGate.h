#pragma once

#include "LogicElement.h"

class XorGate : public LogicElement
{
public:

	//FUNcs
	XorGate(sf::RenderWindow* w, LogicElement* ePtr);
	~XorGate();
	void setSprite();
	void simulate();
};
