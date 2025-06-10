#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern {
private:
  friend int findForm(std::string form);

public:
  Intern();
  Intern(const Intern &other);
  ~Intern();

  Intern &operator=(const Intern &other);
  AForm *makeForm(const std::string &name, const std::string &target);
};

#endif
