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

	sf::CircleShape pinShape;
	sf::RenderWindow* window;
	//FUNCS
	Pin(sf::RenderWindow* w, Pin::pinType type, int idx);
	void setPosition(sf::Vector2f v);
	bool isInside(sf::Vector2f mp);
};
