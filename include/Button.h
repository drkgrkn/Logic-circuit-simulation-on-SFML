//
// Created by peak on 07.05.2022.
//

#ifndef FRONTEND_BUTTON_H
#define FRONTEND_BUTTON_H

#include  <SFML/Graphics.hpp>

class Button {
public:
    sf::Sprite sprite;
    sf::Texture texture;

    bool isClicked(sf::Vector2f mp)
    {
        float x_size = sprite.getTexture()->getSize().x * sprite.getScale().x;
        float y_size = sprite.getTexture()->getSize().y * sprite.getScale().y;
        float x_pos = sprite.getPosition().x;
        float y_pos = sprite.getPosition().y;

        return (
                (mp.x <= x_pos + x_size) &&
                (mp.x >= x_pos) &&
                (mp.y <= y_pos + y_size) &&
                (mp.y >= y_pos)
        );
    }
};


#endif //FRONTEND_BUTTON_H
