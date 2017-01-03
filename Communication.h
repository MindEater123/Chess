#pragma once

/* Includes */
#include "Pipe.h"
#include "Point.h"
#include "board.h"

class communication
{
public:
	communication();
	~communication();
	void setPlacec(std::string);
	Point newpoint();
	Point lastpoint();

private:
	char _myPlacec[5];


};

