
#ifndef DOG_HPP
#define DOG_HPP

#include "Animals.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
  Brain *_brain;
public:
  Dog();
  virtual ~Dog(void);
  virtual void makeSound() const;
};

#endif
