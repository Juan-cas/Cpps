#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>
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

  int getRawBits() const;
  void setRawBits(int raw);

private:
  int value;
  static const int f_bits = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &x);

#endif // FIXED_HPP
