#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(const char *input) : ClapTrap(input) {
  std::cout << "ScavTrap constructor called" << std::endl;
  this->set_hp(100);
  this->set_ep(50);
  this->set_dmg(20);
}

ScavTrap::~ScavTrap() { std::cout << "ScavTrap Destructor called" << std::endl; }

void ScavTrap::guardGate() {
  std::cout << this->get_name() << "is now in gatekeeper mode." << std::endl;
}
