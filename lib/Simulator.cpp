//
// Created by peak on 05.05.2022.
//

#include "../include/Simulator.h"

Simulator::Simulator(sf::RenderWindow* w):
    window(w)
{
    circuitBoard = new CircuitBoard(window);
    topBoard = new TopBoard(window);
    leftBoard = new LeftBoard(window);
}

Simulator::~Simulator()
{
    delete circuitBoard;
    delete topBoard;
    delete leftBoard;
}


void Simulator::close()
{
    delete this;
}

void Simulator::Draw()
{
    window->clear(sf::Color(200,200,200));
    circuitBoard->Draw();
    topBoard->Draw();
    leftBoard->Draw();
    window->display();
}

void Simulator::handleClick(sf::Vector2f mp)
{
    if (leftBoard->contains(mp))
    {
        leftBoard->handleClick(mp);
    } else if (topBoard->contains(mp))
    {
        topBoard->handleClick(mp);
    } else if (circuitBoard->contains(mp))
    {
        circuitBoard->handleClick(mp);
    }
}
