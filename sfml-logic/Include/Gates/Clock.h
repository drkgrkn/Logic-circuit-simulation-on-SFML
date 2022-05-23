#pragma once

#include "LogicElement.h"

class Clock : public LogicElement
{
public:

	//FUNcs
	Clock(sf::RenderWindow* w, LogicElement* ePtr); 
	~Clock();
	void setSprite(); // Handle the correct sprite and scale it
	void simulate() override; //  Set constant output for clock (not used for clock)
	void preSimulate();  //Set constant output for clock (used for clock)
};

