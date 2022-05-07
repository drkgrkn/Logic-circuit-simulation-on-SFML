//
// Created by peak on 04.05.2022.
//

#include "../include/Object.h"

Object::Object(sf::RenderWindow* w)
    : window(w)
{
    next = nullptr;
    locked = false;
    state = false;
    selected = false;
}

void Object::Draw() const
{
    window->draw(sprite);
}

void Object::setBox()
{
    box.left = sprite.getPosition().x;
    box.top = sprite.getPosition().y;
    box.width = sprite.getTexture()->getSize().x * sprite.getScale().x;
    box.height = sprite.getTexture()->getSize().y * sprite.getScale().y;
}

void Object::setNext(Object* objPtr)
{
    next = objPtr;
}

Object* Object::getNext()
{
    return next;
}

bool Object::contains(sf::Vector2f mp) {
    return box.contains(mp);
}

void Object::handleClick(sf::Vector2f mp)
{
    std::cout << "Object clicked!" << std::endl;
}
