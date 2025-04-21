#include "Form.hpp"
#include <iostream>

AForm::AForm(std::string Name, bool Signed, int Grade, int Rgrade)
    : _Name(Name), _Signed(Signed), _Grade(Grade), _Rgrade(Rgrade) {
  if (Grade < 1) {
    throw GradeTooHighException();
  }
  if (Grade > 149) {
    throw GradeTooLowException();
  }
  std::cout << "Form constructor has been called" << std::endl;
}

// destructor:
AForm::~AForm() { std::cout << "Form destructor has been called" << std::endl; }

// setters:
void AForm::setSigned(bool Signed) { _Signed = Signed; }

// getters:
std::string AForm::getName() const { return _Name; }
bool AForm::getSigned() const { return _Signed; }
int AForm::getGrade() const { return _Grade; }
int AForm::getRgrade() const { return _Rgrade; }

// modifiers:
void AForm::beSigned(Bureaucrat &person) {
  if (person.getGrade() <= this->getGrade() && _Signed == false) {
    _Signed = true;
    return;
  }
  if (_Signed == true) {
    std::cout << "The form was already signed, the bureaucrat did nothing"
              << std::endl;
  }
  throw GradeTooLowToSign();
}

// overloaders:
std::ostream &operator<<(std::ostream &out, const AForm &obj) {
  out << "the form " << obj.getName() << " has signed status of "
      << obj.getSigned() << " it's grade is " << obj.getGrade()
      << " and requires the signature of a grade " << obj.getRgrade()
      << " to be signed " << std::endl;
  return out;
}
// Exception classes:
const char *AForm::GradeTooHighException::what() const throw() {
  return "Grade exceeds the max!";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "Grade below the minimum!";
}
const char *AForm::GradeTooLowToSign::what() const throw() {
  return "grade too low";
}
