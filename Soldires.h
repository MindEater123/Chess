#pragma once

/* Includes */
#include "board.h"
#include "Tool.h"

/* Defines */
#define SOLDIER_CANT_MOVE !((this->_place.getY() - toMove.getY() == 1 && this->getColor() || this->_place.getY() - toMove.getY() == -1 && !this->getColor() || (!this->_ifMove) && (this->_place.getY() - toMove.getY() == 2 && this->getColor() || this->_place.getY() - toMove.getY() == -2 && !this->getColor())) && (this->_place.getX() - toMove.getX() == 0 || abs(this->_place.getX() - toMove.getX()) == 1 && board[toMove.getY()][toMove.getX()] != nullptr&&board[toMove.getY()][toMove.getX()]->getColor() != this->getColor()))

/* Code */
class Soldires : public Tool
{
public:
	Soldires();
	Soldires(bool color, Point chise);
	virtual ~Soldires();
	virtual int canMove(Point toMove, Tool* board[BOARD_SIZE][BOARD_SIZE]);

};