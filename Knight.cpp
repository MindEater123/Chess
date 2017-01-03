#include "Knight.h"



Knight::Knight(bool color, Point chise) : Tool(color, chise)
{}
Knight::Knight() : Tool()
{}
Knight::~Knight()
{}

int Knight::canMove(Point toMove, Tool* board[8][8])
{
	//checkIfchessMat(toMove, board);
	if (KNIGHT_CANT_MOVE)
	{
		return BAD_MOV;
	}
	return OK_MOV;
}