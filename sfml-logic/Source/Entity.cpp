#include "Entity.h"

Entity::Entity(sf::RenderWindow* w, buttonType b, Entity* ePtr) :
    Object(w), prev(ePtr),
    next(nullptr), selected(false),
    state(false), grabbed(true)
{
    switch (b)
    {
    case buttonType::AndGate:
        if (!textures[0].loadFromFile("assets/AND.png"))
        {
            std::cout << "Failed to load asset: AND.png" << std::endl;
        }
        break;
    case buttonType::OrGate:
        if (!textures[0].loadFromFile("assets/OR.png"))
        {
            std::cout << "Failed to load asset: OR.png" << std::endl;
        }
        break;
    case buttonType::XorGate:
        if (!textures[0].loadFromFile("assets/XOR.png"))
        {
            std::cout << "Failed to load asset: XOR.png" << std::endl;
        }
        break;
    case buttonType::NotGate:
        if (!textures[0].loadFromFile("assets/NOT.png"))
        {
            std::cout << "Failed to load asset: NOT.png" << std::endl;
        }
        break;
    case buttonType::DFlipFlop:
        if (!textures[0].loadFromFile("assets/DFF.png"))
        {
            std::cout << "Failed to load asset: DFF.png" << std::endl;
        }
        break;
    case buttonType::Logic0:
        if (!textures[0].loadFromFile("assets/GND.png"))
        {
            std::cout << "Failed to load asset: GND.png" << std::endl;
        }
        break;
    case buttonType::Logic1:
        if (!textures[0].loadFromFile("assets/VDD.png"))
        {
            std::cout << "Failed to load asset: VDD.png" << std::endl;
        }
        break;
    case buttonType::Clock:
        if (!textures[0].loadFromFile("assets/CLOCK.png"))
        {
            std::cout << "Failed to load asset: CLOCK.png" << std::endl;
        }
        break;
    case buttonType::LED:
        if (!textures[0].loadFromFile("assets/LEDOFF.png"))
        {
            std::cout << "Failed to load asset: LEDOFF.png" << std::endl;
        }
        if (!textures[1].loadFromFile("assets/LEDON.png"))
        {
            std::cout << "Failed to load asset: LEDON.png" << std::endl;
        }
        break;
    }
    sprite.setTexture(textures[0]);
    sprite.setScale(0.5f, 0.5f);

    float x_size = sprite.getTexture()->getSize().x * sprite.getScale().x;
    float y_size = sprite.getTexture()->getSize().y * sprite.getScale().y;

    selectionIndicator.setOutlineColor(sf::Color::Red);
    selectionIndicator.setOutlineThickness(4);
    selectionIndicator.setSize(sf::Vector2f(x_size, y_size));
}

bool Entity::isInside(sf::Vector2f mp)
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

void Entity::draw()
{
    if (grabbed)
    {
        sf::Vector2f mp = sf::Vector2f(sf::Mouse::getPosition(*window));
        float x = sprite.getTexture()->getSize().x /4;
        float y = sprite.getTexture()->getSize().y /4;
        sprite.setPosition(sf::Vector2f(mp.x - x, mp.y - y));
    }
    if (selected)
    {
        selectionIndicator.setPosition(sprite.getPosition());
        window->draw(selectionIndicator);
    }
    window->draw(sprite);
}