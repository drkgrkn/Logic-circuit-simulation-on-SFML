#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.h"

#define MAX_CONNECTIONS 1

class Pin
{
public:
	enum class pinType { INPUT, OUTPUT};
	enum class pinState { HIGHZ, LOW, HIGH};

	int index;
	int numConnections;

	pinType type;
	pinState state;

	bool isSrc[MAX_CONNECTIONS];
	Pin* connectedTo[MAX_CONNECTIONS];
	Entity* wires[MAX_CONNECTIONS];

	sf::Vector2f pos;
	//sf::CircleShape pinshape;
	sf::RenderWindow* window;
	//FUNCS
	Pin(sf::RenderWindow* w);
};
