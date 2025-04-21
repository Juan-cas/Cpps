#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Fixed
{
	private:
	int value;
	static const int f_bits = 8;
	public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();
	int getRawBits() const;
	void setRawBits(int raw);
};

#endif //FIXED_HPP
