#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
  // cannon:
  WrongCat(void);
  WrongCat(const WrongAnimal &otherAnimal);
  virtual ~WrongCat(void);
  virtual WrongCat &operator=(WrongCat &this_animal);

  // method:
  virtual void makeSound() const;
};

#endif
