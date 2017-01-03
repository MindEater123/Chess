/* some includes */

#include "Pipe.h"
#include "board.h"
#include "Point.h"
#include "Communication.h"
#include <iostream>
#include <thread>

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

/*function*/
void createConnection();