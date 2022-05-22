#pragma once

#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Button.h"

class Entity: public Object
{
public:
	enum class entityType {WIRE, LOGIC, NOTHING};
	
	entityType type;
	bool selected;
	bool grabbed;

	Entity(sf::RenderWindow* w);
	~Entity();
	virtual bool isInside(sf::Vector2f mp);
	virtual void draw();
	virtual void handleClick(sf::Vector2f mp);
	void place();
	virtual void simulate();
	virtual void select();
	virtual void unselect();
	virtual void reset();

};

