#pragma once

#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Board.h"
#include "Plot.h"
#include "Pin.h"

class TopBoard: public Board
{
public:
	Plot* plot;
	Button buttons[2];
	//Funcs
	TopBoard(sf::RenderWindow* w);
	~TopBoard();
	void draw() const override;
	Object::objectType handleClick(sf::Vector2f mp) const;
	void handleScroll(sf::Vector2f mp, sf::Event scroll);
	void plotData(Pin::pinState* data);
	void updatePlot();
};

