#include "Point.hpp"
#include "Fixed.hpp"

//Constructors
Point::Point(){
	_X = Fixed();
	_Y = Fixed();
}

Point::Point(Fixed x, Fixed y){
	_X = x;
	_Y = y;
}

Point::Point(Fixed& other){
	*this = other;
}

Point::Point operator= (Point& other){
	// _X = other.getX();
	// _Y = other.getX();
}

Point::~Point();

//Member functions
// void	Point::setX(Fixed const x);
// Fixed&  Point::getX(void) const;	
//
// void	Point::setY(Fixed const y);
// Fixed&  Point::getY(void) const;	
