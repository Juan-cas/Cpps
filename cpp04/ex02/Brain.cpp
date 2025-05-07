#include "Brain.hpp"

Brain::Brain(void) {

  std::cout << "Brain's default constructor called" << std::endl;
  return;
}

Brain::Brain(std::string str) {

  (void)str;
  std::cout << "Parameter constructor called" << std::endl;
  return;
}

Brain::Brain(const Brain &var) {

  std::cout << "Copy constructor called" << std::endl;
  *this = var;
  return;
}

Brain::~Brain(void) {

  std::cout << "Destructor called" << std::endl;
  return;
}

Brain &Brain::operator=(const Brain &tmp) {

  (void)tmp;
  std::cout << "Operator equalizer called" << std::endl;
  return (*this);
}

std::ostream &operator<<(std::ostream &os, const Brain &tmp) {

  (void)tmp;
  os << std::endl << "Operator output called" << std::endl;
  return (os);
}
