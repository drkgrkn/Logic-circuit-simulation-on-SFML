#pragma once

#include "LogicElement.h"

class Clock : public LogicElement
{
public:

	//FUNcs
	Clock(sf::RenderWindow* w, LogicElement* ePtr);
	~Clock();
	void setSprite();
	void simulate() override;
	void preSimulate() override;
};

