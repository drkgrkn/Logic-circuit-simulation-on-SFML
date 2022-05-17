#include "Button.h"

Button::Button(sf::RenderWindow* w, buttonType bt):
	Object(w), type(bt)
{
    switch (type)
    {
    case buttonType::AndGate:
        if (!textures[0].loadFromFile("assets/AND.png"))
        {
            std::cout << "Failed to load asset: AND.png" << std::endl;
        }
        break;
    case buttonType::OrGate:
        if (!textures[0].loadFromFile("assets/OR.png"))
        {
            std::cout << "Failed to load asset: OR.png" << std::endl;
        }
        break;
    case buttonType::XorGate:
        if (!textures[0].loadFromFile("assets/XOR.png"))
        {
            std::cout << "Failed to load asset: XOR.png" << std::endl;
        }
        break;
    case buttonType::NotGate:
        if (!textures[0].loadFromFile("assets/NOT.png"))
        {
            std::cout << "Failed to load asset: NOT.png" << std::endl;
        }
        break;
    case buttonType::DFlipFlop:
        if (!textures[0].loadFromFile("assets/DFF.png"))
        {
            std::cout << "Failed to load asset: DFF.png" << std::endl;
        }
        break;
    case buttonType::Logic0:
        if (!textures[0].loadFromFile("assets/GND.png"))
        {
            std::cout << "Failed to load asset: GND.png" << std::endl;
        }
        break;
    case buttonType::Logic1:
        if (!textures[0].loadFromFile("assets/VDD.png"))
        {
            std::cout << "Failed to load asset: VDD.png" << std::endl;
        }
        break;
    case buttonType::Clock:
        if (!textures[0].loadFromFile("assets/CLOCK.png"))
        {
            std::cout << "Failed to load asset: CLOCK.png" << std::endl;
        }
        break;
    case buttonType::LED:
        if (!textures[0].loadFromFile("assets/LEDOFF.png"))
        {
            std::cout << "Failed to load asset: LEDOFF.png" << std::endl;
        }
        break;
    case buttonType::Play:
        if (!textures[0].loadFromFile("assets/PLAY.png"))
        {
            std::cout << "Failed to load asset: PLAY.png" << std::endl;
        }
        break;
    case buttonType::Stop:
        if (!textures[0].loadFromFile("assets/STOP.png"))
        {
            std::cout << "Failed to load asset: STOP.png" << std::endl;
        }
        break;
    }
    sprite.setTexture(textures[0]);
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

buttonType Button::handleClick() const
{
	return type;
}

void buttonfuncs::print(buttonType b)
{
    std::cout << static_cast<std::underlying_type<buttonType>::type>(b) << std::endl;
}