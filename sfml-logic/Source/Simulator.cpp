#include "Simulator.h"

Simulator::Simulator(sf::RenderWindow* w):
	window(w), state(simulationState::INACTIVE)
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

void Simulator::draw()
{
	window->clear(sf::Color(200,200,200));
	topBoard->draw();
	leftBoard->draw();
	circuitBoard->draw();
	window->display();
}

void Simulator::handleClick(sf::Vector2f mp)
{
	if (leftBoard->isInside(mp) && state == simulationState::INACTIVE)
	{
		Object::objectType b = leftBoard->handleClick(mp);
		if (b != Object::objectType::NoButton)
			if (b == Object::objectType::Trash)
				circuitBoard->deleteEverything();
			else
			circuitBoard->addLogic(window, b);
		
	}
	else if (topBoard->isInside(mp))
	{
		Object::objectType b = topBoard->handleClick(mp);

		switch (b)
		{
		case Object::objectType::Play:
			if (state == simulationState::INACTIVE)
			{
				topBoard->plot->show_plot = true;
				circuitBoard->unselectAll();
				state = simulationState::PLAYING;
			}
			else if (state == simulationState::PLAYING)
			{
				state = simulationState::PAUSED;
			}
			else if (state == simulationState::PAUSED)
			{
				state = simulationState::PLAYING;
			}
			break;
		case Object::objectType::Stop:
			if (state != simulationState::INACTIVE)
			{
				topBoard->reset();
				circuitBoard->reset();
			}
			state = simulationState::INACTIVE;
			break;
		case Object::objectType::NoButton:
			break;
		}
	}
	else if (circuitBoard->isInside(mp))
	{
		if (state == simulationState::INACTIVE)
		{
			//move objects
			circuitBoard->handleClick(mp);
		}
		else
		{
			Pin::pinState* data = circuitBoard->plot(mp);
			if (data != nullptr)
			{
				topBoard->plotData(data);
			}
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
	if (topBoard->isInside(mp) && topBoard->plot->show_plot)
	{
		topBoard->handleScroll(mp, scroll);
	}
}

void Simulator::handleDelete()
{
	if (state == simulationState::INACTIVE)
	{
		circuitBoard->handleDelete();
	}
	else
	{
		return;
	}
}

void Simulator::handleRelease(sf::Vector2f mp)
{
	if (topBoard->plot->clickedX != nullptr)
		topBoard->handleRelease( mp);
	circuitBoard->handleRelease(mp);
}

void Simulator::simulate()
{
	if (state == simulationState::PLAYING)
	{
		circuitBoard->simulate();
		topBoard->updatePlot();
	}
}
