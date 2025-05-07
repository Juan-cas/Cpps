#include "Cat.hpp"
#include "Animals.hpp"
#include <iostream>
#include <ostream>

// canon:
Cat::Cat() : Animal("Feline") {
  this->_type = "Cat";
  std::cout << "The Cat constructor has been called" << std::endl;
}

Cat::Cat(const Cat &otherAnimal) : Animal(otherAnimal) {
  std::cout << "The cat copy constructor has been called" << std::endl;
}

Cat::~Cat() { std::cout << "The Cat destructor has been called" << std::endl; }

Cat &Cat::operator=(const Cat &otherAnimal) {
  std::cout << "The cat assigment operator called" << std::endl;
  if (this != &otherAnimal) {
    Animal::operator=(otherAnimal);
  }
  return *this;
}


// method:
void Cat::makeSound() const { std::cout << "meow" << std::endl; }
