#pragma once
#include "Fixed.hpp"

class Point{
	public:
		Point();
		Point(float x, float y);
		Point(Point& other);
		Point( const Point &src );
		Point& operator= (const Point& other);
		~Point();

		//Member functions
		float  getX(void) const;	
		float  getY(void) const;	

	private:
		Fixed _Y;
		Fixed _X;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);
