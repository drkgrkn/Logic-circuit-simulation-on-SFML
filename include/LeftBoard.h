//
// Created by peak on 05.05.2022.
//

#ifndef FRONTEND_LEFTBOARD_H
#define FRONTEND_LEFTBOARD_H

#include <SFML/Graphics.hpp>
#include "Button.h"

class LeftBoard
{
public:
    sf::RectangleShape backGround;

    Button buttons[9];

    sf::RenderWindow* window;
    //getter/setter
    explicit LeftBoard(sf::RenderWindow* w);
    void setBackGround();
    void setButtons();
    void Draw() const;
    bool contains(sf::Vector2f mp) const;
    buttonType handleClick(sf::Vector2f mp) const;
};


#endif //FRONTEND_LEFTBOARD_H
