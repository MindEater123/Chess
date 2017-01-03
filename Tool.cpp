#include "Tool.h"

Point Tool::_kingLoc[2];

Tool::Tool()
{
	this->_color = WHITE;
	this->_ifMove = 0;
	this->_place;

}

Tool::Tool(bool color,Point& place)
{
	this->_color = color;
	this->_ifMove = 0;
	this->_place = place;

}
int Tool::canMove(Point toMove , Tool* board[BOARD_SIZE][BOARD_SIZE])
{
	return 0;
}

Tool::~Tool()
{}

void Tool::setPlace(Point place)
{
	this->_place = place;
}

void Tool::setifmove()
{
	this->_ifMove = 1;
}

bool Tool::getColor()
{
	return this->_color;
}

Point Tool::getPlace()
{
	return this->_place;
}

void Tool::setKingLoc()
{
	this->_kingLoc[this->_color] = this->getPlace();
}
Point* Tool::getkingLoc()
{
	return this->_kingLoc;
}