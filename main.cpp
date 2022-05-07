#include <iostream>
#include <SFML/Graphics.hpp>
#include "include/utils.h"
#include "include/Simulator.h"

int main()
{
    //INIT PART
    sf::RenderWindow window(sf::VideoMode(800, 600), "Screen");
    auto simulator = new Simulator(&window);
    //MAIN LOOP
    while(window.isOpen())
    {
        sf::Event event;

        while(window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    simulator->close();
                case sf::Event::MouseButtonPressed:
                {
                    sf::Vector2f mp = sf::Vector2f(sf::Mouse::getPosition(window));
                    simulator->handleClick(mp);
                }
                case sf::Event::KeyPressed:
                {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete))
                    {
                        //LOOP OVER OBJECTS
                            //IF ELEMENT IS SELECTED
                                //DELETE SELECTED ELEMENT
                    }
                }
            }
        }
        simulator->Draw();
    }
    std::cout << "Program terminated." << std::endl;
}

