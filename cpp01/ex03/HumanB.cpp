#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(0) {}

void HumanB::setWeapon(Weapon &type) { this->weapon = &type; }

void HumanB::attack() {
  if (this->weapon) {
    std::cout << this->name << " attacks with their " << this->weapon->getType()
              << std::endl;
    return;
  }
  std::cout << "The human " << this->name << " needs a weapon" << std::endl;
}
