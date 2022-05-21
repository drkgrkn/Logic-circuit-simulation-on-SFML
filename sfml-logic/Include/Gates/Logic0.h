#pragma once

#include "LogicElement.h"

class Logic0 : public LogicElement
{
public:

	//FUNcs
	Logic0(sf::RenderWindow* w, LogicElement* ePtr);
	~Logic0();
	void setSprite();
	void simulate() override;
	void preSimulate() override;
};