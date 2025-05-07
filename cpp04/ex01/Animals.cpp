#include "Animals.hpp"
#include <iostream>
#include <ostream>

Animal::Animal() : _type("Jungle of animals") {
  std::cout << "The Animal constructor has been called" << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
  std::cout << "An animal constructor was called with the type " << type
            << std::endl;
}

Animal::Animal(const Animal &otherAnimal) {
  this->set_type(otherAnimal._type);
  std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal() {
  std::cout << "The Animal destructor has been called" << std::endl;
}

void Animal::makeSound() const {
  std::cout << "All animals around you make sound" << std::endl;
}

Animal &Animal::operator=(const Animal &otherAnimal) {
  std::cout << "Animal assigment operator called" << std::endl;
  if (this != &otherAnimal) {
    this->_type = otherAnimal._type;
  }
  return *this;
}

// getter:
std::string Animal::getType() const { return _type; }

// setter:
void Animal::set_type(std::string type) { this->_type = type; }
