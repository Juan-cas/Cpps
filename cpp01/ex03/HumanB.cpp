#include "HumanB.hpp"

HumanB::HumanB(string name) : name(name), weapon(0) {}

void HumanB::setWeapon(Weapon &type) { this->weapon = &type; }

void HumanB::attack() {
  if (this->weapon->getType().empty() == false) {
    cout << this->name << " attacks with their " << this->weapon->getType()
         << endl;
    return;
  }
  std::cout << "The human needs a weapon" << std::endl;
}

