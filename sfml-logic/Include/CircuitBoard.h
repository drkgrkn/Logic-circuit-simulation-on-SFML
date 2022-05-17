#pragma once

#include "Entity.h"
#include "Board.h"

class CircuitBoard: public Board
{
public:
	Entity* entities;

	CircuitBoard(sf::RenderWindow* w);
	void draw() const override;
	void handleClick(sf::Vector2f mp);
	void handleDelete();
	void addEntity(sf::RenderWindow* w, buttonType b);
	void simulate();
};

