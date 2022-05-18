#pragma once

#include <SFML/Graphics.hpp>
#include "Button.h"

class Board
{
public:
	sf::RectangleShape backGround;
	sf::RenderWindow* window;

	Board(sf::RenderWindow* w);
	void setBackGround(sf::Vector2f p, sf::Vector2f s,
								sf::Color color);
	virtual void draw() const;
	bool isInside(sf::Vector2f mp) const;
};

