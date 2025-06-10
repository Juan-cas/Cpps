#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
  // constructor:
  ScavTrap();
  ScavTrap(const std::string input);
  ScavTrap(const ScavTrap &tmp);
  ~ScavTrap();

  // overloads:
  ScavTrap &operator=(const ScavTrap &tmp);

  // methods:
  void guardGate();
};
#endif
