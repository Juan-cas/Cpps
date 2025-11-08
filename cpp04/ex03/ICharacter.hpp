#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP
#include "AMateria.hpp"
#include <iostream>
#include <string>

class ICharacter {

private:
public:
  // Constuctors:
  ICharacter(void);
  ICharacter(std::string str);
  ICharacter(const ICharacter &var);
  virtual ~ICharacter(void);

  // Methods:
  virtual std::string const &getName() const = 0;
  virtual void equip(AMateria *m) = 0;
  virtual void unequip(int idx) = 0;
  virtual void use(int idx, ICharacter &target) = 0;
};

#endif
