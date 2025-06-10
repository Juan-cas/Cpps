#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>

typedef class Bureaucrat Bureaucrat;

class Form {
private:
  const std::string _Name;
  bool _Signed;
  const int _Grade;
  const int _Rgrade;

public:
  // constructor:
  Form();
  Form(std::string Name, bool Signed, int Grade, int Rgrade);
  Form(Form &form);
  ~Form();

  // setters:
  void setSigned(const bool Signed);

  // modifiers:
  void beSigned(Bureaucrat &person);

  // getters:
  std::string getName() const;
  bool getSigned() const;
  int getGrade() const;
  int getRgrade() const;

  // overloaders:
  friend std::ostream &operator<<(std::ostream &out, const Form &obj);
  Form &operator=(const Form &form);

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
};

#endif
