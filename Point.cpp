#include "Point.h"
#include <math.h>

Point::Point(int x, int y)
{
	this->_x = x;
	this->_y = y;
}
Point::Point(const Point& other)
{
	this->_x = other.getX();
	this->_y = other.getY();
}
Point::Point()
{
	this->_x = 0;
	this->_y = 0;
}
Point::~Point()
{}
Point Point::operator+(const Point& other) const
{
	return Point(this->_x + other.getX(), this->_y + other.getY());
}
Point& Point::operator+=(const Point& other)
{
	this->_x += other.getX();
	this->_y += other.getY();
	return *this;
}
Point& Point::operator=(const Point& other)
{
	this->_x = other.getX();
	this->_y = other.getY();
	return *this;
}
int Point::getX() const
{
	return this->_x;
}
int Point::getY() const
{
	return this->_y;
}
bool Point::operator==(const Point& other)
{
	return this->_y == other.getY() && this->_x == other.getX();
}