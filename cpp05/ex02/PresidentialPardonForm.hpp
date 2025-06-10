#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
class PresidentialPardonForm : public AForm {
private:
  std::string _Target;
  PresidentialPardonForm &operator=(PresidentialPardonForm &Form);

public:
  PresidentialPardonForm();
  PresidentialPardonForm(const std::string &target);
  PresidentialPardonForm(PresidentialPardonForm &Form);
  ~PresidentialPardonForm();

  void SetTarget(std::string &target);
  std::string GetTarget() const;
  void execute(Bureaucrat &person) const;
};

#endif
