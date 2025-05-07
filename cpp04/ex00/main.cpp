#include "Animals.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <ostream>


void mainTests2(void) {
  std::cout << "\nmain test for this module acording to 42, for WrongAnimals\n"
            << std::endl;

  const WrongAnimal *meta = new WrongAnimal();
  const Animal *j = new Dog();
  const WrongAnimal *i = new WrongCat();
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound(); // will output the WrongCat sound!
  j->makeSound();
  meta->makeSound();

  delete i;
  delete j;
  delete meta;
}

void mainTests1(void) {
  std::cout << "\nmain test for this module acording to 42, for normal animals\n"
            << std::endl;

  const Animal *meta = new Animal();
  const Animal *j = new Dog();
  const Animal *i = new Cat();
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound(); // will output the cat sound!
  j->makeSound();
  meta->makeSound();

  delete i;
  delete j;
  delete meta;
}

void testWrongAnimal(void) {
  std::cout << "==== Wrong Animal Tests ====" << std::endl;

  std::cout << "the wrong cat constructor being called" << std::endl;
  WrongCat original;

  std::cout << "the wrong cat copy constructor is being called" << std::endl;
  WrongCat copy(original);

  std::cout << "\n getting the type of the original: ";
  std::cout << original.getType() << std::endl;

  std::cout << "\n getting the type of the copy: ";
  std::cout << copy.getType() << std::endl;

  std::cout << "\noriginal making a sound: ";
  original.makeSound();

  std::cout << "\ncopy making a sound: ";
  copy.makeSound();

  std::cout << "\nchanging the type of dog to firulais" << std::endl;
  original.set_type("firulais");

  std::cout << "\nchecking types again\n original: " << original.getType()
            << "\nthe copy type will be called\n copy: " << copy.getType()
            << std::endl;

  std::cout << "\nboth make sounds again" << std::endl;
  std::cout << "original: ";
  original.makeSound();
  std::cout << "\ncopy: ";
  copy.makeSound();

  std::cout << "\ntests done for WrongCat, destroyers for WrongCat and "
               "WrongAnimal getting called\n"
            << std::endl;
}

void testDog(void) {
  std::cout << "==== Dog Test ====" << std::endl;

  std::cout << "creating the first dog" << std::endl;
  Dog original;

  std::cout << "\ncreating the copy of the first dog" << std::endl;
  Dog copy(original);

  std::cout << "\n getting the type of the original: ";
  std::cout << original.getType() << std::endl;

  std::cout << "\n getting the type of the copy: ";
  std::cout << copy.getType() << std::endl;

  std::cout << "\noriginal making a sound: ";
  original.makeSound();

  std::cout << "\ncopy making a sound: ";
  copy.makeSound();

  std::cout << "\nchanging the type of cat to firulais" << std::endl;
  original.set_type("firulais");

  std::cout << "\nchecking types again\n original: " << original.getType()
            << "\nthe copy type will be called\n copy: " << copy.getType()
            << std::endl;

  std::cout << "\nboth make sounds again" << std::endl;
  std::cout << "original: ";
  original.makeSound();
  std::cout << "\ncopy: ";
  copy.makeSound();

  std::cout
      << "\ntests done for dog, destroyers for dog and animal getting called\n"
      << std::endl;
}

void testCat(void) {
  std::cout << "==== Cat Test ====" << std::endl;

  std::cout << "creating the first cat" << std::endl;
  Cat original;

  std::cout << "\ncreating the copy of the first cat" << std::endl;
  Cat copy(original);

  std::cout << "\ngetting the type of the original: ";
  std::cout << original.getType() << std::endl;

  std::cout << "\ngetting the type of the copy: ";
  std::cout << copy.getType() << std::endl;

  std::cout << "\noriginal making a sound: ";
  original.makeSound();
  std::cout << "copy making a sound: ";
  copy.makeSound();

  std::cout << "\nchanging the type of cat to megatron" << std::endl;
  original.set_type("megatron");

  std::cout << "\nchecking types again\n original: " << original.getType()
            << "the copy type will be called\n copy: " << copy.getType()
            << std::endl;

  std::cout << "\nboth make sounds again\n" << std::endl;
  std::cout << "original: ";
  original.makeSound();
  std::cout << "\ncopy: ";
  copy.makeSound();

  std::cout
      << "\ntests done for cat, destroyers for cat and animal getting called"
      << std::endl;
}

void testAnimals(void) {
  std::cout << "==== Animal tests ====" << std::endl;
  std::cout << "calling Animal constructor" << std::endl;
  Animal meta;

  std::cout << "getting the type of the animal" << std::endl;
  std::cout << meta.getType() << std::endl;

  std::cout << "making the animal make a sound" << std::endl;
  meta.makeSound();

  std::cout << "test for Animal done, animal destructor being called\n"
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
