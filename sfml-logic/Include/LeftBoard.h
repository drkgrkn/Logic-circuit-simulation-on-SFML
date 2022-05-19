#pragma once

#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Board.h"


class LeftBoard: public Board
{
public:
	Button buttons[9];

	LeftBoard(sf::RenderWindow* w);
	void draw() const override;
	Object::objectType handleClick(sf::Vector2f mp) const;
};

