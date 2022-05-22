#include "Gates/Clock.h"

Clock::Clock(sf::RenderWindow* w, LogicElement* ePtr) :
	LogicElement(w, ePtr)
{
	logicType = Object::objectType::Clock;
	pins = new Pin[1]{ Pin(window, Pin::pinType::OUTPUT),
	};
	numPins = 1;
	dataLength = 500;
	dIdx = 0;
	pinsPos = new sf::Vector2f[1]{ sf::Vector2f(42,14),
	};
	setSprite();
}

Clock::~Clock()
{
	delete[] pins;
}

void Clock::setSprite()
{
	sprite.setTexture(*(textures->textures[7]));
	sprite.scale(0.6f, 0.6f);

	float x_size = sprite.getTexture()->getSize().x * sprite.getScale().x;
	float y_size = sprite.getTexture()->getSize().y * sprite.getScale().y;

	selectionIndicator.setOutlineColor(sf::Color::Red);
	selectionIndicator.setFillColor((sf::Color(255, 255, 255, 0)));
	selectionIndicator.setOutlineThickness(4);
	selectionIndicator.setSize(sf::Vector2f(x_size, y_size));
}

void Clock::simulate()
{
	
}

void Clock::preSimulate()
{
	std::cout << (pins[0].state == Pin::pinState::HIGH) << std::endl;

	if (pins[0].state == Pin::pinState::LOW || pins[0].state == Pin::pinState::HIGHZ) {

		pins[0].state = Pin::pinState::HIGH;
		return;

	}

	if (pins[0].state == Pin::pinState::HIGH || pins[0].state == Pin::pinState::HIGHZ) {

		pins[0].state = Pin::pinState::LOW;
		return;

	}
}