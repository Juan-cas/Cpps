#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

void testConstructors() {
  std::cout << "\n--- Test: Invalid Bureaucrat ---" << std::endl;
  try {
    Bureaucrat b1("Bad", 151);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "\n--- Test: Invalid Form ---" << std::endl;
  try {
    PresidentialPardonForm f("Someone"); // Grade too high
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}

void testSigning() {
  std::cout << "\n--- Test: Signing Forms ---" << std::endl;
  Bureaucrat bob("Bob", 50);
  ShrubberyCreationForm form("Garden");

  std::cout << bob << std::endl;
  std::cout << form << std::endl;

  bob.signForm(form);

  std::cout << form << std::endl;
}

void testExecution() {
  std::cout << "\n--- Test: Executing Forms ---" << std::endl;
  Bureaucrat alice("Alice", 1);
  RobotomyRequestForm robot("Bender");

  alice.signForm(robot);
  alice.executeForm(robot);
}

void testCopyAndAssign() {
  std::cout << "\n--- Test: Copy and Assignment ---" << std::endl;

  Bureaucrat john("John", 20);
  Bureaucrat copy = john;

  std::cout << "Copy: " << copy << std::endl;
}

void testExceptions() {
  std::cout << "\n--- Test: Exceptions ---" << std::endl;

  Bureaucrat joe("Joe", 150);
  PresidentialPardonForm pardon("Target");

  std::cout << "joe tries to sign the form with grade " << joe.getGrade()
            << std::endl;
  try {
    joe.signForm(pardon);
  } catch (std::exception &e) {
    std::cout << "Caught exception: " << e.what() << std::endl;
  }

  std::cout << "joe tries to execute the form PresidentialPardonForm "
            << std::endl;
  try {
    joe.executeForm(pardon);
  } catch (std::exception &e) {
    std::cout << "Caught exception: " << e.what() << std::endl;
  }
}

int main() {
  testConstructors();
  testSigning();
  testExecution();
  testCopyAndAssign();
  testExceptions();
}
