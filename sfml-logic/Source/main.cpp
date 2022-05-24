#include <iostream>
#include <time.h>
#include <SFML/Graphics.hpp>
#include "Simulator.h"
#include "Object.h"
#include "Textures.h"

//HOW OFTEN THE SIMULATION WILL CALCULATE
const int timer = 1;

int main()
{
	//initialization of the global texture loader
	Textures  textures = Textures();
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Logic Simulator", sf::Style::Close);
	Object::textures = &textures;
	Simulator simulator(&window);
	time_t last_time = time(0);
	while (window.isOpen())
	{
		//if 1 seconds passed since last time
		if (time(0) - last_time >= timer && simulator.state != Simulator::simulationState::INACTIVE)
		{
			//CHANGE CLOCKS OUTPUT
			//CALCULATE STATE OF CIRCUIT
			simulator.simulate();
			last_time = time(0);
		}
		sf::Event event;
		while (window.pollEvent(event))
		{
			sf::Vector2f mp = sf::Vector2f(sf::Mouse::getPosition(window));

			switch (event.type)
			{
			case sf::Event::Closed:
			{
				simulator.close();
			}
			//FOR GRAPH ZOOMING
			case sf::Event::KeyPressed:
			{
				if (event.key.code == sf::Keyboard::Delete)
				{
					simulator.handleDelete();
					break;
				}
			}
			case sf::Event::MouseWheelScrolled:
			{
				simulator.handleScroll(mp, event);
				break;
			}
			case sf::Event::MouseButtonReleased:
			{
				simulator.handleRelease(mp);
				break;
			}
			//FOR NEARLY EVERYTHING
			case sf::Event::MouseButtonPressed:
			{
				/*this if statement is here so
				simulator doesn't instantly
				simulate the first state after
				pressing play, feels better*/
				if (simulator.state != Simulator::simulationState::INACTIVE)
					last_time = time(0);

				sf::Vector2f mp = sf::Vector2f(sf::Mouse::getPosition(window));
				simulator.handleClick(mp);
			}
			}
		}
		simulator.draw();
	}
}