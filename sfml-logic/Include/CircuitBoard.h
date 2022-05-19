#pragma once

#include "LogicElement.h"
#include "Board.h"
#include "AndGate.h"

class CircuitBoard: public Board
{
public:
	Entity* entities;

	CircuitBoard(sf::RenderWindow* w);
	void draw() const override;
	void handleClick(sf::Vector2f mp);
	void handleDelete();
	void handleRelease(sf::Vector2f mp);
	void addEntity(sf::RenderWindow* w, Object::objectType b);
	void deleteEntity();
	void simulate();
	Entity* chooseEntity(Object::objectType obj);
};

