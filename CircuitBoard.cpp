#include "CircuitBoard.h"

CircuitBoard::CircuitBoard(sf::RenderWindow* w) :
	Board(w)
{
	objects = nullptr;
	setBackGround(sf::Vector2f(100, 100),
				sf::Vector2f(700, 600),
				200);

}

void CircuitBoard::draw() const
{
	window->draw(backGround);
}