#include "Dog.hpp"
#include "Animals.hpp"
#include <iostream>
#include <ostream>

// canon:
Dog::Dog() : Animal("cannine") {
  this->set_type("Dog");
  std::cout << "The Dog constructor has been called" << std::endl;
}

Dog::Dog(const Dog &otherAnimal) : Animal(otherAnimal) {
  std::cout << "The dog copy constructor has been called" << std::endl;
}

Dog::~Dog() { std::cout << "The dog destructor has been called" << std::endl; }

Dog &Dog::operator=(const Animal &otherAnimal) {
  std::cout << "The dog assigment operator called" << std::endl;
  if (this != &otherAnimal) {
    Animal::operator=(otherAnimal);
  }
  return *this;
}

// method:
void Dog::makeSound() const { std::cout << "Woof" << std::endl; }
