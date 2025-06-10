#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
  Intern someRandomIntern;
  Bureaucrat highRanker("Alice", 1); // Top grade bureaucrat

  std::cout << "\n--- Creating PresidentialPardonForm ---" << std::endl;
  AForm *form1 = someRandomIntern.makeForm("presidential pardon", "Neo");
  if (form1) {
    highRanker.signForm(*form1);
    highRanker.executeForm(*form1);
    delete form1;
  }

  std::cout << "\n--- Creating RobotomyRequestForm ---" << std::endl;
  AForm *form2 = someRandomIntern.makeForm("robotomy request", "Trinity");
  if (form2) {
    highRanker.signForm(*form2);
    highRanker.executeForm(*form2);
    delete form2;
  }

  std::cout << "\n--- Creating ShrubberyCreationForm ---" << std::endl;
  AForm *form3 = someRandomIntern.makeForm("shrubbery creation", "Zion");
  if (form3) {
    highRanker.signForm(*form3);
    highRanker.executeForm(*form3);
    delete form3;
  }

  std::cout << "\n--- Creating an Unknown Form ---" << std::endl;
  AForm *form4 = someRandomIntern.makeForm("death star plan", "Alderaan");
  if (!form4)
    std::cout << "Form creation failed as expected for unknown form.\n";

  return 0;
}
