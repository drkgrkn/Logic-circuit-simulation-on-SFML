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
