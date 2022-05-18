#include "AndGate.h"

AndGate::AndGate(sf::RenderWindow* w,Entity* ePtr): LogicElement(w, numPins, ePtr)
{
	numPins = 3;
	sprite.setTexture(Object::textures.textures[0]);
	std::cout << "Andgate constructor";
	pins = new Pin[3]{  Pin(w, Pin::pinType::INPUT, 0),
						Pin(w, Pin::pinType::INPUT, 1),
						Pin(w, Pin::pinType::OUTPUT, 2) };
}

AndGate::~AndGate()
{
	delete[numPins] pins;
}

Pin::pinState AndGate::getState(int index)
{
	return pins[index].state;
}

void AndGate::pinPos()
{
	pins[0].pinShape.setPosition(sprite.getPosition() + sf::Vector2f(0, 0));
	pins[1].pinShape.setPosition(sprite.getPosition() + sf::Vector2f(0, 20));
	pins[2].pinShape.setPosition(sprite.getPosition() + sf::Vector2f(49, 10));
}

void AndGate::calcOutput()
{
	if (getState(1) == Pin::pinState::HIGH && getState(2) == Pin::pinState::HIGH)
	{
		pins[2].state = Pin::pinState::HIGH;
	}
	else
	{
		pins[2].state = Pin::pinState::LOW;
	}
}