#include "Pin.h"

Pin::Pin(sf::RenderWindow* w, Pin::pinType type, int idx):
	window(w), type(type),
	index(idx)
{
	numConnections = 0;
	state = Pin::pinState::LOW;

	isSrc[0] = false;
	connectedTo[0] = nullptr;

	wires[0] = nullptr;
	pinShape.setFillColor(sf::Color(0,50,0));
	pinShape.setRadius(4);
}

void Pin::setPosition(sf::Vector2f v)
{
	pinShape.setPosition(v);
}

bool Pin::isInside(sf::Vector2f mp)
{
	float x_size = pinShape.getRadius()*2;
	float y_size = pinShape.getRadius()*2;
	float x_pos = pinShape.getPosition().x;
	float y_pos = pinShape.getPosition().y;

	return (mp.x <= x_pos + x_size) &&
		(mp.x >= x_pos) &&
		(mp.y <= y_pos + y_size) &&
		(mp.y >= y_pos);
}