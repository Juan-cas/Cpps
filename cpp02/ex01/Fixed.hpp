#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

class Fixed
{
	public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& other);
	~Fixed();

	Fixed& operator=(const Fixed& other);

	int toInt() const;
	float toFloat() const;

	int operator-(const Fixed& other) const;
	int operator+(const Fixed& other) const;
	int operator*(const Fixed& other) const;
	int operator/(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	Fixed *min(Fixed &first, Fixed &second);


	int getRawBits() const;
	void setRawBits(int raw);

	friend std::ostream& operator<<(std::ostream& os, const Fixed& x);
	private:
	int value;
	static const int f_bits = 8;
};

#endif //FIXED_HPP
