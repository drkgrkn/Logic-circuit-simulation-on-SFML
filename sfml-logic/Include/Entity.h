#pragma once

#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Button.h"

class Entity: public Object
{
public:
	sf::RectangleShape selectionIndicator;
	Entity* next;
	Entity* prev;
	bool selected;
	bool grabbed;

	Entity(sf::RenderWindow* w, Entity* ePtr);
	bool isInside(sf::Vector2f mp);
	virtual void draw();
	virtual void handleClick(sf::Vector2f mp);
};

