#include "TopBoard.h"

TopBoard::TopBoard(sf::RenderWindow* w):
	Board(w), buttons{
					{w, Object::objectType::Play},
					{w, Object::objectType::Stop}
				}
{
	plot = new Plot(w);
	setBackGround(sf::Vector2f(100, 0),
		sf::Vector2f(1180, 100),
		sf::Color(155, 155, 155));
	for (int i = 0; i < 2; i++)
	{
		buttons[i].sprite.setPosition(120.f + 80.f * i, 20);
	}
}

TopBoard::~TopBoard()
{
	delete plot;
}

void TopBoard::draw() const
{
	window->draw(backGround);
	for (const auto b : buttons)
	{
		b.draw();
	}
	plot->draw();
}

Object::objectType TopBoard::handleClick(sf::Vector2f mp) const
{
	Object::objectType bt = Object::objectType::NoButton;
	for (const auto b : buttons)
	{
		if (b.isClicked(mp))
		{
			bt = b.handleClick();
			break;
		}
	}
	return bt;
}

void TopBoard::handleScroll(sf::Vector2f mp, sf::Event scroll)
{
	if (plot->isInside(mp))
	{
		plot->handleScroll(scroll);
	}
}

void TopBoard::plotData(Pin::pinState* data)
{
	plot->show_plot = true;
	plot->plot(data);
}

void TopBoard::updatePlot()
{
	if (plot->dataPtr != nullptr)
		plot->updatePlot();
}

void TopBoard::reset()
{
	plot->reset();
}
