#include "Animals.hpp"
#include <iostream>
#include <ostream>

void Animal::makeSound() const {
  std::cout << "All animals around you make sound" << std::endl;
}

Animal &Animal::operator=(Animal &this_animal) {
  std::cout << "Animal assigment operator called" << std::endl;
  if (&this_animal != this) {
    this->_type = this_animal._type;
  }
  return *this;
}

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

// getter:
std::string Animal::getType() const { return _type; }

// setter:
void Animal::set_type(std::string type) { this->_type = type; }
