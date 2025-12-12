#include "base.hpp"
#include "classA.hpp"
#include "classB.hpp"
#include "classC.hpp"
#include <cstdlib>
#include <iostream>
#include <ostream>

static std::string classes[] = {"A", "B", "C"};

static Base *generate(void) {
  std::srand(time(NULL));
  int r = std::rand() % 3;

  switch (r) {
  case 1:
    return (new classA());
  case 2:
    return (new classB());
  case 3:
    return (new classC());
  default:
    std::cerr << "Something has gone terribly Wrong with good ol rand()"
              << std::endl;
    return (NULL);
  }
}

static void identify(Base *p) {
  if (dynamic_cast<classA *>(p))
    std::cout << "the pointer is a classA pointer" << std::endl;
  else if (dynamic_cast<classB *>(p))
    std::cout << "the pointer is a classB pointer" << std::endl;
  else if (dynamic_cast<classC *>(p))
    std::cout << "the pointer is a classC pointer" << std::endl;
  else
    std::cout << "Unable to identify the pointer" << std::endl;
}

static void identify(Base &p) {
  try {
    (void)dynamic_cast<classA &>(p);
    std::cout << "The reference is of classA" << std::endl;
  } catch (...) {
  }
  try {
    (void)dynamic_cast<classB &>(p);
    std::cout << "The reference is of classB" << std::endl;
  } catch (...) {
  }
  try {
    (void)dynamic_cast<classC &>(p);
    std::cout << "The reference is of classC" << std::endl;
  } catch (...) {
  }
}

int main() {
  std::cout << "\nRandomizing the creationg of the class" << std::endl;
  Base *base1 = generate();

  std::cout << "\nUsing identify to identify the pointer type" << std::endl;
  identify(base1);

  std::cout << "\nUsing identify to identify the reference type" << std::endl;
  identify(*base1);

  delete base1;
}
