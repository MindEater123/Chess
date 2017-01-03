#include "Tool.h"

#define REPLACE	board[tempP.getY()][tempP.getX()] = board[toMove.getY()][toMove.getX()];\
 board[board[tempP.getY()][tempP.getX()]->getPlace().getY()][board[tempP.getY()][tempP.getX()]->getPlace().getX()] = temp;\
 board[tempP.getY()][tempP.getX()]->setPlace(tempP);\
 board[kingP.getY()][kingP.getX()]->setKingLoc();

#include <iostream>
using namespace std;

int Tool::checkIfChess(Point toMove, Tool* board[BOARD_SIZE][BOARD_SIZE])
{
	int count = 0;
	//return OK_MOV;
	std::cout << "("<<this->getkingLoc()[this->getColor()].getX() << "," << this->getkingLoc()[this->getColor()].getY() << ")\n";
	/********************************************************************************/
	/* Purpose: checking if there is any sort of chess on the board (not Checkmate) */
	/* Params:  toMove - the location to which the tool wish to move.				*/
	/*          board[8][8] - the current game board                                */
	/*                                                                              */
	/* Retrun:  int value with the game code                                        */
	/********************************************************************************/
	Tool* temp = board[toMove.getY()][toMove.getX()];
	Point tempP = board[this->getPlace().getY()][this->getPlace().getX()]->getPlace();
	Point kingP = this->getkingLoc()[board[this->getPlace().getY()][this->getPlace().getX()]->getColor()];
	int ans = OK_MOV;

	board[toMove.getY()][toMove.getX()] = board[this->getPlace().getY()][this->getPlace().getX()];
	board[this->getPlace().getY()][this->getPlace().getX()] = nullptr;
	board[toMove.getY()][toMove.getX()]->setPlace(toMove);
	if (tempP == kingP)
	{
		board[toMove.getY()][toMove.getX()]->setKingLoc();
	}

	std::cout << "(" << this->getkingLoc()[this->getColor()].getX() << "," << this->getkingLoc()[this->getColor()].getY() << ")\n";
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		cout << "\n";
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (board[i][j] == nullptr)
			{
				cout << " ,";
				continue;
			}
			cout << "O,";
			if (this->getColor() != board[i][j]->getColor() && board[i][j]->canMove(this->getkingLoc()[this->getColor()], board) == OK_MOV)
			{
				REPLACE;
				ans = BAD_MOV_CHESS;

			}
			if  (this->getColor() == board[i][j]->getColor() && board[i][j]->canMove(this->getkingLoc()[!this->getColor()], board) == OK_MOV)
			{

				ans = OK_MOV_CHESS;
			}
		}
	}

	REPLACE
	return ans;

}
#define KINGX this->getkingLoc()[!this->getColor()].getX()
#define KINGY this->getkingLoc()[!this->getColor()].getY()

int Tool::checkIfchessMat(Point toMove, Tool* board[BOARD_SIZE][BOARD_SIZE])
{
	if ((board[KINGY + 1][KINGX + 1] != nullptr || board[KINGY][KINGX]->checkIfChess(Point(KINGY + 1,KINGX + 1), board) == BAD_MOV_CHESS) &&
		(board[KINGY + 1][KINGX + 0] != nullptr || board[KINGY][KINGX]->checkIfChess(Point(KINGY + 1,KINGX + 0), board) == BAD_MOV_CHESS) &&
		(board[KINGY + 1][KINGX - 1] != nullptr || board[KINGY][KINGX]->checkIfChess(Point(KINGY + 1,KINGX - 1), board) == BAD_MOV_CHESS) &&
		(board[KINGY + 0][KINGX + 1] != nullptr || board[KINGY][KINGX]->checkIfChess(Point(KINGY + 0,KINGX + 1), board) == BAD_MOV_CHESS) &&
		(board[KINGY + 0][KINGX - 1] != nullptr || board[KINGY][KINGX]->checkIfChess(Point(KINGY + 0,KINGX - 1), board) == BAD_MOV_CHESS) &&
		(board[KINGY - 1][KINGX + 1] != nullptr || board[KINGY][KINGX]->checkIfChess(Point(KINGY - 1,KINGX + 1), board) == BAD_MOV_CHESS) &&
		(board[KINGY - 1][KINGX + 0] != nullptr || board[KINGY][KINGX]->checkIfChess(Point(KINGY - 1,KINGX + 0), board) == BAD_MOV_CHESS) &&
		(board[KINGY - 1][KINGX - 1] != nullptr || board[KINGY][KINGX]->checkIfChess(Point(KINGY - 1,KINGX - 1), board) == BAD_MOV_CHESS))
	{
		return OK_MOVE_CHECKMATE;
	}

		
}