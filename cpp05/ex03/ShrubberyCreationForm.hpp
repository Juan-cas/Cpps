#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "Form.hpp"

class Shrubbery : public AForm {
private:
  std::string _Target;

public:
  Shrubbery(std::string Name, bool Signed, int Grade, int Rgrade,
            std::string target);
  Shrubbery(std::string target);
  ~Shrubbery();

  void beSigned(Bureaucrat &person);
};

#endif
