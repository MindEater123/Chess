#include "king.h"


King::King(bool color, Point chise) : Tool(color, chise)
{
	this->setKingLoc();
}
King::King() : Tool()
{}
King::~King()
{}


int King::canMove(Point toMove, Tool* board[BOARD_SIZE][BOARD_SIZE])
{

	setKingLoc();
	//checkIfchessMat(toMove, board);
	Point back = _place;
	if (KING_CANT_MOVE)
	{
		return BAD_MOV;
	}
	if (this->checkIfChess(toMove, board) == BAD_MOV_CHESS)
	{
		return BAD_MOV_CHESS;
	}
	return OK_MOV;
}