#include "LogicElement.h"

LogicElement::LogicElement(sf::RenderWindow* w, int numPins, Entity* ePtr) :
	Entity(w, ePtr), numPins(numPins)
{
	pins = nullptr;
	/*
	pins = new Pin[4]{Pin(w, Pin::pinType::INPUT, 0),
						Pin(w, Pin::pinType::INPUT, 1),
						Pin(w, Pin::pinType::INPUT, 2),
						Pin(w, Pin::pinType::INPUT, 3) };
						*/
}