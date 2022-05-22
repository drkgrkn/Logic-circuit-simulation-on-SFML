#pragma once

#include "LeftBoard.h"
#include "TopBoard.h"
#include "CircuitBoard.h"
#include <iostream>

class Simulator
{
public:
	enum class simulationState { PLAYING, PAUSED, INACTIVE};
	simulationState state;
	CircuitBoard* circuitBoard;
	TopBoard* topBoard;
	LeftBoard* leftBoard;
	sf::RenderWindow* window;

	//Funcs
	Simulator(sf::RenderWindow* w);
	~Simulator();
	void close();
	void draw();
	void handleClick(sf::Vector2f mp);
	void handleScroll(sf::Vector2f mp, sf::Event scroll);
	void handleDelete();
	void handleRelease(sf::Vector2f mp);
	void simulate();
};

