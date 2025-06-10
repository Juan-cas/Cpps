#include "AMateria.hpp"
#include "ICharacter.hpp"

// Constructor:


AMateria::AMateria(std::string str) : _Type(str) {}

AMateria::AMateria(const AMateria &var) : _Type(var._Type){}

AMateria::~AMateria(void) {}

// Overloads:

/*
AMateria &AMateria::operator=(const AMateria &tmp) {

  if (this != &tmp) {
    _Type = tmp._Type;
  }
  return (*this);
}
*/


// Methods:

std::string const &AMateria::getType() const { return _Type; }

void AMateria::use(ICharacter &target) {
  std::cout << "Using materia against " << target.getName() << std::endl;
}
