
#ifndef DOG_HPP
#define DOG_HPP

#include "Animals.hpp"

class Dog : public Animal {
private:
  std::string _type;

public:
  // cannonical:
  Dog();
  Dog(const Dog &otherAnimal);
  virtual ~Dog(void);
  virtual Dog &operator=(const Animal &this_animal);

  // method:
  virtual void makeSound() const;
};

#endif
