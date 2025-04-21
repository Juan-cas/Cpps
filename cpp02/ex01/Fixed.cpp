#include "Fixed.hpp"

Fixed::Fixed()
{
    value = 0;
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called\n";
    this->value = value << f_bits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called\n";
    this->value = (int)roundf(value * (1 << this->f_bits));
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << '\n';
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << '\n';
    if (this != &other)
    {
        this->value = other.value;
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor Called" << '\n';
}

int Fixed::getRawBits( void ) const
{
    std::cout << "GetRawBits member function called" << '\n';
    return this->value;
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "SetRawBits member function called";
    this->value = raw;
}

float Fixed::toFloat( void ) const
{
    return ((float)this->value) / (float)(1 << f_bits);
}

int Fixed::toInt( void ) const
{
    return (this->value >> f_bits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}
