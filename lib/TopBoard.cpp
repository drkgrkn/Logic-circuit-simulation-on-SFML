//
// Created by peak on 06.05.2022.
//

#include "../include/TopBoard.h"

TopBoard::TopBoard(sf::RenderWindow* w):
    window(w), buttons{Play,
                        Stop}
{
    setBackGround();
    setButtons();
}

void TopBoard::setBackGround()
{
    backGround.setSize(sf::Vector2f(800, 100));
    backGround.setFillColor(sf::Color(150,150,150));
}

void TopBoard::setButtons()
{
    for (int i = 0; i < 2; i++)
    {
        buttons[i].sprite.setPosition(120.f + 80.f*i , 20);
    }
}

void TopBoard::Draw()
{
    window->draw(backGround);
    for (int i = 0; i < 2; i++)
    {
        buttons[i].draw(window);
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

buttonType TopBoard::handleClick(sf::Vector2f mp) const
{
    std::cout<< "TopBoard clicked!" << std::endl;
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
