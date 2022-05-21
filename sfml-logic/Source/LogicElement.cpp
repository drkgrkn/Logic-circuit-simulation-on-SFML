#include "LogicElement.h"

LogicElement::LogicElement(sf::RenderWindow* w, LogicElement* ePtr) :
	Entity(w), prev(ePtr),
	next(nullptr)
{
	type = Entity::entityType::LOGIC;
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
		for (int p = 0; p < numPins; p++)
		{
			for (int w = 0; w < pins[p].MAX_CONNECTIONS; w++)
			{
				if (pins[p].wires[w] != nullptr)
				{
					pins[p].wires[w]->moveRoot(pins[p].shape.getPosition());
				}
			}
		}
	}
	else
	{
		sprite.setColor(sf::Color(255, 255, 255, 255));
	}
	if (selected)
	{
		selectionIndicator.setPosition(sprite.getPosition());
		window->draw(selectionIndicator);
	}
	window->draw(sprite);
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
		if (pins[i].isInside(mp) && selected)
		{
			pins[i].handleClick();
			return;
		}
	}
	if (selected)
		grabbed = true;
	return;
}

void LogicElement::embedWire(sf::Vector2f mp, Wire* wPtr)
{
	bool success = false;
	for (int i = 0; i < numPins; i++)
	{
		if (pins[i].isInside(mp))
		{
			pins[i].embedWire(wPtr, &pins[i]);
			selected = false;
		}
	}
}

bool LogicElement::isColliding(Entity* le)
{
	float px1 = this->sprite.getPosition().x;
	float py1 = this->sprite.getPosition().y;
	float sx1 = this->sprite.getTexture()->getSize().x * this->sprite.getScale().x;
	float sy1 = this->sprite.getTexture()->getSize().y * this->sprite.getScale().y;

	float px2 = le->sprite.getPosition().x;
	float py2 = le->sprite.getPosition().y;
	float sx2 = le->sprite.getTexture()->getSize().x * le->sprite.getScale().x;
	float sy2 = le->sprite.getTexture()->getSize().y * le->sprite.getScale().y;

	bool collisionX = px1 + sx1 >= px2 && px2 + sx2 >= px1;
	bool collisionY = py1 + sy1 >= py2 && py2 + sy2 >= py1;

	return collisionX && collisionY;
}
