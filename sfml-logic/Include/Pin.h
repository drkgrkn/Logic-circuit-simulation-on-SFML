#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Wire.h"

class Wire;
#define MAX_CONNECTIONS 5


class Pin
{
public:
	//SELF
	enum class pinType { INPUT, OUTPUT };
	enum class pinState { LOW, HIGH };
	sf::RenderWindow* window;
	pinState state;
	pinType type;
	sf::RectangleShape shape;

	//Other objects
	int numConnections;
	bool isSrc[MAX_CONNECTIONS];
	Pin* connectedTo[MAX_CONNECTIONS];
	Wire* wires[MAX_CONNECTIONS];



	//FUNCS
	Pin(sf::RenderWindow* w, Pin::pinType t);
	void setShape();
	void setPosition(sf::Vector2f v);
	void draw();
	bool isInside(sf::Vector2f mp);
	void handleClick();
	void embedWire(sf::Vector2f mp, Wire* wPtr);
	void unembedWire(Wire* wPtr);
};
