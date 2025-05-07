#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP
#include <string>

typedef struct AMateria AMateria;

class IMateriaSource {

public:

  // Constructors:
  virtual ~IMateriaSource(void);

  // Methods:
  virtual void learnMateria(AMateria *) = 0;
  virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif
