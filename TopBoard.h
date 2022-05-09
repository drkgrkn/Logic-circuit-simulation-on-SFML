#pragma once

#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Board.h"

class TopBoard: public Board
{
public:
	Button buttons[2];
	//Funcs
	TopBoard(sf::RenderWindow* w);
	void draw() const override;
	buttonType handleClick(sf::Vector2f mp) const;
};

