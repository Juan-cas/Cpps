#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
public:
  Harl();
  ~Harl();
  void complain(std::string level);
  typedef void (Harl::*FooPtr)();

private:
  void debug();
  void info();
  void warning();
  void error();
};

#endif // HARL_HPP
