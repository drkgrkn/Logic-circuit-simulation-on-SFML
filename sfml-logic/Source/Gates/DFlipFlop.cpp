#include "Gates/DFlipFlop.h"

DFlipFlop::DFlipFlop(sf::RenderWindow* w, LogicElement* ePtr) ://Constructor of Dflipflop which initializes number of pins, types and position of the pins relative to Dflipflop sprite
	LogicElement(w, ePtr)
{
	logicType = Object::objectType::DFlipFlop;
	pins = new Pin[4]{ Pin(window, Pin::pinType::INPUT),
						Pin(window, Pin::pinType::INPUT),
						Pin(window, Pin::pinType::OUTPUT),
						Pin(window,Pin::pinType::OUTPUT)
	};
	numPins = 4;
	dataLength = 500;
	dIdx = 0;
	pinsPos = new sf::Vector2f[4]{ sf::Vector2f(-2,7),
								sf::Vector2f(-2,20),
								sf::Vector2f(52,8),
								sf::Vector2f(52,31)
	};
	setSprite();
}

DFlipFlop::~DFlipFlop()        //Delete Dflipflop object and pins
{
	delete[] pins;
}

void DFlipFlop::setSprite()
{
	sprite.setTexture(*(textures->textures[4]));
	sprite.scale(0.6f, 0.6f);

	float x_size = sprite.getTexture()->getSize().x * sprite.getScale().x; // Resize Dlipflop sprite to 0.6 times by itself
	float y_size = sprite.getTexture()->getSize().y * sprite.getScale().y; 

	selectionIndicator.setOutlineColor(sf::Color::Red);
	selectionIndicator.setFillColor((sf::Color(255, 255, 255, 0)));        //Initiate the selection box proporties
	selectionIndicator.setOutlineThickness(4);
	selectionIndicator.setSize(sf::Vector2f(x_size, y_size));
}

void DFlipFlop::simulate()         
{
	if (pins[0].connectedTo[0] != nullptr)
	{
		pins[0].state = pins[0].connectedTo[0]->state;          //INPUT UPDATE 
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

	if (pins[0].state == Pin::pinState::HIGH && pins[1].state == Pin::pinState::HIGH) {      //OUTPUT UPDATE

		pins[2].state = Pin::pinState::HIGH;
		pins[3].state = Pin::pinState::LOW;

	}

	if (pins[0].state == Pin::pinState::LOW && pins[1].state == Pin::pinState::HIGH) {

		pins[2].state = Pin::pinState::LOW;
		pins[3].state = Pin::pinState::HIGH;
	}

	if (pins[1].state == Pin::pinState::LOW && pins[0].state != Pin::pinState::HIGHZ) {

		pins[2].state = Pin::pinState::HIGH;
	}

	else if (pins[0].state == Pin::pinState::HIGHZ || pins[1].state == Pin::pinState::HIGHZ) {

		pins[2].state = Pin::pinState::HIGHZ;
		pins[3].state = Pin::pinState::HIGHZ;
	}

	else {
		std::cout << "5555";
	}
}



void DFlipFlop::preSimulate()
{
	
}