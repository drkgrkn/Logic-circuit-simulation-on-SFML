#pragma once

#include "LogicElement.h"

class DFlipFlop : public LogicElement
{
public:

	//FUNcs
	DFlipFlop(sf::RenderWindow* w, LogicElement* ePtr);
	~DFlipFlop();
	void setSprite() override; // Handle the correct sprite and scale it
	void simulate(); //  Determine the next state of the output pin 
    void preSimulate() override; //Determine the next state of the output pin (not used for dflipflop)

};