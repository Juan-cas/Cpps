#include "FragTrap.hpp"


FragTrap::FragTrap(const char *input) : ClapTrap(input) {
  std::cout << "FragTrap constructor called" << std::endl;
  this->set_hp(100);
  this->set_ep(100);
  this->set_dmg(30);
}

FragTrap::~FragTrap() { std::cout << "FragTrap Destructor called" << std::endl; }

void FragTrap::highFivesdGuys() {
  std::cout << this->get_name() << " is waiting for a high~five." << std::endl;
}
