#pragma once

#include "LogicElement.h"

class Logic1 : public LogicElement
{
public:

	//FUNcs
	Logic1(sf::RenderWindow* w, LogicElement* ePtr);
	~Logic1();
	void setSprite();
	void simulate();
};
