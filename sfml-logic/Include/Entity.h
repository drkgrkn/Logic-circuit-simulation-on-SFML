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

	bool state;
	bool selected;
	bool grabbed;

	Entity(sf::RenderWindow* w, Object::objectType b, Entity* ePtr);
	bool isInside(sf::Vector2f mp);
	void draw();
};

