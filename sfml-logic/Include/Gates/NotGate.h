#pragma once


#include "LogicElement.h"

class NotGate : public LogicElement
{
public:

	//FUNcs
	NotGate(sf::RenderWindow* w, LogicElement* ePtr);
	~NotGate();
	void setSprite();
};

