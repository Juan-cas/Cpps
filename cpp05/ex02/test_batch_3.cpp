#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "tests.hpp"
#include <cassert>
#include <iostream>

void tests_batch_3(void) {
  std::cout << "test 5.1" << std::endl;
  std::cout << "Shoulnt catch exeptions" << std::endl;
  try {
    Bureaucrat pepe("Pepe", 3); // Too low to sign
    PresidentialForm cursedForm("Forbidden Scroll", false, 10, 5, "Juan");
    std::cout << cursedForm << std::endl;
    pepe.signForm(cursedForm); // Should succeed
    std::cout << cursedForm << std::endl;
    pepe.executeForm(cursedForm);
  } catch (const std::exception &e) {
    std::cerr << "Test 5.1 is not expecting a exception: " << e.what()
              << std::endl;
  }

  std::cout << "\ntest 5.2" << std::endl;
  std::cout << "Shoulnt catch exeptions" << std::endl;
  try {
    Bureaucrat pepe("Pepe", 3); 
    Shrubbery cursedForm("Forbidden Scroll", false, 10, 5, "Paula");
    std::cout << cursedForm << std::endl;
    pepe.signForm(cursedForm); 
    std::cout << cursedForm << std::endl;
    pepe.executeForm(cursedForm);
  } catch (const std::exception &e) {
    std::cerr << "Test 5.2 is not expecting an exception: " << e.what()
              << std::endl;
  }

  std::cout << "\ntest 5.3" << std::endl;
  std::cout << "Shoulnt catch exeptions" << std::endl;
  try {
    Bureaucrat pepe("Pepe", 3);
    RobotomyForm cursedForm("Forbidden Scroll", false, 10, 5, "Armando");
    std::cout << cursedForm << std::endl;
    pepe.signForm(cursedForm); 
    std::cout << cursedForm << std::endl;
    pepe.executeForm(cursedForm);
  } catch (const std::exception &e) {
    std::cerr << "Test 5.3 is not expecting an exception: " << e.what()
              << std::endl;
  }

  std::cout << "\ntest 5.4" << std::endl;
  std::cout << "Should catch Bureaucrat not being able to execute" << std::endl;
  try {
    Bureaucrat pepe("Pepe", 10);
    PresidentialForm cursedForm("Forbidden Scroll", false, 10, 9, "Juan");
    std::cout << cursedForm << std::endl;
    pepe.signForm(cursedForm); 
    std::cout << cursedForm << std::endl;
    pepe.executeForm(cursedForm);
  } catch (const std::exception &e) {
    std::cerr << "Test 5.4 caught expected exception: " << e.what()
              << std::endl;
  }

  std::cout << "\ntest 5.5" << std::endl;
  std::cout << "Should catch Bureaucrat not being able to execute" << std::endl;
  try {
    Bureaucrat pepe("Pepe", 10);
    Shrubbery cursedForm("Forbidden Scroll", false, 10, 9, "Paula");
    std::cout << cursedForm << std::endl;
    pepe.signForm(cursedForm); 
    std::cout << cursedForm << std::endl;
    pepe.executeForm(cursedForm);
  } catch (const std::exception &e) {
    std::cerr << "Test 5.5 caught expected exception: " << e.what()
              << std::endl;
  }

  std::cout << "\ntest 5.6" << std::endl;
  std::cout << "Should catch Bureaucrat not being able to execute" << std::endl;
  try {
    Bureaucrat pepe("Pepe", 10);
    RobotomyForm cursedForm("Forbidden Scroll", false, 10, 9, "Armando");
    std::cout << cursedForm << std::endl;
    pepe.signForm(cursedForm); 
    std::cout << cursedForm << std::endl;
    pepe.executeForm(cursedForm);
  } catch (const std::exception &e) {
    std::cerr << "Test 5.6 caught expected exception: " << e.what()
              << std::endl;
  }

  std::cout << "\ntest 5.7" << std::endl;
  std::cout << "Should catch the exception of the form not being signed" << std::endl;
  try {
    Bureaucrat pepe("Pepe", 10);
    RobotomyForm cursedForm("Forbidden Scroll", false, 10, 9, "Armando");
    pepe.executeForm(cursedForm);
    std::cout << cursedForm << std::endl;
    pepe.signForm(cursedForm); 
    std::cout << cursedForm << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Test 5.7 caught expected exception: " << e.what()
              << std::endl;
  }
  
  std::cout << "\ntest 5.8" << std::endl;
  std::cout << "Should catch the exception of the form not being signed" << std::endl;
  try {
    Bureaucrat pepe("Pepe", 10);
    RobotomyForm cursedForm("Forbidden Scroll", false, 10, 9, "Armando");
    pepe.executeForm(cursedForm);
    std::cout << cursedForm << std::endl;
    pepe.signForm(cursedForm); 
    std::cout << cursedForm << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Test 5.8 caught expected exception: " << e.what()
              << std::endl;
  }
}
