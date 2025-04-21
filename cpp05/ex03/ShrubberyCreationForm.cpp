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

void Shrubbery::beSigned(Bureaucrat &person) {
  bool is_signed = this->getSigned();
  if (person.getGrade() <= this->getGrade() && is_signed == false) {
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
    this->setSigned(true);
    return;
  }
  if (is_signed == true) {
    std::cout << "The form was already signed, the bureaucrat did nothing"
              << std::endl;
  }
  throw GradeTooLowToSign();
}
