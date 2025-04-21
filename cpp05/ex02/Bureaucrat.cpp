#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>
#include <ostream>

// constructor / destructor
Bureaucrat::Bureaucrat(const std::string Name, int Grade) : _Name(Name) {
  if (Grade < 1)
    throw GradeTooHighException();
  if (Grade > 149)
    throw GradeTooLowException();
  setGrade(Grade);
  std::cout << "Bureaucrat constructor called" << std::endl;
  std::cout << "Creating a Bureaucrat with the name " << Name
            << " and the grade " << Grade << std::endl;
}

Bureaucrat::~Bureaucrat() {
  std::cout << "Bureaucrat destructor called" << std::endl;
}

// getters:
std::string Bureaucrat::getName() const { return _Name; }
int Bureaucrat::getGrade() const { return _Grade; }

// setters:
void Bureaucrat::setName(std::string Name) { this->_Name = Name; }
void Bureaucrat::setGrade(int Grade) { this->_Grade = Grade; }

// modifiers:
void Bureaucrat::gradeIncrese() {
  if (_Grade == 1)
    throw GradeTooHighException();
  this->_Grade -= 1;
}

void Bureaucrat::gradeDecrease() {
  if (_Grade == 150)
    throw GradeTooLowException();
  this->_Grade -= 1;
}

// form signers:

void Bureaucrat::signForm(AForm &form) {
  try {
    form.beSigned(*this);
  } catch (const std::exception &e) {
    std::cerr << this->getName() << " coulnt sign " << form.getName()
              << e.what() << std::endl;
  }
}

void Bureaucrat::executeForm(AForm const &form) {
  try {
    form.beExcecuted(*this);
  } catch (const std::exception &e) {
    std::cerr << this->getName() << " coulnt execute " << form.getName()
              << ": " << e.what() << std::endl;
    throw;
  }
}

// exception sub::class:
const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade exceeds the max!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade below the minimum!";
}

// overloaders:
std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj) {
  out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
  return out;
}
