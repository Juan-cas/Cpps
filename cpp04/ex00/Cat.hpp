#ifndef CAT_HPP
#define CAT_HPP

#include "Animals.hpp"

class Cat : public Animal {
public:
  Cat();
  virtual ~Cat(void);
  virtual void makeSound() const;
};

#endif
