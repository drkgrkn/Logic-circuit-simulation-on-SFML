#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Wire.h"

class Wire;

class Pin
{
public:
	//SELF
	enum class pinType { INPUT, OUTPUT };
	const int MAX_CONNECTIONS;
	enum class pinState { LOW, HIGH };
	sf::RenderWindow* window;
	pinState state;
	pinType type;
	sf::RectangleShape shape;

	//Other objects
	int numConnections;
	Pin** connectedTo;
	Wire** wires;



	//FUNCS
	Pin(sf::RenderWindow* w, Pin::pinType t);
	~Pin();
	void setShape();
	void setPosition(sf::Vector2f v);
	void draw();
	bool isInside(sf::Vector2f mp);
	void handleClick();
	void embedWire(Wire* w, Pin* p);
	void unembedWire(Wire* w);
	void connect(Wire* w, Pin* p);
};
