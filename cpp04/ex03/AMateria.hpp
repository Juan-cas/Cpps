#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include <iostream>
#include "IMateriaSource.hpp"
#include <string>

typedef struct ICharacter ICharacter;

class AMateria {

private:
  std::string _Type;

public:
  // Constructors:
  AMateria(std::string str);
  AMateria(const AMateria &var);
  virtual ~AMateria(void);

  // Overloads:
  AMateria &operator=(const AMateria &tmp);

  // Methods:
  std::string const &getType() const;
  virtual AMateria *clone() const = 0;
  virtual void use(ICharacter &target);
};

#endif
