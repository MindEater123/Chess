#include "Bishop.h"



Bishop::Bishop(bool color, Point chise) : Tool(color, chise)
{}
Bishop::Bishop() : Tool()
{}
Bishop::~Bishop()
{}

int Bishop::canMove(Point toMove, Tool* board[BOARD_SIZE][BOARD_SIZE])
{
	/* Checks if Bishop can move to the position															   */
	/*																										   */
	/* Params: Point toMove - contain the x and y to which the user want to move							   */
	/*		   Tool* board[BOARD_SIZE][BOARD_SIZE] - contains an array of tools with all the tools in the game */
	/*																										   */
	/* Return: int - contains status code for the graphic engine											   */	
	
	int x,y;
	if (BISHOP_CANT_MOVE)
	{
		return BAD_MOV;
	}
	for (x = this->_place.getX(), y = this->_place.getY(); toMove.getY() != y;)// -1 && (x != 0 && y != 0 && y != 7 && x != 7 || this->_place.getX() == x);)
	{
		if (this->_place.getX() - toMove.getX() < 0)
		{
			x++;
		}
		else
		{
			x--;
		}
		if (this->_place.getY() - toMove.getY() < 0)
		{
			y++;
		}
		else
		{
			y--;
		}
		if (board[y][x] != nullptr && toMove.getY() != y)
		{
			return BAD_MOV;
		}
	}
	return OK_MOV;
}