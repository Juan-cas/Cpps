#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>

typedef class Bureaucrat Bureaucrat;

class AForm {
private:
  const std::string _Name;
  bool _Signed;
  const int _Grade;
  const int _Rgrade;
  AForm &operator=(const AForm &form);

protected:
  // setters:
  virtual void setSigned(const bool Signed);

public:
  // constructor:
  AForm();
  AForm(std::string Name, bool Signed, int Grade, int Rgrade);
  AForm(const AForm &form);
  virtual ~AForm();

  // getters:
  virtual std::string getName() const;
  virtual bool getSigned() const;
  virtual int getGrade() const;
  virtual int getRgrade() const;

  // overloaders:
  friend std::ostream &operator<<(std::ostream &out, const AForm &obj);

  // modifiers:
  virtual void beSigned(Bureaucrat &person);

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

  virtual void execute(Bureaucrat &person) const = 0;
};

#endif
