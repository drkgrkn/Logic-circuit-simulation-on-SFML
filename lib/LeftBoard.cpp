//
// Created by peak on 05.05.2022.
//


//
// Created by peak on 02.05.2022.
//

#include "../include/LeftBoard.h"
#include <SFML/Graphics.hpp>
#include <iostream>

LeftBoard::LeftBoard(sf::RenderWindow* w):
    window(w)
{
    setBackGround();
    setBox();
    setSampleTextures();
    setSampleSprites();
}

void LeftBoard::setBackGround()
{
    backGround.setSize(sf::Vector2f(100,600));
    backGround.setFillColor(sf::Color(150,150,150));
}

void LeftBoard::setBox()
{
    box.left = backGround.getPosition().x;
    box.top = backGround.getPosition().y;
    box.width = 100;
    box.height = 600;
}

void LeftBoard::setSampleTextures()
{
    std::array<std::string,9> arr =
            {
                    "../assets/AND.png",
                    "../assets/OR.png",
                    "../assets/XOR.png",
                    "../assets/NOT.png",
                    "../assets/DFF.png",
                    "../assets/GND.png",
                    "../assets/VDD.png",
                    "../assets/CLOCK.png",
                    "../assets/LEDOFF.png"
            };
    for (int i = 0; i<9; i++)
    {
        if (!this->sampleTextures[i].loadFromFile(arr[i]))
        {
            std::cout << "Failed to load asset: "<< arr[i] << std::endl;
        }
    }
}

void LeftBoard::setSampleSprites()
{
    for (int i=0; i< 9; i++)
    {
        sampleSprites[i].setTexture(sampleTextures[i]);
        sampleSprites[i].setScale(0.5f, 0.5f);
        sampleSprites[i].setPosition(25.f, 25.f + i*60);
    }
}

void LeftBoard::Draw() const
{
    window->draw(backGround);
    for (int i = 0; i < 9; i++)
    {
        window->draw(sampleSprites[i]);
    }
}

bool LeftBoard::contains(sf::Vector2f mp) const
{
    return box.contains(mp);
}


void LeftBoard::handleClick(sf::Vector2f mp) const
{
    std::cout<< "LeftBoard clicked!" << std::endl;
        int index;
        for (int i = 0; i < 9; i++)
        {
            if (buttons[i]->isClicked(mp))
            {
                index = i;
            }
        }


}

