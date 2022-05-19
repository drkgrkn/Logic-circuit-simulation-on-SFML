#include "Object.h"

Textures* Object::textures;

Object::Object(sf::RenderWindow* w) :
	window(w)
{
}

void Object::draw() const
{
	window->draw(sprite);
}