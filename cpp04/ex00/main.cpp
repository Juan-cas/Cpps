#include "Animals.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <ostream>

void mainTests2(void) {
  std::cout << "\n=======main test for this module acording to 42, for "
               "WrongAnimals=======\n"
            << std::endl;

  std::cout << "Creating the wrong animal subclass\n" << std::endl;
  const WrongAnimal *meta = new WrongAnimal();
  std::cout << "Creating a Dog subclass\n" << std::endl;
  const Animal *j = new Dog();
  std::cout << "Creating a WrongCat class\n" << std::endl;
  const WrongAnimal *i = new WrongCat();
  std::cout << "Getting the type of the dog and it will make its sound\n"
            << j->getType() << std::endl;
  j->makeSound();
  std::cout << "Getting the type of the WrongCat we created and it will make "
               "its sound\n"
            << i->getType() << std::endl;
  j->makeSound();
  std::cout << "Testing the main WrongAnimals class sound\n" << std::endl;
  meta->makeSound();

  std::cout << "Using destructors on the variables we created for the classes"
            << std::endl;
  delete i;
  delete j;
  delete meta;
}

void mainTests1(void) {
  std::cout << "\n======main test for this module acording to 42, for normal "
               "animals=====\n"
            << std::endl;

  std::cout << "\nmain test for this module acording to 42, for Animals\n"
            << std::endl;

  std::cout << "\nCreating the animal subclass\n" << std::endl;
  const Animal *meta = new Animal();
  std::cout << "\nCreating a Dog subclass\n" << std::endl;
  const Animal *j = new Dog();
  std::cout << "\nCreating a WrongCat class\n" << std::endl;
  const Animal *i = new Cat();
  std::cout << "\nGetting the type of the dog and it will make its sound\n"
            << j->getType() << std::endl;
  j->makeSound();
  std::cout << "\nGetting the type of the Cat we created and it will make "
               "its sound\n"
            << i->getType() << std::endl;
  j->makeSound();
  std::cout << "\nTesting the main Animals class sound\n" << std::endl;
  meta->makeSound();

  std::cout << "Using destructors on the variables we created for the classes\n"
            << std::endl;
  delete i;
  delete j;
  delete meta;
}

void testWrongAnimal(void) {
  std::cout << "\n==== Wrong Animal Tests ====\n" << std::endl;

  std::cout << "the wrong cat constructor being called" << std::endl;
  WrongCat original;

  std::cout << "the wrong cat copy constructor is being called" << std::endl;
  WrongCat copy(original);

  std::cout << " getting the type of the original: ";
  std::cout << original.getType() << std::endl;

  std::cout << " getting the type of the copy: ";
  std::cout << copy.getType() << std::endl;

  std::cout << "original making a sound: ";
  original.makeSound();

  std::cout << "copy making a sound: ";
  copy.makeSound();

  std::cout << "changing the type of dog to firulais" << std::endl;
  original.set_type("firulais");

  std::cout << "checking types again original: " << original.getType()
            << "the copy type will be called copy: " << copy.getType()
            << std::endl;

  std::cout << "both make sounds again" << std::endl;
  std::cout << "original: -> ";
  original.makeSound();
  std::cout << "  |   copy: ->";
  copy.makeSound();

  std::cout << "tests done for WrongCat, destroyers for WrongCat and "
               "WrongAnimal getting called"
            << std::endl;
}

void testDog(void) {
  std::cout << "\n==== Dog Test ====\n" << std::endl;

  std::cout << "creating the first dog" << std::endl;
  Dog original;

  std::cout << "creating the copy of the first dog" << std::endl;
  Dog copy(original);

  std::cout << " getting the type of the original: ";
  std::cout << original.getType() << std::endl;

  std::cout << " getting the type of the copy: ";
  std::cout << copy.getType() << std::endl;

  std::cout << "original making a sound: ";
  original.makeSound();

  std::cout << "copy making a sound: ";
  copy.makeSound();

  std::cout << "changing the type of cat to firulais" << std::endl;
  original.set_type("firulais");

  std::cout << "checking types again original: " << original.getType()
            << "the copy type will be called copy: " << copy.getType()
            << std::endl;

  std::cout << "both make sounds again" << std::endl;
  std::cout << "original: ";
  original.makeSound();
  std::cout << "copy: ";
  copy.makeSound();

  std::cout
      << "\ntests done for dog, destroyers for dog and animal getting called\n"
      << std::endl;
}

void testCat(void) {
  std::cout << "\n==== Cat Test ====" << std::endl;

  std::cout << "creating the first cat" << std::endl;
  Cat original;

  std::cout << "creating the copy of the first cat" << std::endl;
  Cat copy(original);

  std::cout << "getting the type of the original: ";
  std::cout << original.getType() << std::endl;

  std::cout << "getting the type of the copy: ";
  std::cout << copy.getType() << std::endl;

  std::cout << "original making a sound: ";
  original.makeSound();
  std::cout << "copy making a sound: ";
  copy.makeSound();

  std::cout << "changing the type of cat to megatron" << std::endl;
  original.set_type("megatron");

  std::cout << "\nchecking types again original: " << original.getType()
            << "the copy type will be called\n copy: " << copy.getType()
            << std::endl;

  std::cout << "both make sounds again" << std::endl;
  std::cout << "original: ";
  original.makeSound();
  std::cout << "copy: ";
  copy.makeSound();

  std::cout
      << "\ntests done for cat, destroyers for cat and animal getting called"
      << std::endl;
}

void testAnimals(void) {
  std::cout << "\n==== Animal tests ====\n" << std::endl;
  std::cout << "calling Animal constructor" << std::endl;
  Animal meta;

  std::cout << "getting the type of the animal" << std::endl;
  std::cout << meta.getType() << std::endl;

  std::cout << "making the animal make a sound" << std::endl;
  meta.makeSound();

  std::cout << "test for Animal done, animal destructor being called"
            << std::endl;
}

int main(void) {
  testAnimals();
  testCat();
  testDog();
  testWrongAnimal();
  mainTests1();
  mainTests2();
  return 0;
}
