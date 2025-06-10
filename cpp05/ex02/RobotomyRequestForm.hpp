#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
  std::string _Target;
  RobotomyRequestForm &operator=(RobotomyRequestForm &form);

public:
  // constructors:
  RobotomyRequestForm();
  RobotomyRequestForm(const std::string &target);
  RobotomyRequestForm(RobotomyRequestForm &form);
  ~RobotomyRequestForm();

  std::string GetTarget() const;
  void execute(Bureaucrat &person) const;
};

#endif
