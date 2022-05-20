#include "Wire.h"

Wire::Wire(sf::RenderWindow* w, Pin* p) :
	Entity(w)
{
	std::cout << w << std::endl;
	type = Entity::entityType::WIRE;
    pins[0] = p;
	vertices[0] = pins[0]->shape.getPosition();
}

Wire::~Wire()
{
	if (pins[0] != nullptr)
	{
		pins[0]->unembedWire(this);
	}
	if (pins[1] != nullptr)
	{
		pins[1]->unembedWire(this);
	}
}

void Wire::draw()
{
	if (grabbed)
	{
		vertices[3] = sf::Vector2f(sf::Mouse::getPosition(*window));
		float x = (vertices[0].x + vertices[3].x) / 2;

		vertices[1] = sf::Vector2f(x, vertices[0].y);
		vertices[2] = sf::Vector2f(x, vertices[3].y);
		
		setBody();
	}


	for (int i = 0; i < 3; i++)
	{
		window->draw(body[i]);
	}
}

void Wire::place(sf::Vector2f mp)
{
	vertices[3] = mp;
	grabbed = false;
	selected = false;
}

void Wire::embedToPin(sf::Vector2f mp, Pin* p)
{
	std::cout << window << std::endl;

	pins[1] = p;
	place(mp);
}

void Wire::setBody()
{
	body[0].setPosition(vertices[0]);
	body[0].setSize(sf::Vector2f(vertices[1].x - vertices[0].x, 4));
	body[0].setFillColor(sf::Color::Black);

	body[1].setPosition(vertices[1]);
	body[1].setSize(sf::Vector2f(4, vertices[2].y - vertices[1].y));
	body[1].setFillColor(sf::Color::Black);

	body[2].setPosition(vertices[2]);
	body[2].setSize(sf::Vector2f(vertices[3].x - vertices[2].x, 4));
	body[2].setFillColor(sf::Color::Black);
}

bool Wire::isInside(sf::Vector2f mp)
{
	return false;
}