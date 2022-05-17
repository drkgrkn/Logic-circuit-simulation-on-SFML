#pragma once

#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Button.h"

class Entity: public Object
{
public:
	Entity* next;
	Entity* prev;

	bool state;
	bool selected;

	Entity(sf::RenderWindow* w, buttonType b, Entity* ePtr);
	bool isInside(sf::Vector2f mp);
	void draw();
};

