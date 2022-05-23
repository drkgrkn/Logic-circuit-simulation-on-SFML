#include "Gates/XorGate.h"

XorGate::XorGate(sf::RenderWindow* w, LogicElement* ePtr) : //Constructor of XorGate which initializes number of pins, types and position of the pins relative toXorGate sprite
	LogicElement(w, ePtr)
{
	logicType = Object::objectType::XorGate;
	pins = new Pin[3]{ Pin(window, Pin::pinType::INPUT),
						Pin(window, Pin::pinType::INPUT),
						Pin(window, Pin::pinType::OUTPUT) };
	numPins = 3;
	dataLength = 500;
	dIdx = 0;
	pinsPos = new sf::Vector2f[3]{ sf::Vector2f(-3,5),
								sf::Vector2f(-3,22),
								sf::Vector2f(50,14)
	};
	setSprite();
}

XorGate::~XorGate()  // //Delete XorGate object and pins
{
	delete[] pins;
}

void XorGate::setSprite()
{
	sprite.setTexture(*(textures->textures[2]));
	sprite.scale(0.6f, 0.6f);

	float x_size = sprite.getTexture()->getSize().x * sprite.getScale().x; // Resize XorGate sprite to 0.6 times by itself
	float y_size = sprite.getTexture()->getSize().y * sprite.getScale().y;

	selectionIndicator.setOutlineColor(sf::Color::Red);
	selectionIndicator.setFillColor((sf::Color(255, 255, 255, 0))); //Initiate the selection box proporties
	selectionIndicator.setOutlineThickness(4);
	selectionIndicator.setSize(sf::Vector2f(x_size, y_size));
}

void XorGate::simulate() {

	//INPUT UPDATE
	if (pins[0].connectedTo[0] != nullptr)
	{
		pins[0].state = pins[0].connectedTo[0]->state;
	}
	else
	{
		pins[0].state = Pin::pinState::HIGHZ;
	}
	if (pins[1].connectedTo[0] != nullptr)
	{
		pins[1].state = pins[1].connectedTo[0]->state;
	}
	else
	{
		pins[1].state = Pin::pinState::HIGHZ;
	}

	//OUTPUT UPDATE
	if (pins[0].state == Pin::pinState::HIGHZ || pins[1].state == Pin::pinState::HIGHZ)
	{
		pins[2].state = Pin::pinState::HIGHZ;
	}
	else if ((pins[0].state == Pin::pinState::HIGH && pins[1].state == Pin::pinState::LOW) || (pins[0].state == Pin::pinState::LOW && pins[1].state == Pin::pinState::HIGH))
	{
		pins[2].state = Pin::pinState::HIGH;
	}
	else
	{
		pins[2].state = Pin::pinState::LOW;
	}



}