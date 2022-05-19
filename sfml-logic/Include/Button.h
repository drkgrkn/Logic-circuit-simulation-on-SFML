#pragma once

#include <SFML/Graphics.hpp>
#include "Object.h"

class Button: public Object
{
public:
    Object::objectType type;

    //methods
    Button(sf::RenderWindow* w, Object::objectType bt);
    bool isClicked(sf::Vector2f mp) const;
    Object::objectType handleClick() const;
};

