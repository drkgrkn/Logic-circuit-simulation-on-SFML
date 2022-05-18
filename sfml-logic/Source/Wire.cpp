#include "Wire.h"

Wire::Wire(sf::RenderWindow* w, sf::Vector2f v, Pin* p):
	window(w)
{
	vertex[0] = sf::Vertex(v, sf::Color::Black);
	pins[0] = p;
}

void Wire::place(sf::Vector2f v, Pin* p)
{
	vertex[3] = sf::Vertex(v);
	pins[1] = p;

	float x = (vertex[0].position.x + vertex[3].position.x) / 2;

	vertex[1] = sf::Vertex(sf::Vector2f(x, vertex[0].position.y), sf::Color::Black);
	vertex[2] = sf::Vertex(sf::Vector2f(x, vertex[3].position.y), sf::Color::Black);
}

void Wire::draw()
{
	window->draw(vertex, 3, sf::LineStrip);
}