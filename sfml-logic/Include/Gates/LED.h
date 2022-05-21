#pragma once

#include "LogicElement.h"

class LED : public LogicElement
{
public:

	//FUNcs
	LED(sf::RenderWindow* w, LogicElement* ePtr);
	~LED();
	void setSprite();
	void simulate();
};
