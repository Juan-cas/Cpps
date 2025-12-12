#include "base.hpp"
#include "classA.hpp"
#include "classB.hpp"
#include "classC.hpp"
#include <cstdlib>
#include <iostream>
#include <ostream>

static std::string classes[] = {"A", "B", "C"};

static Base *generate(void) {

  switch (rand() % 3) {
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
    classA &a = dynamic_cast<classA &>(p);
    std::cout << "The pointer is of classA" << std::endl;
  } catch (std::bad_cast &e) {
  }
  try {
    classB &b = dynamic_cast<classB &>(p);
    std::cout << "The pointer is of classB" << std::endl;
  } catch (std::bad_cast &e) {
  }
  try {
    classC &c = dynamic_cast<classC &>(p);
    std::cout << "The pointer is of classC" << std::endl;
  } catch (std::bad_cast &e) {
  }
}

int main() {
  Base *base1 = generate();
  identify(base1);
  identify(base1);
  Base *base2 = generate();
  identify(base2);
  identify(base2);
  Base *base3 = generate();
  identify(base3);
  identify(base3);
}
