#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
class RobotomyForm : public AForm {
private:
  std::string _Target;

public:
  RobotomyForm(std::string Name, bool Signed, int Grade, int Rgrade,
               std::string target);
  RobotomyForm(std::string target);
  ~RobotomyForm();

  void beExcecuted(Bureaucrat &person) const;
};

#endif
