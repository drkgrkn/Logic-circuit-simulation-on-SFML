#include "Wire.h"

Wire::Wire(sf::RenderWindow* w, Pin* p) :
	Entity(w)
{
	std::cout << w << std::endl;
	type = Entity::entityType::WIRE;
    pins[0] = p;
	pins[1] = nullptr;
	vertices[0].x = pins[0]->shape.getPosition().x + 3;
	vertices[0].y = pins[0]->shape.getPosition().y + 3;
}

Wire::~Wire()
{
	if (pins[0] != nullptr)
	{
		pins[0]->unembedWire(this);
	}
	if (pins[1] != nullptr)
	{
		pins[1]->unembedWire(this);
	}
}

void Wire::draw()
{
	if (grabbed)
	{
		vertices[3] = sf::Vector2f(sf::Mouse::getPosition(*window));
		float x = (vertices[0].x + vertices[3].x) / 2;
		
		setBody();
	}
	if (selected)
	{
		for (int i = 0; i < 5; i++)
		{

		}
	}


	for (int i = 0; i < 5; i++)
	{
		window->draw(body[i]);
		body[i].setFillColor(sf::Color::Black);
	}
}




void Wire::setBody()			// wire seperated into 5 body parts
{
	
	float x = (vertices[0].x + vertices[3].x) / 2;
	vertices[1] = sf::Vector2f(x, vertices[0].y);
	vertices[2] = sf::Vector2f(x, vertices[3].y);

	body[0].setPosition(vertices[0]);
	body[0].setSize(sf::Vector2f(vertices[1].x - vertices[0].x, 4));		// first horizontal line
	body[0].setFillColor(sf::Color::Black);

	body[1].setPosition(vertices[1]);
	body[1].setSize(sf::Vector2f(4, 4));									// first elbow
	body[1].setFillColor(sf::Color::Black);

	body[2].setPosition(vertices[1]);
	body[2].setSize(sf::Vector2f(4, vertices[2].y - vertices[1].y));		// vertical line
	body[2].setFillColor(sf::Color::Black);

	body[3].setPosition(vertices[2]);
	body[3].setSize(sf::Vector2f(4, 4));									// second elbow
	body[3].setFillColor(sf::Color::Black);

	body[4].setPosition(vertices[2]);
	body[4].setSize(sf::Vector2f(vertices[3].x - vertices[2].x, 4));		// second horizontal line
	body[4].setFillColor(sf::Color::Black);
}

void Wire::moveTip(Pin* p, sf::Vector2f v)
{
	if (p == pins[0])
	{
		vertices[0] = v;
	}
	else if (p == pins[1])
	{
		vertices[3] = v;
	}
	
	setBody();
}

bool Wire::isInside(sf::Vector2f mp)
{
	bool flag;

	for (int i = 0; i < 5; i++) {


		float x_size = body[i].getSize().x;
		float y_size = body[i].getSize().y;
		float x_pos = body[i].getPosition().x;
		float y_pos = body[i].getPosition().y;

	 flag = (mp.x <= x_pos + x_size) &&
			(mp.x >= x_pos) &&
			(mp.y <= y_pos + y_size) &&
			(mp.y >= y_pos);
	 
	 if (flag) {

		 return flag;
	 }
	 }
	return flag;
}

void Wire::embed(Pin* p)
{
	if (p->type == pins[0]->type || p->numConnections == p->MAX_CONNECTIONS)
	{
		delete this;
		return;
	}
	selected = false;
	grabbed = false;
	pins[1] = p;
	pins[0]->connect(this, pins[1]);
	pins[1]->embedWire(this, pins[0]);
}

void Wire::simulate()
{
	for (int i = 0; i < 2; i++)
	{
		if (pins[i]->type == Pin::pinType::OUTPUT)
		{
			if (pins[i]->state == Pin::pinState::HIGH)
			{
				for (int j = 0; j < 5; j++)
				{
					body[j].setFillColor(sf::Color::Red);
				}
			}
			else if (pins[i]->state == Pin::pinState::LOW)
			{
				for (int j = 0; j < 5; j++)
				{
					body[j].setFillColor(sf::Color::Black);
				}
			}
		}
	}
}
