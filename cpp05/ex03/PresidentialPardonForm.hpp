#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"
class PresidentialForm : public AForm {
private:
  std::string _Target;

public:
  PresidentialForm(std::string Name, bool Signed, int Grade, int Rgrade,
                   std::string target);
  PresidentialForm(std::string target);
  ~PresidentialForm();

  void beExcecuted(Bureaucrat &person) const;
};

#endif
