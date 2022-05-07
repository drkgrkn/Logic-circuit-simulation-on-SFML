//
// Created by peak on 05.05.2022.
//

#include "../include/Simulator.h"

Simulator::Simulator(sf::RenderWindow* w):
    window(w), objPtr(nullptr)
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
        buttonType b = leftBoard->handleClick(mp);
        createObject(b);
    } else if (topBoard->contains(mp))
    {
        buttonType b = topBoard->handleClick(mp);
        switch (b)
        {
            case NoButton:
                break;
            case Play:
                break;
            case Stop:
                break;
        }
    } else if (circuitBoard->contains(mp))
    {
        circuitBoard->handleClick(mp);
    }
}

void Simulator::createObject(buttonType b)
{
    if (b == NoButton)
        return;
    std::cout << "Create Object" << b << std::endl;
}