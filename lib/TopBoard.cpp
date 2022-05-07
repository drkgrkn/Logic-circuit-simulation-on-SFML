//
// Created by peak on 06.05.2022.
//

#include "../include/TopBoard.h"

TopBoard::TopBoard(sf::RenderWindow* w):
    window(w)
{
    setBackGround();
    setSampleTextures();
    setSampleSprites();
}

void TopBoard::setBackGround()
{
    backGround.setSize(sf::Vector2f(800, 100));
    backGround.setFillColor(sf::Color(150,150,150));
}

void TopBoard::setSampleTextures()
{
    std::array<std::string, 2> arr =
            {
                "../assets/PLAY.png",
                "../assets/STOP.png"
            };
    for (int i = 0; i<2; i++)
    {
        if (!this->buttonTextures[i].loadFromFile(arr[i]))
        {
            std::cout << "Failed to load asset: "<< arr[i] << std::endl;
        }
    }
}

void TopBoard::setSampleSprites()
{
    for (int i=0; i< 2; i++)
    {
        buttonSprites[i].setTexture(buttonTextures[i]);
        buttonSprites[i].setScale(0.5f, 0.5f);
        buttonSprites[i].setPosition(120.f + i*80.f, 20);
    }
}

void TopBoard::Draw()
{
    window->draw(backGround);
    for (int i = 0; i < 2; i++)
    {
        window->draw(buttonSprites[i]);
    }
}

bool TopBoard::contains(sf::Vector2f mp) const
{
    float x_size = backGround.getSize().x;
    float y_size = backGround.getSize().y;
    float x_pos = backGround.getPosition().x;
    float y_pos = backGround.getPosition().y;

    return
            (mp.x <= x_pos + x_size) &&
            (mp.x >= x_pos) &&
            (mp.y <= y_pos + y_size) &&
            (mp.y >= y_pos);
}

void TopBoard::handleClick(sf::Vector2f mp) const
{
    std::cout<< "TopBoard clicked!" << std::endl;
}
