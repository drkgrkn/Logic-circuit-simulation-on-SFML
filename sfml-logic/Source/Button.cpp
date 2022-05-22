#include "Button.h"

Button::Button(sf::RenderWindow* w, Object::objectType bt):
	Object(w), type(bt)
{
    switch (type)
    {
    case Object::objectType::AndGate:
        sprite.setTexture(*(textures->textures[0]));
        break;
    case Object::objectType::OrGate:
        sprite.setTexture(*(textures->textures[1]));
        break;
    case Object::objectType::XorGate:
        sprite.setTexture(*(textures->textures[2]));
        break;
    case Object::objectType::NotGate:
        sprite.setTexture(*(textures->textures[3]));
        break;
    case Object::objectType::DFlipFlop:
        sprite.setTexture(*(textures->textures[4]));
        break;
    case Object::objectType::Logic0:
        sprite.setTexture(*(textures->textures[5]));
        break;
    case Object::objectType::Logic1:
        sprite.setTexture(*(textures->textures[6]));
        break;
    case Object::objectType::Clock:
        sprite.setTexture(*(textures->textures[7]));
        break;
    case Object::objectType::LED:
        sprite.setTexture(*(textures->textures[8]));
        break;
    case Object::objectType::Trash:
        sprite.setTexture(*(textures->textures[10]));
        break;
    case Object::objectType::Play:
        sprite.setTexture(*(textures->textures[11]));
        break;
    case Object::objectType::Stop:
        sprite.setTexture(*(textures->textures[12]));
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

Object::objectType Button::handleClick() const
{
	return type;
}
