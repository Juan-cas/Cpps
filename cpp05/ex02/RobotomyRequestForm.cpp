#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", false, 72, 45), _Target("default target") {
  std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", false, 72, 45), _Target(target) {
  std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &other)
    : AForm(other) {
  _Target = other.GetTarget();
  std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
  std::cout << "RobotomyRequestForm destructor has been called" << std::endl;
}

// form signers:
void RobotomyRequestForm::execute(Bureaucrat &person) const {
  if (this->getSigned() == false) {
    std::cout << "The form has not been signed therefore cant be executed"
              << std::endl;
    throw FormNotSignedException();
    return;
  }
  if (person.getGrade() > getRgrade()) {
    std::cout << "The Bureaucrat " << person.getName()
              << " doesnt have the required grade to execute the form "
              << std::endl;
    throw GradeTooLowException();
    return;
  }
  if (person.getGrade() <= this->getRgrade() && this->getSigned() == true) {
    std::cout << "The Bureaucrat: " << person.getName()
              << " has executed the form " << std::endl;
    std::srand(std::time(0));
    int random_chance = std::rand() % 100;
    if (random_chance < 50) {
      std::cout << "drilling noises, " << this->GetTarget()
                << " has been robotomized." << std::endl;
      return;
    }
    std::cout << "The robotomy has failed" << std::endl;
    return;
  }
}

std::string RobotomyRequestForm::GetTarget() const { return _Target; }
