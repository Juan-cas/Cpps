#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
  WrongCat(void);
  virtual ~WrongCat(void);
  virtual void makeSound() const;
};

#endif
