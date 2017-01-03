
#include "Rooks.h"

Rooks::Rooks(bool color, Point chise) : Tool(color, chise)
{}
Rooks::Rooks() : Tool()
{}
Rooks::~Rooks()
{

}

int Rooks::canMove(Point toMove,Tool* board[BOARD_SIZE][BOARD_SIZE])
{
	int i;
	//checkIfchessMat(toMove, board);
	if (ROOKS_CANT_MOVE)
	{
		return BAD_MOV;
	}
	
	for (i = this->_place.getX(); i != toMove.getX() - 1 && i != toMove.getX() + 1 && toMove.getX() != this->_place.getX();)
	{
		i += (toMove.getX() - this->_place.getX()) / abs(toMove.getX() - this->_place.getX());
		if (board[toMove.getY()][i]!=nullptr)
		{
			return BAD_MOV;
		}
	}
	for (i = this->_place.getY(); i != toMove.getY() - 1 && i != toMove.getY() + 1 && toMove.getY() != this->_place.getY();)
	{
		i += (toMove.getY() - this->_place.getY()) / abs(toMove.getY() - this->_place.getY());
		if (board[i][toMove.getX()] != nullptr)
		{
			return BAD_MOV;
		}
	}
	
	return OK_MOV;
}