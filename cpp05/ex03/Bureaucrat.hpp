#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class AForm;

class Bureaucrat {
private:
  std::string _Name;
  int _Grade;

public:
  // constructor / destructor
  Bureaucrat(std::string Name, int Grade);
  ~Bureaucrat();

  // getters:
  std::string getName() const;
  int getGrade() const;

  // setters:
  void setName(std::string Name);
  void setGrade(int Grade);

  // value changers:
  void gradeIncrese();
  void gradeDecrease();
  void signForm(AForm &form);

  // exception classes:
  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  // overloads:
  friend std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);
};
#endif
