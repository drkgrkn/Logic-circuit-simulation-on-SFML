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
	Entity* clickedEntity = getClicked(mp);
	Entity* selectedEntity = getSelected();

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
		Entity* selected = getSelected();
		if (selected != nullptr)
			selected->selected = false;
		LogicElement* last = getLast();
		last->next = chooseLogic(b);
	}
}

void CircuitBoard::deleteLogic()
{
	Entity* e = getSelected();
	if (e == nullptr)
	{
		return;
	}
	else if (e->type == Entity::entityType::WIRE)
	{
		return;
	}
	else
	{
		LogicElement* le = (LogicElement*)e;
		bool isLast = false;
		bool isFirst = false;
		if (le->prev == nullptr)
		{
			isFirst = true;
		}
		if (le->next == nullptr)
		{
			isLast = true;
		}

		if (!isLast)
		{
			le->next->prev = le->prev;
		}
		if (!isFirst)
		{
			le->prev->next = le->next;
		}
		else
		{
			entities = le->next;
		}
		delete le;

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
	Entity* ge = getGrabbed();

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
					w->embed( &temp->pins[p]);
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

	int length = 0;
	for (LogicElement* temp = entities; temp != nullptr; temp = temp->next)
	{
		length++;
	}
	for (int i = 0; i < length; i++)
	{
		for (LogicElement* temp = entities; temp != nullptr; temp = temp->next)
		{
			temp->simulate();
		}
	}
	//ACTUAL SIMULATION ENDS
	for (LogicElement* temp = entities; temp != nullptr; temp = temp->next)
	{
		for (int p = 0; p < temp->numPins; p++)
		{
			for (int w = 0; w < temp->pins[p].numConnections; w++)
			{
				temp->pins[p].wires[w]->simulate();
			}
		}
	}

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

	case Object::objectType::OrGate:
		return new OrGate(window, lastPtr);

	case Object::objectType::XorGate:
		return new XorGate(window, lastPtr);

	case Object::objectType::NotGate:
		return new NotGate(window, lastPtr);

	case Object::objectType::DFlipFlop:
		return new DFlipFlop(window, lastPtr);

	case Object::objectType::Logic0:
		return new Logic0(window, lastPtr);

	case Object::objectType::Logic1:
		return new Logic1(window, lastPtr);

	case Object::objectType::Clock:
		return new Clock(window, lastPtr);

	case Object::objectType::LED:
		return new LED(window, lastPtr);
	}
}

void CircuitBoard::deleteWire()
{
	Entity* e = getSelected();

	if (e->type == Entity::entityType::WIRE)
	{
		Wire* w = (Wire*)e;
		delete w;
	}
}

Entity* CircuitBoard::getClicked(sf::Vector2f mp)
{
	Entity* clickedEntity = nullptr;
	for (LogicElement* temp = entities; temp != nullptr; temp = temp->next)
	{
		for (LogicElement* temp = entities; temp != nullptr; temp = temp->next)
		{
			if (temp->isInside(mp))
			{
				clickedEntity = temp;
			}
			for (int p = 0; p < temp->numPins; p++)
			{
				for (int w = 0; w < temp->pins[p].MAX_CONNECTIONS; w++)
				{
					if (temp->pins[p].wires[w] != nullptr)
					{
						if (temp->pins[p].wires[w]->isInside(mp))
						{
							std::cout << "wire clicked";
							clickedEntity = temp->pins[p].wires[w];
						}
					}
				}
			}
		}
	}
	return clickedEntity;
}

Entity* CircuitBoard::getSelected()
{
	Entity* selectedEntity = nullptr;
	for (LogicElement* temp = entities; temp != nullptr; temp = temp->next)
	{
		for (LogicElement* temp = entities; temp != nullptr; temp = temp->next)
		{
			if (temp->selected)
			{
				selectedEntity = temp;
			}
			for (int p = 0; p < temp->numPins; p++)
			{
				for (int w = 0; w < temp->pins[p].MAX_CONNECTIONS; w++)
				{
					if (temp->pins[p].wires[w] != nullptr)
					{
						if (temp->pins[p].wires[w]->selected)
						{
							selectedEntity = temp->pins[p].wires[w];
						}
					}
				}
			}
		}
	}
	return selectedEntity;
}

Entity* CircuitBoard::getGrabbed()
{
	Entity* grabbedEntity = nullptr;
	for (LogicElement* temp = entities; temp != nullptr; temp = temp->next)
	{
		for (LogicElement* temp = entities; temp != nullptr; temp = temp->next)
		{
			if (temp->grabbed)
			{
				grabbedEntity = temp;
			}
			for (int p = 0; p < temp->numPins; p++)
			{
				for (int w = 0; w < temp->pins[p].numConnections; w++)
				{
					if (temp->pins[p].wires[w]->grabbed)
					{
						grabbedEntity = temp->pins[p].wires[w];
					}
				}
			}
		}
	}
	return grabbedEntity;
}

LogicElement* CircuitBoard::getLast()
{
	for (LogicElement* temp = entities; temp != nullptr; temp = temp->next)
	{
		if (temp->next == nullptr)
		{
			return temp;
		}
	}
}