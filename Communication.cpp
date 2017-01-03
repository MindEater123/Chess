#include "Communication.h"

communication::communication()
{
	this->_myPlacec[0] = 0;
	this->_myPlacec[1] = 0;
	this->_myPlacec[2] = 0;
	this->_myPlacec[3] = 0;
	this->_myPlacec[4] = 0;
}

communication::~communication()
{}

void communication::setPlacec(std::string myPlacec)
{
	this->_myPlacec[0] = myPlacec[0];
	this->_myPlacec[1] = myPlacec[1];
	this->_myPlacec[2] = myPlacec[2];
	this->_myPlacec[3] = myPlacec[3];
}
Point communication::newpoint()
{
	return Point(((this->_myPlacec)[2] - 'a'),(int)((this->_myPlacec)[3] - '1'));
}
Point communication::lastpoint()
{
	return Point(((this->_myPlacec)[0] - 'a'),(int)((this->_myPlacec)[1] - '1'));
}