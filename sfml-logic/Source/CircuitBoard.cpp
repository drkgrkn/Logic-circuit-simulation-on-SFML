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
		switch (le->logicType)
		{
		case Object::objectType::AndGate:
		{
			AndGate* g = (AndGate*)le;
			delete g;
			break;
		}
		case Object::objectType::OrGate:
		{
			OrGate* g = (OrGate*)le;
			delete g;
			break;
		}
		case Object::objectType::XorGate:
		{
			XorGate* g = (XorGate*)le;
			delete g;
			break;
		}
		case Object::objectType::NotGate:
		{
			NotGate* g = (NotGate*)le;
			delete g;
			break;
		}
		case Object::objectType::DFlipFlop:
		{
			DFlipFlop* g = (DFlipFlop*)le;
			delete g;
			break;
		}
		case Object::objectType::Logic0:
		{
			Logic0* g = (Logic0*)le;
			delete g;
			break;
		}
		case Object::objectType::Logic1:
		{
			Logic1* g = (Logic1*)le;
			delete g;
			break;
		}
		case Object::objectType::Clock:
		{
			Clock* g = (Clock*)le;
			delete g;
			break;
		}
		case Object::objectType::LED:
		{
			LED* g = (LED*)le;
			delete g;
			break;
		}
		}

	}
}

void CircuitBoard::handleDelete()
{
	Entity* selected = getSelected();
	if (selected->type == Entity::entityType::LOGIC)
		deleteLogic();
	else if (selected->type == Entity::entityType::WIRE)
		deleteWire();
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
	//PRE-SIMULATE
	for (LogicElement* temp = entities; temp != nullptr; temp = temp->next)
	{
		temp->preSimulate();
	}
	//SIMULATE
	for (int i = 0; i < length; i++)
	{
		for (LogicElement* temp = entities; temp != nullptr; temp = temp->next)
		{
			temp->simulate();
		}
	}
	//POST-UPDATE
	for (LogicElement* temp = entities; temp != nullptr; temp = temp->next)
	{
		temp->updateData();
	}
	//ACTUAL SIMULATION ENDS
	//WIRES UPDATE FOR 
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

void CircuitBoard::reset()
{
	for (LogicElement* temp = entities; temp != nullptr; temp = temp->next)
	{
		temp->reset();
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

Pin::pinState* CircuitBoard::plot(sf::Vector2f mp)
{
	Entity* e = getClicked(mp);
	if (e == nullptr)
	{
		return nullptr;
	}
	else if (e->type == Entity::entityType::LOGIC)
	{
		LogicElement* le = (LogicElement*)e;
		return le->data;
	}
	else
	{
		return nullptr;
	}
}

Entity* CircuitBoard::getClicked(sf::Vector2f mp)
{
	/*FOR LOGIC ELEMENTS TO HAVE PRECEDENCE
	INSTEAD OF 1 FOR LOOP ITERATING OVER EVERYTHING
	WE ITERATE OVER ONLY LOGIC ELEMENTS FIRST*/
	Entity* clickedEntity = nullptr;
	for (LogicElement* temp = entities; temp != nullptr; temp = temp->next)
	{
		for (LogicElement* temp = entities; temp != nullptr; temp = temp->next)
		{
			if (temp->isInside(mp))
			{
				clickedEntity = temp;
				goto getClickend;
			}
		}
	}
	for (LogicElement* temp = entities; temp != nullptr; temp = temp->next)
	{
		{
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
							goto getClickend;
						}
					}
				}
			}
		}
	}
	getClickend:
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