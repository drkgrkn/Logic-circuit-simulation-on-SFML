//
// Created by peak on 05.05.2022.
//
#pragma once
#ifndef FRONTEND_SIMULATOR_H
#define FRONTEND_SIMULATOR_H

#include <SFML/Graphics.hpp>
#include "Object.h"
#include "LeftBoard.h"
#include "CircuitBoard.h"
#include "TopBoard.h"
#include "Button.h"

class Simulator {
    CircuitBoard* circuitBoard;
    TopBoard* topBoard;
    LeftBoard* leftBoard;
    Object* objPtr;
public:
    sf::RenderWindow* window;
    //FUNCS
    explicit Simulator(sf::RenderWindow* w);
    ~Simulator();
    void close();
    void Draw();
    void handleClick(sf::Vector2f mp);
    void createObject(buttonType b);
};


#endif //FRONTEND_SIMULATOR_H
