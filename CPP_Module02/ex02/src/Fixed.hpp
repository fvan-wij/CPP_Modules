#pragma once
#include <iostream>

class Fixed{
	public:
		//Dustructors
		Fixed();
		Fixed(const int integer);
		Fixed(const float floatingPointNumber);
		Fixed(const Fixed& other);

		//Assignment operator
		Fixed& operator= (const Fixed& other);

		//Comparison operators
		bool operator> (const Fixed& other);
		bool operator< (const Fixed& other);
		bool operator>= (const Fixed& other);
		bool operator<= (const Fixed& other);
		bool operator== (const Fixed& other);
		bool operator!= (const Fixed& other);
		
		//Increment/decrement operators
		Fixed& operator++ (); //Prefix increment
		Fixed  operator++ (int); //Postfix increment
		Fixed& operator-- ();
		Fixed  operator-- (int);

		//Arithmetic operators
		float operator+ (const Fixed& other);
		float operator- (const Fixed& other);
		float operator* (const Fixed& other);
		float operator/ (const Fixed& other);

		//Insertion operator
		friend std::ostream& operator<<(std::ostream& os, const Fixed& obj);

		//Destructor
		~Fixed();

		//Member functions
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		
	private:
		int						_fpnVal;
		static int constexpr	_FRACTBITS = 8;

};
