//
// Created by peak on 04.05.2022.
//
#pragma once
#ifndef FRONTEND_OBJECT_H
#define FRONTEND_OBJECT_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Object
/*Inheriting from this:
- Wires
- LogicElement:
    -AndGate
    -OrGate
    -XorGate
    -NotGate
    -DFlipFlop
    -Logic0
    -Logic1
    -Clock
    -LED
 */
{
    sf::Rect<float> box;
    Object* next;
    bool locked;

    sf::RenderWindow* window;
    sf::Texture textures[2];

    sf::Sprite sprite;
    bool state;

    bool selected;
    //functions
public:
    //Constructor
    explicit Object(sf::RenderWindow* w );
    //All objects will be drawn
    void Draw() const;
    void setBox();
    void setNext(Object*);
    Object* getNext();
    bool contains(sf::Vector2f mp);
    void handleClick(sf::Vector2f mp);
};


#endif //FRONTEND_OBJECT_H
