#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>
#include <ostream>

// canon:
WrongCat::WrongCat(void) : WrongAnimal() {
  this->_type = "WrongCat";
  std::cout << "The WrongCat constructor has been called" << std::endl;
}

WrongCat::WrongCat(const WrongAnimal &otherAnimal) : WrongAnimal(otherAnimal) {
  std::cout << "wrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat(void) {
  std::cout << "The WrongCat destructor has been called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat &otherAnimal) {
  if (this != &otherAnimal) {
    WrongAnimal::operator=(otherAnimal);
  }
  return *this;
}

// method:
void WrongCat::makeSound(void) const { std::cout << "Woof" << std::endl; }
