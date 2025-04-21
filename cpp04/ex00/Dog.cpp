#include "Dog.hpp"

Dog::Dog() : Animal("dog"){
	this->set_type("Dog");
	std::cout << "The Dog constructor has been called" << std::endl;
}

Dog::~Dog() {
	std::cout << "The Dog destructor has been called" << std::endl;
}


void Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}
