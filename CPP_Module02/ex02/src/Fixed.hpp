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
		bool operator> (const Fixed& other) const;
		bool operator< (const Fixed& other) const;
		bool operator>= (const Fixed& other) const;
		bool operator<= (const Fixed& other) const;
		bool operator== (const Fixed& other) const;
		bool operator!= (const Fixed& other) const;
		
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


		//Destructor
		~Fixed();

		//Member functions
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		//Public (overloaded?) member functions
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);

		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
		
	private:
		int						_fpnVal;
		static int constexpr	_FRACTBITS = 8;

};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);
