#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>
#include <string>

class MateriaSource : public IMateriaSource{

private:
  AMateria *_materias[4];

public:
  // Constructors;
  MateriaSource(void);
  MateriaSource(const MateriaSource &var);
  ~MateriaSource(void);

  // Overload:
  MateriaSource &operator=(const MateriaSource &tmp);

  // Methods
  virtual void learnMateria(AMateria *);
  virtual AMateria *createMateria(std::string const &type);
};

#endif
