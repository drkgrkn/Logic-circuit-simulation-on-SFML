#include "CircuitBoard.h"

CircuitBoard::CircuitBoard(sf::RenderWindow* w) :
	Board(w), entities(nullptr)
{
	setBackGround(sf::Vector2f(100, 100),
		sf::Vector2f(1180, 620),
		sf::Color(255, 255, 235));

}

void CircuitBoard::draw() const
{
	window->draw(backGround);
	if (entities != nullptr)
	{
		for (Entity* temp = entities; temp != nullptr;temp = temp->next)
		{
			temp->draw();
		}
	}
}

void CircuitBoard::handleClick(sf::Vector2f mp)
{
	Entity* selected = nullptr;
	Entity* clicked = nullptr;
	for (Entity* temp = entities; temp != nullptr;temp = temp->next)
	{
		if (temp->selected)
		{
			selected = temp;
		}
		if (temp->isInside(mp))
		{
			clicked = temp;
		}
	}
	/*with both selected and clicked
	there are 4 situations
							clicked == nullptr | clicked != nullptr
	selected == nullptr				1					2
	selected != nullptr				3					4			*/

	/*situation 1 & 3:
		nothing is clicked thus everything should be unselected*/
	if (!clicked)
	{
		if (selected)
		{
			selected->selected = false;
			return;
		}
	}
	/*situation 2:
	something is clicked but nothing is selected
	-> something becomes selected*/
	else if (clicked && !selected)
	{
		clicked->selected = true;
	}
	/*situation 4:
	something is clicked and something is selected:
	possibility 1:
		-> they are same, it becomes grabbed
	possibility 2:
		-> they are different, selected becomes unselected, clicked becomes selected*/
	else
	{
		if (clicked == selected)
		{
			clicked->grabbed = true;
		}
		else
		{
			selected->selected = false;
			clicked->selected = true;
		}
	}
}

void CircuitBoard::addEntity(sf::RenderWindow* w, Object::objectType b)
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
				//unselect if selected exists
				for (Entity* temp2 = entities; temp2 != nullptr;temp2 = temp2->next)
				{
					if (temp2->selected)
					{
						temp2->selected = false;
					}
				}
				//add new entity which is selected
				temp->next = new Entity(window, b, temp);
				break;
			}
		}
	}
}

void CircuitBoard::deleteEntity()
{
	Entity* e = nullptr;
	for (Entity* temp = entities; temp != nullptr; temp = temp->next)
	{
		if (temp->selected)
		{
			e = temp;
		}
	}
	if (e == nullptr)
	{
		return;
	}
	else
	{
		bool isLast = false;
		bool isFirst = false;
		if (e->prev == nullptr)
		{
			isFirst = true;
		}
		if (e->next == nullptr)
		{
			isLast = true;
		}

		if (!isLast)
		{
			e->next->prev = e->prev;
		}
		if (!isFirst)
		{
			e->prev->next = e->next;
		}
		else
		{
			entities = e->next;
		}
		delete e;
	}
}

void CircuitBoard::handleDelete()
{
	deleteEntity();
}

void CircuitBoard::handleRelease(sf::Vector2f mp)
{
	/*if entity is dropped outside
	  destroy that entity*/
	  /*if entity is dropped outside
		destroy that entity*/
	bool flag = false;
	for (Entity* temp = entities; temp != nullptr; temp = temp->next)
	{
		if (temp->grabbed)
		{
			flag = true;
		}
	}
	if (!isInside(mp) && flag)
	{
		deleteEntity();
	}
	/* else ungrab the entity*/
	else
	{
		for (Entity* temp = entities; temp != nullptr; temp = temp->next)
		{
			if (temp->grabbed)
			{
				temp->grabbed = false;
				//temp->selected = false;
			}
		}
	}
}

void CircuitBoard::simulate()
{
	std::cout << "Simulate" << std::endl;
}
