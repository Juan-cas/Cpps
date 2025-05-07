#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <filesystem>

// Constructors:
Ice::Ice(void) : AMateria("ice") {

  return;
}

Ice::Ice(const Ice &var) : AMateria(var) {
  _Type = var._Type;
}

Ice::~Ice(void) {

  return;
}

AMateria *Ice::clone() const { return new Ice(*this); }

// Overloads:
Ice &Ice::operator=(const Ice &tmp) {
  AMateria::operator=(tmp);
  return (*this);
}

// Methods:
void Ice::use(ICharacter& target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}

