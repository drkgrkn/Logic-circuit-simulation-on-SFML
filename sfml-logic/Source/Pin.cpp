#include "Pin.h"

Pin::Pin(sf::RenderWindow* w, Pin::pinType t)
{
	window = w;
	state = pinState::LOW;
	type = t;
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
	std::cout << "CLICKED" << std::endl;
}