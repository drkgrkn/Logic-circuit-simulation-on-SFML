#pragma once

#include <SFML/Graphics.hpp>
#include "Object.h"

#define MAX_CONNECTIONS 1

class Pin
{
public:
	enum class pinType { INPUT, OUTPUT};
	enum class pinState { HIGHZ, LOW, HIGH};

	int index;

	pinType type;
	bool isSrc[MAX_CONNECTIONS];

	Pin* connectedTo[MAX_CONNECTIONS];
	Object* wires[MAX_CONNECTIONS];
	int numConnections;
	sf::Vector2f pos;
	sf::CircleShape shape;
	sf::RenderWindow* window;
	//FUNCS
	Pin(sf::RenderWindow* w);
};
