#pragma once

#include <Entity.h>
#include <Pin.h>

class LogicElement: public Entity
{
public:
	Pin* pins;
	int numPins;
	int* data;
	int dataLength;
	int dIdx;
	sf::Vector2f* pinsPos;

	//FUNCS
	LogicElement(sf::RenderWindow* w, Entity* ePtr);
	~LogicElement();
	void updateData(Pin::pinState ps);
	virtual void setSprite();
	void draw() override;
	void handleClick(sf::Vector2f mp) override;
};

