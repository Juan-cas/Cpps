#include "WrongCat.hpp"
#include <iostream>
#include <ostream>


WrongCat::WrongCat(void) : WrongAnimal("cat"){
	this->_type = "WrongCat";
	std::cout << "The WrongCat constructor has been called" << std::endl;
}

WrongCat::~WrongCat(void) {
	std::cout << "The WrongCat destructor has been called" << std::endl;
}

void WrongCat::makeSound(void) const {
	std::cout << "meow" << std::endl;
}
