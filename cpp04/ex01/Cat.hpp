#ifndef CAT_HPP
#define CAT_HPP

#include "Animals.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
  std::string _type;
  Brain *_brain;

public:
  // canon:
  Cat();
  Cat(const Cat &otherAnimal);
  virtual Cat &operator=(const Cat &this_animal);
  virtual ~Cat(void);
  Animal* clone() const;

  // method:
  void makeSound() const;
};

#endif
