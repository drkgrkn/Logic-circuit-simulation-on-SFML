//
// Created by peak on 06.05.2022.
//

#ifndef FRONTEND_TOPBOARD_H
#define FRONTEND_TOPBOARD_H

#include <SFML/Graphics.hpp>
#include <iostream>

class TopBoard {
    sf::RectangleShape backGround;
    std::array<sf::Texture, 2> buttonTextures;
    std::array<sf::Sprite, 2> buttonSprites;
    sf::RenderWindow* window;
    void setBackGround();
    void setSampleTextures();
    void setSampleSprites();
public:
    explicit TopBoard(sf::RenderWindow* w);
    void Draw();
    bool contains(sf::Vector2f mp) const;
    void handleClick(sf::Vector2f mp) const;
};


#endif //FRONTEND_TOPBOARD_H
