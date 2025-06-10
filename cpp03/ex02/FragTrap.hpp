#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
  // constructor:
  FragTrap();
  FragTrap(const std::string input);
  FragTrap(const FragTrap &tmp);
  ~FragTrap();

  // overloads:
  FragTrap &operator=(const FragTrap &tmp);

  // methods:
  void highFivesdGuys(void);
};
#endif
