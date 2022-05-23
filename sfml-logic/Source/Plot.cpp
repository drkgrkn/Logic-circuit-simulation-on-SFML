#include "Plot.h"

Plot::Plot(sf::RenderWindow* w) :
	window(w), display_len(10),
	show_plot(false), hists(nullptr),
	clickedX(nullptr), start(0)
{
	setBackGround();
	setText();

	show_plot = true;

}

Plot::~Plot()
{
	if (hists != nullptr)
		delete[] hists;
	if (data != nullptr)
		delete[] data;
	if (clickedX != nullptr)
		delete clickedX;
}

void Plot::setBackGround()
{
	backGround.setPosition(350, 20);
	backGround.setSize(sf::Vector2f(800, 60));
	backGround.setFillColor(sf::Color::White);
}

void Plot::setText()
{
	if (!font.loadFromFile("assets/ARCADECLASSIC.ttf"))
	{
		std::cout << "Failed to load asset: ARCADECLASSIC.ttf" << std::endl;
	}
	for (int i = 0; i < 2; i++)
	{
		text[i].setFont(font);
		text[i].setFillColor(sf::Color::Black);
		text[i].setCharacterSize(18);
	}

	float px = backGround.getPosition().x;
	float py = backGround.getPosition().y;

	text[0].setString("High");
	text[0].setPosition(sf::Vector2f(px - 44, py - 4));
	text[1].setString("Low");
	text[1].setPosition(sf::Vector2f(px - 35,py + 41));
}

/*I hope I won't need to revisit this function O_O
  just pass the array and it's length, it should work*/
void Plot::makePlot()
{
	std::cout << display_len << std::endl;

	if (hists)
		delete[] hists;
	float w = backGround.getSize().x / display_len;
	float h = backGround.getSize().y / 6;
	float px = backGround.getPosition().x;
	float py = backGround.getPosition().y;
	hists = new sf::RectangleShape[display_len];
	for (int i = 0; i < display_len; i++)
	{
		hists[i].setFillColor(sf::Color::Green);
		hists[i].setPosition(px + (i) * w, py + h - 4 * h * (data[start + i] - 1));
		hists[i].setSize(sf::Vector2f(w, h * (1 + 4 * data[start + i])));
	}
	for (int i = 0; i < 2; i++)
	{
		time[i].setFont(font);
		time[i].setFillColor(sf::Color::Black);
		time[i].setCharacterSize(18);
		time[i].setString(std::to_string(start + i*display_len));
		time[i].setPosition(sf::Vector2f(px + (i) * w * display_len, py + h * 6));
	}
}

void Plot::deletePlot()
{
	delete[] hists;
	hists = nullptr;
}

void Plot::movePlot()
{
	std::cout << "Hey" << std::endl;
	float w = backGround.getSize().x / display_len;
	*clickedX /= w;
	std::cout << *clickedX << std::endl;

	start += *clickedX;
	if (start < 0)
		start = 0;
	if (start > max_len - display_len)
		start = max_len - display_len;
	makePlot();
}

void Plot::draw() const
{
	window->draw(backGround);
	window->draw(text[0]);
	window->draw(text[1]);
	if (display_len >= 1 && show_plot && hists != nullptr)
	{
		for (int i = 0; i < display_len; i++)
		{
			window->draw(hists[i]);
		}
	}
	window->draw(time[0]);
	window->draw(time[1]);
}

//Are these functions too far?
void Plot::increaseDisplayLength()
{
	if (display_len < max_len)
		display_len++;
	makePlot();
}

void Plot::decreaseDisplayLength()
{
	if (display_len > 1)
		display_len--;
	makePlot();
}

bool Plot::isInside(sf::Vector2f mp) const
{
	float x_size = backGround.getSize().x;
	float y_size = backGround.getSize().y;
	float x_pos = backGround.getPosition().x;
	float y_pos = backGround.getPosition().y;

	return  (mp.x <= x_pos + x_size) &&
			(mp.x >= x_pos) &&
			(mp.y <= y_pos + y_size) &&
			(mp.y >= y_pos);
}

void Plot::handleClick(sf::Vector2f mp)
{
	std::cout << "handleClick" << std::endl;
	if (clickedX != nullptr)
		delete clickedX;
	clickedX = new int;
	*clickedX = mp.x;
}

void Plot::handleRelease(sf::Vector2f mp)
{
	if (hists != nullptr)
	{
		*clickedX = *clickedX - mp.x;
		movePlot();
	}
	delete clickedX;
	clickedX = nullptr;
}

void Plot::handleScroll(sf::Event scroll)
{
	if (scroll.mouseWheelScroll.delta < 0)
		increaseDisplayLength();
	else
		decreaseDisplayLength();
}

void Plot::plot(Pin::pinState* pData)
{
	dataPtr = pData;
	max_len = 0;
	display_len = 0;
	for (; pData[display_len] != Pin::pinState::HIGHZ; display_len++)
	{
		max_len++;
	}
	if (data != nullptr)
	{
		delete[] data;
		data = nullptr;
	}
	parseData(pData);
	makePlot();
}

void Plot::updatePlot()
{
	max_len = 0;
	display_len = 0;
	for (; dataPtr[display_len] != Pin::pinState::HIGHZ; display_len++)
	{
		max_len++;
	}
	parseData(dataPtr);
	makePlot();
}

void Plot::parseData(Pin::pinState* pData)
{
	if (data != nullptr)
	{
		delete[] data;
		data = nullptr;
	}
	data = new int[display_len];
	for (int i = 0; i < display_len; i++)
	{
		if (pData[i] == Pin::pinState::LOW || pData[i] == Pin::pinState::HIGHZ)
		{
			data[i] = 0;
		}
		else
		{
			data[i] = 1;
		}
	}
}

void Plot::reset()
{
	if (data != nullptr)
	{
		delete[] data;
		data = nullptr;
	}
	if (hists != nullptr)
	{
		delete[] hists;
		hists = nullptr;
	}
	dataPtr = nullptr;
	show_plot = false;
	max_len = 0;
	display_len = 0;
	time[0].setString(" ");
	time[1].setString(" ");
}
