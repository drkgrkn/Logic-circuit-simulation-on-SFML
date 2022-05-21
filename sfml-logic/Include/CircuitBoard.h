#pragma once

#include "LogicElement.h"
#include "Board.h"
#include "Gates/AndGate.h"
#include "Gates/OrGate.h"
#include "Gates/XorGate.h"
#include "Gates/NotGate.h"
#include "Gates/DFlipFlop.h"
#include "Gates/Logic0.h"
#include "Gates/Logic1.h"
#include "Gates/Clock.h"
#include "Gates/LED.h"

class Wire;

class CircuitBoard: public Board
{
private:
	LogicElement* getLast();
	Entity* getClicked(sf::Vector2f mp);
	Entity* getSelected();
	Entity* getGrabbed();
public:
	LogicElement* entities;

	CircuitBoard(sf::RenderWindow* w);
	void draw() const override;
	void handleClick(sf::Vector2f mp);
	void handleDelete();
	void handleRelease(sf::Vector2f mp);
	void addLogic(sf::RenderWindow* w, Object::objectType b);
	void deleteLogic();
	void simulate();
	LogicElement* chooseLogic(Object::objectType obj);

	//Wire stuff
	void deleteWire();

};

