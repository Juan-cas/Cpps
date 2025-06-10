#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationFormCreationForm", false, 145, 137),
      _Target("Default Target") {
  std::cout << "Default ShrubberyCreationFormCreationForm with default target"
            << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationFormCreationForm", false, 145, 137),
      _Target(target) {
  std::cout << "ShrubberyCreationFormCreationForm called with target: "
            << target << "." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
  std::cout << "ShrubberyCreationFormCreationForm destructor has been called"
            << std::endl;
}

// form signers:
void ShrubberyCreationForm::execute(Bureaucrat &person) const {
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
