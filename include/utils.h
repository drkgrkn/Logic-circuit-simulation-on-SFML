//
// Created by peak on 03.05.2022.
//

#include <SFML/Graphics.hpp>

#ifndef FRONTEND_UTILS_H
#define FRONTEND_UTILS_H
namespace utils {
//Checks whether the given vector coordinates lie inside
//the given sprite, returns true if inside
    bool isInside(const sf::Vector2i &mp, const sf::Sprite &sprite);

//checks whether the given two sprites are on top of each other
//returns true if colliding
    bool isColliding(const sf::Sprite &s1, const sf::Sprite &s2);

//Moves the top left corner of the given sprite to the given
//vector coordinates
    void moveSprite(const sf::Vector2i mp, sf::Sprite &sprite);

//changes the second vertex so either it matches to
//first one vertically or horizontally
//whichever is greater
    std::array<sf::Vertex, 4> CreateWire(sf::Vector2f p1, sf::Vector2f &p2);

//to create S shaped wires, to be visited later
    void DrawWires(sf::RenderWindow &window, std::vector<std::array<sf::Vertex, 4>> &wires);
}
#endif //FRONTEND_UTILS_H

