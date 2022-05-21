#include "Gates/AndGate.h"

AndGate::AndGate(sf::RenderWindow* w, LogicElement* ePtr):
	LogicElement(w, ePtr)
{
	pins = new Pin[3]{	Pin(window, Pin::pinType::INPUT),
						Pin(window, Pin::pinType::INPUT),
						Pin(window, Pin::pinType::OUTPUT) };
	numPins = 3;
	dataLength = 500;
	data = new int[dataLength];
	dIdx = 0;
	pinsPos = new sf::Vector2f[3]{ sf::Vector2f(-2,5),
								sf::Vector2f(-2,22),
								sf::Vector2f(51,14)
								};
	setSprite();
}

AndGate::~AndGate()
{
	delete[] pins;
}

void AndGate::setSprite()
{
	sprite.setTexture(*(textures->textures[0]));
	sprite.scale(0.6f, 0.6f);

	float x_size = sprite.getTexture()->getSize().x * sprite.getScale().x;
	float y_size = sprite.getTexture()->getSize().y * sprite.getScale().y;

	selectionIndicator.setOutlineColor(sf::Color::Red);
	selectionIndicator.setFillColor((sf::Color(255, 255, 255, 0)));
	selectionIndicator.setOutlineThickness(4);
	selectionIndicator.setSize(sf::Vector2f(x_size, y_size));
}

void AndGate::Simulate()
{
	
}