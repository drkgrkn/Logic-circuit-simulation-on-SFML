#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Textures.h"

class Object
{
public:
	enum class objectType {
		AndGate,
		OrGate,
		XorGate,
		NotGate,
		DFlipFlop,
		Logic0,
		Logic1,
		Clock,
		LED,
		Play,
		Stop,
		NoButton
	};

	sf::Sprite sprite;
	sf::RenderWindow* window;
	static Textures* textures;
//functions
	Object(sf::RenderWindow* w);
	virtual void draw() const;
	//void setTexture(std::string str);
};

