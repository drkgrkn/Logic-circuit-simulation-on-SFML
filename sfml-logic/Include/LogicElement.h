#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Pin.h"

class LogicElement : public Entity
{
public:
	Pin pins[4];	
	int numPins;

};