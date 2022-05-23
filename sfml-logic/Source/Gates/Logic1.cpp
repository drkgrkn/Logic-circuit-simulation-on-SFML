#include "Gates/Logic1.h"

Logic1::Logic1(sf::RenderWindow* w, LogicElement* ePtr) ://Constructor of Logic1 which initializes number of pins, types and position of the pins relative to Logic1 sprite
	LogicElement(w, ePtr)
{
	logicType = Object::objectType::Logic1;
	pins = new Pin[1]{ Pin(window, Pin::pinType::OUTPUT),
	};
	numPins = 1;
	dataLength = 500;
	dIdx = 0;
	pinsPos = new sf::Vector2f[1]{ sf::Vector2f(14,28) };
	setSprite();
}
 
Logic1::~Logic1()            //Delete Logic1 object and pins
{
	delete[] pins;
}

void Logic1::setSprite()
{
	sprite.setTexture(*(textures->textures[6]));
	sprite.scale(0.6f, 0.6f);

	float x_size = sprite.getTexture()->getSize().x * sprite.getScale().x; // Resize Logic1 sprite to 0.6 times by itself
	float y_size = sprite.getTexture()->getSize().y * sprite.getScale().y;

	selectionIndicator.setOutlineColor(sf::Color::Red);
	selectionIndicator.setFillColor((sf::Color(255, 255, 255, 0))); //Initiate the selection box proporties
	selectionIndicator.setOutlineThickness(4);
	selectionIndicator.setSize(sf::Vector2f(x_size, y_size));
}

void Logic1::simulate(){ // Constant output pin (HIGH)

	pins[0].state = Pin::pinState::HIGH;


}

void Logic1::preSimulate()
{
	
}
