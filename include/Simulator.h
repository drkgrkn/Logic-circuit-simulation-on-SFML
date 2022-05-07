//
// Created by peak on 05.05.2022.
//

#ifndef FRONTEND_SIMULATOR_H
#define FRONTEND_SIMULATOR_H

#include <SFML/Graphics.hpp>
#include "Object.h"
#include "LeftBoard.h"
#include "CircuitBoard.h"
#include "TopBoard.h"

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
};


#endif //FRONTEND_SIMULATOR_H
