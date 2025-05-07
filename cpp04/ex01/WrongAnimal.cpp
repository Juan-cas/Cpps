#include "WrongAnimal.hpp"
#include "Animals.hpp"
#include <iostream>
#include <ostream>

// canon:
WrongAnimal::WrongAnimal(void) : _type("Jungle of animals") {
  std::cout << "The WrongAnimal constructor has been called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &otherAnimal)
    : _type(otherAnimal.getType()) {
  std::cout << "An WrongAnimal constructor was called with the type " << _type
            << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
  std::cout << "The wrong constructor was called with the type " << type
            << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
  std::cout << "The WrongAnimal destructor has been called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal &otherAnimal) {
  std::cout << "WrongAnimal assigment operator called" << std::endl;
  if (&otherAnimal != this) {
    WrongAnimal::operator=(otherAnimal);
  }
  return *this;
}

// getter:
std::string WrongAnimal::getType(void) const { return _type; }

// setter:
void WrongAnimal::set_type(std::string type) { this->_type = type; }

// method:
void WrongAnimal::makeSound(void) const {
  std::cout << "All animals around you make sound" << std::endl;
}
