#include "Gates/NotGate.h"

NotGate::NotGate(sf::RenderWindow* w, LogicElement* ePtr) :
	LogicElement(w, ePtr)
{
	logicType = Object::objectType::NotGate;
	pins = new Pin[2]{ Pin(window, Pin::pinType::INPUT),
						Pin(window, Pin::pinType::OUTPUT) };
	numPins = 2;
	dataLength = 500;
	dIdx = 0;
	pinsPos = new sf::Vector2f[2]{ sf::Vector2f(-3,13),
								sf::Vector2f(53,13),
	};
	setSprite();
}

NotGate::~NotGate()
{
	delete[] pins;
}

void NotGate::setSprite()
{
	sprite.setTexture(*(textures->textures[3]));
	sprite.scale(0.6f, 0.6f);

	float x_size = sprite.getTexture()->getSize().x * sprite.getScale().x;
	float y_size = sprite.getTexture()->getSize().y * sprite.getScale().y;

	selectionIndicator.setOutlineColor(sf::Color::Red);
	selectionIndicator.setFillColor((sf::Color(255, 255, 255, 0)));
	selectionIndicator.setOutlineThickness(4);
	selectionIndicator.setSize(sf::Vector2f(x_size, y_size));
}

void NotGate::simulate() {

	//INPUT UPDATE
	if (pins[0].connectedTo[0] != nullptr)
	{
		pins[0].state = pins[0].connectedTo[0]->state;
	}
	else
	{
		pins[0].state = Pin::pinState::HIGHZ;
	}

	//OUTPUT UPDATE
	if (pins[0].state == Pin::pinState::HIGHZ)
	{
		pins[1].state = Pin::pinState::HIGHZ;
	}
	if (pins[0].state == Pin::pinState::HIGH)
	{
		pins[1].state = Pin::pinState::LOW;
	}

	else if (pins[0].state == Pin::pinState::LOW)
	{
		pins[1].state = Pin::pinState::HIGH;
	}


}