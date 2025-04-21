#ifndef INTERN_HPP
#define INTERN_HPP


#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <string>

class Intern {
  private:
  friend int findForm(std::string form);

public:
  Intern();
  ~Intern();

  AForm *makeForm(const std::string &name, const std::string &target);
};

#endif
