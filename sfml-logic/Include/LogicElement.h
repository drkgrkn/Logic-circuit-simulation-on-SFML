#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Pin.h"

class LogicElement : public Entity
{
public:
	Pin* pins;	
	int numPins;

	//FUNCS
	LogicElement(sf::RenderWindow* w, int numPins, Entity* ePtr);
};