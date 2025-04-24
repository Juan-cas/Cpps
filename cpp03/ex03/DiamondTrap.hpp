
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
  std::string _Name;

public:
  DiamondTrap(const std::string &Name);
  DiamondTrap(const DiamondTrap &other);
  DiamondTrap(void);
  void whoami();
  ~DiamondTrap();
};
#endif
