#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"
#include <iostream>
#include <string>

class Cure : public AMateria {

private:
  std::string _Type;

public:
  // Constructor:
  Cure(void);
  Cure(const Cure &var);
  virtual ~Cure(void);

  // Overloads:
  Cure &operator=(const Cure &tmp);
  virtual AMateria *clone() const;

  // Methods:
  virtual void use(ICharacter &target);
  std::string const &getType() const;
};

#endif
