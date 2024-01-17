#include "Point.hpp"
#include "Fixed.hpp"

//Constructors
Point::Point(){
	_X = Fixed(0);
	_Y = Fixed(0);
}

Point::Point(const float x, const float y){
	_X = Fixed(x);
	_Y = Fixed(y);
}

Point::Point(Point& other){
	*this = other;
}

Point::Point( const Point &src ){
	_X = src.getX();
	_Y = src.getY();
}

Point& Point::operator= (const Point& other){
	this->_X = other.getX();
	this->_Y = other.getX();
	return (*this);
}

//Destructor
Point::~Point()
{

}

//Member functions
float  Point::getX(void) const{
	return (this->_X.toFloat());
}

float  Point::getY(void) const{
	return (this->_Y.toFloat());
}
