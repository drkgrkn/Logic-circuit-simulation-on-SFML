#pragma once

#include "Pin.h"

class Wire
{
public:
	sf::RenderWindow* window;
	sf::Vertex vertex[4];
	Pin* pins[2];

	Wire(sf::RenderWindow* w, sf::Vector2f v, Pin* p);
	void place(sf::Vector2f v, Pin* p);
	void draw();
};

