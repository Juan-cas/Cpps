
#ifndef DOG_HPP
#define DOG_HPP

#include "Animals.hpp"

class Dog : public Animal {
public:
  Dog();
  virtual ~Dog(void);
  virtual void makeSound() const;
};

#endif
