#include "Queen.h"



Queen::Queen(bool color, Point chise) : Tool(color, chise)
{}
Queen::Queen() : Tool()
{}
Queen::~Queen()
{}

int Queen::canMove(Point toMove, Tool* board[8][8])
{
	//checkIfchessMat(toMove, board);
	Rooks ifitwasRooks(this->getColor(), this->_place);
	Bishop ifitwasBishop(this->getColor(), this->_place);
	if (QUEEN_CANT_MOVE)
	{
		return BAD_MOV;
	}
	return OK_MOV;
}