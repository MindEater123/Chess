#include "board.h"

Board::Board() : Board("rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1")
{}

Board::Board(char boerd[66])
{
	int i;
	for (i = 0; i < 64; i++)
	{
		if (boerd[i] == 'r')
		{
			CREATE_BLACK_ROOKS;
		}
		else if (boerd[i] == 'R')
		{
			CREATE_WHITE_ROOKS;
		}
		else if(boerd[i] == 'k')
		{
			CREATE_BLACK_KING;
		}
		else if (boerd[i] == 'K')
		{
			CREATE_WHITE_KING;
		}
		else if (boerd[i] == 'b')
		{
			CREATE_BLACK_BISHOP;
		}
		else if (boerd[i] == 'B')
		{
			CREATE_WHITE_BISHOP;
		}
		else if (boerd[i] == 'n')
		{
			CREATE_BLACK_KNIGHT;
		}
		else if (boerd[i] == 'N')
		{
			CREATE_WHITE_KNIGHT;
		}
		else if (boerd[i] == 'q')
		{
			CREATE_BLACK_QUEEN;
		}
		else if (boerd[i] == 'Q')
		{
			CREATE_WHITE_QUEEN;
		}
		else if (boerd[i] == 'p')
		{
			CREATE_BLACK_SOLDIERS;
		}
		else if (boerd[i] == 'P')
		{
			CREATE_WHITE_SOLDIERS;
		}
		else
		{
			CREATE_EMPTY;
		}
	}
	this->_myPlace = Point(0, 0);
	this->_colorTrene = 1;
}
void Board::setMyPlace(Point point)
{
	this->_myPlace = point;
}
Board::~Board()
{
	
}
int Board::canMove(Point movePoint)
{
	if (this->_board[this->_myPlace.getY()][this->_myPlace.getX()] == nullptr)
	{
		return BAD_MOV_EMPTY_SRC;
	}
	if (this->_board[movePoint.getY()][movePoint.getX()] != nullptr && this->_board[this->_myPlace.getY()][this->_myPlace.getX()]->getColor() == this->_board[movePoint.getY()][movePoint.getX()]->getColor())
	{
		return BAD_MOV_FULL_DST;
	}
	if (this->_board[this->_myPlace.getY()][this->_myPlace.getX()]->getColor() == this->_colorTrene)
	{
		return BAD_MOV_EMPTY_SRC;
	}
	int chess = this->_board[this->_myPlace.getY()][this->_myPlace.getX()]->checkIfChess(movePoint, this->_board);
	if (chess == BAD_MOV_CHESS)
	{
		return BAD_MOV_CHESS;
	}
	int canmove = this->_board[this->_myPlace.getY()][this->_myPlace.getX()]->canMove(movePoint, this->_board);
	if (chess == OK_MOV_CHESS && !canmove)
	{
		if (this->_board[this->_myPlace.getY()][this->_myPlace.getX()]->checkIfchessMat(movePoint, this->_board) == OK_MOVE_CHECKMATE)
		{
			return OK_MOVE_CHECKMATE;
		}
		return OK_MOV_CHESS;
	}
	return canmove;
}

void Board::setMove(Point movePoint)
{
	if (this->_board[movePoint.getY()][movePoint.getX()] != nullptr)
	{
		delete this->_board[movePoint.getY()][movePoint.getX()];
	}
	this->_board[movePoint.getY()][movePoint.getX()] = this->_board[this->_myPlace.getY()][this->_myPlace.getX()];
	if ((this->_board[movePoint.getY()][movePoint.getX()]->getkingLoc())[(int)this->_board[movePoint.getY()][movePoint.getX()]->getColor()] == this->_board[movePoint.getY()][movePoint.getX()]->getPlace())
	{
		this->_board[movePoint.getY()][movePoint.getX()]->setKingLoc();
	}
	
	this->_board[this->_myPlace.getY()][this->_myPlace.getX()] = nullptr;
	this->_board[movePoint.getY()][movePoint.getX()]->setPlace(movePoint);
	this->_board[movePoint.getY()][movePoint.getX()]->setifmove();
	this->_colorTrene = !this->_colorTrene;
}