#include "Animals.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>
#include <ostream>

void brainTest(void) {
  std::cout << "\n===== Brain tests =====" << std::endl;
  const Cat cat;
  const Dog dog;
  Animal *herd[10];
  Animal *copy_herd[10];

  std::cout << "\n======= Creating the base herd of 5 cats and 5 dogs\n"
            << std::endl;
  for (int i = 0; i < 10; i++) {
    if (i < 5) {
      herd[i] = new Cat();
    } else {
      herd[i] = new Dog();
    }
  }
  std::cout
      << "\n======= Creating a copy of the herd of 5 cats and 5 dogs ====\n"
      << std::endl;
  for (int i = 0; i < 10; i++) {
    if (i < 5) {
      copy_herd[i] = herd[i]->clone();
    } else {
      copy_herd[i] = herd[i]->clone();
    }
  }
  std::cout << "\n======= Original herd making sound and showing its type ====="
            << std::endl;
  for (int i = 0; i < 10; i++) {
    std::cout << "the animal " << i + 1 << " of type " << herd[i]->getType()
              << " will make a sound and show its type " << std::endl;
    herd[i]->makeSound();
  }
  std::cout
      << "\n===== changing the type of the herd to prove deep copies ====="
      << std::endl;
  for (int i = 0; i < 10; i++) {
    if (i < 5) {
      copy_herd[i]->set_type("OwlCat");
    } else if (i < 10) {
      copy_herd[i]->set_type("Thunderdog");
    }
  }
  std::cout << "\n cats are now OwlCats and Dogs are Thunderdogs \n"
            << std::endl;
  std::cout << "\n====== Checking the CopyHerd to see if their types changed "
               "aswell =====\n"
            << std::endl;
  for (int i = 0; i < 10; i++) {
    std::cout << "the animal " << i + 1 << " of type "
              << copy_herd[i]->getType()
              << " will make a sound and show its type \n"
              << std::endl;
    copy_herd[i]->makeSound();
  }
  std::cout << "\n ===== showing both types of herd =====\n\n" << std::endl;
  for (int i = 0; i < 10; i++) {
    std::cout << "For both original and copy herds index " << i + 1
              << " the slot contains \n"
              << herd[i]->getType() << " << Original : Modified Copy >> "
              << copy_herd[i]->getType() << "\n"
              << std::endl;
  }

  std::cout << "\n ====== Starting to destroy copies then originals ======\n"
            << std::endl;
  for (int i = 0; i < 10; i++) {
    delete copy_herd[i];
  }
  for (int i = 0; i < 10; i++) {
    delete herd[i];
  }
}

int main(void) {
  brainTest();
  std::cout << "\n------- Tests done -------" << std::endl;
  return 0;
}
