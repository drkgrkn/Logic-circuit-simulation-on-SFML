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
        window(w), buttons{AndGate,
                            OrGate,
                            XorGate,
                            NotGate,
                            DFlipFlop,
                            Logic0,
                            Logic1,
                            Clock,
                            LED}
{
    setBackGround();
    setButtons();
}

void LeftBoard::setBackGround()
{
    backGround.setSize(sf::Vector2f(100,600));
    backGround.setFillColor(sf::Color(150,150,150));
}

void LeftBoard::setButtons()
{
    for (int i = 0; i < 9; i++)
    {
        buttons[i].sprite.setPosition(25.f, 25.f + i*60);
    }
}



void LeftBoard::Draw() const
{
    window->draw(backGround);
    for (int i = 0; i < 9; i++)
    {
        buttons[i].draw(window);
    }
}

bool LeftBoard::contains(sf::Vector2f mp) const
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


buttonType LeftBoard::handleClick(sf::Vector2f mp) const
{
    std::cout<< "LeftBoard clicked!" << std::endl;
    buttonType temp = NoButton;
    for (const auto b: buttons)
    {
        if (b.isClicked(mp))
        {
            temp = b.handleClick();
            break;
        }
    }
    return temp;
}

