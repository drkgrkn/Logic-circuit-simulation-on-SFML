#pragma once


#include "LogicElement.h"

class NotGate : public LogicElement
{
public:

	//FUNcs
	NotGate(sf::RenderWindow* w, LogicElement* ePtr); 
	~NotGate();
	void setSprite(); // Handle the correct sprite and scale it
	void simulate(); // Determine the next state of OUTPUT PIN
};

