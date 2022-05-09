#include "Simulator.h"

Simulator::Simulator(sf::RenderWindow* w):
	window(w)
{
	topBoard = new TopBoard(w);
	leftBoard = new LeftBoard(w);
	circuitBoard = new CircuitBoard(w);
}

Simulator::~Simulator()
{
	delete leftBoard;
	delete topBoard;
	delete circuitBoard;
}

void Simulator::close()
{
	window->close();
}

void Simulator::draw() {
	window->clear();
	topBoard->draw();
	circuitBoard->draw();
	leftBoard->draw();
	window->display();
}

void Simulator::handleClick(sf::Vector2f mp)
{
	if (leftBoard->isInside(mp))
	{
		buttonType b = leftBoard->handleClick(mp);
		buttonfuncs::print(b);
	}
	else if (topBoard->isInside(mp))
	{
		buttonType b = topBoard->handleClick(mp);
		buttonfuncs::print(b);
	}
}