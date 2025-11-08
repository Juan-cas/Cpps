#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {

protected:
  std::string _type;

public:
  // canon:
  WrongAnimal(void);
  WrongAnimal(std::string type);
  WrongAnimal(const WrongAnimal &otherAnimal);
  virtual ~WrongAnimal(void);
  WrongAnimal &operator=(WrongAnimal &this_animal);

  // getter:
  std::string getType(void) const;

  // setters:
  void set_type(std::string type);

  // method:
  virtual void makeSound() const;
};

#endif
