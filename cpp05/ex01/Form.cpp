#include "Form.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

Form::Form() : _Name("RandomForm"), _Signed(false), _Grade(149), _Rgrade(149) {}

Form::Form(std::string Name, bool Signed, int Grade, int Rgrade)
    : _Name(Name), _Signed(Signed), _Grade(Grade), _Rgrade(Rgrade) {
  if (Grade < 1) {
    throw GradeTooHighException();
  }
  if (Grade > 150) {
    throw GradeTooLowException();
  }
  std::cout << "Form constructor has been called" << std::endl;
}

Form::Form(Form &form)
    : _Name(form.getName()), _Signed(form.getSigned()), _Grade(form.getGrade()),
      _Rgrade(form.getRgrade()) {}

Form::~Form() { std::cout << "Form destructor has been called" << std::endl; }

// setters:
void Form::setSigned(bool Signed) { _Signed = Signed; }

// getters:
std::string Form::getName() const { return _Name; }
bool Form::getSigned() const { return _Signed; }
int Form::getGrade() const { return _Grade; }
int Form::getRgrade() const { return _Rgrade; }

// modifiers:
void Form::beSigned(Bureaucrat &person) {
  if (person.getGrade() <= this->getGrade() && _Signed == false) {
    _Signed = true;
    return;
  }
  else if (_Signed == true) {
    std::cout << "The form was already signed, the bureaucrat did nothing"
              << std::endl;
    return;
  }
  throw GradeTooLowToSign();
}

// overloaders:
std::ostream &operator<<(std::ostream &out, const Form &obj) {
  out << "the form " << obj.getName() << " has signed status of "
      << obj.getSigned() << " it's grade is " << obj.getGrade()
      << " and requires the signature of a grade " << obj.getRgrade()
      << " to be signed " << std::endl;
  return out;
}

Form &Form::operator=(const Form &form) {
  if (this != &form) {
    this->setSigned(form.getSigned());
  }
  return *this;
}

// Exception classes:
const char *Form::GradeTooHighException::what() const throw() {
  return "Grade exceeds the max!";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "Grade below the minimum!";
}
const char *Form::GradeTooLowToSign::what() const throw() {
  return "grade too low";
}
