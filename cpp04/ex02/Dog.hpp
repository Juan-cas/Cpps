
#ifndef DOG_HPP
#define DOG_HPP

#include "Animals.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
  std::string _type;
  Brain *_brain;

public:
  // cannonical:
  Dog();
  Dog(const Dog &otherAnimal);
  virtual ~Dog(void);
  virtual Dog &operator=(const Animal &this_animal);
  Animal *clone() const;

  // method:
  virtual void makeSound() const;
};

#endif
