#pragma once

#include "LogicElement.h"

class LED : public LogicElement
{
public:

	//FUNcs
	LED(sf::RenderWindow* w, LogicElement* ePtr);
	~LED();
	void setSprite(); // Handle the correct sprite and scale it (just for initialization)
	void setSprite(int); // Handle the correct sprite and scale it (for changing sprite to LEDON and LEDOFF)
	void simulate();    // Change sprite depends on INPUT pin	
	void reset() override; //For the reset button of simulation
};
