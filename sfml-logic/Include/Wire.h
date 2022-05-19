#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.h"
#include "Pin.h"

class Pin;

class Wire: public Entity
{
public:
	/*Entity
		selected
		grabbed*/
	sf::Vector2f vertices[4];
	Pin* pins[2];

	Wire(sf::RenderWindow* w, Pin* p);
	void draw();
	void place(sf::Vector2f mp);
	void embedToPin(sf::Vector2f mp, Pin* p);
};

