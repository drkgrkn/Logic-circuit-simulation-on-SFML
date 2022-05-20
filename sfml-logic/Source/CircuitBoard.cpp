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
		for (LogicElement* temp = entities; temp != nullptr;temp = temp->next)
		{
			temp->draw();
		}
	}
}

void CircuitBoard::handleClick(sf::Vector2f mp)
{
	Entity* clickedEntity = nullptr;
	Entity* selectedEntity = nullptr;
	for (LogicElement* temp = entities; temp != nullptr; temp = temp->next)
	{
		if (temp->isInside(mp))
		{
			clickedEntity = temp;
		}
		if (temp->selected)
		{
			selectedEntity = temp;
		}
		for (int p = 0; p < temp->numPins; p++)
		{
			for (int w = 0; w < temp->pins[p].numConnections; w++)
			{
				if (temp->pins[p].wires[w]->isInside(mp))
				{
					clickedEntity = temp->pins[p].wires[w];
				}
				if (temp->pins[p].wires[w]->selected)
				{
					selectedEntity = temp->pins[p].wires[w];
				}
			}
		}
	}
	if (clickedEntity == nullptr)
	{
		if (selectedEntity != nullptr)
		{
			selectedEntity->selected = false;
			return;
		}
		else
		{
			return;
		}
	}

	if (clickedEntity != selectedEntity)
	{
		clickedEntity->selected = true;
		if (selectedEntity != nullptr)
			selectedEntity->selected = false;
		return;
	}

	if (clickedEntity == selectedEntity)
	{
		clickedEntity->handleClick(mp);
		return;
	}
}

void CircuitBoard::addLogic(sf::RenderWindow* w, Object::objectType b)
{
	LogicElement* temp = entities;
	if (temp == nullptr)
	{
		entities = chooseLogic(b);
	}
	else
	{
		for (; temp != nullptr; temp = temp->next)
		{
			if (temp->next == nullptr)
			{
				//unselect if selected exists
				for (LogicElement* temp2 = entities; temp2 != nullptr;temp2 = temp2->next)
				{
					if (temp2->selected)
					{
						temp2->selected = false;
					}
				}
				//add new entity which is selected
				temp->next = chooseLogic(b);
				break;
			}
		}
	}
}

void CircuitBoard::deleteLogic()
{
	LogicElement* e = nullptr;
	for (LogicElement* temp = entities; temp != nullptr; temp = temp->next)
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
	deleteLogic();
}

void CircuitBoard::handleRelease(sf::Vector2f mp)
{
	/*if entity is dropped outside
	  destroy that entity*/
	//GRABBED ENTITY
	Entity* ge = nullptr;
	for (LogicElement* temp = entities; temp != nullptr; temp = temp->next)
	{
		if (temp->grabbed)
		{
			ge = temp;
		}
		for (int p = 0; p < temp->numPins; p++)
		{
			for (int w = 0; w < temp->pins[p].numConnections; w++)
			{
				if (temp->pins[p].wires[w]->grabbed)
				{
					ge = temp->pins[p].wires[w];
				}
			}
		}
	}

	if (ge == nullptr)
	{
		return;
	}
	else if (ge->type == Entity::entityType::LOGIC)
	{
		LogicElement* e = (LogicElement*)ge;
		if (!isInside(mp))
		{
			deleteLogic();
			return;
		}
		for (LogicElement* temp = entities; temp != nullptr; temp = temp->next)
		{
			if (temp == e)
			{
				continue;
			}
			else if (temp->isColliding(e))
			{
				deleteLogic();
				e = nullptr;
				return;
			}
		}
		if (e != nullptr)
		{
			e->grabbed = false;
		}
	}
	else if (ge->type == Entity::entityType::WIRE)
	{
		Wire* w = (Wire*)ge;
		for (LogicElement* temp = entities; temp != nullptr; temp = temp->next)
		{
			for (int p = 0; p < temp->numPins; p++)
			{
				if (temp->pins[p].isInside(mp))
				{
					w->embedToPin(mp, &temp->pins[p]);
					return;
				}
			}
		}
		deleteWire();
	}
}

void CircuitBoard::simulate()
{
	std::cout << "Simulate" << std::endl;
}

LogicElement* CircuitBoard::chooseLogic(Object::objectType obj)
{
	LogicElement* lastPtr = entities;
	for (LogicElement* temp = entities; temp != nullptr; temp = temp->next)
	{
		lastPtr = temp;
	}

	switch (obj)
	{
	case Object::objectType::AndGate:
		return new AndGate(window, lastPtr);
	}
}

void CircuitBoard::deleteWire()
{
	Wire* wire = nullptr;
	for (LogicElement* temp = entities; temp != nullptr; temp = temp->next)
	{
		for (int p = 0; p < temp->numPins; p++)
		{
			for (int w = 0; p < temp->pins[p].numConnections; w++)
			{
				if (temp->pins[p].wires[w]->grabbed)
				{
					wire = temp->pins[p].wires[w];
				}
			}
		}
	}

	delete wire;
}