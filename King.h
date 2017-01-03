#pragma once
/* Includes */
#include "board.h"
#include "Tool.h"

/* Defines */
#define KING_CANT_MOVE !((this->_place.getX() == toMove.getX() + 1 || this->_place.getX() == toMove.getX() - 1 || this->_place.getY() == toMove.getY() + 1 || this->_place.getY() == toMove.getY() - 1) && abs(this->_place.getX() - toMove.getX()) <=1   && abs(this->_place.getY() - toMove.getY()) <= 1)

class King : public Tool
{
public:
	King();
	King(bool color, Point chise);
	virtual ~King();
	virtual int canMove(Point toMove, Tool* board[BOARD_SIZE][BOARD_SIZE]);

};