#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

typedef std::string str;

class Zombie {
public:
  Zombie();
  Zombie(std::string name);
  ~Zombie(void);

  void announce() const;
  void set_name(std::string &name);
  str get_name() const;
  void announce();

private:
  std::string _Name;
};

void randomChump(std::string name);
Zombie *newZombie(std::string name);
Zombie *zombieHorde(int N, std::string name);

#endif
