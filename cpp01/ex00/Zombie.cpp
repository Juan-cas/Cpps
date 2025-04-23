#include "Zombie.hpp"
#include <cstdlib>
#include <iostream>
#include <ostream>

void Zombie::announce() {
  std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name) {
  this->name = name;
  std::cout << "A new Zombie has spawned named " << this->name << " beware."
            << std::endl;
}

Zombie *Zombie::newZombie(std::string name) {
  Zombie *zombie = new Zombie(name);
  zombie->announce();
  return (zombie);
}

Zombie::~Zombie() {
  std::cout << "Zombie named: " << this->name << " has died." << std::endl;
}


std::string Zombie::get_name() const { return (this->name); }
