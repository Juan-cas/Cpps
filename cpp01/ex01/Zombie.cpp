#include "Zombie.hpp"
#include <iostream>
#include <ostream>

Zombie::Zombie() : _Name("Random Zombie") {}

Zombie::Zombie(std::string name) : _Name(name) {
  std::cout << "A new Zombie has spawned named " << this->get_name()
            << " beware." << std::endl;
}

Zombie::~Zombie() {
  std::cout << "Zombie named: " << get_name() << " has died." << std::endl;
}

std::string Zombie::get_name() const { return this->_Name; }

void Zombie::set_name(std::string &name) { this->_Name = name; }

Zombie *newZombie(std::string name) { return (new Zombie(name)); }

void Zombie::announce() {
  std::cout << this->get_name() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie *zombieHorde(int N, std::string name) {
  if (N <= 0)
    return NULL;
  Zombie *horde = new Zombie[N];
  for (int i = 0; i < N; i++) {
    horde[i].set_name(name);
  }
  return horde;
}
