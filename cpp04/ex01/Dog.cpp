#include "Dog.hpp"

Dog::Dog() : Animal("dog"){
	this->set_type("Dog");
	this->_brain = new Brain();
	std::cout << "The Dog constructor has been called" << std::endl;
}

Dog::~Dog() {
	delete this->_brain;
	std::cout << "The Dog destructor has been called" << std::endl;
}


void Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}
