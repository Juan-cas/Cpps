#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Default PresidentialPardonForm", false, 25, 5),
      _Target("Default target") {
  std::cout << "Default PresidentialPardonForm constructor has been called"
            << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", false, 25, 5), _Target(target) {
  std::cout << "PresidentialPardonForm constructor has been called"
            << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &Form)
    : AForm(Form) {
  _Target = Form.GetTarget();
}

PresidentialPardonForm::~PresidentialPardonForm() {
  std::cout << "PresidentiaPardonForm destructor has been called" << std::endl;
}

// form signers:
void PresidentialPardonForm::execute(Bureaucrat &person) const {
  if (this->getSigned() == false) {
    std::cout << "The form has not been signed therefore cant be executed"
              << std::endl;
    throw FormNotSignedException();
  }
  if (person.getGrade() > this->getRgrade()) {
    std::cout << "The Bureaucrat " << person.getName()
              << " doesnt have the required grade to execute the form "
              << std::endl;
    throw GradeTooLowException();
  }
  std::cout << "The Bureaucrat: " << person.getName()
            << " has executed the form " << std::endl;
  std::cout << _Target << " has been pardoned by Zaphod Beeblebrox "
            << std::endl;
  return;
}

std::string PresidentialPardonForm::GetTarget() const { return this->_Target; }

void PresidentialPardonForm::SetTarget(std::string &target) {
  _Target = target;
}
