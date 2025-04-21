#include "WrongAnimal.hpp"
#include <iostream>
#include <ostream>

WrongAnimal::WrongAnimal(void) : _type("Jungle of animals") {
  std::cout << "The WrongAnimal constructor has been called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
  std::cout << "An WrongAnimal constructor was called with the type " << type << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
  std::cout << "The WrongAnimal destructor has been called" << std::endl;
}

void WrongAnimal::makeSound(void) const {
  std::cout << "All animals around you make sound" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal &this_animal) {
  std::cout << "WrongAnimal assigment operator called" << std::endl;
  if (&this_animal != this) {
    this->_type = this_animal._type;
  }
  return *this;
}

// getter:
std::string WrongAnimal::getType(void) const { return _type; }

// setter:
void WrongAnimal::set_type(std::string type) { this->_type = type; }
