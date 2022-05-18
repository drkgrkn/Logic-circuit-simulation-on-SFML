#include "Button.h"

Button::Button(sf::RenderWindow* w, buttonType bt):
	Object(w), type(bt)
{
    //ELLERINDEN OPER MERT
    switch (type)
    {
    case buttonType::AndGate:
        sprite.setTexture(textures.textures[0]);
        break;
    case buttonType::OrGate:
        sprite.setTexture(textures.textures[1]);
        break;
    case buttonType::XorGate:
        sprite.setTexture(textures.textures[2]);
        break;
    case buttonType::NotGate:
        sprite.setTexture(textures.textures[3]);
        break;
    case buttonType::DFlipFlop:
        sprite.setTexture(textures.textures[4]);
        break;
    case buttonType::Logic0:
        sprite.setTexture(textures.textures[5]);
        break;
    case buttonType::Logic1:
        sprite.setTexture(textures.textures[6]);
        break;
    case buttonType::Clock:
        sprite.setTexture(textures.textures[7]);
        break;
    case buttonType::LED:
        sprite.setTexture(textures.textures[8]);
        break;
    case buttonType::Play:
        sprite.setTexture(textures.textures[9]);
        break;
    case buttonType::Stop:
        sprite.setTexture(textures.textures[10]);
        break;
    }
    sprite.setScale(0.6f, 0.6f);
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