#include "ScavTrap.hpp"
#include "ClapTrap.hpp"


// constructors:

ScavTrap::ScavTrap() : ClapTrap() {
  this->set_name("default");
  this->set_hp(100);
  this->set_ep(50);
  this->set_dmg(20);
}

ScavTrap::ScavTrap(const char *input) : ClapTrap() {
  std::cout << "ScavTrap constructor called" << std::endl;
  this->set_name(input);
  this->set_hp(100);
  this->set_ep(50);
  this->set_dmg(20);
}

ScavTrap::ScavTrap(const ScavTrap &tmp) : ClapTrap(tmp) {
    this->set_name(tmp.get_name());
    this->set_hp(tmp.get_hp());
    this->set_ep(tmp.get_ep());
    this->set_dmg(tmp.get_dmg());
}

ScavTrap::~ScavTrap() { std::cout << "ScavTrap Destructor called" << std::endl; }

// overloads:
ScavTrap &ScavTrap::operator=(const ScavTrap &tmp) {
  if (this != &tmp) {
    ClapTrap::operator=(tmp);
  }
  return *this;
}

// methods:
void ScavTrap::guardGate() {
  std::cout << this->get_name() << "is now in gatekeeper mode." << std::endl;
}
