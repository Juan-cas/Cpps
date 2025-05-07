#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>
#include <string>

class Brain {

private:
  std::string ideas[100];

public:
  Brain(void);
  Brain(std::string str);
  Brain(const Brain &var);
  ~Brain(void);
  Brain &operator=(const Brain &tmp);
};
std::ostream &operator<<(std::ostream &os, const Brain &tmp);

#endif
