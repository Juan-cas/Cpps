#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

class Character : public ICharacter {

private:
  AMateria *_Inventory[5];
  std::string _Name;
  AMateria *_Floor[20];

public:
  // Constructors:
  Character(void);
  Character(std::string str);
  Character(const Character &var);
  virtual ~Character(void);

  // Overloads:
  Character &operator=(const Character &tmp);

  // Methods:
  virtual std::string const &getName() const;
  virtual void equip(AMateria *m);
  virtual void unequip(int idx);
  virtual void use(int idx, ICharacter &target);
};

#endif
