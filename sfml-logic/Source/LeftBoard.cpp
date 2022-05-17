#include <iostream>
#include "LeftBoard.h"

LeftBoard::LeftBoard(sf::RenderWindow* w) :
    Board(w), buttons{ {w, buttonType::AndGate},
                    {w, buttonType::OrGate},
                    {w, buttonType::XorGate},
                    {w, buttonType::NotGate},
                    {w, buttonType::DFlipFlop},
                    {w, buttonType::Logic0},
                    {w, buttonType::Logic1},
                    {w, buttonType::Clock},
                    {w, buttonType::LED}}
{
	setBackGround(sf::Vector2f(0, 0),
		sf::Vector2f(100, 720),
		150);
    for (int i = 0; i < 9; i++)
    {
        buttons[i].sprite.setPosition(25.f, 25.f + i * 60);
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

buttonType LeftBoard::handleClick(sf::Vector2f mp) const
{
    buttonType temp = buttonType::NoButton;
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