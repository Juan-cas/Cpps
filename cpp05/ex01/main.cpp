#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <cassert>
#include <iostream>

void testFormGradeValidation() {
  try {
    Form invalidHigh("Top Secret", false, 0, 50); // Grade too high
  } catch (const Form::GradeTooHighException &e) {
    std::cout << "Caught expected GradeTooHighException: " << e.what()
              << std::endl;
    assert(std::string(e.what()) == "Grade exceeds the max!");
  }

  try {
    Form invalidLow("Useless Form", false, 151, 50); // Grade too low
  } catch (const Form::GradeTooLowException &e) {
    std::cout << "Caught expected GradeTooLowException: " << e.what()
              << std::endl;
    assert(std::string(e.what()) == "Grade below the minimum!");
  }
}

void testFormSigning() {
  Bureaucrat boss("Alice", 1);   // Highest rank
  Bureaucrat intern("Bob", 150); // Lowest rank
  Form contract("Work Contract", false, 50, 25);

  try {
    contract.beSigned(boss); // Should succeed
    std::cout << "Form successfully signed by " << boss.getName() << std::endl;
  } catch (const std::exception &e) {
    std::cout << "Unexpected exception: " << e.what() << std::endl;
  }

  try {
    contract.beSigned(intern); // Should fail
  } catch (const Form::GradeTooLowToSign &e) {
    std::cout << "Correctly failed to sign: " << e.what() << std::endl;
  }
}

int main() {
  testFormGradeValidation();
  testFormSigning();

  return 0;
}
