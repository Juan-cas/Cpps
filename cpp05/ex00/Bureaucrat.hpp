#include <string>

class Bureaucrat {
private:
  std::string _Name;
  int _Grade;

public:
  // constructor / destructor
  Bureaucrat();
  Bureaucrat(const std::string Name, int Grade);
  Bureaucrat(const Bureaucrat &burocrat);
  ~Bureaucrat();

  // getters:
  std::string getName() const;
  int getGrade() const;

  // setters:
  void setGrade(int Grade);

  // value changers:
  void gradeIncrease();
  void gradeDecrease();

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

  Bureaucrat &operator=(const Bureaucrat &other);
};
