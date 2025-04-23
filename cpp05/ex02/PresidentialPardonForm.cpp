#include "PresidentialPardonForm.hpp"

PresidentialForm::PresidentialForm(const std::string Name, bool Signed,
                                   int Grade, int Rgrade,
                                   const std::string target)
    : AForm(Name, Signed, Grade, Rgrade), _Target(target) {
  std::cout << "The constructor for the PresidentialForm has been called"
            << std::endl;
}

PresidentialForm::~PresidentialForm() {
  std::cout << "PresidentiaPardonForm destructor has been called" << std::endl;
}

// form signers:
void PresidentialForm::beExcecuted(Bureaucrat &person) const {
  if (this->getSigned() == false) {
    std::cout << "The form has not been signed therefore cant be executed"
              << std::endl;
    throw FormNotSignedException();
    return;
  }
  if (person.getGrade() > this->getRgrade()) {
    std::cout << "The Bureaucrat " << person.getName()
              << " doesnt have the required grade to execute the form "
              << std::endl;
    throw GradeTooLowException();
    return;
  }
  if (person.getGrade() <= this->getRgrade() && this->getSigned() == true) {
    std::cout << "The Bureaucrat: " << person.getName()
              << " has executed the form " << std::endl;
    std::cout << _Target << " has been pardoned by Zaphod Beeblebrox "
              << std::endl;
    return;
  }
}
