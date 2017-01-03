#pragma once
#include <vector>
//#include "CImg.h"

class Point
{
public:
	Point(int x, int y);
	Point(const Point& other);
	Point();
	virtual ~Point();
	
	Point operator+(const Point& other) const;
	Point& operator+=(const Point& other);
	Point& operator=(const Point& other);
	bool operator==(const Point& other);

	int getX() const;
	int getY() const;
private:
	int _x;
	int _y;
};