#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Object
{
public:
	sf::Texture textures[2];
	sf::Sprite sprite;
	sf::RenderWindow* window;

//functions
	Object(sf::RenderWindow* w);
	void draw() const;
	void setTexture(std::string str);
};

