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

Intern::Intern(const Intern &other) {
  (void)other;
  std::cout << "intern copy constructor has been called" << std::endl;
}

Intern &Intern::operator=(const Intern &other) {
  if (this != &other) {
  }
  return *this;
}

Intern::~Intern() { std::cout << "intern destructor called" << std::endl; }

int findForm(std::string form) {
  if (form == "shrubbery creation")
    return 1;
  if (form == "presidential pardon")
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
    return new ShrubberyCreationForm(target);
  case 2:
    std::cout << "Intern creates a PresidentialPardonForm" << std::endl;
    return new PresidentialPardonForm(target);
  case 3:
    std::cout << "Intern creates a RobotomyRequestForm" << std::endl;
    return new RobotomyRequestForm(target);
  default:
    std::cout << "the intern didnt understand the request to create a form and "
                 "thus did nothing"
              << std::endl;
    return NULL;
  }
}
