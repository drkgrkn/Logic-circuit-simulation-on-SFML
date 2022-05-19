#include "Entity.h"

Entity::Entity(sf::RenderWindow* w, Object::objectType b, Entity* ePtr) :
    Object(w), prev(ePtr),
    next(nullptr), selected(true), grabbed(true)
{
    switch (b)
    {
    case Object::objectType::AndGate:
        sprite.setTexture(*(textures->textures[0]));
        break;
    case Object::objectType::OrGate:
        sprite.setTexture(*(textures->textures[1]));
        break;
    case Object::objectType::XorGate:
        sprite.setTexture(*(textures->textures[2]));
        break;
    case Object::objectType::NotGate:
        sprite.setTexture(*(textures->textures[3]));
        break;
    case Object::objectType::DFlipFlop:
        sprite.setTexture(*(textures->textures[4]));
        break;
    case Object::objectType::Logic0:
        sprite.setTexture(*(textures->textures[5]));
        break;
    case Object::objectType::Logic1:
        sprite.setTexture(*(textures->textures[6]));
        break;
    case Object::objectType::Clock:
        sprite.setTexture(*(textures->textures[7]));
        break;
    case Object::objectType::LED:
        sprite.setTexture(*(textures->textures[8]));
        break;
    case Object::objectType::Play:
        sprite.setTexture(*(textures->textures[10]));
        break;
    case Object::objectType::Stop:
        sprite.setTexture(*(textures->textures[11]));
        break;
    }
    sprite.scale(0.6f, 0.6f);

    float x_size = sprite.getTexture()->getSize().x * sprite.getScale().x;
    float y_size = sprite.getTexture()->getSize().y * sprite.getScale().y;

    selectionIndicator.setOutlineColor(sf::Color::Red);
    selectionIndicator.setFillColor((sf::Color(255, 255, 255, 0)));
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
        sprite.setColor(sf::Color(255, 255, 255, 128));
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
    sprite.setColor(sf::Color(255, 255, 255, 255));
}