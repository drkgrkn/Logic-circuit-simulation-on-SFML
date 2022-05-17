#include "Plot.h"

Plot::Plot(sf::RenderWindow* w) :
	window(w), display_len(10),
	show_plot(false), hists(nullptr)
{
	setBackGround();
	setText();
	for (int i = 0; i < 500; i++)
	{
		data[i] = i % 2;
	}
	makePlot();
	show_plot = true;

}

Plot::~Plot()
{
	delete[display_len] hists;
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
	if (hists)
		delete[display_len] hists;
	float w = backGround.getSize().x / display_len;
	float h = backGround.getSize().y / 6;
	float px = backGround.getPosition().x;
	float py = backGround.getPosition().y;
	hists = new sf::RectangleShape[display_len];
	std::cout << w << std::endl;
	if (data.size() > display_len)
	{
		for (int i = 0; i < display_len; i++)
		{
			hists[i].setFillColor(sf::Color::Green);
			hists[i].setPosition(px + (display_len - 1 - i) * w, py + h - 4 * h * (data[data.size()-1 -i] - 1));
			hists[i].setSize(sf::Vector2f(w, h * (1 + 4 * data[data.size()-1-i])));
		}
	}
	else
	{
		delete[display_len] hists;
		hists = new sf::RectangleShape[data.size()];
		for (int i = data.size() - 1; i >= 0; i--)
		{
			hists[i].setFillColor(sf::Color::Green);
			hists[i].setPosition(px + i * w / display_len, py + h - 4 * h * (data[i] - 1));
			hists[i].setSize(sf::Vector2f(w / display_len, h * (1 + 4 * data[i])));
		}
	}
	for (int i = 0; i < 2; i++)
	{
		time[i].setFont(font);
		time[i].setFillColor(sf::Color::Black);
		time[i].setCharacterSize(18);
		time[i].setString(std::to_string(data.size() - i*display_len));
		time[i].setPosition(sf::Vector2f(px + (1-i) * w * display_len, py + h * 6));
	}
}

void Plot::deletePlot()
{
	delete[display_len] hists;
	hists = nullptr;
}

void Plot::draw() const
{
	window->draw(backGround);
	window->draw(text[0]);
	window->draw(text[1]);
	if (display_len >= 1 && show_plot)
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
	display_len++;
	makePlot();
}

void Plot::decreaseDisplayLength()
{
	if (display_len > 10)
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

void Plot::handleScroll(sf::Event scroll)
{
	if (scroll.mouseWheelScroll.delta < 0)
		increaseDisplayLength();
	else
		decreaseDisplayLength();
}