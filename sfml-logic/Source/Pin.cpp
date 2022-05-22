#include "Pin.h"


Pin::Pin(sf::RenderWindow* w, Pin::pinType t):
	MAX_CONNECTIONS((t == Pin::pinType::OUTPUT) ? 5 : 1)
{
	window = w;
	state = pinState::HIGHZ;
	type = t;

	numConnections = 0;
	wires = new Wire*[MAX_CONNECTIONS];
	connectedTo = new Pin*[MAX_CONNECTIONS];

	for (int i = 0; i < MAX_CONNECTIONS; i++)
	{
		wires[i] = nullptr;
		connectedTo[i] = nullptr;
	}

	setShape();
}

Pin::~Pin()
{
	for (int i = 0; i < MAX_CONNECTIONS; i++)
	{
		if (wires[i] != nullptr)
		{
			delete wires[i];
		}
	}
	delete[] wires;
	delete[] connectedTo;
}

void Pin::setShape()
{
	shape.setSize(sf::Vector2f(10, 10));
	shape.setFillColor(sf::Color::Black);
}

void Pin::setPosition(sf::Vector2f v)
{
	shape.setPosition(v);
}

void Pin::draw()
{
	for (int idx = 0; idx < MAX_CONNECTIONS; idx++)
	{
		if (wires[idx] != nullptr)
		{
			wires[idx]->draw();
		}
	}
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
	if (numConnections == MAX_CONNECTIONS)
	{
		return;
	}
	else
	{
		std::cout << MAX_CONNECTIONS << std::endl;

		for (int idx = 0; idx < MAX_CONNECTIONS; idx++)
		{
			if (wires[idx] == nullptr)
			{
				wires[idx] = new Wire(window, this);
				numConnections++;
				break;
			}
		}
	}
}

void Pin::embedWire(Wire* w, Pin* p)
{
	for (int idx = 0; idx < MAX_CONNECTIONS; idx++)
	{
		if (wires[idx] == nullptr)
		{
			wires[idx] = w;
			connectedTo[idx] = p;
			numConnections++;
			break;
		}
	}
}

void Pin::unembedWire(Wire* w)
{
	for (int idx = 0; idx < MAX_CONNECTIONS; idx++)
	{
		if (w == wires[idx])
		{
			wires[idx] = nullptr;
			connectedTo[idx] = nullptr;
			numConnections--;
			break;
		}
	}
}

void Pin::connect(Wire* w,Pin* p)
{
	for (int idx = 0; idx < numConnections; idx++)
	{
		if (w == wires[idx])
		{
			connectedTo[idx] = p;
			break;
		}
	}
}

void Pin::reset()
{
	state = Pin::pinState::HIGHZ;
	for (int i = 0; i < numConnections; i++)
	{
		wires[i]->reset();
	}
}