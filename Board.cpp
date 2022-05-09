#include "Board.h"

Board::Board(sf::RenderWindow* w) :
	window(w)
{
}

void Board::setBackGround(sf::Vector2f p, sf::Vector2f s,
							int color)
{
	backGround.setSize(s);
	backGround.setPosition(p);
	backGround.setFillColor(sf::Color(color, color, color));
}

bool Board::isInside(sf::Vector2f mp) const
{
    float x_size = backGround.getSize().x;
    float y_size = backGround.getSize().y;
    float x_pos = backGround.getPosition().x;
    float y_pos = backGround.getPosition().y;

    return (mp.x <= x_pos + x_size) &&
           (mp.x >= x_pos) &&
           (mp.y <= y_pos + y_size) &&
           (mp.y >= y_pos);
}

void Board::draw() const
{

}