#pragma once

/* Includes */
#include "board.h"
#include "Tool.h"

/* Defines */
#define BISHOP_CANT_MOVE abs(this->_place.getX() - toMove.getX()) != abs(this->_place.getY() - toMove.getY()) // basic moves for bishop 

/* Code */
class Bishop : public Tool
{
public:
	Bishop();
	Bishop(bool color, Point chise);
	virtual ~Bishop();
	virtual int canMove(Point toMove, Tool* board[BOARD_SIZE][BOARD_SIZE]);

};