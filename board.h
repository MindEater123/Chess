#ifndef BOARD
#define BOARD

/* Includes */

#include "Pipe.h"
#include "Point.h"
#include "Communication.h"
#include "Rooks.h"
#include "King.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "Soldires.h"

/* Defines */

//Creating defines
//~~~~~~~~~~~~~~~~~
#define CREATE_BLACK_KING this->_board[7 - i / BOARD_SIZE][i % BOARD_SIZE] = new King(BLACK, Point(i % BOARD_SIZE, 7 - i / BOARD_SIZE))
#define CREATE_WHITE_KING this->_board[7 - i / BOARD_SIZE][i % BOARD_SIZE] = new King(WHITE, Point(i % BOARD_SIZE, 7 - i / BOARD_SIZE))
#define CREATE_BLACK_BISHOP this->_board[7 - i / BOARD_SIZE][i % BOARD_SIZE] = new Bishop(BLACK, Point(i % BOARD_SIZE, 7 - i / BOARD_SIZE))
#define CREATE_WHITE_BISHOP this->_board[7 - i / BOARD_SIZE][i % BOARD_SIZE] = new Bishop(WHITE, Point(i % BOARD_SIZE, 7 - i / BOARD_SIZE))
#define CREATE_WHITE_ROOKS this->_board[7 - i / BOARD_SIZE][i % BOARD_SIZE] = new Rooks(WHITE, Point(i % BOARD_SIZE, 7 - i / BOARD_SIZE))
#define CREATE_BLACK_ROOKS this->_board[7 - i / BOARD_SIZE][i % BOARD_SIZE] = new Rooks(BLACK, Point(i % BOARD_SIZE, 7 - i / BOARD_SIZE))
#define CREATE_WHITE_SOLDIERS this->_board[7 - i / BOARD_SIZE][i % BOARD_SIZE] = new Soldires(WHITE, Point(i % BOARD_SIZE, 7 - i / BOARD_SIZE))
#define CREATE_BLACK_SOLDIERS this->_board[7 - i / BOARD_SIZE][i % BOARD_SIZE] = new Soldires(BLACK, Point(i % BOARD_SIZE, 7 - i / BOARD_SIZE))
#define CREATE_WHITE_QUEEN this->_board[7 - i / BOARD_SIZE][i % BOARD_SIZE] = new Queen(WHITE, Point(i % BOARD_SIZE, 7 - i / BOARD_SIZE))
#define CREATE_BLACK_QUEEN this->_board[7 - i / BOARD_SIZE][i % BOARD_SIZE] = new Queen(BLACK, Point(i % BOARD_SIZE, 7 - i / BOARD_SIZE))
#define CREATE_WHITE_KNIGHT this->_board[7 - i / BOARD_SIZE][i % BOARD_SIZE] = new Knight(WHITE, Point(i % BOARD_SIZE, 7 - i / BOARD_SIZE))
#define CREATE_BLACK_KNIGHT this->_board[7 - i / BOARD_SIZE][i % BOARD_SIZE] = new Knight(BLACK, Point(i % BOARD_SIZE, 7 - i / BOARD_SIZE))
#define CREATE_EMPTY this->_board[7 - i / BOARD_SIZE][i % BOARD_SIZE] = nullptr

/* Code */

class Board
{
public:
	Board(); // creates new board
	Board(char boerd[66]);
	~Board();
	int canMove(Point); //Checks if tool can move
	void setMove(Point); // sets new position for tool
	void setMyPlace(Point); 

private:
	Tool* _board[BOARD_SIZE][BOARD_SIZE];
	Point _myPlace;
	bool _colorTrene;

};

#endif