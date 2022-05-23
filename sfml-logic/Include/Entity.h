#pragma once

#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Button.h"

/*
  Entities are "alive" object that actively
  do their purpose on the CircuitBoard object
  We created this because we wanted Wires
  and LogicElements to have some properties
  that Buttons shouldn't
*/
class Entity: public Object
{
public:
	//Entity can either be a LogicElement
	//or Wire. Added NOTHING for just in case situations
	enum class entityType {WIRE, LOGIC, NOTHING};
	entityType type;
	
	//Wires and LogicElements can be selected:
	//	For General purposes
	//Or grabbed:
	//	For moving around
	//But buttons don't reqire either of these
	//Thus Entities main purpose is this method
	bool selected;
	bool grabbed;

	//receives *window to pass onto Object()
	Entity(sf::RenderWindow* w);
	~Entity();
	//generic isInside function
	virtual bool isInside(sf::Vector2f mp);
	//Wires and LogicElements will have different
	//draw methods thus virtual
	virtual void draw();
	//Nearly everything has a handleClick method
	//to make code more readable
	virtual void handleClick(sf::Vector2f mp);
	//unselect and ungrab function
	void place();
	//All entities will have a job during simulate
	//process
	virtual void simulate();
	//to abstract away entity->selected = true/false;
	//Also LogicElements and Wires will have to do some
	//different tasks when selected/unselected
	virtual void select();
	virtual void unselect();

	//Reset data saved and everything that might have changed
	//during simulation
	virtual void reset();

};

