#include "Brain.hpp"
#include <iostream>

Brain::Brain(void) {
  for (int i = 0; i < 100; i++) {
    _Ideas[i] = "Random Idea\n";
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
  if (this != &var) {
    for (int i = 0; i < 100; i++) {
      _Ideas[i] = var._Ideas[i];
    }
  }
  std::cout << "Brain Copy constructor called" << std::endl;
  return;
}

Brain::~Brain(void) {
  std::cout << "Brain Destructor has been called" << std::endl;
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

void Brain::getIdea(int index) {
  if (index > 100 || index < 1) {
    std::cout << "this brain is little it  can only hold from 1 to 100 ideas\n "
                 "Please try to pick an idea from 1 to 100"
              << std::endl;
  }
  std::cout << _Ideas[index] << std::endl;
}

void Brain::setIdea(int index, std::string idea) {
  if (index > 100 || index < 1) {
    std::cout << "this brain is little it  can only hold from 1 to 100 ideas\n "
                 "Please try to store an idea in an index from 1 to 100"
              << std::endl;
  }
  _Ideas[index] = idea;
}
