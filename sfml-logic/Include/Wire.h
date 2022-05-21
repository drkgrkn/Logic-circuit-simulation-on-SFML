#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.h"
#include "Pin.h"

class Pin;

class Wire: public Entity
{
public:
	/*Entity
		selected
		grabbed*/
	sf::Vector2f vertices[4];
	sf::RectangleShape body[5];
	Pin* pins[2];

	//FUNCS
	Wire(sf::RenderWindow* w, Pin* p);
	~Wire();
	void draw();
	void setBody();
	void moveTip(Pin* p, sf::Vector2f v);
	bool isInside(sf::Vector2f mp) override;
	void embed(Pin* p);
};

