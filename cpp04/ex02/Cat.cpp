#include "Cat.hpp"
#include "Animals.hpp"
#include <iostream>
#include <ostream>

// canon:
Cat::Cat() : Animal("Feline") {
  this->set_type("cat");
  this->_brain = new Brain();
  std::cout << "The Cat constructor has been called" << std::endl;
}

Cat::Cat(const Cat &otherAnimal) : Animal(otherAnimal) {
  this->_brain = new Brain(*otherAnimal._brain);
  std::cout << "The cat copy constructor has been called" << std::endl;
}

Animal *Cat::clone() const { return new Cat(*this); }

Cat::~Cat() {
  delete this->_brain;

  std::cout << "The Cat destructor has been called" << std::endl;
}

Cat &Cat::operator=(const Cat &otherAnimal) {
  std::cout << "The cat assigment operator called" << std::endl;
  if (this != &otherAnimal) {
    Animal::operator=(otherAnimal);
  }
  return *this;
}

// method:
void Cat::makeSound() const { std::cout << "meow" << std::endl; }
