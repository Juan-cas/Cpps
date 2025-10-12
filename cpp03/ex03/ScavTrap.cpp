#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <ostream>

ScavTrap::ScavTrap(std::string input) : ClapTrap(input) {
  std::cout << "ScavTrap constructor called" << std::endl;
  set_name(input);
  set_hp(100);
  set_ep(50);
  set_dmg(20);
}

ScavTrap::ScavTrap() {
  std::cout << "Scavtrap constructor called" << std::endl;
  set_name("Default");
  set_hp(100);
  set_ep(50);
  set_dmg(20);
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
  if (ClapTrap::get_hp() <= 0) {
    std::cout << this->get_name()
              << " doesn't have enought Hitpoints for anything" << std::endl;
    return;
  }
  if (ClapTrap::get_ep() <= 0) {
    std::cout << this->get_name()
              << " doesn't have enought energy for Attacking" << std::endl;
    return;
  }
  std::cout << this->get_name() << " attacks " << target << ", for "
            << this->get_dmg() << std::endl;
  this->use_energy();
}

void ScavTrap::guardGate() {
  std::cout << this->get_name() << " is now in gatekeeper mode." << std::endl;
}
