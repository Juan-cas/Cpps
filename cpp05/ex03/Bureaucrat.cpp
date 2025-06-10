#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <ostream>

// constructor / destructor
Bureaucrat::Bureaucrat() : _Name("Random Bureaucrat"), _Grade(149) {
  std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string Name, int Grade) : _Name(Name) {
  if (Grade < 1)
    throw GradeTooHighException();
  if (Grade > 150)
    throw GradeTooLowException();
  setGrade(Grade);
  std::cout << "Bureaucrat constructor called" << std::endl;
  std::cout << "Creating a Bureaucrat with the name " << Name
            << " and the grade " << Grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &target) {
  _Grade = target._Grade;
  _Name = target._Name;
}

Bureaucrat::~Bureaucrat() {
  std::cout << "Bureaucrat destructor called" << std::endl;
}

// getters:
std::string Bureaucrat::getName() const { return _Name; }
int Bureaucrat::getGrade() const { return _Grade; }

// setters:
void Bureaucrat::setGrade(int Grade) {
  if (Grade < 0)
    throw GradeTooHighException();
  if (Grade > 150)
    throw GradeTooLowException();
  this->_Grade = Grade;
}

void Bureaucrat::signForm(AForm &form) {
  try {
    form.beSigned(*this);
    std::cout << "form has been successfully signed" << std::endl;
  } catch (std::exception &e) {
    std::cout << this << " couln't sign the form named " << form.getName()
              << " because " << e.what() << std::endl;
  }
}

void Bureaucrat::setName(const std::string &name) { _Name = name; }

// modifiers:
void Bureaucrat::gradeIncrease() {
  if (_Grade - 1 < 1)
    throw GradeTooHighException();
  this->_Grade -= 1;
}

void Bureaucrat::gradeDecrease() {
  if (_Grade + 1 > 150)
    throw GradeTooLowException();
  this->_Grade += 1;
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

Bureaucrat &Bureaucrat::Bureaucrat::operator=(const Bureaucrat &other) {
  if (this != &other) {
    this->setGrade(other.getGrade());
    this->setName(other.getName());
  }
  std::cout << "Equalizer operator called" << std::endl;
  return *this;
}

// methods:
void Bureaucrat::executeForm(AForm const &form) {
  std::cout << "bureaucrat " << _Name << " with grade " << _Grade
            << " tries to execute the form " << std::endl;
  form.execute(*this);
  std::cout << "the form has been executed" << std::endl;
}
