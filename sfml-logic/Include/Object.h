#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Textures.h"

class Object
{
public:
	sf::Sprite sprite;
	sf::RenderWindow* window;
	static Textures textures;
//functions
	Object(sf::RenderWindow* w);
	virtual void draw() const;
	//void setTexture(std::string str);
};

