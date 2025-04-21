#ifndef CAT_HPP
#define CAT_HPP

#include "Animals.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
  Brain *_brain;
public:
  Cat();
  virtual ~Cat(void);
  virtual void makeSound() const;
};

#endif
