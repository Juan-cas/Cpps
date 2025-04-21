#include "Fixed.hpp"

Fixed::Fixed()
{
    value = 0;
    std::cout << "Default constructor called" << '\n';
}

Fixed::Fixed(const Fixed& other)
{
    Fixed::value = other.value;
    std::cout << "Copy constuctor called" << '\n';
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << '\n';
    if (this != &other)
        this->value = other.getRawBits();
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