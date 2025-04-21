#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
  ScavTrap(const char *input);
  void guardGate();
  ~ScavTrap();
};
#endif
