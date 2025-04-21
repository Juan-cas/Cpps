#ifndef ANIMALS_HPP
#define ANIMALS_HPP

#include <iostream>
#include <string>

class Animal{
protected:
  std::string _type;
public:
	Animal();
	Animal(std::string type);
	void set_type(std::string type);
	std::string getType() const;
	Animal& operator=(Animal& this_animal);
	virtual ~Animal(void);
	virtual void makeSound() const;
};

#endif
