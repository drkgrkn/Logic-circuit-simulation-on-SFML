#pragma once

#include "LogicElement.h"
#include "Board.h"
#include "AndGate.h"

class Wire;

class CircuitBoard: public Board
{
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

};

