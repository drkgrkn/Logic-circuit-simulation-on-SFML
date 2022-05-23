#include "Gates/LED.h"

LED::LED(sf::RenderWindow* w, LogicElement* ePtr) : //Constructor of LED which initializes number of pins, types and position of the pins relative to LED sprite 
	LogicElement(w, ePtr)
{
	logicType = Object::objectType::LED;
	pins = new Pin[1]{ Pin(window, Pin::pinType::INPUT),
	};
	numPins = 1;
	dataLength = 500;
	dIdx = 0;
	pinsPos = new sf::Vector2f[1]{ sf::Vector2f(8,40),
	};
	setSprite();
}

LED::~LED()  // Delete LED object and pins
{
	delete[] pins;
}

void LED::setSprite() 
{
	sprite.setTexture(*(textures->textures[8]));
	sprite.scale(0.6f, 0.6f);

	float x_size = sprite.getTexture()->getSize().x * sprite.getScale().x; // Resize LED sprite to 0.6 times by itself (initialization)
	float y_size = sprite.getTexture()->getSize().y * sprite.getScale().y;

	selectionIndicator.setOutlineColor(sf::Color::Red);
	selectionIndicator.setFillColor((sf::Color(255, 255, 255, 0))); //Initiate the selection box proporties
	selectionIndicator.setOutlineThickness(4);
	selectionIndicator.setSize(sf::Vector2f(x_size, y_size));
}


void LED::setSprite(int index) {
	
	sprite.setTexture(*(textures->textures[index+8]));
	sprite.scale(1.f, 1.f);

	float x_size = sprite.getTexture()->getSize().x * sprite.getScale().x; // Resize LED sprite to 0.6 times by itself (for toggling LED)
	float y_size = sprite.getTexture()->getSize().y * sprite.getScale().y;

	selectionIndicator.setOutlineColor(sf::Color::Red);
	selectionIndicator.setFillColor((sf::Color(255, 255, 255, 0)));    //Initiate the selection box proporties
	selectionIndicator.setOutlineThickness(4);
	selectionIndicator.setSize(sf::Vector2f(x_size, y_size));

	}

void LED::simulate()  
{
	
}

void LED::reset()      //For the reset button of simulation
{
	setSprite(0);
	dIdx = 0;
	delete[] data;
	dataLength = 500;
	data = new Pin::pinState[dataLength];
	for (int i = 0; i < dataLength; i++)
	{
		data[i] = Pin::pinState::HIGHZ;
	}
	for (int p = 0; p < numPins; p++)
	{
		pins[p].reset();
	}
}

void LED::updateData()
{
	//INPUT UPDATE
	if (pins[0].connectedTo[0] != nullptr)
	{
		pins[0].state = pins[0].connectedTo[0]->state;
	}
	else
	{
		setSprite(0);
		pins[0].state = Pin::pinState::HIGHZ;
	}

	//OUTPUT UPDATE + Change sprite depends on INPUT 

	if (pins[0].state == Pin::pinState::HIGH)
	{
		setSprite(1);
	}
	if (pins[0].state == Pin::pinState::LOW)
	{
		setSprite(0);
	}
	int idx = 0;
	switch (logicType)
	{
	case (Object::objectType::Logic0):
	case (Object::objectType::Logic1):
	case(Object::objectType::Clock):
	case (Object::objectType::LED):
		idx = 0;
		break;
	case (Object::objectType::NotGate):
		idx = 1;
		break;
	default:
		idx = 2;
		break;
	}
	if (dIdx >= dataLength)
	{
		dataLength += 500;
		auto arr = new Pin::pinState[dataLength];
		std::copy(data, data + dataLength - 500, arr);
		delete[] data;
		data = arr;
	}
	if (pins[idx].state == Pin::pinState::HIGH)
	{
		data[dIdx++] = Pin::pinState::HIGH;
	}
	else if (pins[idx].state == Pin::pinState::LOW)
	{
		data[dIdx++] = Pin::pinState::LOW;
	}
	else
	{
		data[dIdx++] = Pin::pinState::HIGHZ;
	}
}
