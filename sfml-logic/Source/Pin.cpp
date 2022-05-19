#include "Pin.h"



Pin::Pin(sf::RenderWindow* w, Pin::pinType t)
{
	window = w;
	state = pinState::LOW;
	type = t;

	numConnections = 0;

	setShape();
}

void Pin::setShape()
{
	shape.setSize(sf::Vector2f(10, 10));
	shape.setFillColor(sf::Color::Red);
}

void Pin::setPosition(sf::Vector2f v)
{
	shape.setPosition(v);
}

void Pin::draw()
{
	window->draw(shape);
}

bool Pin::isInside(sf::Vector2f mp)
{
	float x_size = shape.getSize().x;
	float y_size = shape.getSize().y;
	float x_pos = shape.getPosition().x;
	float y_pos = shape.getPosition().y;

	return (mp.x <= x_pos + x_size) &&
		(mp.x >= x_pos) &&
		(mp.y <= y_pos + y_size) &&
		(mp.y >= y_pos);
}

void Pin::handleClick()
{
	if (numConnections < MAX_CONNECTIONS)
	{
		wires[numConnections] = new Wire(window, this);
		numConnections++;
	}
}

void Pin::embedWire(sf::Vector2f mp, Wire* wPtr)
{
	if (numConnections < MAX_CONNECTIONS)
	{
		wires[numConnections] = wPtr;
		numConnections++;
		wPtr->embedToPin(mp, this);
	}
}

void Pin::unembedWire(Wire* wPtr)
{
	for (int i = 0; i < MAX_CONNECTIONS; i++)
	{
		if (wires[i] == wPtr)
		{
			wires[i] = nullptr;
			numConnections--;
			connectedTo[i] = nullptr;
			delete wPtr;
			wPtr = nullptr;
		}
	}
}