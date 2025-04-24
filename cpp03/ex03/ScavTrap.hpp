#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
  ScavTrap(std::string input);
  ScavTrap();
  void guardGate();
  virtual void attack(const std::string &target);
  ~ScavTrap();
};
#endif
