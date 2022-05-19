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
	//Checking if a wire is selected
	Wire* grabbed_wire = nullptr;
	for (LogicElement* temp = entities; temp!= nullptr; temp = temp->next)
	{
		for (int i = 0; i < temp->numPins; i++)
		{
			for (int j = 0; j < temp->pins[i].numConnections; j++)
			{														//ADDRESS OF SELECTED WIRE
				std::cout << temp->pins[i].wires[j] << std::endl;
				grabbed_wire = (temp->pins[i].wires[j]->grabbed) ? (temp->pins[i].wires[j]) : nullptr;
				break;
			}
			if (grabbed_wire != nullptr) break;
		}
		if (grabbed_wire != nullptr) break;
	}
	for (LogicElement* temp = entities; temp != nullptr;temp = temp->next)
	{
		if (temp->isInside(mp))
		{
			/*IF THERE EXISTS A SELECTED WIRE
			  WE APPLY DIFFERENT LOGIC*/
			if (grabbed_wire != nullptr)
			{
				temp->embedWire(mp, grabbed_wire);
			}
			else
			{
				temp->handleClick(mp);
			}
			break;
		}
		else
		{
			if (grabbed_wire != nullptr)
			{
				grabbed_wire->pins[0]->unembedWire(grabbed_wire);
			}
			temp->selected = false;
		}
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
	  /*if entity is dropped outside
		destroy that entity*/
	bool flag = false;
	for (LogicElement* temp = entities; temp != nullptr; temp = temp->next)
	{
		if (temp->grabbed)
		{
			flag = true;
		}
	}
	if (!isInside(mp) && flag)
	{
		deleteLogic();
	}
	/* else ungrab the entity*/
	else
	{
		for (LogicElement* temp = entities; temp != nullptr; temp = temp->next)
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