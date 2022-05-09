#include <iostream>
#include <SFML/Graphics.hpp>
#include "Simulator.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Logic Simulator");
	Simulator simulator(&window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
			case sf::Event::MouseButtonPressed:
				sf::Vector2f mp = sf::Vector2f(sf::Mouse::getPosition(window));
				simulator.handleClick(mp);
			}
		}

		simulator.draw();
	}
}