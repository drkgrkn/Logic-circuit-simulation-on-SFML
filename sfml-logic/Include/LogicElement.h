#pragma once

#include "Entity.h"
#include "Pin.h"
#include "Wire.h"
// LE = LogicElement
/*
  Since all LEs will have some similar
  properties like Pins and data history
  for graphing purposes
  this abstract class exists
*/
class LogicElement: public Entity
{
public:
	//self explanatory selectionIndicator
	sf::RectangleShape selectionIndicator;
	//Linked list next/prev attributes
	LogicElement* next;
	//prev didn't end up being that useful
	LogicElement* prev;

	//all LEs will have pins
	Pin* pins;

	//To identify LE type
	Object::objectType logicType;
	//LEs might have different
	//number of pins
	int numPins;
	//history of output for plotting purposes
	Pin::pinState* data;
	//Program gradully allocates memory
	//so it doesnt need infinite at beginning
	int dataLength;
	//last data update index
	//so element itself knows where to place next
	//output
	int dIdx;

	//Pin positions for displaying purposes
	sf::Vector2f* pinsPos;

	//FUNCS
	//Since LogicElements reside in a linkedlist inside
	//circuitBoard, they must receive a LE pointer to fill the
	//prev attribute
	LogicElement(sf::RenderWindow* w, LogicElement* ePtr);
	~LogicElement();
	//Pos simulation loop function to update history
	void updateData();
	//self explanatory funcs
	virtual void setSprite();
	void draw() override;
	void handleClick(sf::Vector2f mp) override;
	void embedWire(sf::Vector2f mp, Wire* wPtr);
	//bool func to check whether two LE's are colliding with
	//each other
	bool isColliding(Entity* le);
	//function to reset a LE after simulation is ceased
	virtual void reset() override;
	//pre simulation loop function to prepare LE
	virtual void preSimulate();
	//func to run once before the simulation
	virtual void initialize();
};

