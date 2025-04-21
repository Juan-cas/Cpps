#include "Cat.hpp"

Cat::Cat() : Animal("cat"){
	this->_type = "Cat";
	std::cout << "The Cat constructor has been called" << std::endl;
}

Cat::~Cat() {
	std::cout << "The Cat destructor has been called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "meow" << std::endl;
}
