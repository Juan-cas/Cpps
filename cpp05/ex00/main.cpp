#include "Bureaucrat.hpp"
#include <cassert>
#include <iostream>

int main() {
//exceptions handled gracefully:
/*  try {
    Bureaucrat bureaucrat = Bureaucrat("juan", 0);
  } catch (const Bureaucrat::GradeTooLowException &e) {
    std::cout << "Caught expected exeception: " << e.what() << std::endl;
    assert(std::string(e.what()) == "Grade below the minimum!");
  };
*/
/*
  try {
    Bureaucrat bureaucrat = Bureaucrat("juan", 151);
  } catch (const Bureaucrat::GradeTooHighException &e) {
    std::cout << "Caught expected exeception: " << e.what() << std::endl;
    assert(std::string(e.what()) == "Grade exceeds the max!");
  };
  
*/
  try {
    Bureaucrat bureaucrat = Bureaucrat("juan", 2);
  } catch (const Bureaucrat::GradeTooLowException &e) {
    std::cout << "Caught expected exeception: " << e.what() << std::endl;
    assert(std::string(e.what()) == "Grade below the minimum!");
  };
  //exception not handled gracefully:
  //Bureaucrat b("juan", 0);
  //std::cout << b << std::endl;
  return 0;
}
