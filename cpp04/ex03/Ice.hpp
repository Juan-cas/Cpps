#ifndef ICE_HPP
#define ICE_HPP
#include "AMateria.hpp"
#include <iostream>
#include <string>

class Ice : public AMateria {

private:
  std::string _Type;

public:
  // Constructors:
  Ice(void);
  Ice(const Ice &var);
  virtual ~Ice(void);

  // Overloads:
  Ice &operator=(const Ice &tmp);
  virtual AMateria *clone() const;

  // Methods:
  virtual void use(ICharacter& target);
  std::string const &getType() const;
};

#endif
