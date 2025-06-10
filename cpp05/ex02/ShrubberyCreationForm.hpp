#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
  std::string _Target;
  ShrubberyCreationForm &operator=(ShrubberyCreationForm &target);

public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(const std::string &target);
  ShrubberyCreationForm(ShrubberyCreationForm &Target);
  ~ShrubberyCreationForm();

  void execute(Bureaucrat &person) const;
};

#endif
