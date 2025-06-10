#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
public:
  Zombie(std::string name);
  ~Zombie(void);

  void announce();
  std::string get_name() const;

private:
  std::string name;
};

void randomChump(std::string name);
Zombie *newZombie(std::string name);

#endif
