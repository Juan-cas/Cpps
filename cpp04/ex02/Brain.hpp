#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>
#include <string>

class Brain {

private:
  std::string _Ideas[100];

public:
  Brain(void);
  Brain(std::string ideas[100]);
  Brain(const Brain &var);
  ~Brain(void);
  Brain &operator=(const Brain &tmp);
  void Ideas(void) {

  }
};
std::ostream &operator<<(std::ostream &os, const Brain &tmp);

#endif
