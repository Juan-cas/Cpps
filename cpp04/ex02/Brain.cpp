#include "Brain.hpp"
#include <iostream>
#include <ostream>

Brain::Brain() {
  std::cout << "Brain constructor called" << std::endl;
}
  
Brain::~Brain() {
  std::cout << "Brain destructor called" << std::endl;
}
