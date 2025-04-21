#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"
#include <fstream>
#include <iostream>

Shrubbery::Shrubbery(const std::string Name, bool Signed, int Grade, int Rgrade,
                     const std::string target)
    : AForm(Name, Signed, Grade, Rgrade), _Target(target) {
  std::cout << "The constructor for the ShrubberyCreationForm has been called"
            << std::endl;
}

Shrubbery::Shrubbery(std::string target)
    : AForm("Intern_created_ShrubberyForm", false, 149, 149), _Target(target) {
  std::cout << "The intern has created a ShrubberyForm" << std::endl;
}

Shrubbery::~Shrubbery() {
  std::cout << "ShrubberyCreationForm destructor has been called" << std::endl;
}


//form signers:
void Shrubbery::beExcecuted(Bureaucrat &person) const {
  if (this->getSigned() == false) {
    std::cout << "The form has not been signed therefore cant be executed"
              << std::endl;
    throw FormNotSignedException();
    return;
  }
  if (person.getGrade() > this->getRgrade()) {
    std::cout << "The Bureaucrat " << person.getName()
              << " cant execute the form " << std::endl;
    throw GradeTooLowException();
    return;
  }
  if (person.getGrade() <= this->getRgrade() && this->getSigned() == true) {
    std::cout << "The Bureaucrat: " << person.getName()
              << " has executed the form" << std::endl;
    std::string file_name = (_Target + "_shrubbery");
    std::ofstream outfile(file_name.c_str());
    if (outfile.is_open()) {
      outfile << "       ###\n"
              << "      #o###\n"
              << "    #####o###\n"
              << "   #o#\\#|#/###\n"
              << "    ###\\|/#o#\n"
              << "     # }|{  #\n"
              << "       }|{\n";
      outfile.close();
    }
    return;
  }
}
