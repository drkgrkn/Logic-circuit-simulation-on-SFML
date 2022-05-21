#include "Gates/Logic0.h"

Logic0::Logic0(sf::RenderWindow* w, LogicElement* ePtr) :
	LogicElement(w, ePtr)
{
	pins = new Pin[1]{ Pin(window, Pin::pinType::OUTPUT),
	};
	numPins = 1;
	dataLength = 500;
	data = new int[dataLength];
	dIdx = 0;
	pinsPos = new sf::Vector2f[1]{ sf::Vector2f(8,-3),

	};
	setSprite();
}

Logic0::~Logic0()
{
	delete[] pins;
}

void Logic0::setSprite()
{
	sprite.setTexture(*(textures->textures[5]));
	sprite.scale(0.6f, 0.6f);

	float x_size = sprite.getTexture()->getSize().x * sprite.getScale().x;
	float y_size = sprite.getTexture()->getSize().y * sprite.getScale().y;

	selectionIndicator.setOutlineColor(sf::Color::Red);
	selectionIndicator.setFillColor((sf::Color(255, 255, 255, 0)));
	selectionIndicator.setOutlineThickness(4);
	selectionIndicator.setSize(sf::Vector2f(x_size, y_size));
}

void Logic0::simulate() {

	pins[0].state = Pin::pinState::LOW;

}