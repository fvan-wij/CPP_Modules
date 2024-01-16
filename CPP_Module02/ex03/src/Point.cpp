#include "Point.hpp"
#include "Fixed.hpp"

//Constructors
Point::Point(){
	_X = Fixed();
	_Y = Fixed();
}

Point::Point(Fixed x, Fixed y){
	_X = x;
}
Point::Point(Fixed& other);
Point::Point operator= (Fixed& other);
Point::~Point();

//Member functions
// void	Point::setX(Fixed const x);
// Fixed&  Point::getX(void) const;	
//
// void	Point::setY(Fixed const y);
// Fixed&  Point::getY(void) const;	
