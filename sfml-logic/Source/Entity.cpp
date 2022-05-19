#include "Entity.h"

Entity::Entity(sf::RenderWindow* w, Entity* ePtr) :
    Object(w), prev(ePtr),
    next(nullptr), selected(true), grabbed(true)
{
    
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
    
}

void Entity::handleClick(sf::Vector2f mp)
{
    std::cout << "Empty Entity Clicked" << std::endl;
}