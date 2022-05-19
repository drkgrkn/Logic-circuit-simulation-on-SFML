#include <iostream>
#include "LeftBoard.h"

LeftBoard::LeftBoard(sf::RenderWindow* w) :
    Board(w), buttons{ {w, Object::objectType::AndGate},
                    {w, Object::objectType::OrGate},
                    {w, Object::objectType::XorGate},
                    {w, Object::objectType::NotGate},
                    {w, Object::objectType::DFlipFlop},
                    {w, Object::objectType::Logic0},
                    {w, Object::objectType::Logic1},
                    {w, Object::objectType::Clock},
                    {w, Object::objectType::LED}}
{
	setBackGround(sf::Vector2f(0, 0),
		sf::Vector2f(100, 720),
		sf::Color(155, 155, 155));
    for (int i = 0; i < 9; i++)
    {
        float x = buttons[i].sprite.getTexture()->getSize().x / 4;      // align sprites located on the leftboard
        float y = buttons[i].sprite.getTexture()->getSize().y / 4;      // according to their sizes
        buttons[i].sprite.setPosition(45.f - x, 125.f + i * 60 - y);
    }
}

void LeftBoard::draw() const
{
    window->draw(backGround);
    for (const auto b : buttons)
    {
        b.draw();
    }
}

Object::objectType LeftBoard::handleClick(sf::Vector2f mp) const
{
    Object::objectType temp = Object::objectType::NoButton;
    for (const auto b : buttons)
    {
        if (b.isClicked(mp))
        {
            temp = b.handleClick();
            break;
        }
    }
    return temp;
}