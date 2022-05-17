#pragma once

#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Board.h"
#include "Plot.h"

class TopBoard: public Board
{
public:
	Plot* plot;
	Button buttons[2];
	//Funcs
	TopBoard(sf::RenderWindow* w);
	~TopBoard();
	void draw() const override;
	buttonType handleClick(sf::Vector2f mp) const;
	void handleScroll(sf::Vector2f mp, sf::Event scroll);
};

