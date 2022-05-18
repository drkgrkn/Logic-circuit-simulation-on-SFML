#pragma once

#include <SFML/Graphics.hpp>
#include "LogicElement.h"
#include "Pin.h"

class AndGate : public LogicElement {
public:
	int numPins;
	AndGate(sf::RenderWindow* w, Entity* ePtr);
	~AndGate();
	Pin::pinState getState(int index);

	void pinPos();

	void calcOutput();
};