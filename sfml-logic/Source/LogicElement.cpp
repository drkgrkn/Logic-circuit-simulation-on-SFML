#include "LogicElement.h"

LogicElement::LogicElement(sf::RenderWindow* w, Entity* ePtr) :
	Entity(w, ePtr)
{
	//PINS AND numPins depend on gate type, thus
	//will be set in higher class (AndGate, OrGate)
	dIdx = 0;
	dataLength = 500;
	data = new int[dataLength];
}

LogicElement::~LogicElement()
{
	delete[] data;
}

void LogicElement::updateData(Pin::pinState ps)
{
	if (dIdx >= dataLength)
	{
		dataLength += 500;
		auto arr = new int[dataLength];
		std::copy(data, data + dataLength - 500, arr);
		delete[] data;
		data = arr;
	}
	if (ps == Pin::pinState::HIGH)
	{
		data[dIdx++] = 1;
	}
	else
	{
		data[dIdx++] = 0;
	}
}

void LogicElement::setSprite()
{

}

void LogicElement::draw()
{
	if (grabbed)
	{
		sprite.setColor(sf::Color(255, 255, 255, 128));
		sf::Vector2f mp = sf::Vector2f(sf::Mouse::getPosition(*window));
		float x = sprite.getTexture()->getSize().x / 4;
		float y = sprite.getTexture()->getSize().y / 4;
		sprite.setPosition(sf::Vector2f(mp.x - x, mp.y - y));
	}
	if (selected)
	{
		selectionIndicator.setPosition(sprite.getPosition());
		window->draw(selectionIndicator);
	}
	window->draw(sprite);
	sprite.setColor(sf::Color(255, 255, 255, 255));
	for (int i = 0; i < numPins; i++)
	{	
		pins[i].setPosition(sprite.getPosition() + pinsPos[i]);
		pins[i].draw();
	}
}

void LogicElement::handleClick(sf::Vector2f mp)
{
	for (int i = 0; i < numPins; i++)
	{
		if (pins[i].isInside(mp))
		{
			pins[i].handleClick();
			return;
		}
	}
	if (selected)
	{
		grabbed = true;
	}
	else
	{
		selected = true;
	}
}
