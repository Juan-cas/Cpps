#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <filesystem>

// Constructors:
Ice::Ice(void) : AMateria("ice") {}

Ice::Ice(const Ice &var) : AMateria(var) {
  _Type = var._Type;
}

Ice::~Ice(void) {}

AMateria *Ice::clone() const { return new Ice(*this); }

// Overloads:
Ice &Ice::operator=(const Ice &tmp) {
  _Type = tmp._Type;
  return (*this);
}

// Methods:
void Ice::use(ICharacter& target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}

