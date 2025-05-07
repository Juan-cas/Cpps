#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

// Constructors:
Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &var) : AMateria(var) {}

Cure::~Cure(void) {}

AMateria *Cure::clone() const { return new Cure(*this); }

// Overloards:

Cure &Cure::operator=(const Cure &tmp) {
  AMateria::operator=(tmp);
  return (*this);
}

// Methods:

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.getName() << "'s wounds *"
            << std::endl;
}

std::string const &Cure::getType() const { return _Type; }
