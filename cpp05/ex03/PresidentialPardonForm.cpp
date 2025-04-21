#include "PresidentialPardonForm.hpp"
#include "Form.hpp"

PresidentialForm::PresidentialForm(const std::string Name, bool Signed,
                                   int Grade, int Rgrade,
                                   const std::string target)
    : AForm(Name, Signed, Grade, Rgrade), _Target(target) {
  std::cout << "The constructor for the PresidentialForm has been called"
            << std::endl;
}

PresidentialForm::PresidentialForm(std::string target)
    : AForm("Intern_created_Presidentialform", false, 149, 149),
      _Target(target) {
  std::cout << "The intern has created a PresidentialForm" << std::endl;
}

PresidentialForm::~PresidentialForm() {
  std::cout << "PresidentiaPardonForm destructor has been called" << std::endl;
}

void PresidentialForm::beSigned(Bureaucrat &person) {
  bool is_signed = this->getSigned();
  if (person.getGrade() <= this->getGrade() && is_signed == false) {
    this->setSigned(true);
    std::cout << _Target << " has been pardoned by Zaphod Beeblebrox "
              << std::endl;
    return;
  }
  if (is_signed == true) {
    std::cout << "The form was already signed, the bureaucrat did nothing"
              << std::endl;
  }
  throw GradeTooLowToSign();
}
