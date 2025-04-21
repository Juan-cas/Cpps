#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {
public:
  Fixed();
  Fixed(const int value);
  Fixed(const float value);
  Fixed(const Fixed &other);
  ~Fixed();

  Fixed &operator=(const Fixed &other);

  int toInt() const;
  float toFloat() const;

  int getValue() const;

  Fixed operator-(const Fixed &other);
  Fixed operator+(const Fixed &other);
  Fixed operator*(const Fixed &other);
  Fixed operator/(const Fixed &other);
  Fixed &operator++();
  Fixed operator++(int);
  Fixed &operator--();
  Fixed operator--(int);
  int operator/(const Fixed &other) const;
  bool operator==(const Fixed &other) const;
  bool operator!=(const Fixed &other) const;
  bool operator<(const Fixed &other) const;
  bool operator>(const Fixed &other) const;
  bool operator<=(const Fixed &other) const;
  bool operator>=(const Fixed &other) const;
  static Fixed& min(Fixed &first, Fixed &second);
  static const Fixed &min(const Fixed &first, const Fixed &second);
  static Fixed& max(Fixed &first, Fixed &second);
  static const Fixed &max(const Fixed &first, const Fixed &second);

  int getRawBits() const;
  void setRawBits(int raw);

  friend std::ostream &operator<<(std::ostream &os, const Fixed &x);

private:
  int value;
  static const int f_bits = 8;
};

#endif // FIXED_HPP
