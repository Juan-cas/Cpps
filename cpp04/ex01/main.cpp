#include "Animals.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>
#include <ostream>

void brainTest(void) {
  std::cout << "===== Brain tests =====" << std::endl;
  const Cat cat;
  const Dog dog;
  Animal *herd[10];
  Animal *copy_herd[10];

  std::cout << "======= Creating the base herd of 5 cats and 5 dogs"
            << std::endl;
  for (int i = 0; i < 10; i++) {
    if (i < 5) {
      herd[i] = new Cat();
    } else {
      herd[i] = new Dog();
    }
  }
  std::cout << "======= Creating a copy of the herd of 5 cats and 5 dogs"
            << std::endl;
  for (int i = 0; i < 10; i++) {
    if (i < 5) {
      copy_herd[i] = herd[i]->clone();
    } else {
      copy_herd[i] = herd[i]->clone();
    }
  }
  std::cout << "======= Original herd making sound and showing its type"
            << std::endl;
  for (int i = 0; i < 10; i++) {
    std::cout << "the animal " << i + 1 << " will make a sound and show its type "
              << std::endl;
    herd[i]->makeSound();
    std::cout << herd[i]->getType() << std::endl;
  }
  std::cout << "===== changing the type of the herd to prove deep copies"
            << std::endl;
  for (int i = 0; i < 10; i++) {
    if (i < 5) {
      herd[i]->set_type("OwlCat");
    } else if (i < 10) {
      herd[i]->set_type("Thunderdog");
    }
  }
  std::cout << " cats are now OwlCats and Dogs are Thunderdogs " << std::endl;
  std::cout << "Checking the CopyHerd to see if their types changed aswell"
            << std::endl;
  for (int i = 0; i < 10; i++) {
    std::cout << "the copy animal " << i + 1
              << " will make a sound and show its type " << std::endl;
    copy_herd[i]->makeSound();
    std::cout << copy_herd[i]->getType() << std::endl;
  }
  std::cout << "showing both types of herd\n\n" << herd[0]->getType() << " : "
    << herd[7]->getType() << std::endl;
  std::cout << "Starting to destroy copies then originals" << std::endl;
  for (int i = 0; i < 10; i++) {
    delete copy_herd[i];
  }
  for (int i = 0; i < 10; i++) {
    delete herd[i];
  }
}

int main(void) {
  brainTest();
  std::cout << "------- Tests done -------" << std::endl;
  return 0;
}
