#include "Animals.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main(void) {
  Animal *zoo[20];
  for (int i = 0; i < 3; i++) {
    zoo[i] = new Cat();
    std::cout << "creating cat #" << i << std::endl;
  }
  for (int i = 3; i < 6; i++) {
    zoo[i] = new Dog();
    std::cout << "creating dog #" << i << std::endl;
  }

  for (int i = 0; i < 3; i++) {
    std::cout << "the cat # " << i << "says: " << std::endl;
    zoo[i]->makeSound();
  }
  for (int i = 3; i < 6; i++) {
    std::cout << "the dog #" << i << "says: " << std::endl;
    zoo[i]->makeSound();
  }
  for (int i = 0; i < 3; i++) {
    delete zoo[i];
    std::cout << "deleting cat #" << i << std::endl;
  }
  for (int i = 3; i < 6; i++) {
    delete zoo[i];
    std::cout << "creating dog #" << i << std::endl;
  }
  return 0;
}
