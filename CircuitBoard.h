#pragma once

#include "Object.h"
#include "Board.h"

class CircuitBoard: public Board
{
public:
	Object* objects;

	CircuitBoard(sf::RenderWindow* w);
	void draw() const override;
};

