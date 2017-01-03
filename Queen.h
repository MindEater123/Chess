#pragma once

/* Includes */
#include "board.h"
#include "Tool.h"
#include "Bishop.h"
#include "Rooks.h"

/* Defines */
#define QUEEN_CANT_MOVE (ifitwasRooks.canMove(toMove, board) && ifitwasBishop.canMove(toMove, board))

/* Code */
class Queen : public Tool
{
public:
	Queen();
	Queen(bool color, Point chise);
	virtual ~Queen();
	virtual int canMove(Point toMove, Tool* board[BOARD_SIZE][BOARD_SIZE]);

};