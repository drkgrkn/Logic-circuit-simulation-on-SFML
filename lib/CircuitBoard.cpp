//
// Created by peak on 05.05.2022.
//

#include "../include/CircuitBoard.h"

CircuitBoard::CircuitBoard(sf::RenderWindow* w):
    window(w)
{
    setBackGround();
    setSampleTextures();
    setSampleSprites();
}

void CircuitBoard::setBackGround()
{
    backGround.setSize(sf::Vector2f(800,600));
    backGround.setFillColor(sf::Color(200,200,200));
}

void CircuitBoard::setSampleTextures()
{
    //Loads PLAY AND STOP BUTTON
}

void CircuitBoard::setSampleSprites()
{
    //Loads TEXTURES TO SPRITES
}

void CircuitBoard::Draw() const
{
    window->draw(backGround);
}

bool CircuitBoard::contains(sf::Vector2f mp) const
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

void CircuitBoard::handleClick(sf::Vector2f mp)
{
    std::cout << "CircuitBoard clicked!" << std::endl;
}
