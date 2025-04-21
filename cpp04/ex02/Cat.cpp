#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal() {
  this->_type = "Cat";
  this->_brain = new Brain();
  std::cout << "The Cat constructor has been called" << std::endl;
}

Cat::~Cat() {
  delete this->_brain;
  std::cout << "The Cat destructor has been called" << std::endl;
}

void Cat::makeSound() const { std::cout << "meow" << std::endl; }
