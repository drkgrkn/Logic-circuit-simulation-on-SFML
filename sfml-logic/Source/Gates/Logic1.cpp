#include "Gates/Logic1.h"

Logic1::Logic1(sf::RenderWindow* w, LogicElement* ePtr) :
	LogicElement(w, ePtr)
{
	pins = new Pin[1]{ Pin(window, Pin::pinType::OUTPUT),
	};
	numPins = 1;
	dataLength = 500;
	data = new int[dataLength];
	dIdx = 0;
	pinsPos = new sf::Vector2f[1]{ sf::Vector2f(14,28) };
	setSprite();
}

Logic1::~Logic1()
{
	delete[] pins;
}

void Logic1::setSprite()
{
	sprite.setTexture(*(textures->textures[6]));
	sprite.scale(0.6f, 0.6f);

	float x_size = sprite.getTexture()->getSize().x * sprite.getScale().x;
	float y_size = sprite.getTexture()->getSize().y * sprite.getScale().y;

	selectionIndicator.setOutlineColor(sf::Color::Red);
	selectionIndicator.setFillColor((sf::Color(255, 255, 255, 0)));
	selectionIndicator.setOutlineThickness(4);
	selectionIndicator.setSize(sf::Vector2f(x_size, y_size));
}