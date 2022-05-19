#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.h"

#define MAX_CONNECTIONS 1

class Pin
{
public:
	enum class pinType { INPUT, OUTPUT};
	enum class pinState { LOW, HIGH};
	sf::RenderWindow* window;
	pinState state;
	pinType type;
	sf::RectangleShape shape;



	//FUNCS
	Pin(sf::RenderWindow* w, Pin::pinType t);
	void setShape();
	void setPosition(sf::Vector2f v);
	void draw();
	bool isInside(sf::Vector2f mp);
	void handleClick();
	//int numConnections;

	//bool isSrc[MAX_CONNECTIONS];
	//Pin* connectedTo[MAX_CONNECTIONS];
	//Entity* wires[MAX_CONNECTIONS];

	//sf::Vector2f pos;
	////sf::CircleShape pinshape;
	//sf::RenderWindow* window;
	////FUNCS
	//Pin(sf::RenderWindow* w);
};
