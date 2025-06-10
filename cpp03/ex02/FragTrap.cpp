#include "FragTrap.hpp"
#include "ClapTrap.hpp"

// constructor:

FragTrap::FragTrap() : ClapTrap() {
  std::cout << "FragTrap default constructor called" << std::endl;
  this->set_name("default");
  this->set_hp(100);
  this->set_ep(100);
  this->set_dmg(30);
}

FragTrap::FragTrap(const std::string input) : ClapTrap() {
  std::cout << "FragTrap constructor called" << std::endl;
  this->set_name(input);
  this->set_hp(100);
  this->set_ep(100);
  this->set_dmg(30);
}

FragTrap::FragTrap(const FragTrap &tmp) : ClapTrap() {
  std::cout << "FragTrap copy constructor is called" << std::endl;
  this->set_name(tmp.get_name());
  this->set_hp(tmp.get_hp());
  this->set_ep(tmp.get_ep());
  this->set_dmg(tmp.get_dmg());
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap Destructor called" << std::endl;
}

// overloads:
FragTrap &FragTrap::operator=(const FragTrap &tmp) {
  if (this != &tmp) {
    ClapTrap::operator=(tmp);
  }
  return *this;
}

// methods:
void FragTrap::highFivesdGuys() {
  std::cout << this->get_name() << " is waiting for a high~five." << std::endl;
}
