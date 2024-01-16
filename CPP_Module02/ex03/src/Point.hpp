#pragma once
#include "Fixed.hpp"

class Point{
	public:
		Point();
		Point(Fixed x, Fixed y);
		Point(Fixed& other);
		Point operator= (Fixed& other);
		~Point();

		//Member functions
		void	setX(Fixed const x);
		Fixed&  getX(void) const;	

		void	setY(Fixed const y);
		Fixed&  getY(void) const;	

	private:
		Fixed const _X;
		Fixed const _Y;

};
