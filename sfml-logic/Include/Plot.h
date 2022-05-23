#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <array>

#include "Pin.h"
class Plot
{
public:
private:
	void increaseDisplayLength();
	void decreaseDisplayLength();

public:
	sf::RenderWindow* window;
	sf::RectangleShape backGround;
	sf::RectangleShape* hists;
	int start;
	int* clickedX;
	int* data;
	Pin::pinState* dataPtr;
	int max_len;
	int display_len;
	bool show_plot;
	sf::Font font;
	sf::Text text[2];
	sf::Text time[2];


	//Funcs
	Plot(sf::RenderWindow* w);
	~Plot();
	void setBackGround();
	void setText();
	void makePlot();
	void deletePlot();
	void movePlot();
	void handleClick(sf::Vector2f mp);
	void handleRelease(sf::Vector2f mp);
	void handleScroll(sf::Event scroll);
	void draw() const;
	bool isInside(sf::Vector2f mp) const;
	void plot(Pin::pinState* pData);
	void updatePlot();
	void parseData(Pin::pinState* pData);
	void reset();
};
