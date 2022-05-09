#pragma once

#include <SFML/Graphics.hpp>
#include "Object.h"

enum class buttonType
{
    NoButton,
    AndGate,
    OrGate,
    XorGate,
    NotGate,
    DFlipFlop,
    Logic0,
    Logic1,
    Clock,
    LED,
    Play,
    Stop
};

namespace buttonfuncs {
    void print(buttonType b);
}

class Button: public Object
{
public:
    buttonType type;

    //methods
    Button(sf::RenderWindow* w, buttonType bt);
    bool isClicked(sf::Vector2f mp) const;
    buttonType handleClick() const;
};

