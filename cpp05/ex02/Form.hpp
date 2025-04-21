#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
  const std::string _Name;
  bool _Signed;
  const int _Grade;
  const int _Rgrade;

public:
  // constructor:
  AForm(std::string Name, bool Signed, int Grade, int Rgrade);

  // destructor:
  ~AForm();

  // setters:
  void setSigned(bool Signed);

  // modifiers:
  virtual void beSigned(Bureaucrat &person);
  virtual void beExcecuted(Bureaucrat &person) const ;

  // getters:
  std::string getName() const;
  bool getSigned() const;
  int getGrade() const;
  int getRgrade() const;

  // overloaders:
  friend std::ostream &operator<<(std::ostream &out, const AForm &obj);

  // exception classes:
  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowToSign : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class FormNotSignedException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

#endif
