#include "Point.hpp"
#include "Fixed.hpp"

//Constructors
Point::Point() : _X(0), _Y(0){

}

Point::Point(const float x, const float y) : _X(x), _Y(y){

}

Point::Point(Point& other){
	*this = other;
}

Point::Point(const Point &other) : _X(other.getX()), _Y(other.getY()){

}

//Operators
Point& Point::operator= (const Point& other){
	const_cast<Fixed&>(this->_X) = other.getX();
	const_cast<Fixed&>(this->_Y) = other.getY();
	return (*this);
}

bool Point::operator== (const Point& other) const{
	if (this->_X == other.getX() && this->_Y == other.getY())
		return (true);
	else
	 	return (false);
}

std::ostream& operator<<(std::ostream& os, const Point& p){
	os << "(" << p.getX() << ", " << p.getY() << ")";
	return (os);
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
