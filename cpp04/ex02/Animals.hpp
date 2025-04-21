#ifndef ANIMALS_HPP
#define ANIMALS_HPP

#include <string>

class Animal {
protected:
  std::string _type;

public:
  //getter:
  virtual std::string getType() const;
  //setter:
  virtual void set_type(std::string type);
  virtual Animal &operator=(Animal &this_animal);
  virtual void makeSound() const;
  virtual ~Animal();
};

#endif
