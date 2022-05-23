#include "Gates/Clock.h"

Clock::Clock(sf::RenderWindow* w, LogicElement* ePtr) ://Constructor of Clock class which initializes number of pins, types and position of the pins relative to Clock's sprite
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

Clock::~Clock()                  //Delete clock object and pins
{
	delete[] pins;
}

void Clock::setSprite()
{
	sprite.setTexture(*(textures->textures[7]));
	sprite.scale(0.6f, 0.6f);

	float x_size = sprite.getTexture()->getSize().x * sprite.getScale().x;    // Resize clock sprite to 0.6 times by itself
	float y_size = sprite.getTexture()->getSize().y * sprite.getScale().y;

	selectionIndicator.setOutlineColor(sf::Color::Red);
	selectionIndicator.setFillColor((sf::Color(255, 255, 255, 0)));         //Initiate the selection box proporties
	selectionIndicator.setOutlineThickness(4);
	selectionIndicator.setSize(sf::Vector2f(x_size, y_size));
}

void Clock::simulate()  //not used for clock
{
	
}

void Clock::preSimulate()     // OUTPUT UPDATE
{
	if (pins[0].state == Pin::pinState::LOW || pins[0].state == Pin::pinState::HIGHZ) {

		pins[0].state = Pin::pinState::HIGH;
		return;

	}

	if (pins[0].state == Pin::pinState::HIGH || pins[0].state == Pin::pinState::HIGHZ) {

		pins[0].state = Pin::pinState::LOW;
		return;

	}
}