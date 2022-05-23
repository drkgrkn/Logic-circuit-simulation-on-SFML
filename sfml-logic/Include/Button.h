#pragma once

#include <SFML/Graphics.hpp>
#include "Object.h"

class Button: public Object
{
public:
    Object::objectType type;

    /*
    Constructor receives *window as every other class
    also buttonType which decides what the object will
    look like, and what they will return when clicked*/
    Button(sf::RenderWindow* w, Object::objectType bt);
    //Generic is clicked method to check if mouse
    //is inside given button
    bool isClicked(sf::Vector2f mp) const;
    //what to do if button is clicked
    Object::objectType handleClick() const;
};

