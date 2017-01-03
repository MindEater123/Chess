#pragma once

/* Includes */
#include "board.h"
#include "Tool.h"

/* Defines */
#define KNIGHT_CANT_MOVE !((abs(this->_place.getX() - toMove.getX()) == 1 && abs(this->_place.getY() - toMove.getY()) == 2) || (abs(this->_place.getX() - toMove.getX()) == 2 && abs(this->_place.getY() - toMove.getY()) == 1))

/* Code */
class Knight : public Tool
{
public:
	Knight();
	Knight(bool color, Point chise);
	virtual ~Knight();
	virtual int canMove(Point toMove, Tool* board[BOARD_SIZE][BOARD_SIZE]);

};