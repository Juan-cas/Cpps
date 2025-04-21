#include "RobotomyRequestForm.hpp"
#include "Form.hpp"
#include <cstdlib>
#include <ctime>

RobotomyForm::RobotomyForm(const std::string Name, bool Signed, int Grade,
                           int Rgrade, const std::string target)
    : AForm(Name, Signed, Grade, Rgrade), _Target(target) {
  std::cout << "The constructor for the RobotomyRequestForm has been called"
            << std::endl;
}

RobotomyForm::RobotomyForm(std::string target)
    : AForm("Intern_created_RobotomyForm", false, 149, 149), _Target(target) {
  std::cout << "The intern has created a RobotomyForm" << std::endl;
}

RobotomyForm::~RobotomyForm() {
  std::cout << "RobotomyRequestForm destructor has been called" << std::endl;
}


void RobotomyForm::beExcecuted(Bureaucrat &person) const {
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
    std::srand(std::time(0));
    int random_chance = std::rand() % 100;
    if (random_chance < 50) {
      std::cout << "drilling noises, " << this->_Target
                << " has been robotomized." << std::endl;
      return;
    }
    std::cout << "The robotomy has failed" << std::endl;
    return;
  }
}

