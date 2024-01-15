#pragma once

class Fixed{
	public:
		Fixed();
		Fixed(const int integer);
		Fixed(const float floatingPointNumber);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		
	private:
		int						_fpnVal;
		static int constexpr	_FRACTBITS = 8;

};
