#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm()
    : _Name("RandomAForm"), _Signed(false), _Grade(149), _Rgrade(149) {}

AForm::AForm(std::string Name, bool Signed, int Grade, int Rgrade)
    : _Name(Name), _Signed(Signed), _Grade(Grade), _Rgrade(Rgrade) {
  if (Grade < 1) {
    throw GradeTooHighException();
  }
  if (Grade > 150) {
    throw GradeTooLowException();
  }
  std::cout << "AForm constructor has been called" << std::endl;
}

AForm::AForm(const AForm &form)
    : _Name(form.getName()), _Signed(form.getSigned()), _Grade(form.getGrade()),
      _Rgrade(form.getRgrade()) {}

AForm::~AForm() {
  std::cout << "AForm destructor has been called" << std::endl;
}

// setters:
void AForm::setSigned(bool Signed) { _Signed = Signed; }

// getters:
std::string AForm::getName() const { return _Name; }
bool AForm::getSigned() const { return _Signed; }
int AForm::getGrade() const { return _Grade; }
int AForm::getRgrade() const { return _Rgrade; }

// modifiers:
void AForm::beSigned(Bureaucrat &person) {
  if (_Signed == true) {
    std::cout << "The form" << this->getName()
              << " is already signed and so the bureaucrat did nothing"
              << std::endl;
    return;
  } else if (person.getGrade() <= this->getGrade()) {
    std::cout << "The bureaucrat with the name " << person.getName() << " and "
              << person.getGrade() << " successfully signed the form "
              << this->getName() << std::endl;
    _Signed = true;
    return;
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
  return "grade too low to sign the form";
}

const char *AForm::FormNotSignedException::what() const throw() {
  return "Form has not been signed yet!";
}
