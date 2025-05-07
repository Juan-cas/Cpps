#include "Dog.hpp"
#include "Animals.hpp"
#include "Brain.hpp"
#include <iostream>
#include <ostream>

// canon:
Dog::Dog() : Animal("cannine") {
  this->set_type("Dog");
  this->_brain = new Brain();
  std::cout << "The Dog constructor has been called" << std::endl;
}

Dog::Dog(const Dog &otherAnimal) : Animal(otherAnimal) {
  this->_brain = new Brain(*otherAnimal._brain);
  std::cout << "The dog copy constructor has been called" << std::endl;
}

Dog::~Dog() {
  delete this->_brain;

  std::cout << "The dog destructor has been called" << std::endl;
}

Animal *Dog::clone() const { return new Dog(*this); }
Dog &Dog::operator=(const Animal &otherAnimal) {
  std::cout << "The dog assigment operator called" << std::endl;
  if (this != &otherAnimal) {
    Animal::operator=(otherAnimal);
  }
  return *this;
}

// method:
void Dog::makeSound() const { std::cout << "Woof" << std::endl; }
