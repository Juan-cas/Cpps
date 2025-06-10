#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "tests.hpp"
#include "AForm.hpp"
#include <cassert>
#include <iostream>

void tests_batch_2(void) {

  std::cout << "\n== Test 4.1 should work as intended ==" << std::endl;
  try {
    PresidentialForm form = PresidentialForm();
  } catch (const std::exception &e) {
    std::cerr << "Test 4.1 caught an unexpected exception: " << e.what()
              << std::endl;
  }

  std::cout << "\n== Test 4.2 should work as intended ==" << std::endl;
  try {
    AForm cursedForm("Forbidden Scroll", false, 1, 5);
  } catch (const std::exception &e) {

    std::cerr << "Test 4.2 caught an unexpected exception: " << e.what()
              << std::endl;
  }

  std::cout << "\n== test 4.3: invalid form grade required (grade too low)=="
            << std::endl;

  try {
    AForm cursedForm("Forbidden Scroll", false, 200,
                     5); // Invalid grade, should throw
  } catch (const std::exception &e) {
    std::cerr << "Test 4.3 caught expected exception: " << e.what()
              << std::endl;
  }

  std::cout << "\n== test 4.4: invalid form grade required (grade too high)=="
            << std::endl;

  try {
    AForm cursedForm("Forbidden Scroll", false, 0,
                     5); // Invalid grade, should throw
  } catch (const std::exception &e) {
    std::cerr << "Test 4.4 caught expected exception: " << e.what()
              << std::endl;
  }
}
