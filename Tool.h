#ifndef TOOL
#define TOOL


#include "Point.h"


/* Defines */

//game defines:
//~~~~~~~~~~~~~~
#define WHITE 0
#define BLACK 1
#define BOARD_SIZE 8

//engine communications defines:
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define OK_MOV 0
#define OK_MOV_CHESS 1
#define BAD_MOV_EMPTY_SRC 2
#define BAD_MOV_FULL_DST 3
#define BAD_MOV_CHESS 4
#define BAD_MOV_BAD_INDEX 5
#define BAD_MOV 6
#define BAD_MOV_SAME 7
#define OK_MOVE_CHECKMATE 8

class Tool
{
public:
	Tool();
	Tool(bool color, Point& place);
	virtual ~Tool();
	void setPlace(Point place);
	virtual int canMove(Point toMove, Tool* board[BOARD_SIZE][BOARD_SIZE]);
	void setifmove();
	bool getColor();
	Point getPlace();
	int checkIfChess(Point toMove, Tool* board[BOARD_SIZE][BOARD_SIZE]);
	int checkIfchessMat(Point toMove, Tool* board[BOARD_SIZE][BOARD_SIZE]);
	void setKingLoc();
	Point* getkingLoc();
private:
protected:
	Point _place;
	bool _ifMove;
	bool _color;
	static Point _kingLoc[2];
};

#endif