#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Textures.h"

class Object
{
public:
	/*
	Maybe this could have been inside just
	Button class but early on we thought
	LogicElement class would have taken advantage
	of this enumeration too
	That's why it's here
	*/
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
		Trash,
		NoButton
	};

	//All object have sprites (except wire)
	sf::Sprite sprite;
	//All will have a window reference to draw
	//themselves
	sf::RenderWindow* window;
	/*
	Instead of every object locally loading
	their own texture, all of them point to a
	single Textures object to get their
	own texture. Saves memory and gives much
	more cleaner code
	*/
	static Textures* textures;
//functions
	Object(sf::RenderWindow* w);
	//Since all object deriving classed will have
	//their own draw method, I predeclared it here
	virtual void draw() const;

	//DEPRECATED WITH STATIC TEXTURES CLASS
	//void setTexture(std::string str);
};

