#include "Object.h"

Object::Object(sf::RenderWindow* w) :
	window(w)
{

}

void Object::draw() const
{
	window->draw(sprite);
}