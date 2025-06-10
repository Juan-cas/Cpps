#include "Bureaucrat.hpp"
#include <cassert>
#include <iostream>

int main() {
  // exceptions handled gracefully:
  std::cout << "Testing grade too high exception with grade 0\n" << std::endl;
  try {
    Bureaucrat bureaucrat = Bureaucrat("juan", 0);
  } catch (const Bureaucrat::GradeTooHighException &e) {
    std::cout << "Caught expected exeception: " << e.what() << std::endl;
    assert(std::string(e.what()) == "Grade exceeds the max!");
  };
  std::cout << "\nTesting grade too low exception with grade 151\n" << std::endl;
  try {
    Bureaucrat bureaucrat = Bureaucrat("juan", 151);
  } catch (const Bureaucrat::GradeTooLowException &e) {
    std::cout << "Caught expected exeception: " << e.what() << std::endl;
    assert(std::string(e.what()) == "Grade below the minimum!");
  };

  std::cout << "\nTesting copy constructor\n" << std::endl;
  Bureaucrat buro = Bureaucrat("roberto", 100);
  std::cout << "copying roberto into another bureaucrat" << std::endl;
  Bureaucrat buro2(buro);

  std::cout << buro2 << std::endl;
  std::cout << buro << std::endl;

  return 0;
}
