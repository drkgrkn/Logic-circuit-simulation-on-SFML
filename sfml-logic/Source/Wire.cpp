#include "Wire.h"

Wire::Wire(sf::RenderWindow* w, Pin* p) :
	Entity(w)
{
	type = Entity::entityType::WIRE;
    pins[0] = p;
	vertices[0] = pins[0]->shape.getPosition();
}

void Wire::draw()
{
	if (grabbed)
	{
		vertices[3] = sf::Vector2f(sf::Mouse::getPosition(*window));
		float x = (vertices[0].x + vertices[3].x) / 2;

		vertices[1] = sf::Vector2f(x, vertices[0].y);
		vertices[2] = sf::Vector2f(x, vertices[3].y);
	}
		sf::RectangleShape rectangle;
		rectangle.setPosition(vertices[0]);
		rectangle.setSize(sf::Vector2f(vertices[1].x - vertices[0].x, 4));
		rectangle.setFillColor(sf::Color::Black);
		window->draw(rectangle);

		rectangle.setPosition(vertices[1]);
		rectangle.setSize(sf::Vector2f(4, vertices[2].y - vertices[1].y));
		rectangle.setFillColor(sf::Color::Black);
		window->draw(rectangle);

		rectangle.setPosition(vertices[2]);
		rectangle.setSize(sf::Vector2f(vertices[3].x - vertices[2].x, 4));
		rectangle.setFillColor(sf::Color::Black);
		window->draw(rectangle);
}

void Wire::place(sf::Vector2f mp)
{
	vertices[3] = sf::Vector2f(sf::Mouse::getPosition(*window));
	grabbed = false;
	selected = false;
}

void Wire::embedToPin(sf::Vector2f mp, Pin* p)
{
	pins[1] = p;
	place(mp);
}
