#pragma once

#include <SFML/Graphics.hpp>
#include "Button.h"

class Board
{
public:
	sf::RectangleShape backGround;
	sf::RenderWindow* window;

	Board(sf::RenderWindow* w);
	//this could have been virtual too
	void setBackGround(sf::Vector2f p, sf::Vector2f s,
								sf::Color color);
	//generic draw function
	//All boards have different
	//stuff they need to call draw on too
	//so this needs to be overridden
	virtual void draw() const;
	//generic isInside function to check if
	//mouse is inside given object
	bool isInside(sf::Vector2f mp) const;
};

