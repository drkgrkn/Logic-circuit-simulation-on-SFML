//
// Created by peak on 03.05.2022.
//

#include <SFML/Graphics.hpp>
namespace utils {
    bool isInside(const sf::Vector2i &mp, const sf::Sprite &sprite)
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

    bool isColliding(const sf::Sprite &s1, const sf::Sprite &s2)
    {
        float s1_size_x = s1.getTexture()->getSize().x * s1.getScale().x;
        float s1_size_y = s1.getTexture()->getSize().y * s1.getScale().y;
        float s1_pos_x = s1.getPosition().x;
        float s1_pos_y = s1.getPosition().y;

        float s2_size_x = s2.getTexture()->getSize().x * s2.getScale().x;
        float s2_size_y = s2.getTexture()->getSize().y * s2.getScale().y;
        float s2_pos_x = s2.getPosition().x;
        float s2_pos_y = s2.getPosition().y;

        return (
                s1_pos_x + s1_size_x >= s2_pos_x &&
                s2_pos_x + s2_size_x >= s1_pos_x &&
                s1_pos_y + s1_size_y >= s2_pos_y &&
                s2_pos_y + s2_size_y >= s1_pos_y
        );
    }

    void moveSprite(const sf::Vector2i mp, sf::Sprite &sprite)
    {
        float x = sprite.getTexture()->getSize().x * sprite.getScale().x / 2;
        float y = sprite.getTexture()->getSize().y * sprite.getScale().y / 2;

        // -x/-y to center the sprite
        sprite.setPosition(mp.x - x, mp.y - y);
    }

    std::array<sf::Vertex, 4> CreateWire(sf::Vector2f p1, sf::Vector2f &p2)
    {
        return std::array<sf::Vertex, 4>
                {
                        sf::Vertex(p1),
                        sf::Vertex(sf::Vector2f(p1.x + (p2.x - p1.x) / 2, p1.y)),
                        sf::Vertex(sf::Vector2f(p1.x + (p2.x - p1.x) / 2, p2.y)),
                        sf::Vertex(p2)
                };
    }

    void DrawWires(sf::RenderWindow &window, std::vector<std::array<sf::Vertex, 4>> &wires)
    {
        for (const auto wire: wires)
        {
            for (int i = 0; i < 3; i++)
            {
                sf::Vertex line[] =
                {
                        wire[i],
                        wire[i + 1]
                };
                window.draw(line, 2, sf::Lines);
            }
        }
    }
}