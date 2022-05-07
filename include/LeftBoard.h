//
// Created by peak on 05.05.2022.
//

#ifndef FRONTEND_LEFTBOARD_H
#define FRONTEND_LEFTBOARD_H

#include <SFML/Graphics.hpp>

class LeftBoard
{
public:
    sf::Rect<float> box;
    sf::RectangleShape backGround;

    //
    std::array<sf::Texture,9> sampleTextures;
    std::array<sf::Sprite,9> sampleSprites;
    //

    sf::RenderWindow* window;
    //getter/setter
    explicit LeftBoard(sf::RenderWindow* w);
    void setBackGround();
    void setBox();
    void setSampleTextures();
    void setSampleSprites();
    void Draw() const;
    bool contains(sf::Vector2f mp) const;
    void handleClick(sf::Vector2f mp) const;
};


#endif //FRONTEND_LEFTBOARD_H
