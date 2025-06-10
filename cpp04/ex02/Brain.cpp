#include "Brain.hpp"

Brain::Brain(void) {
  for (int i = 0; i < 100; i++) {
    _Ideas[i] = "Random Idea";
  }
  std::cout << "Brain's default constructor called" << std::endl;
  return;
}

Brain::Brain(std::string ideas[100]) {
  for (int i = 0; i < 100; i++) {
    _Ideas[i] = ideas[i];
  }
  std::cout << "Parameter constructor called" << std::endl;
  return;
}

Brain::Brain(const Brain &var) {
  std::cout << "Copy constructor called" << std::endl;
  for (int i = 0; i < 100; i++) {
    _Ideas[i] = var._Ideas[i];
  }
  return;
}

Brain::~Brain(void) {
  std::cout << "Destructor called" << std::endl;
  return;
}

Brain &Brain::operator=(const Brain &tmp) {

  if (this != &tmp) {
    for (int i = 0; i < 100; i++) {
      _Ideas[i] = tmp._Ideas[i];
    }
  }
  std::cout << "Operator equalizer called" << std::endl;
  return (*this);
}
