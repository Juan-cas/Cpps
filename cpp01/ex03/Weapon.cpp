#include "Weapon.hpp"
#include <iostream>
#include <ostream>

Weapon::Weapon() {
  std::cout << "Weapon default constructor called" << std::endl;
}

Weapon::Weapon(std::string weapon) : _Type(weapon) {
  std::cout << "Defined Weapon constructor called" << std::endl;
}

void Weapon::setType(std::string Weapon) { this->_Type = Weapon; }

Weapon::~Weapon() { std::cout << "Weapon destructor called" << std::endl; }

std::string Weapon::getType() { return this->_Type; }
