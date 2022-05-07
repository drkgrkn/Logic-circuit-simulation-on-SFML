//
// Created by peak on 07.05.2022.
//
#pragma once
#ifndef FRONTEND_BUTTON_H
#define FRONTEND_BUTTON_H

#include  <SFML/Graphics.hpp>
enum buttonType
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

class Button {
public:
    sf::Sprite sprite;
    sf::Texture texture;
    buttonType type;

    Button(buttonType b);
    bool isClicked(sf::Vector2f mp) const;
    void draw(sf::RenderWindow* window) const;
    buttonType handleClick() const;
};


#endif //FRONTEND_BUTTON_H
