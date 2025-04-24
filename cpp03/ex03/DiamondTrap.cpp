#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <ostream>

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name),
      _Name(name) {
  std::cout << "DiamondTrap " << get_name() << "> Status: Created" << std::endl;
  this->set_hp(FragTrap::get_hp());
  this->set_ep(ScavTrap::get_ep());
  this->set_dmg(FragTrap::get_dmg());
}

void DiamondTrap::whoami() {
  std::cout << "Diamond name is " << get_name() << std::endl;
  std::cout << "Clap trap name is" << ClapTrap::get_name() << std::endl;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap's destructor has been called" << std::endl;
}
