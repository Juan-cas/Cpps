#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "tests.hpp"
#include <cassert>
#include <iostream>

void tests_batch_1(void) {

  std::cout << "== Test 1: Valid signing ==" << std::endl;
  try {
    Bureaucrat juan("Juan", 3); // High enough grade*/
    AForm pizzaForm("Let's Eat Pizza", false, 5, 6);
    std::cout << pizzaForm << std::endl;
    juan.signForm(pizzaForm); // Should succeed*/
    std::cout << pizzaForm << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Test 1 failed: " << e.what() << std::endl;
  }

  std::cout << "\n== Test 2: Grade too low to sign ==" << std::endl;
  try {
    Bureaucrat pepe("Pepe", 10); // Too low to sign
    AForm taxForm("Tax Form", false, 5, 6);
    pepe.signForm(taxForm); // Should throw
  } catch (const std::exception &e) {
    std::cerr << "Test 2 caught expected exception: " << e.what() << std::endl;
  }

  std::cout << "\n== Test 3: Invalid Bureaucrat grade (too high) =="
            << std::endl;
  try {
    Bureaucrat hacker("Hacker",
                      0); // Invalid grade, should throw in constructor
  } catch (const std::exception &e) {
    std::cerr << "Test 3 caught expected exception: " << e.what() << std::endl;
  }

  std::cout << "\n== Test 3.1: Invalid Bureaucrat grade (too low) =="
            << std::endl;
  try {
    Bureaucrat hacker("Hacker",
                      150); // Invalid grade, should throw in constructor
  } catch (const std::exception &e) {
    std::cerr << "Test 3.1 caught expected exception: " << e.what()
              << std::endl;
  }
}
