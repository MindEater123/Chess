#pragma once

/* Includes */
#include "board.h"
#include "Tool.h"

/* Defines */
#define ROOKS_CANT_MOVE !(this->_place.getX() == toMove.getX() && this->_place.getY() != toMove.getY()|| this->_place.getX() != toMove.getX() && this->_place.getY() == toMove.getY())



/* Code */

class Rooks : public Tool
{
public:
	Rooks();
	Rooks(bool color, Point chise);
	virtual ~Rooks();
	virtual int canMove(Point toMove, Tool* board[BOARD_SIZE][BOARD_SIZE]);

};