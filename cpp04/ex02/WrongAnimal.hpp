#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {

protected:
  std::string _type;

public:
  WrongAnimal(void);
  WrongAnimal(std::string type);
  void set_type(std::string type);
  std::string getType(void) const;
  WrongAnimal &operator=(WrongAnimal &this_animal);
  virtual ~WrongAnimal(void);
  virtual void makeSound() const;
};

#endif
