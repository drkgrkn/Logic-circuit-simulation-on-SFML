#include "CircuitBoard.h"

CircuitBoard::CircuitBoard(sf::RenderWindow* w) :
	Board(w), entities(nullptr)
{
	setBackGround(sf::Vector2f(100, 100),
				sf::Vector2f(1180, 620),
				200);

}

void CircuitBoard::draw() const
{
	window->draw(backGround);
	if (entities != nullptr)
	{
		for (Entity* temp = entities; temp != nullptr;temp = temp->next)
		{
			std::cout << temp << std::endl;
			temp->draw();
		}
	}
}

void CircuitBoard::handleClick(sf::Vector2f mp)
{
	Entity* grabbed = nullptr;

	for (Entity* temp = entities; temp != nullptr; temp = temp->next)
	{
		if (!temp->selected && temp->isInside(mp))
		{
			temp->selected = true;
			grabbed = temp;
		}
	}
	for (Entity* temp = entities; temp != nullptr; temp = temp->next)
	{
		if (temp->selected && temp != grabbed)
		{
			temp->selected = false;
		}
	}

}

void CircuitBoard::addEntity(sf::RenderWindow* w, buttonType b)
{
	Entity* temp = entities;
	if (temp == nullptr)
	{
		entities = new Entity(w, b, nullptr);
	}
	else
	{
		for (; temp != nullptr; temp = temp->next)
		{
			if (temp->next == nullptr)
			{
				temp->next = new Entity(window, b, temp);
				std::cout << "hey " << std::endl;
				break;
			}
		}
	}
}

void CircuitBoard::handleDelete()
{
	for(Entity* temp = entities;temp->next != nullptr; temp = temp->next)
	{
		if (temp->selected)
		{
			if (temp->prev != nullptr)
				temp->prev->next = temp->next;
			if (temp->next != nullptr)
				temp->next->prev = temp->prev;
			delete temp;
		}
	}
}

void CircuitBoard::simulate()
{
	std::cout << "Simulate" << std::endl;
}
