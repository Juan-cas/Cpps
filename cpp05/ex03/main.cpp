#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <cassert>
#include <iostream>

int main() {
  Intern randomintern1 = Intern();
  AForm *shru = randomintern1.makeForm("shrubbery form", "paula");
  std::cout << shru << std::endl;
  return 0;
}
