#ifndef ANIMALS_HPP
#define ANIMALS_HPP

#include <string>

class Animal {
protected:
  std::string _type;

public:
  // Canonical way
  Animal();
  Animal(std::string type);
  Animal(const Animal &otherAnimal);
  virtual ~Animal(void);
  virtual Animal* clone() const = 0;
  Animal &operator=(const Animal &this_animal);

  // setter:
  virtual void set_type(std::string type);

  // getter:
  std::string getType() const;

  // methods:
  virtual void makeSound() const;
};

#endif
