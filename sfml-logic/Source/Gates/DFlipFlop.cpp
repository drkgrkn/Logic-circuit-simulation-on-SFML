#include "Gates/DFlipFlop.h"

DFlipFlop::DFlipFlop(sf::RenderWindow* w, LogicElement* ePtr) :
	LogicElement(w, ePtr)
{
	pins = new Pin[4]{ Pin(window, Pin::pinType::INPUT),
						Pin(window, Pin::pinType::INPUT),
						Pin(window, Pin::pinType::OUTPUT),
						Pin(window,Pin::pinType::OUTPUT)
	};
	numPins = 4;
	dataLength = 500;
	dIdx = 0;
	pinsPos = new sf::Vector2f[4]{ sf::Vector2f(-2,7),
								sf::Vector2f(-2,20),
								sf::Vector2f(52,8),
								sf::Vector2f(52,31)
	};
	setSprite();
}

DFlipFlop::~DFlipFlop()
{
	delete[] pins;
}

void DFlipFlop::setSprite()
{
	sprite.setTexture(*(textures->textures[4]));
	sprite.scale(0.6f, 0.6f);

	float x_size = sprite.getTexture()->getSize().x * sprite.getScale().x;
	float y_size = sprite.getTexture()->getSize().y * sprite.getScale().y;

	selectionIndicator.setOutlineColor(sf::Color::Red);
	selectionIndicator.setFillColor((sf::Color(255, 255, 255, 0)));
	selectionIndicator.setOutlineThickness(4);
	selectionIndicator.setSize(sf::Vector2f(x_size, y_size));
}