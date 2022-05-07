//
// Created by peak on 07.05.2022.
//

#include <iostream>
#include "../include/Button.h"

Button::Button(buttonType b)
{
    type = b;
    switch (type)
    {
        case AndGate:
            if(!texture.loadFromFile("../assets/AND.png"))
            {
                std::cout << "Failed to load asset: AND.png" << std::endl;
            }
            break;
        case OrGate:
            if(!texture.loadFromFile("../assets/OR.png"))
            {
                std::cout << "Failed to load asset: OR.png" << std::endl;
            }
            break;
        case XorGate:
            if(!texture.loadFromFile("../assets/XOR.png"))
            {
                std::cout << "Failed to load asset: XOR.png" << std::endl;
            }
            break;
        case NotGate:
            if(!texture.loadFromFile("../assets/NOT.png"))
            {
                std::cout << "Failed to load asset: NOT.png" << std::endl;
            }
            break;
        case DFlipFlop:
            if(!texture.loadFromFile("../assets/DFF.png"))
            {
                std::cout << "Failed to load asset: DFF.png" << std::endl;
            }
            break;
        case Logic0:
            if(!texture.loadFromFile("../assets/GND.png"))
            {
                std::cout << "Failed to load asset: GND.png" << std::endl;
            }
            break;
        case Logic1:
            if(!texture.loadFromFile("../assets/VDD.png"))
            {
                std::cout << "Failed to load asset: VDD.png" << std::endl;
            }
            break;
        case Clock:
            if(!texture.loadFromFile("../assets/CLOCK.png"))
            {
                std::cout << "Failed to load asset: CLOCK.png" << std::endl;
            }
            break;
        case LED:
            if(!texture.loadFromFile("../assets/LEDOFF.png"))
            {
                std::cout << "Failed to load asset: LEDOFF.png" << std::endl;
            }
            break;
        case Play:
            if(!texture.loadFromFile("../assets/PLAY.png"))
            {
                std::cout << "Failed to load asset: PLAY.png" << std::endl;
            }
            break;
        case Stop:
            if(!texture.loadFromFile("../assets/STOP.png"))
            {
                std::cout << "Failed to load asset: STOP.png" << std::endl;
            }
            break;
    }
    sprite.setTexture(texture);
    sprite.setScale(0.5f, 0.5f);
}

bool Button::isClicked(sf::Vector2f mp) const
{
    float x_size = sprite.getTexture()->getSize().x * sprite.getScale().x;
    float y_size = sprite.getTexture()->getSize().y * sprite.getScale().y;
    float x_pos = sprite.getPosition().x;
    float y_pos = sprite.getPosition().y;

    return (
            (mp.x <= x_pos + x_size) &&
            (mp.x >= x_pos) &&
            (mp.y <= y_pos + y_size) &&
            (mp.y >= y_pos)
    );
}

void Button::draw(sf::RenderWindow* window) const
{
    window->draw(sprite);
}

buttonType Button::handleClick() const
{
    return type;
}