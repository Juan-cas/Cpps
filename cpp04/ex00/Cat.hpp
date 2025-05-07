#ifndef CAT_HPP
#define CAT_HPP

#include "Animals.hpp"

class Cat : public Animal {
private:
  std::string _type;

public:
  // canon:
  Cat();
  Cat(const Cat &otherAnimal);
  virtual Cat &operator=(const Cat &this_animal);
  virtual ~Cat(void);

  // method:
  void makeSound() const;
};

#endif
