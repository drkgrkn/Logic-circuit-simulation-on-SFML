#pragma once

#include "Entity.h"
#include "Pin.h"
#include "Wire.h"

class LogicElement: public Entity
{
public:
	sf::RectangleShape selectionIndicator;
	LogicElement* next;
	LogicElement* prev;
	Pin* pins;
	int numPins;
	int* data;
	int dataLength;
	int dIdx;
	sf::Vector2f* pinsPos;

	//FUNCS
	LogicElement(sf::RenderWindow* w, LogicElement* ePtr);
	~LogicElement();
	void updateData(Pin::pinState ps);
	virtual void setSprite();
	void draw() override;
	void handleClick(sf::Vector2f mp) override;
	void embedWire(sf::Vector2f mp, Wire* wPtr);
};

