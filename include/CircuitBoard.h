//
// Created by peak on 05.05.2022.
//

#ifndef FRONTEND_CIRCUITBOARD_H
#define FRONTEND_CIRCUITBOARD_H

#include <SFML/Graphics.hpp>
#include "Object.h"

class CircuitBoard
{
    Object* objects;
    sf::RectangleShape backGround;
    sf::RenderWindow* window;
    void setBackGround();
    void setSampleTextures();
    void setSampleSprites();
public:
    explicit CircuitBoard(sf::RenderWindow* w);
    void Draw() const;
    bool contains(sf::Vector2f mp) const;
    void handleClick(sf::Vector2f mp);
};


#endif //FRONTEND_CIRCUITBOARD_H
