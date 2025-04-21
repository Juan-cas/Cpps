#include "Fixed.hpp"

Fixed::Fixed() {
  value = 0;
  std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int value) {
  std::cout << "Int constructor called\n";
  this->value = value << f_bits;
}

Fixed::Fixed(const float value) {
  std::cout << "Float constructor called\n";
  this->value = (int)roundf(value * (1 << this->f_bits));
}

Fixed::Fixed(const Fixed &other) {
  std::cout << "Copy constructor called" << '\n';
  *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called" << '\n';
  if (this != &other) {
    this->value = other.value;
  }
  return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const {
  std::cout << "GetRawBits member function called" << '\n';
  return this->value;
}

void Fixed::setRawBits(int const raw) {
  std::cout << "SetRawBits member function called";
  this->value = raw;
}

float Fixed::toFloat(void) const {
  return ((float)this->value) / (float)(1 << f_bits);
}

int Fixed::toInt(void) const { return (this->value >> f_bits); }

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
  os << fixed.toFloat();
  return os;
}

bool Fixed::operator==(const Fixed &other) const {
  return this->value == other.value;
}

bool Fixed::operator!=(const Fixed &other) const {
  return this->value != other.value;
}

bool Fixed::operator<(const Fixed &other) const {
  return this->value < other.value;
}

bool Fixed::operator>(const Fixed &other) const {
  return this->value > other.value;
};

bool Fixed::operator<=(const Fixed &other) const {
  return this->value <= other.value;
};

bool Fixed::operator>=(const Fixed &other) const {
  return this->value >= other.value;
};

Fixed Fixed::operator-(const Fixed &other) {
  return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator+(const Fixed &other) {
  return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) {
  return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) {
  return Fixed(toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
  this->value++;
  return *this;
}

Fixed& Fixed::operator--() {
  this->value--;
  return *this;
}

Fixed Fixed::operator--(int) { 
  Fixed tmp(*this);
  --(*this);
  return tmp;
}

Fixed Fixed::operator++(int) { 
  Fixed tmp(*this);
  ++(*this);
  return tmp;
}

int Fixed::getValue() const {
  return value;
}

Fixed& Fixed::min(Fixed &first, Fixed &second)
{
  return (first < second) ? first : second;
}

const Fixed& Fixed::min(const Fixed &first, const Fixed &second)
{
  return (first < second) ? first : second;
}

 Fixed& Fixed::max(Fixed &first, Fixed &second)
{
  return (first > second) ? first : second;
}


 const Fixed& Fixed::max(const Fixed& first, const Fixed& second)
{
  return (first > second) ? first : second;
}
