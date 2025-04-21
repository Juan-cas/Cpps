#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstddef>

Intern::Intern() {
  std::cout
      << "Intern constructor called a new nameless inter has joined the fray"
      << std::endl;
}

Intern::~Intern() { std::cout << "intern destructor called" << std::endl; }

int findForm(std::string form) {
  if (form == "shrubbery request")
    return 1;
  if (form == "presidential request")
    return 2;
  if (form == "robotomy request")
    return 3;
  return 4;
}

AForm *Intern::makeForm(const std::string &name, const std::string &target) {
  int form_type = findForm(name);
  switch (form_type) {
  case 1:
    std::cout << "Intern creates a ShrubberyCreationForm" << std::endl;
    return new Shrubbery(target);
  case 2:
    std::cout << "Intern creates a PresidentialPardonForm" << std::endl;
    return new PresidentialForm(target);
  case 3:
    std::cout << "Intern creates a RobotomyRequestForm" << std::endl;
    return new RobotomyForm(target);
  default:
    std::cout << "the intern didnt understand the request to create a form and "
                 "thus did nothing"
              << std::endl;
    return NULL;
  }
}
