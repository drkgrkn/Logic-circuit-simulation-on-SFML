#include "Simulator.h"

Simulator::Simulator(sf::RenderWindow* w):
	window(w), state(false)
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
	leftBoard->draw();
	circuitBoard->draw();
	window->display();
}

void Simulator::handleClick(sf::Vector2f mp)
{
	if (leftBoard->isInside(mp) && state == false)
	{
		buttonType b = leftBoard->handleClick(mp);
		if (b != buttonType::NoButton)
			circuitBoard->addEntity(window, b);
	}
	else if (topBoard->isInside(mp))
	{
		buttonType b = topBoard->handleClick(mp);
		buttonfuncs::print(b);

		switch (b)
		{
		case buttonType::Play:
			state = 1;
			break;
		case buttonType::Stop:
			state = 0;
			break;
		case buttonType::NoButton:
			break;
		}
	}
	else if (circuitBoard->isInside(mp))
	{
		if (state == false)
		{
			//move objects
			circuitBoard->handleClick(mp);
		}
		else if (state == true)
		{
			/*Object stores its own history?
			retrieve it's history
			feed to plot object calculateGraph()
			
			Maybe predefine an array size that's long
			enum -> low - high - undefined
			
			plot reads into an 0-1 array till undefined
			is found*/
		}
	}
}

void Simulator::handleScroll(sf::Vector2f mp, sf::Event scroll)
{
	if (topBoard->isInside(mp))
	{
		topBoard->handleScroll(mp, scroll);
	}
}

void Simulator::handleDelete()
{
	circuitBoard->handleDelete();
}

void Simulator::simulate()
{
	circuitBoard->simulate();
}